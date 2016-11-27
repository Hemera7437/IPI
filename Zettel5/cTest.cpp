#include <iostream>	
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector <string> findSpace(string s){
    vector<string> space;
    
    int length = s.size();
    int pos = s.find(' ');
    int i;     
	string pickName;
    for(int i = 0; i < length; ++i){
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

vector <string> split_words(string s)					// diese funktion wurde übertragen aus dem was ich ursprünglich gezeigt bekommen habe
{
    vector<string> v1;    
    
    vector<string> c = findSpace(s);
    
	for(int i = 0; i < c.size(); ++i){					// hier wird jedes wort einzeln ausgespuckt
		v1.push_back(c[i]);
        //cout << c[i] << endl;
	}
    
    return v1;
}

int main () {
    string s;
	cout << "Please enter a sentence" << endl;
	getline(cin, s);
    
    vector<string> c = findSpace(s);
	vector<string> b = split_words(s);
    
	for(int i = 0; i < c.size(); ++i){					// hier wird jedes wort einzeln ausgespuckt
		cout << c[i] << endl;
	}
        
	for(int i = 0; i < b.size(); ++i){
		cout << b[i] << endl;
	}
    
    return 0;
}