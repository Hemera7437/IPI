#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include <cctype>
#include <stdio.h>


std::string to_lower (std::string s) {
	int i=0;
	int k = s.size(); 
	char c;
	while (i <= k)
	{
		c = s[i];
		putchar (tolower(c));
		i++;
	}
	
	std::cout << c << std::endl;  	
	
	s =+ c;
	
	std::cout << s << std::endl;
	
	return s;	
}

std::string letters_only(std::string s) {
	int i=0;
	int k = s.size(); 
	std::string temp = "";

	//char str[]="C++";
	while (i < k)
	{
		if ( isalpha(s[i]) ) {
			printf ( "character %c is alphabetic\n", s[i] );
		}
		
		else {
			printf ( "character %c is not alphabetic\n", s[i] );
			s[i] = temp [i];
			//std::cout << ("character %c" , s[i]) << std::endl;
		}
		i++;
	}
	std::cout << "letters_only: " << s << std::endl;
	
}

/*
bool is palindrom(std::string s) {
	
	
}
*/

int main(){
	std::cout << "Geben sie ein Wort oder einen Satz ein" << std::endl;
	std::string s;
	char c;
	std::getline(std::cin, s);
	to_lower(s);
	letters_only(s);
}
