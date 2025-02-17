#include <iostream>
using namespace std;

#ifndef EXO
#define EXO 6
#endif

#if EXO == 1
int main() {
    int tab[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "la taille totale du tableau: " << sizeof(tab) << endl;
    cout << "la taille d'un element du tableau: " << sizeof(tab[0]) << endl;
    cout << "le nombre d'elements du tableau: " << sizeof(tab) / sizeof(tab[0]) << endl;
    return 0;
}
#elif EXO == 2
int main() {
    int small_room, large_room;
    const int small_cost = 250;
    const int large_cost = 350;
    const double tax = 0.06;
    const int duration = 30;

    cout << "Number of small rooms: ";
    cin >> small_room;
    cout << "Number of large rooms: ";
    cin >> large_room;

    const int cost = small_room * small_cost + large_room * large_cost;
    const double tax_amount = cost * tax;
    const double total_estimate = cost + tax_amount;

    cout << "Estimate for carpet cleaning service" << endl;
    cout << "Number of small rooms: " << small_room << endl;
    cout << "Number of large rooms: " << large_room << endl;
    cout << "Price per small room: " << small_cost << "dh" << endl;
    cout << "Price per large room: " << large_cost << "dh" << endl;
    cout << "Cost: " << cost << "dh" << endl;
    cout << "Tax: " << tax_amount << "dh" << endl;
    cout << "===============================" << endl;
    cout << "Total estimate: " << total_estimate << "dh" << endl;
    cout << "This estimate is valid for " << duration << " days" << endl;

    return 0;
}
#elif EXO == 3
// Fonction constexpr récursive pour calculer la factorielle
constexpr int factorial(int n) {
    return (n <= 1) ? 1 : (n * factorial(n - 1));
}

// Utilisation de la fonction pour définir une constante compile-time
constexpr int fact_5 = factorial(5);

// Vérification de la factorielle calculée avec static_assert
static_assert(fact_5 == 120, "La factorielle de 5 devrait être 120");

int main() {
    // Affichage de la factorielle calculée
    cout << "La factorielle de 5 est: " << fact_5 << endl;
    return 0;
}
#elif EXO == 4
int  value=100;
int main() {
    int value=50;
    cout<<"Valeur locale: "<<value<<endl;
    cout<<"Valeur globale: "<<::value<<endl;
    return 0;
}
#elif EXO == 5


// Définir une macro pour la valeur de pi
#define PI 3.14159

// Déclarer une constante pour le nombre de mois dans une année
const int MONTHS_IN_YEAR = 12;

// Déclarer une constante compile-time pour le rayon d'un cercle
constexpr double RADIUS = 7.0;

int main() {
    // Calculer l'aire du cercle
    double area = PI * RADIUS * RADIUS;

    // Afficher les résultats
    std::cout << "Nombre de mois dans une année : " << MONTHS_IN_YEAR << std::endl;
    std::cout << "Rayon du cercle : " << RADIUS << std::endl;
    std::cout << "Aire du cercle : " << area << std::endl;

    return 0;
}
#elif EXO == 6
#include <limits>

bool safe_multiply(int a, int b, int &result) {
    long long temp = (long long)a*b; // Calculer en long long
    if (temp > numeric_limits<int>::max() || temp < numeric_limits<int>::min()) {
        return false; // Débordement détecté
    }
    result = (int)(temp);
    return true;
}

int main() {
    int a = 300000;
    int b = 10000;
    int result;
    
    if (safe_multiply(a, b, result)) {
        std::cout << "Le résultat de la multiplication est: " << result << std::endl;
    } else {
        std::cout << "Erreur: Débordement détecté lors de la multiplication!" << std::endl;
    }

    return 0;
}


#endif  

