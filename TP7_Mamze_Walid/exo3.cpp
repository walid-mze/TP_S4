#include <iostream>
#include <string>

using namespace std;


class Joueur{
private: 
    int score;
    string nom;
public:
    Joueur(string nom , int score){
    cout << "Constructeur appelé" << endl;
    this->nom = nom;
    this->score = score;
    
}
    ~Joueur(){
        cout << "Destructeur appelé" << endl;
    }
    void afficher(){
        cout << "Joueur : " << nom << ", Score : " << score << endl;
    }
};
int main(){
    Joueur j1("Alice",100);
    j1.afficher();  
    return 0;
}