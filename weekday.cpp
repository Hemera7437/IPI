#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include <cmath> 

template<typename T>
std::string to_string(const T& value)
{
    std::ostringstream stream;
    stream << value;
    return stream.str();
} //to string fix

int weekday2001(int d, int m, int y){
	int z, j1, p, schalt, w;
	std::string Tag;
	
	z = y - 2001;
	j1 = ( 365*z + (z/4) - (z/100) + (z/400) ) % 7;
	
	( ( (y%4) == 0 && (y%100) != 0 ) || (y%400) == 0 ) ? schalt = 1 
		:  schalt =0;	
	
	(m == 1)? p = d  : 
		(m == 2)? p = d + 31 : 
			(m > 2 && schalt == 0)? p = d + 59 + ((153*m - 457) / 5) : 
				(m > 2 && schalt == 1)? p = d + 60 + ((153*m - 457) / 5)  :
					m = m;
	
	w = (j1 + p -1) % 7;
	
	(w == 0)? Tag = "Montag" 
		: (w == 1)? Tag = "Dienstag"
			: (w == 2)? Tag = "Mittwoch"
				: (w == 3)? Tag = "Donnerstag"
					: (w == 4)? Tag = "Freitag"
						: (w == 5)? Tag = "Samstag"
							: (w == 6)? Tag = "Sonntag"
								: Tag = "Fehler";
	
	std::cout << "Durch weekday2001: " << to_string(d) << "." << to_string(m) << "." << to_string(y)  << " war ein " << Tag << " \n";
}

int floorDiv(int a, int b){
	int test, r;
	test = a/b;
	(test > 0)? r = a/b
		: r = ( -( std::abs(a)  / std::abs(b)) + -1 ); 
	return r;
}
/* bei - (|a| + c) / |b| muss c in Abhängigkeit von a und b eigentlich 
c=a%b, wobei floorMod(a,b) verwendet wird, sein*/

int floorMod(int a, int b) {
	int r;
	r = a - b * floorDiv (a,b);
}  
/*Wie unterscheidet sich floorMod () von der %-operation in c++? (aufgabe 2c)
	
*/

int weekday(int d, int m, int y){
	int z, j1, p, schalt, w;
	std::string Tag;
	
	z = y - 2001;
	j1 = floorMod( ( 365*z + floorDiv(z,4) - floorDiv(z,100) + floorDiv(z,400) ) , 7 ) ;
	
	( ( (y%4) == 0 && (y%100) != 0 ) || (y%400) == 0 ) ? schalt = 1 
		:  schalt =0;	
	
	(m == 1)? p = d  : 
		(m == 2)? p = d + 31 : 
			(m > 2 && schalt == 0)? p = d + 59 + floorDiv((153*m - 457) , 5) : 
				(m > 2 && schalt == 1)? p = d + 60 + floorDiv((153*m - 457) , 5) :
					m = m;
	
	w = floorMod ( (j1 + p - 1) , 7);
	
	(w == 0)? Tag = "Montag" 
		: (w == 1)? Tag = "Dienstag"
			: (w == 2)? Tag = "Mittwoch"
				: (w == 3)? Tag = "Donnerstag"
					: (w == 4)? Tag = "Freitag"
						: (w == 5)? Tag = "Samstag"
							: (w == 6)? Tag = "Sonntag"
								: Tag = "Fehler";
	
	std::cout << "Durch floor-Rechnung: " << to_string(d) << "." << to_string(m) << "." << to_string(y)  << " war ein " << Tag << " \n";
}

int weekday1(int d, int m, int y){
	int z, j1, p, schalt, w;
	std::string Tag;
	
	z = y - 1;
	j1 = ( 365*z + (z/4) - (z/100) + (z/400) ) % 7;
	
	( ( (y%4) == 0 && (y%100) != 0 ) || (y%400) == 0 ) ? schalt = 1 
		:  schalt =0;	
	
	(m == 1)? p = d  : 
		(m == 2)? p = d + 31 : 
			(m > 2 && schalt == 0)? p = d + 59 + ((153*m - 457) / 5) : 
				(m > 2 && schalt == 1)? p = d + 60 + ((153*m - 457) / 5)  :
					m = m;
	
	w = (j1 + p -1) % 7;
	
	(w == 0)? Tag = "Montag" 
		: (w == 1)? Tag = "Dienstag"
			: (w == 2)? Tag = "Mittwoch"
				: (w == 3)? Tag = "Donnerstag"
					: (w == 4)? Tag = "Freitag"
						: (w == 5)? Tag = "Samstag"
							: (w == 6)? Tag = "Sonntag"
								: Tag = "Fehler";
	
	std::cout << "Durch weekday1: "<< to_string(d) << "." << to_string(m) << "." << to_string(y)  << " war ein " << Tag << " \n";
}

int main () {
	int d, m, y;
	std::cout << "Geben sie den Tag ein" << std::endl;
	std::cin >> d;
	std::cout << "Geben sie den Monat ein" << std::endl;
	std::cin >> m;
	std::cout << "Geben sie die Jahreszahl ein" << std::endl;
	std::cin >> y;
	//assert(y > 1583);
	weekday2001(d, m, y);
	weekday(d, m, y);
	weekday1(d, m, y);
}