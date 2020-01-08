#include <iostream>
#include "polynomial.h"

int main(){
	// wielomiany mozemy tworzyc w nastepujacy sposob:
	// double x[4] = {9,2,-6,8}; polynomial p1(x, 4);
	// polynomial p2("9x^3+2x^2-6x+8");
	// polynomial p3(3);   <-- zrobi wielomian 3 stopnia o wspolczynnikach 0
	// polynomial p4(p3);
	// -----------------------------------------------
	// mozliwe operacje (po prawej stronie moze byc wielomian lub liczba):
	// +, +=, -, -=, *, *= , /, /=
	// [] - zwraca wspolczynnik przy podanym stopniu np.  p1[2];
	// () - zwraca pochodna wielomianu przy podanym stopniunp.  p2(3);
	// dzielenie wielmianow dziala tylko dla takich (x +- liczba) !!!
	// dostepne sa takze operatory  >> i <<  np. std::cout << p1;

	
	system("pause");
	return 0;
}