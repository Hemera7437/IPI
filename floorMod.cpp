#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include <cmath> 

int floorDiv(int a, int b){
	int test, r;
	test = a/b;
	(test > 0)? r = a/b
		: r = ( -( (std::abs(a) + a%b + b ) / std::abs(b)) ); 
	return r;
}

int floorMod(int a, int b) {
	int r;
	r = a - b * floorDiv (a,b);
}

int main() {
	int a= -17;
	int b= 9;
	//int r = a/b;
	std::cout << "the floorDiv answer is: " << floorDiv(a,b) << std::endl;
	std::cout << "the floorMod answer is: " << floorMod(a,b) << std::endl;
	assert (a == floorDiv(a, b) * b + floorMod(a, b));
}