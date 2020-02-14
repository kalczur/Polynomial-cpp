#include <iostream>
#include "polynomial.h"

int main(){

	//double x[4] = {9,2,6,8};	polynomial p1(x, 4);

	polynomial p1("x^3");
	polynomial p2("x^5");
	polynomial p3(0);

	p2 /= p1;

	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl;
	std::cout << p3 << std::endl;

	//std::cout << p2 << std::endl;
	//std::cin >> p1;
	//std::cout << p1 << std::endl;

	system("pause");
	return 0;
}