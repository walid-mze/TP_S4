#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <vector>
using namespace std;



void sort_by_length(const string& text){
    map<int, vector<string>> words;
    istringstream s(text);  
    string word;
    while (s >> word){
        words[word.size()].push_back(word);
    }
    string result="";
    for (auto p: words){
        for (auto w: p.second){
            result+=w+" ";
        }
    }
    cout << result << endl;
}
int main(){
    string text;
    cout << "Phrase: ";
    getline(cin, text);
    cout << "trie par longueur: ";
    sort_by_length(text);
    return 0;
}