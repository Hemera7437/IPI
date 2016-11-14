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

int main() {
	int a= -12;
	int b= 5;
	//int r = a/b;
	std::cout << "the answer is: " << floorDiv(a,b) << std::endl;
}