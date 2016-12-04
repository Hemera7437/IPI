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
    ifstream infile("encrypted_text.txt"); // Datei öffnen
    string text; // leerer String für den eingelesenen Text
    string line; // leerer String für die aktuelle Zeile
    while(infile){
        getline(infile, line); // nächste Zeile einlesen ...
        text += line + "\n"; // ... und an den Text anhängen
    }
    
    
    for (char i = 97; i <= 122; ++i){   //den count aller Buchstaben auf 0 setzen 
        counts [i] = 0;                 // 97 - 'a' und 122 - 'z'
    }
    
    for(int iter = 0; iter < text.length(); ++iter) {
        char current = text[iter];
        if (isalpha(current)){
            current = tolower(text[iter]);  //damit 'A' und 'a' der gleiche Buchstabe ist    
            ++counts[current] ;
        }
    }
    
    for (char i = 97; i <= 122; ++i){   //Häufigkeit der Buchstaben ausgeben lassen
        cout << counts[i] << " ";
    }

    
}