#include <iostream>
#include <string>
#include <vector>
using namespace std;


template <typename T>
class Conteneur{
    private:
        vector<T> elements;
        int capacite;
    public:
        Conteneur(int cap) : capacite(cap) {
            elements.reserve(capacite);
        }
        void ajouter(const T& element) {
            if (elements.size()<=capacite){
                elements.push_back(element);
            }
        }

        T obtenir(int index){
                return elements.at(index);
            
        }
};


int main() {
    Conteneur<int> c1(3); // Capacité de 3 c1.ajouter(10);
    c1.ajouter(10);
    c1.ajouter(20);
    c1.ajouter(30);
    c1.ajouter(40); // Capacité dépassée
    cout << c1.obtenir(0) << "␣" << c1.obtenir(1) << std::endl; // Affiche 10 20
    Conteneur<std::string> c2(2);
    c2.ajouter("Bonjour");
    c2.ajouter("Monde");
    cout << c2.obtenir(0) << "␣" << c2.obtenir(1) << std::endl; // Affiche Bonjour Monde
    return 0;
}