#include <iostream>
#include <fstream>
#include <iomanip>

int main() {
    std::ofstream out_file("output.txt");
    if (!out_file) {
        std::cerr << "Erreur lors de l'ouverture du fichier" << std::endl;
        return 1;
    }

    double num;
    std::cout << "Entrez des nombres flottants (entrée vide pour arrêter) : ";
    while (std::cin >> num) {
        out_file << std::fixed << std::setprecision(2)
                 << std::setw(10) << std::left << num << std::endl;
    }

    out_file.close();
    std::cout << "Nombres enregistrés dans output.txt" << std::endl;
    return 0;
}
