#ifndef KUBERNETESCLUSTER_H
#define KUBERNETESCLUSTER_H

#include "Server.h"
#include "Pod.h"
#include <memory>
#include <vector>
#include <string>
#include <iostream>

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
    
    friend std::ostream& operator<<(std::ostream& os, const KubernetesCluster& c);
};

#endif // KUBERNETESCLUSTER_H 