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
    
    string s1 = s.substr(0, pos);
    string s2 = s.substr(pos, length);
    cout << s1 << " , " << s2 <<endl;	
    
    Leerzeichen.push_back(s1);
    Leerzeichen.push_back(s2);
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
    string s = "Alpha Beta!";
    string s1, s2;
    
    findeLeerzeichen(s);
	vector<string> b = split_words(s);
    
	for(int i = 0; i < b.size(); ++i){
		cout << b[i] << endl;
	}
    
    return 0;
}