#pragma once
#include <exception>

class InsufficientStockException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Insufficient stock to remove!";
    }
};
