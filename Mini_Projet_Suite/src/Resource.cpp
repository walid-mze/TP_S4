#include "Resource.h"

Resource::Resource(std::string id, double cpu, double memory)
    : id_(std::move(id)), cpu_(cpu), memory_(memory), active_(false) {} 