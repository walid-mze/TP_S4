#include "Cloud_Util.h"
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