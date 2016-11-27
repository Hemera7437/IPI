#include <iostream>     //diesmal konnte ich auch nicht widerstehen sarkastische Kommentare abzugeben
#include <vector>
#include <algorithm>
#include <string>
#include "text.hpp"

using namespace std;

//Aufgabe 3a
vector <string> split_words(string s){ 
    vector<string> space;
    
    int length = s.size();
    //int pos = s.find(' ');
    int i;     
    
	string pickName;
    for(i = 0; i < length; ++i){
		if(s[i] == ' '){
			space.push_back(pickName);		// sollte ein Leerzeichen vorkommen, wird das wort in den vector eingefügt
			pickName = "";					// danach wird der string wieder resettet um keine doppelten zeichen zu übertragen
		}else{
			pickName += s[i];				// sollte der character kein Leerzeichen sein wird er dem hilfs string angefügt
		}
	}
	space.push_back(pickName);				// hier wird das letzte wort auch noch hinzu gefügt, weil normalerweise der letzte character kein Leerzeichen ist
    return space;
}

//Aufgabe 3b
string mix(string s)
{
    //Anfangsbuchstaben finden
    double length = s.size();
    int startpoint;
   
    for (int i = 0; i <= length; ++i)
    {
        if ( isalnum(s[i]) )
        {
            startpoint = i;
            break;
        }
        else
        {
            continue;
        }
    }
    string start = s.substr(0, startpoint + 1);  //Anfangszeichen in string speichern
 
    //Endbuchstaben finden
    int endpoint;
   
    for (int i = 0; i <= length; ++i)
    {
        if ( isalnum(s[length-i]) )
        {
            endpoint = length - i;
            break;
        }
        else
        {
            continue;
        }
    }
    string end = s.substr(endpoint);  //Endzeichen in string speichern
 
    //Die Mitte vom Wort mischen
    string rest = s.substr(startpoint + 1, endpoint - startpoint - 1);    //Die Mitte als string aus dem Ursprungswort trennen
 
    random_shuffle( rest.begin(), rest.end() );
   
    //Das gemischte Wort zusammensetzen
    string mixed = start + rest + end;
    return mixed;   
}

//Aufgabe 3c
string split_and_mix(string s) {    
    
    vector<string> splittext = split_words(s); //string auf-splitten
   
    string mixword;
    string mixtext;
   
    for (int i = 0; i < splittext.size(); ++i)
    {        
        mixword = mix(splittext[i]); //Jedes Feld des Vektors (ein Wort) einzeln mischen
        
        mixtext = mixtext + mixword + ' ' ; //string aus den gemischten Wörtern zusammensetzten
    }
   
    return mixtext;
}

int main () {  //viele "endl" für bessere Lesbarkeit auf dem terminal
    //Aufgabe 3d    
    cout << " 1. " << endl << str1 << endl << endl;
    cout << split_and_mix(str1) << endl << endl;
    
    cout << " 2. " << endl << str2 << endl << endl;
    cout << split_and_mix(str2) << endl << endl;
    
    cout << " 3. " << endl << str3 << endl << endl;     //#Douglas Adams
    cout << split_and_mix(str3) << endl << endl;
    
    cout << " 4. " << endl << str4 << endl << endl;     //I saw what you did there! A "Faust" quote. *Gasp* Are you trying to tell us, 
    cout << split_and_mix(str4) << endl << endl;        //that IPI is like playing with the devil? Wait, rethorical question, the answer is: yes it is :P
    
    cout <<  " 5. " << endl <<str5 << endl << endl;
    cout << split_and_mix(str5) << endl << endl;
    
    return 0;
}