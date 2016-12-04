#include <iostream> 
#include <fstream>
#include <map>
#include <vector>

using namespace std;

map <char, int> counts; 
//char c =  122;        //65 = A , 97 = a

map <char, int> sorted;

/*vector<char> letters{
    
}*/

map <char, char> decrypt;

int main(){
    ifstream infile("encrypted_text.txt"); // Datei öffnen
    string text; // leerer String für den eingelesenen Text
    string line; // leerer String für die aktuelle Zeile
    while(infile){
        getline(infile, line); // nächste Zeile einlesen ...
        text += line + "\n"; // ... und an den Text anhängen
    }
    
    //cout << c;
}