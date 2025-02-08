#include <iostream>
using namespace std;

#ifndef EXO
    #define EXO 4 // Définir EXO à 4 si non défini
#endif

#if EXO == 1
    #include <iostream>
    #define PI 3.14159 // Définir la constante PI

    int main(){
        // Vérifier si la macro DEBUG est définie
        #ifdef DEBUG 
            cout<<"the macro DEBUG is defined"<<endl;
        #else
            #define DEBUG // Définir la macro DEBUG si elle n'est pas définie
            cout<<"the macro DEBUG is not defined"<<endl;
        #endif
    }

#elif EXO == 2
    int main(int argc, char* argv[]) {
        // Afficher les arguments passés en ligne de commande
        for (int i = 1; i < argc; ++i) {
            cout<<"Argument "<<i<< ": "<< argv[i]<<endl;
        }
        return 0;
    }

#elif EXO == 3
    namespace mon_espace {
        int var=5; // Définir une variable dans l'espace de noms mon_espace
    }

    int main(){
        // Afficher la valeur de var sans utiliser l'espace de noms std
        std::cout<<"la valeur de var sans using namespace std: "<<mon_espace::var<<std::endl;
        using namespace std;
        // Afficher la valeur de var en utilisant l'espace de noms std
        cout<<"la valeur de var avec using namespace std: " << mon_espace::var<<endl;
        return 0;
    }

#elif EXO == 4
    int main(){
        int n;
        float x;
        // Demander à l'utilisateur d'entrer un nombre entier
        cout<<"Entrez un nombre entier: ";
        cin>>n;
        // Demander à l'utilisateur d'entrer un nombre décimal
        cout<<"Entrez un nombre décimal: ";
        cin >>x;
        // Afficher les valeurs saisies
        cout <<"valeurs saisies: "<<n<<" et " <<x<<endl;
    }

#else
    // Cas par défaut
#endif