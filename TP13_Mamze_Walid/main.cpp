#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include "additionneur.hpp"
#include "livre.hpp"

void exercice1() {
    std::vector<int> vec{1, 2, 3, 4, 5};
    Additionneur add(10);
    std::for_each(vec.begin(), vec.end(), add);
    std::cout << "\n";
}

void filtrer(const std::vector<int>& v, std::function<bool(int)> predicat) {
    for (int x : v) {
        if (predicat(x)) {
            std::cout << x << " ";
        }
    }
    std::cout << "\n";
}

void exercice2() {
    std::vector<int> v{10, 15, 20, 25, 30, 50, 75};
    filtrer(v, [=](int x) { return x > 20; });
    filtrer(v, [=](int x) { return x % 2 == 0; });
}

void exercice3() {
    std::vector<int> v{10, 12, 15, 17};
    std::transform(v.begin(), v.end(), v.begin(), [](int x) {
        return x + 5;
    });
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";
}

void exercice4() {
    std::vector<Livre> livres = {
        {"C++ Moderne", 350},
        {"Apprendre Python", 500},
        {"Algorithmique", 450}
    };

    std::sort(livres.begin(), livres.end(), [](const Livre& a, const Livre& b) {
        return a.titre < b.titre;
    });

    std::cout << "Tri par titre:\n";
    for (const auto& l : livres) std::cout << l << "\n";

    std::sort(livres.begin(), livres.end(), [](const Livre& a, const Livre& b) {
        return a.pages > b.pages;
    });

    std::cout << "\nTri par nombre de pages décroissant:\n";
    for (const auto& l : livres) std::cout << l << "\n";
}

int main() {
    std::cout << "Exercice 1:\n";
    exercice1();
    std::cout << "\nExercice 2:\n";
    exercice2();
    std::cout << "\nExercice 3:\n";
    exercice3();
    std::cout << "\nExercice 4:\n";
    exercice4();
    return 0;
}
