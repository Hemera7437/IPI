#include <iostream>	
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

string findeLeerzeichen(string s){
    int length = s.size();
    int pos = s.find(" ");
    
    string s1 = s.substr(0, pos);
    string s2 = s.substr(pos, length);
    cout << s1 << " , " << s2 <<endl;	
}

vector <string> split_words(string s)
{
    vector<string> v1;    
    v1.push_back(s);
    
    //s.find(" ");
    
    return v1;
}

int main () {
    string s = "Alpha Beta";
    findeLeerzeichen(s);
	vector<string> b = split_words(s);
    
	for(int i = 0; i < b.size(); ++i){
		cout << b[i] << endl;
	}
    
    return 0;
}