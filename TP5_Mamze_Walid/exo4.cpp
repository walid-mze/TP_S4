#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>

void top_frequent_words(const std::string& text, int n) {
    std::map<std::string, int> freq;
    std::istringstream stream(text);
    std::string word;
    
    // Comptage des mots
    while (stream >> word) {
        freq[word]++;
    }
    
    // Conversion de la map en vector
    std::vector<std::pair<std::string, int>> sorted_words(freq.begin(), freq.end());
    
    // Tri des mots par fréquence décroissante
    std::sort(sorted_words.begin(), sorted_words.end(), 
              [](const auto& a, const auto& b) { return a.second > b.second; });
    
    // Affichage des N mots les plus fréquents
    std::cout << "Top " << n << " mots les plus fréquents :\n";
    for (int i = 0; i < n && i < sorted_words.size(); ++i) {
        std::cout << i + 1 << ". " << sorted_words[i].first << " -> " << sorted_words[i].second << "\n";
    }
}

int main() {
    std::string text = "C++ est rapide, C++ est puissant, C++ est utilisé";
    
    for (char& c : text) {
        if (ispunct(c)) c = ' ';
    }
    
    top_frequent_words(text, 3);
    return 0;
}
