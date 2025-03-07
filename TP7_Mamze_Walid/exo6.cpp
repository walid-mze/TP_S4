#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Fichier {
private:
    string nom;
    fstream* flux;

public:
    Fichier(string nom) : nom(nom), flux(nullptr) {}

    ~Fichier() {
        if (flux) {
            flux->close();
            delete flux;
            flux=nullptr;
            cout << "Mémoire du flux libérée." << endl;
        }
    }

    void ecrire(const string& texte) {
        flux = new fstream(nom, ios::out);
        if (flux->is_open()) {
            *flux << texte;
            flux->close();
            cout << "Sauvegarde des données..." << endl;
        } else {
            cout << "Erreur lors de l'ouverture du fichier pour écriture." << endl;
        }
    }

    void lire() {
        flux = new fstream(nom, ios::in);
        if (flux->is_open()) {
            cout << "Lecture des données..." << endl;
            string ligne;
            while (getline(*flux, ligne)) {
                cout << "Contenu du fichier :" << endl;
                cout << ligne << endl;
            }
            flux->close();

        } else {
            cout << "Erreur lors de l'ouverture du fichier pour lecture." << endl;
        }
    }
};


int main() {
    Fichier fichier("test.txt");
    fichier.ecrire("Bonjour, ceci est un test.");
    fichier.lire();
    return 0;
}