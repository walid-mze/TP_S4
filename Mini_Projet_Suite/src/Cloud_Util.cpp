#include "Cloud_Util.h"
#include "CloudExceptions.h"
#include <fstream>
#include <iostream>

void display(const KubernetesCluster& cluster) {
    std::cout << cluster;
}

void deployPods(KubernetesCluster& cluster, std::vector<std::unique_ptr<Pod>>& pods) {
    for (auto& pod : pods) {
        std::cout << "-> Déploiement du Pod " << *pod << std::endl;
        cluster.deployPod(std::move(pod));
    }
}

void saveClusterMetrics(const KubernetesCluster& cluster, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw FileException("Impossible d'ouvrir le fichier " + filename);
    }
    file << cluster.getMetrics();
    file.close();
}

void forEachContainer(const KubernetesCluster& cluster, const std::function<void(const Container&)>& func) {
    for (const auto& server : cluster.getServers()) {
        for (const auto& pod : server->getPods()) {
            for (const auto& container : pod->getContainers()) {
                func(*container);
            }
        }
    }
} 