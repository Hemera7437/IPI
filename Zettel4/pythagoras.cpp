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