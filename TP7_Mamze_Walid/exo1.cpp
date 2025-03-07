#include <iostream>
#include <string>

using namespace std;


class Joueur{
private: 
    int score;
    string nom;
public:
    Joueur(string nom , int score){
    this->nom = nom;
    this->score = score;
}
    void afficher(){
        cout << "Joueur : " << nom << ", Score : " << score << endl;
    }
};
int main(){
    Joueur j1("Alice",100);
    Joueur j2("Bob",200);
    j1.afficher();  
    j2.afficher();
    return 0;
}