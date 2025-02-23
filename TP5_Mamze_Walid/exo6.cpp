#include <iostream>
#include <string>
#include <sstream>
#include <regex>
using namespace std;

bool contains_email(const string& text){
    istringstream s(text);
    string word;
    while(s>>word){
        regex pattern("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}");
        if (regex_match(word, pattern)){
            cout <<"Adresse email détectée : " << word << endl;
            return true;
        }
    }
    return false;
    cout << "Aucune adresse email détectée" << endl;
}

int main(){
    string text;
    cout << "Phrase : ";
    getline(cin, text);
    contains_email(text);
    return 0;
}

