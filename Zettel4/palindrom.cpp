#include <iostream>
#include <cctype>
#include <cassert>

using namespace std;

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

string letters_only(string s){
	int length = s.size();
	string result = "";
	char c;
	for(int i = 0; i < length; ++i){
		c = s[i];
		if(isalpha(c)){
			result.insert(0, 1, c);
		}
	}
	return result;
}

bool is_palindrom(string s){
	bool pali = false;
	if(letters_only(letters_only(s)) == letters_only(s)){
		pali = true;
	}
	return pali;
}

int main(){
	string s;
	//asserts
	assert (is_palindrom("anna") == true);
	assert (is_palindrom("otto") == true);
	assert (is_palindrom("ein neger mit gazelle zagt im regen nie") == true);
	assert (is_palindrom("hallo") == false);
	assert (is_palindrom("ipi") == true);
	assert (is_palindrom("xyz") == false);
	
	cout << "Geben sie ein Wort oder einen Satz ein" << std::endl;
	getline(cin, s);
	s = to_lower(s);
	if(is_palindrom(s)){
		cout << "ist ein Palindrom";
	} else {
		cout << "ist kein Palindrom";
	}
}