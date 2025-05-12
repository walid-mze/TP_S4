#ifndef CLOUD_UTIL_H
#define CLOUD_UTIL_H

#include "KubernetesCluster.h"
#include "Container.h"
#include <functional>
#include <vector>
#include <memory>

void display(const KubernetesCluster& cluster);
void deployPods(KubernetesCluster& cluster, std::vector<std::unique_ptr<Pod>>& pods);
void saveClusterMetrics(const KubernetesCluster& cluster, const std::string& filename);
void forEachContainer(const KubernetesCluster& cluster, const std::function<void(const Container&)>& func);

#endif // CLOUD_UTIL_H 