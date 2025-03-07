#include <iostream>
#include <string>

using namespace std;

class Joueur {
private:
    int score;
    string nom;
public:
    int age=20;
    Joueur(string nom, int score) {
        this->nom = nom;
        this->score = score;
    }
    ~Joueur() {
        cout << "Objet dynamique supprimé." << endl;
    }
    void afficher() {
        cout << "Nom: " << nom << endl;
        cout << "Score: " << score << endl;
    }
};

int main() {
    // Utilisation des modificateurs d'accès
    //Joueur j1("Bob", 200);
    //cout << "Nom: " << j1.nom ; erreur car nom est privé
    //cout << "Age: " << j1.age << endl;va afficher 20 car age est public


    // Allocation dynamique d'un objet Joueur
    Joueur* joueurPtr = new Joueur("Alice", 100);

    joueurPtr->afficher();

    // Libération de l'objet dynamique
    delete joueurPtr;

    return 0;
}