#ifndef SERVER_H
#define SERVER_H

#include "Resource.h"
#include "CloudExceptions.h"
#include "Pod.h"
#include <iostream>
#include <vector>

class Server : public Resource {
private:
    double available_cpu_;
    double available_memory_;
    std::vector<std::unique_ptr<Pod>> pods_;

public:
    Server(std::string id, double cpu, double memory);
    
    void allocate(double cpu, double memory);  // Changed to void and will throw exceptions
    void start() override;
    void stop() override;
    std::string getMetrics() const override;
    void addPod(std::unique_ptr<Pod> pod);
    const std::vector<std::unique_ptr<Pod>>& getPods() const { return pods_; }
    
    friend std::ostream& operator<<(std::ostream& os, const Server& s);
    
    // Getters
    double getAvailableCpu() const { return available_cpu_; }
    double getAvailableMemory() const { return available_memory_; }
};

#endif // SERVER_H 