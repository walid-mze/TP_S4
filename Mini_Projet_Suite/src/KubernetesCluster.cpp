#include "KubernetesCluster.h"
#include "CloudExceptions.h"
#include <algorithm>

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
    try {
        // Find a suitable server
        for (auto& server : nodes_) {
            if (server->isActive()) {
                double total_cpu = 0;
                double total_memory = 0;
                
                // Calculate total resources needed
                for (const auto& container : pod->getContainers()) {
                    total_cpu += container->getCpu();
                    total_memory += container->getMemory();
                }
                
                // Try to allocate resources
                try {
                    server->allocate(total_cpu, total_memory);
                    pod->setServer(server.get());
                    server->addPod(std::move(pod));
                    return;
                } catch (const AllocationException& e) {
                    // Continue to next server
                    continue;
                }
            }
        }
        throw AllocationException("Aucun serveur disponible pour déployer le pod");
    } catch (const AllocationException& e) {
        std::cerr << "Exception capturée : " << e.what() << std::endl;
        throw;
    }
}

bool KubernetesCluster::schedulePod(Pod& pod) {
    for (const auto& node : nodes_) {
        try {
            node->allocate(pod.getTotalCpu(), pod.getTotalMemory());
            return true;
        } catch (const AllocationException&) {
            continue;
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

std::vector<std::shared_ptr<Server>> KubernetesCluster::getFilteredServers(
    const std::function<bool(const Server&)>& filter) const {
    std::vector<std::shared_ptr<Server>> filtered;
    for (const auto& server : nodes_) {
        if (filter(*server)) {
            filtered.push_back(server);
        }
    }
    return filtered;
} 