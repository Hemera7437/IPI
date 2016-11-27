#include <iostream>	
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector <string> split_words(string s){  //meine eigene Funktion um den String bei Leerzeichen zu trennen
    vector<string> space;
    
    int length = s.size();
    //int pos = s.find(' ');
    int i;     
    
	string pickName;
    for(i = 0; i < length; ++i){
		if(s[i] == ' '){
			space.push_back(pickName);			// sollte ein Leerzeichen vorkommen, wird das wort in den vector eingefügt
			pickName = "";								// danach wird der string wieder resettet um keine doppelten zeichen zu übertragen
		}else{
			pickName += s[i];							// sollte der character kein Leerzeichen sein wird er dem hilfs string angefügt
		}
	}
	space.push_back(pickName);					// hier wird das letzte wort auch noch hinzu gefügt, weil normalerweise der letzte character kein Leerzeichen ist
    return space;
}


string mix(std::string s)
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
    string start = s.substr(0, startpoint + 1);    //Anfangszeichen in string speichern
 
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
    string end = s.substr(endpoint);    //Endzeichen in string speichern
 
    //Die Mitte vom Wort mischen
    string rest = s.substr(startpoint + 1, endpoint - startpoint - 1);    //Die Mitte als string aus dem Ursprungswort trennen
 
    random_shuffle( rest.begin(), rest.end() );
   
    //Das gemischte Wort zusammensetzen
    string mixed = start + rest + end;
    return mixed;   
}

string split_and_mix(std::string s) {    
    
    vector<string> splittext = split_words(s); //string mithilfe von split_words trennen
   
    std::string mixword;
    std::string mixtext;
   
    for (int i = 0; i < splittext.size(); ++i)
    {        
        mixword = mix(splittext[i]); //Jedes Feld des Vektors (ein Wort) einzeln mischen
        
        mixtext = mixtext + mixword + ' ' ; //string aus den gemischten Wörtern zusammensetzten
    }
   
    return mixtext;
}

int main () {
    string s;
	cout << "Please enter a sentence" << endl;
	getline(cin, s);
    
	vector<string> b = split_words(s);
      
	for(int i = 0; i < b.size(); ++i){  // hier wird jedes wort einzeln ausgespuckt
		cout << b[i] << endl;
	}
    
    cout << mix(s) << endl;
    cout << split_and_mix(s) << endl;
    
    return 0;
}