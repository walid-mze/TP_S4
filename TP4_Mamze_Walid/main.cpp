#include <iostream>
using namespace std;
#include <array>
#include <vector>
#include <list>
#include <set>
#include <unordered_map>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>

#ifndef EXO
#define EXO 11
#endif

#if EXO == 1
int main() {
    int array[5] = {10, 20, 30, 40, 50};
    int sum=0;
    cout<<"Elements : ";
    for(int i=0; i<5; i++) {
       cout<<array[i]<<" ";
         sum+=array[i];
    }
    cout<<"\nSomme : "<<sum<<endl;
}

#elif EXO == 2
    int main() {
        int mat[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        int sum=0;
        cout<<"Matrice : "<<endl;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
            sum+=mat[i][i];
        }
        cout<<"Somme diagonale : "<<sum<<endl;
        return 0;
    }

#elif EXO == 3
    int main() {
        std::array<int, 5> tab = {1, 2, 3, 4, 5};
        cout << "Original : ";
        for (int i = 0; i < tab.size(); i++) {
            cout << tab[i] << " ";
        }
        cout << endl;

        cout << "Inversé : ";
        for (int i = tab.size() - 1; i >= 0; i--) {
            cout << tab[i] << " ";
        }
        cout << endl;

        return 0;
    }

    
#elif EXO == 4
int main() {
    vector<int> numbers;
    int num;
    cout << "Entrez des nombres (entrez -1 pour terminer) : ";
    while (cin >> num && num != -1) {
        numbers.push_back(num);
    }

    cout << "Doublé : ";
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] * 2 << " ";
    }
    cout << endl;

    return 0;
}

#elif EXO == 5
int main() {
        std::list<int> numbers = {10, 20, 30, 40, 50};
    
        // Insertion au début et à la fin
        numbers.push_front(0);
        numbers.push_back(60);
    
        // Affichage de la liste finale
        cout << "Après insertion : ";
        for (int num : numbers) {
            cout << num << " ";
        }
        cout << endl;
        return 0;
}

#elif EXO == 6
int main(){
    set<int> numbers = {5,10,15,20};
    numbers.insert(10);
    for (int num : numbers) {
        cout << num << " ";
    }

}
#elif EXO == 7
int main(){
    map<string, int> notes={{"John", 85}, {"Bob", 78}, {"Alice", 90}};

    for (auto pair : notes) {
        cout << pair.first << " : " << pair.second << endl;
    }
    
}
#elif EXO == 8
int main() {
    string phrase = "pomme banane pomme orange banane banane";
    unordered_map<string, int> counter;
    stringstream ss(phrase);
    string word;

    while (ss >> word) {
        counter[word]++;
    }

    for (auto pair : counter) {
        cout << pair.first << " : " << pair.second << endl;
    }

    return 0;
}


#elif EXO == 9
    int main() {
        vector<int> numbers = {30, 10, 50, 20, 40};
    
        cout << "Original : ";
        for (int num : numbers) {
            cout << num << " ";
        }
        cout << endl;
    
        sort(numbers.begin(), numbers.end());
    
        cout << "Trié : ";
        for (int num : numbers) {
            cout << num << " ";
        }
        cout << endl;
    
        return 0;
    }

#elif EXO == 10
int main() {
    set<int> numbers = {100, 4, 200, 1, 3, 2};
    set<int> result;
    int maxi = 0;

    for (int num : numbers) {
        // Si le nombre précédent n'est pas dans le set, c'est le début d'une nouvelle séquence
        if (numbers.find(num - 1) == numbers.end()) {
            int cur = num;
            int taille = 1;
            set<int> seq;
            seq.insert(cur);

            // Compter la longueur de la séquence actuelle
            while (numbers.find(cur + 1) != numbers.end()) {
                cur += 1;
                taille += 1;
                seq.insert(cur);
            }

            // Mettre à jour la plus longue séquence trouvée
            if (taille > maxi) {
                result = seq;
                maxi = taille;
            }
        }
    }

    cout << "Plus longue séquence : " << maxi<<" " ;
    cout<<"(";
    for (int num : result) {
        cout << num << ", ";
    }
    cout<<")"<<endl;


    return 0;
}

#elif EXO==11


void put(unordered_map<int, list<pair<int, int>>::iterator>& cache,
         list<pair<int, int>>& lru, int& capacity, int key, int value) {
    if (cache.find(key) != cache.end()) {
        // If the key exists, update the value and move it to the front of the list
        cache[key]->second = value;
        lru.splice(lru.begin(), lru, cache[key]);
    } else {
        if (lru.size() == capacity) {
            auto last = lru.back();
            cache.erase(last.first);
            lru.pop_back();
        }
        // Add the new key-value pair to the front of the list
        lru.push_front({key, value});
        cache[key] = lru.begin();
    }
}

int get(unordered_map<int, list<pair<int, int>>::iterator>& cache,
        list<pair<int, int>>& lru, int key) {
    if (cache.find(key) == cache.end()) {
        return -1; 
    }
    // Move the element to the front of the list to mark it as recently used
    lru.splice(lru.begin(), lru, cache[key]);
    return cache[key]->second;
}

void display(const list<pair<int, int>>& lru) {
    for (const auto& pair : lru) {
        cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    cout << endl;
}

int main() {
    int capacity = 2;
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    list<pair<int, int>> lru;

    // Test the LRU
    cout << "ajout de  (1, 10) et (2, 20)" << endl;
    put(cache, lru, capacity, 1, 10);
    put(cache, lru, capacity, 2, 20);
    cout<<"Etat du cache: ";

    display(lru); 

    cout << "acceder a la clé  1: " << get(cache, lru, 1) << endl;
    cout<<"Etat du cache: ";
    display(lru); 

    cout << "ajout de  (3, 30), supression de  (2, 20)" << endl;
    put(cache, lru, capacity, 3, 30);
    cout<<"Etat du cache: ";
    display(lru);  

    return 0;
}

#endif