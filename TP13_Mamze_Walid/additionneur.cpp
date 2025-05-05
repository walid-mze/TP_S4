#include "additionneur.hpp"
#include <iostream>

Additionneur::Additionneur(int v) : valeur(v) {}

void Additionneur::operator()(int x) const {
    std::cout << (x + valeur) << " ";
}
