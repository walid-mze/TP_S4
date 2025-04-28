#include <iostream>
#include <vector>
#include <memory>
#include <string>

// Classe de base
class PaireBase {
public:
    virtual ~PaireBase() = default;
    virtual void afficher() const = 0; // méthode virtuelle pure
};

// Classe template générale
template<typename T, typename U>
class Paire : public PaireBase {
private:
    T premier;
    U second;
public:
    Paire(T p, U s) : premier(p), second(s) {}

    void afficher() const override {
        if constexpr (std::is_same_v<T, bool>)
            std::cout << (premier ? "vrai" : "faux");
        else
            std::cout << premier;

        std::cout << " , ";

        if constexpr (std::is_same_v<U, bool>)
            std::cout << (second ? "vrai" : "faux");
        else
            std::cout << second;

        std::cout << std::endl;
    }
};

// Spécialisation partielle pour Paire<T, int>
template<typename T>
class Paire<T, int> : public PaireBase {
private:
    T premier;
    int second;
public:
    Paire(T p, int s) : premier(p), second(s) {}

    void afficher() const override {
        std::cout << "Le second paramètre est un entier: ";

        if constexpr (std::is_same_v<T, bool>)
            std::cout << (premier ? "vrai" : "faux");
        else
            std::cout << premier;

        std::cout << " , " << second << std::endl;
    }
};

int main() { 
    std::vector<std::unique_ptr<PaireBase>> paires;
    paires.push_back(std::make_unique<Paire<double, int>>(3.14, 42));
    paires.push_back(std::make_unique<Paire<int, bool>>(10, true)); 
    paires.push_back(std::make_unique<Paire<std::string, double>>("Test", 2.71));
    for (const auto& p : paires) {
        p->afficher();
    }
    return 0;
    }
