#include <iostream>
#include <string>
using namespace std;
#

string encode_rle(const string& text){
    string result="";
    int count=1;
    for (auto i=1 ;i<text.size(); i++){
        if (text[i]==text[i-1]){
            count++;
        }
        else{
            result+=text[i-1]+to_string(count);
            count=1;
        }
    }
    result+=text[text.size()-1]+to_string(count);
    return result;
}

int main(){
    string text;
    cout<<"Texte : ";
    getline(cin, text);
    cout<<"Encodé : ";
    cout<<encode_rle(text)<<endl;
    return 0;
}