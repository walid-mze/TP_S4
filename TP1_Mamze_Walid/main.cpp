#include <iostream>
using namespace std;

#ifndef EXO
    #define EXO 5 // Définir EXO à 5 si non défini
#endif

#if EXO == 1
int main(){
    // Afficher des messages de bienvenue
    cout <<"Hello World!"<< endl;
    cout <<"Bienvenue en C++!"<<endl;
}

#elif EXO == 2
int main(){
    int number;
    // Demander à l'utilisateur d'entrer un nombre
    cout << "Veuillez entrer un nombre: ";
    cin >>number;
    // Afficher le nombre entré par l'utilisateur
    cout << "Vous avez entré: "<<number<< endl;
}

#elif EXO == 3
int main(){
    int a, b;
    // Demander à l'utilisateur d'entrer deux nombres
    cout << "Entrez deux nombres:";
    cin >> a >> b;
    // Afficher les résultats des opérations arithmétiques
    cout << "Somme: "<<a+b<< endl;
    cout << "Difference: "<< a-b << endl;
    cout << "Produit: "<< a*b << endl;
    cout << "Quotient: "<< a/b << endl;
}

#elif EXO == 4
int main() {
    // Demander à l'utilisateur d'entrer un nombre
    std::cout << "Entrez un nombre:";
    int nombre;
    std::cin >> nombre;
    // Afficher le nombre entré par l'utilisateur
    std::cout << "Vous avez entré: "<<nombre<<std::endl;
    return 0;
}

#elif EXO == 5
int main(){
    int temp;
    // Demander à l'utilisateur d'entrer une température en Celsius
    cout <<"Entrez une température en Celsius:";
    cin >> temp;
    // Convertir la température en Fahrenheit et afficher le résultat
    cout <<"Température en Fahrenheit: " << temp * 9/5+32 << endl;
}

#else
int main(){
    // Cas par défaut
    cout <<"Cas par défaut"<<endl;
}
#endif