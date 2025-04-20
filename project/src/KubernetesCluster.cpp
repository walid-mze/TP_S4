#include "KubernetesCluster.h"

void KubernetesCluster::addNode(std::shared_ptr<Server> node) {
    nodes_.push_back(std::move(node));
}

bool KubernetesCluster::removePod(const std::string& name) {
    auto it = std::find_if(pods_.begin(), pods_.end(),
        [&name](const std::unique_ptr<Pod>& p) { return p->getName() == name; });
    
    if (it != pods_.end()) {
        pods_.erase(it);
        return true;
    }
    return false;
}

void KubernetesCluster::deployPod(std::unique_ptr<Pod> pod) {
    if (schedulePod(*pod)) {
        pod->deploy();
        pods_.push_back(std::move(pod));
    } else {
        std::cout << "Échec du déploiement du pod " << pod->getMetrics() 
                  << ": ressources insuffisantes." << std::endl;
    }
}

bool KubernetesCluster::schedulePod(Pod& pod) {
    for (const auto& node : nodes_) {
        if (node->allocate(pod.getTotalCpu(), pod.getTotalMemory())) {
            return true;
        }
    }
    return false;
}

Pod* KubernetesCluster::getPod(const std::string& name) {
    auto it = std::find_if(pods_.begin(), pods_.end(),
        [&name](const std::unique_ptr<Pod>& p) { return p->getName() == name; });
    
    return (it != pods_.end()) ? it->get() : nullptr;
}

std::string KubernetesCluster::getMetrics() const {
    std::string metrics = "=== Cluster Metrics ===\n";
    for (const auto& node : nodes_) {
        metrics += node->getMetrics() + "\n";
    }
    for (const auto& pod : pods_) {
        metrics += pod->getMetrics();
    }
    return metrics;
}

std::ostream& operator<<(std::ostream& os, const KubernetesCluster& c) {
    os << c.getMetrics();
    return os;
} 