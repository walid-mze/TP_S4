#pragma once
#include <exception>

class NegativeQuantityException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Cannot add negative quantity!";
    }
};
