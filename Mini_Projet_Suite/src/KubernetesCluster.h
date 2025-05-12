#ifndef KUBERNETES_CLUSTER_H
#define KUBERNETES_CLUSTER_H

#include "Server.h"
#include "Pod.h"
#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <functional>

class KubernetesCluster {
private:
    std::vector<std::shared_ptr<Server>> nodes_;
    std::vector<std::unique_ptr<Pod>> pods_;

public:
    void addNode(std::shared_ptr<Server> node);
    bool removePod(const std::string& name);
    void deployPod(std::unique_ptr<Pod> pod);
    bool schedulePod(Pod& pod);
    Pod* getPod(const std::string& name);
    std::string getMetrics() const;
    const std::vector<std::shared_ptr<Server>>& getServers() const { return nodes_; }
    
    // New method for filtering servers
    std::vector<std::shared_ptr<Server>> getFilteredServers(
        const std::function<bool(const Server&)>& filter) const;
    
    friend std::ostream& operator<<(std::ostream& os, const KubernetesCluster& c);
};

#endif // KUBERNETES_CLUSTER_H 