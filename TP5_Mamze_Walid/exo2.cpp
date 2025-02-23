#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <unordered_map>
using namespace std;
void word_freq(const string& text){
    stringstream s(text); 
    unordered_map<string, int> freq;
  
    // To store individual words
    string word; 
    
    while (s >> word){
       freq[word]++;
    }
    for (auto p: freq){
        cout << p.first << " --> " << p.second << endl;
    }
}

int main(){
        // Used for breaking words
        string input;
        cout << "Entrer une phrase: ";
        getline(cin, input); // Read input from the user
        word_freq(input);
        
}