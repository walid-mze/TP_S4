#pragma once
#include <vector>
#include "StackFullException.hpp"
#include "StackEmptyException.hpp"

class Stack {
private:
    std::vector<int> elements;
    size_t capacity;
public:
    Stack(size_t cap) : capacity(cap) {}

    void push(int value) {
        if (elements.size() >= capacity)
            throw StackFullException();
        elements.push_back(value);
    }

    void pop() {
        if (elements.empty())
            throw StackEmptyException();
        elements.pop_back();
    }

    size_t size() const { return elements.size(); }
};
