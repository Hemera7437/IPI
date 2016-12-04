#include <iostream> 
#include <fstream>
#include <map>
#include <vector>

using namespace std;

map <char, int> counts;  //3b
map <int, char> sorted;  //3c

int main (){    
    //Aufgabe 3a
    ifstream infile("encrypted_text.txt"); // Datei öffnen
    string text; // leerer String für den eingelesenen Text
    string line; // leerer String für die aktuelle Zeile
    while(infile){
        getline(infile, line); // nächste Zeile einlesen ...
        text += line + "\n"; // ... und an den Text anhängen
    }
    
    //Aufgabe 3b
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
    
    /*for (char i = 97; i <= 122; ++i){   //Häufigkeit der Buchstaben ausgeben lassen
        cout << counts[i] << " ";
    }*/
    
    //Aufgabe 3c
    for (char i = 97; i <= 122; ++i){   //schlüssel und wert von counts vertauschen
        auto current = ( sorted[ counts[i] ] = i );
        cout << current << " " << counts [i];
    }
    
}