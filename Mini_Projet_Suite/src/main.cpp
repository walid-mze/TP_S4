#include "KubernetesCluster.h"
#include "Server.h"
#include "Container.h"
#include "Pod.h"
#include "Cloud_Util.h"
#include "MetricLogger.h"
#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
#include <algorithm>

int main() {
    std::cout << "=== Test AllocationException direct ===\n";
    try {
        Server failNode("fail-node", 1.0, 1024.0);
        failNode.allocate(4.0, 4096.0); // Trop gros
    } catch (const AllocationException& e) {
        std::cout << "Exception capturée : " << e.what() << std::endl;
    }

    std::cout << "\n=== Test FileException ===\n";
    KubernetesCluster cluster;
    auto nodeX = std::make_shared<Server>("nodeX", 12.0, 12048.0);
    nodeX->start();
    cluster.addNode(nodeX);
    try {
        saveClusterMetrics(cluster, "cluster1_metrics.txt");
        std::cout << "Métriques sauvegardées avec succès.\n";
    } catch (const FileException& e) {
        std::cout << "Exception capturée : " << e.what() << std::endl;
    }

    std::cout << "\n=== Test Lambda : serveurs inactifs ===\n";
    KubernetesCluster cluster1;
    auto inactiveServer = std::make_shared<Server>("node3", 2.0, 4096.0);
    cluster1.addNode(inactiveServer);
    auto inactifs = cluster1.getFilteredServers([](const Server& s) {
        return !s.isActive();
    });
    for (const auto& server : inactifs) {
        std::cout << server->getMetrics() << std::endl;
    }

    std::cout << "\n=== Déploiement sur un serveur inactif ===\n";
    auto c = std::make_unique<Container>("inactive-c1", "busybox", 1.0, 1024.0);
    auto pod = std::make_unique<Pod>("test-pod");
    pod->addContainer(std::move(c));
    try {
        cluster1.deployPod(std::move(pod));
    } catch (const AllocationException& e) {
        std::cout << "Exception capturée : " << e.what() << std::endl;
    }

    std::cout << "\n=== Pods triés par nombre de conteneurs ===\n";
    // Création des conteneurs
    auto c1 = std::make_unique<Container>("c1", "nginx", 2.0, 1024.0);
    auto c2 = std::make_unique<Container>("c2", "redis", 4, 2048.0);
    auto c3 = std::make_unique<Container>("c3", "mysql", 2, 1024.0);

    // Création des pods
    auto pod1 = std::make_unique<Pod>("web-pod");
    pod1->addContainer(std::move(c1));
    pod1->addContainer(std::move(c2));
    auto pod2 = std::make_unique<Pod>("db-pod");
    pod2->addContainer(std::move(c3));

    // Déploiement sans planification réelle, on injecte les pods manuellement
    std::vector<std::unique_ptr<Pod>> pods;
    pods.push_back(std::move(pod1));
    pods.push_back(std::move(pod2));
    for (auto& p : pods) {
        std::cout << "-> Déploiement du Pod [Pod: " << p->getName() << "]\n";
        for (const auto& container : p->getContainers()) {
            std::cout << container->getMetrics() << "\n";
        }
        try {
            cluster.deployPod(std::move(p));
        } catch (const AllocationException& e) {
            std::cout << "Exception capturée : " << e.what() << std::endl;
        }
        std::cout << "sur le nœud\n";
        for (const auto& server : cluster.getServers()) {
            std::cout << server->getMetrics() << std::endl;
        }
    }

    std::cout << "\n=== Tri des pods ===\n";
    std::vector<const Pod*> podRefs;
    for (const auto& server : cluster.getServers()) {
        for (const auto& pod : server->getPods()) {
            podRefs.push_back(pod.get());
        }
    }
    std::sort(podRefs.begin(), podRefs.end(),
        [](const Pod* a, const Pod* b) {
            return a->getContainers().size() > b->getContainers().size();
        });
    for (const auto& pod : podRefs) {
        std::cout << "[Pod: " << pod->getName() << "]\n";
        for (const auto& container : pod->getContainers()) {
            std::cout << container->getMetrics() << "\n";
        }
    }

    std::cout << "\n=== Tous les conteneurs du cluster 1 ===\n";
    forEachContainer(cluster, [](const Container& c) {
        std::cout << c.getMetrics() << std::endl;
    });

    return 0;
}