#pragma once
#include <exception>

class DivideByZeroException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Division by zero!";
    }
};
