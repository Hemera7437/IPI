#include <iostream>	
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector <string> findeLeerzeichen(string s){
    vector<string> Leerzeichen;
    
    int length = s.size();
    int pos = s.find(" ");
    int i;     
	string pickName;
    for(int i = 0; i < length; ++i){
		if(s[i] == pos){
			Leerzeichen.push_back(pickName);
		}else{
			pickName =+ s[i];
		}
	}
    
    return Leerzeichen;
}

vector <string> split_words(string s)
{
    vector<string> v1;    
    v1.push_back(s);
    
    //s.find(" ");
    
    return v1;
}

int main () {
    string s = "Alpha Beta! Gamma";
    string s1, s2;
    
    vector<string> l = findeLeerzeichen(s);
    
	for(int i = 0; i < l.size(); ++i){
		cout << l[i] << " , " << endl;
	}    
    
	vector<string> b = split_words(s);
    
	for(int i = 0; i < b.size(); ++i){
		cout << b[i] << endl;
	}
    
    return 0;
}