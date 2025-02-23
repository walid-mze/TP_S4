#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool is_palindrome(const string& text) {
    string filter = "";
    for (auto &c : text) {
        if (isalpha(c)) {
            filter += tolower(c);
        }
    }
    string temp = filter;
    reverse(temp.begin(), temp.end());
    return filter == temp;
}

int main() {
    string input;
    cout << "Entrez une phrase : ";
    getline(cin, input);
    
    if (is_palindrome(input)) {
        cout << "\"" << input << "\" est un palindrome." << endl;
    } else {
        cout << "\"" << input << "\" n'est pas un palindrome." << endl;
    }
    
    return 0;
}