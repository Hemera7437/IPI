#include <iostream> 
#include <fstream>
#include <map>
#include <vector>

using namespace std;

map <char, int> counts;

string to_lower(string s){
	int length = s.size();
	string result = "";
	char c;
	for(int i = 0; i < length; ++i){
		c = tolower(s[i]);
		result += c;
	}
	return result;
}


int main (){
    ifstream infile("text.txt"); // Datei öffnen
    string text; // leerer String für den eingelesenen Text
    string line; // leerer String für die aktuelle Zeile
    while(infile){
        getline(infile, line); // nächste Zeile einlesen ...
        text += line + "\n"; // ... und an den Text anhängen
    }
    
    string textLow = to_lower(text);    //damit 'A' und 'a' der gleiche Buchstabe ist
    
    for (char i = 97; i <= 122; ++i){   //den count aller Buchstaben auf 0 setzen 
        counts [i] = 0;                 // 97 - 'a' und 122 - 'z'
    }
    
    for(auto iter = text.begin(); iter != text.end(); ++iter) {
        /*char current = text[iter];
        cout << current << endl;
        counts[current]++;
        ++ ( counts [ text[iter] ] );
        cout << counts[iter]; */
    }
    
    char test = 'a';
    cout << ++counts[test] << test;
    
    //cout << counts[ text[1] ];
    
    //for (char i = 97; i <= 122; ++i){  cout << "counts " << counts[i]; }

    
}