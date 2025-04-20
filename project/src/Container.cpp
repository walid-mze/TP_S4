#include "Container.h"

Container::Container(std::string id, std::string image, double cpu, double memory)
    : Resource(std::move(id), cpu, memory), image_(std::move(image)) {}

void Container::start() {
    active_ = true;
}

void Container::stop() {
    active_ = false;
}

std::string Container::getMetrics() const {
    return "[Container: " + id_ + ": " + std::to_string(cpu_) + " CPU, " + 
           std::to_string(memory_) + " Memory, " + image_ + "]";
}

std::ostream& operator<<(std::ostream& os, const Container& c) {
    os << c.getMetrics();
    return os;
} 