#include "Server.h"
#include <sstream>
#include <iomanip>

Server::Server(std::string id, double cpu, double memory)
    : Resource(std::move(id), cpu, memory), available_cpu_(cpu), available_memory_(memory) {}

void Server::allocate(double cpu, double memory) {
    if (!active_) {
        throw AllocationException("Serveur " + id_ + " est inactif");
    }
    if (cpu > available_cpu_ || memory > available_memory_) {
        throw AllocationException("Ressources insuffisantes sur le serveur " + id_);
    }
    available_cpu_ -= cpu;
    available_memory_ -= memory;
}

void Server::start() {
    active_ = true;
}

void Server::stop() {
    active_ = false;
}

void Server::addPod(std::unique_ptr<Pod> pod) {
    pods_.push_back(std::move(pod));
}

std::string Server::getMetrics() const {
    std::ostringstream oss;
    oss << "[Server: " << std::left << std::setw(6) << id_
        << " | Total: " << std::setw(2) << cpu_ << " CPU, "
        << std::setw(5) << memory_ << " MB | Free: "
        << std::setw(2) << available_cpu_ << " CPU, "
        << std::setw(5) << available_memory_ << " MB]";
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Server& s) {
    os << s.getMetrics();
    return os;
} 