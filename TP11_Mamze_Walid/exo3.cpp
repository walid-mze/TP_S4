#include <iostream>
#include "Stack.hpp"
#include "StackFullException.hpp"
#include "StackEmptyException.hpp"

void func_c(Stack& s) {
    s.push(99); // Should cause StackFullException
}

void func_b(Stack& s) {
    func_c(s);
}

void func_a(Stack& s) {
    func_b(s);
}

int main() {
    try {
        Stack stack(2);
        stack.push(1);
        stack.push(2);
        std::cout << "Stack size: " << stack.size() << std::endl;
        func_a(stack);
    }
    catch (const StackFullException& ex) {
        std::cerr << "Caught in main: " << ex.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
    }

    try {
        Stack stack(2);
        std::cout << "Stack size: " << stack.size() << std::endl;
        stack.pop(); // Should throw
    }
    catch (const StackEmptyException& ex) {
        std::cerr << "Caught in main: " << ex.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
    }

    std::cout << "Program completed" << std::endl;
    return 0;
}
