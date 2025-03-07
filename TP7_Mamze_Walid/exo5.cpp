#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Etudiant{
private: 
    string nom;
    vector<int> notes;
public:
    Etudiant(string nom){
    this->nom = nom;
}
    void ajouter_note(int note){
        notes.push_back(note);
    }
    void afficher(){
        cout << "Etudiant : " << nom << endl;
        cout << "Notes : ";
        for (int note : notes) {
            cout << note << ", ";
        }
        cout << endl;
    }
    double  avg(){
        int sum = 0;
        for (int note : notes) {
            sum += note;
        }
        return sum / notes.size();
    }
    void display_avg(){
        cout << "Moyenne : " << avg() << endl;
    }



};
int main(){
    Etudiant e1("Karim");
    e1.ajouter_note(15);
    e1.ajouter_note(18);
    e1.ajouter_note(12);
    e1.afficher();
    e1.display_avg();
    return 0;
}