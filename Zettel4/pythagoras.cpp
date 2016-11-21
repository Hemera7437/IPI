#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

bool is_square(int n){
	double x, y;
	
	x = sqrt(n); //Aufgabe 2a
	y = floor(x);
	
	if (n%4 ==2 || n%4 ==3){  //Aufgabe 2b
		return false;
	}
	
	if (x == y){
		return true;
	}
	else {
		return false;
	}	
}
/*Teilaufgabe 2b
Beweisen Sie die Gültigkeit der obigen Aussage mit Hilfe der allgemeinen Eigenschaft der Modulo-Operation
(m * n)%k = ( (m%k) * (n%k) ) % k
==> n= 16 -->  (4*4)%4  = 0 = ( (4%4) * (4%4) )%4  wobei das letzte %4 nichts mehr macht = (4%4) * (4%4)
==> n= 25 -->  (5*5)%4  = 1 = ( (5%4) * (5%4) )%4
==> n= 6  -->  (2*3)%4  = 2 = ( (2%4) * (3%4) )%4  ==> 6 ist keine Quadratzahl
*/

void pythagorean_triple(int bmax){
	int a, b;
	for (b = 1; b <= bmax; ++b){
		for (a = 1; a < b; ++a){
			if ( is_square(a*a + b*b) == true ) {
				cout << "(" << a << ", " << b << ", " << sqrt(a*a + b*b) << ")" << endl;
			}
		}
	}
}


int main (){
	int bmax = 400;
	pythagorean_triple(bmax);
}
