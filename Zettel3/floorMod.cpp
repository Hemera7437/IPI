#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include <cmath> 

int floorDiv(int a, int b){
	int test, r;
	int c = std::abs(b) - 1;
	test = a / b;
	(test > 0)? r = a / b
		: r = ( -( (std::abs(a) + c) / std::abs(b) ) ); 
	return r;
}

int floorMod(int a, int b) {
	int r;
	r = a - b * floorDiv (a,b);
}

int main() {
	assert(floorMod(-12,5) == 3);
    assert(floorMod(12,-5) == -3);
    assert(floorMod(-17,9) == 1);
    assert(floorMod(17,-9) == -1);
	
	int a= -12;
	int b= 5;
	//int r = a/b;
	std::cout << "the floorDiv answer is: " << floorDiv(a,b) << std::endl;
	std::cout << "the floorMod answer is: " << floorMod(a,b) << std::endl;
	assert (a == floorDiv(a, b) * b + floorMod(a, b));
}
