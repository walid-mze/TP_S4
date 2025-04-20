#include "Pod.h"

Pod::Pod(std::string name, std::unordered_map<std::string, std::string> labels)
    : name_(std::move(name)), labels_(std::move(labels)) {}

void Pod::addContainer(std::unique_ptr<Container> container) {
    containers_.push_back(std::move(container));
}

bool Pod::removeContainer(const std::string& id) {
    auto it = std::find_if(containers_.begin(), containers_.end(),
        [&id](const std::unique_ptr<Container>& c) { return c->getId() == id; });
    
    if (it != containers_.end()) {
        containers_.erase(it);
        return true;
    }
    return false;
}

void Pod::deploy() {
    for (const auto& container : containers_) {
        container->start();
    }
}

std::string Pod::getMetrics() const {
    std::string metrics = "[Pod: " + name_ + "]\n";
    for (const auto& container : containers_) {
        metrics += container->getMetrics() + "\n";
    }
    return metrics;
}

std::ostream& operator<<(std::ostream& os, const Pod& p) {
    os << p.getMetrics();
    return os;
}

const std::vector<std::unique_ptr<Container>>& Pod::getContainers() const {
    return containers_;
}

double Pod::getTotalCpu() const {
    double total = 0.0;
    for (const auto& container : containers_) {
        total += container->getCpu();
    }
    return total;
}

double Pod::getTotalMemory() const {
    double total = 0.0;
    for (const auto& container : containers_) {
        total += container->getMemory();
    }
    return total;
} 