#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Objet{
private:
string nom;
int quantite;
public:

    Objet(string nom, int quantite){
        this->nom = nom;
        this->quantite = quantite;
    }
    string get_nom(){
        return nom;
    }
    int get_quantite(){
        return quantite;
    }

};

class Inventaire{
    private:
        vector<Objet*> objets;

    public:
        void ajouter_objet(string nom, int quantite){
            Objet* obj= new Objet(nom,quantite);
            objets.push_back(obj);
            cout << "Ajout de  " << nom << " (x" << quantite<<")" << endl;

        }
        ~Inventaire(){
            for (Objet* obj : objets) {
                delete obj;
            }
            cout <<"Mémoire de l'inventaire libérée."<<endl;
        }
        void afficher(){
            for (Objet* obj : objets) {
                cout << "- "<< obj->get_nom() << " (x" << obj->get_quantite() << ")" << endl;
            }
        }
};


int main(){
    Inventaire inv;
    inv.ajouter_objet("Pomme", 3);
    inv.ajouter_objet("Épée", 1);
    inv.afficher();
    return 0;
}