#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

template<typename T>
std::string to_string(const T& value)
{
    std::ostringstream stream;
    stream << value;
    return stream.str();
} //to string fix

std::string easter(int y) {
	int a, b, c, d, e, k, p, q, m, n, x, z;
	int test;
	//std::cout << "Geben sie die Jahreszahl ein" << std::endl;
	//std::cin >> y;
	std::string Monat;
	a = y % 19;
	b = y % 4;
	c = y % 7;
	k = y / 100;
	p = (8*k + 13)/25;
	q = k / 4;
	m = (15 + k - p - q) % 30;
	d = (19*a + m) %30;
	n = (4 + k - q)% 7;
	e = (2*b + 4*c + 6*d + n) % 7;
	x = 22 + d + e;
	
	(x == 57)? test = 50   
		: (x == 56 && d == 28 && a > 10)? test = 49   
			: test = x ;
	
	
	
	(test > 31)?  Monat = "April"
		: Monat = "Maerz";  
		//aus irgendeinem Grund, kann er den monat März andersrum nicht anzeigen...
		
	(Monat == "Maerz")? z = test
		: z = test -31;
	
	
	std::cout << to_string(y) << " war Ostern am " << to_string(z) << ". " << Monat << " \n";
	
	return Monat;
}

int main(){
	int y;
	
	/*
	std::cout << "Geben sie die Jahreszahl ein" << std::endl;
	std::cin >> y;
	assert(y > 1583);
	easter(y);
	*/
	
	assert (easter(2016) == "Maerz");
	assert (easter(1902) == "Maerz");
	assert (easter(1998) == "April"); 
	assert (easter(2022) == "April"); 
	assert (easter(2000) == "April"); 
	assert (easter(2005) == "Maerz"); 
	assert (easter(1995) == "April"); 
	assert (easter(1947) == "April");
	assert (easter(1905) == "April");  
	assert (easter(1907) == "Maerz");
	
}