#include "Container.h"
#include <sstream>
#include <iomanip>

Container::Container(std::string id, std::string image, double cpu, double memory)
    : Resource(std::move(id), cpu, memory), image_(std::move(image)) {}

void Container::start() {
    active_ = true;
}

void Container::stop() {
    active_ = false;
}

std::string Container::getMetrics() const {
    std::ostringstream oss;
    oss << "[Container: " << std::left << std::setw(3) << id_
        << " : " << std::setw(2) << cpu_ << " CPU, "
        << std::setw(4) << memory_ << " Memory, "
        << std::setw(10) << image_ << "]";
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Container& c) {
    os << c.getMetrics();
    return os;
} 