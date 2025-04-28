#pragma once
#include <exception>

class StackFullException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Stack is full!";
    }
};
