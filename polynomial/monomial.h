#pragma once
#include "polynomial.h"
#include "polynomialBase.h"
#include <iostream>

class monomial: public polynomialBase
{
private:
	double cof;
public:
	monomial(const monomial& m);
	monomial(const char* str);
	monomial(double a, int b);
	virtual double operator[] (int num);
	int getDeg();
	virtual double operator()(double num);

	monomial& operator*= (const monomial& m);
	monomial& operator*= (double num);
	monomial& operator* (const monomial& m);
	monomial& operator* (double num);

	monomial& operator/= (const monomial& m);
	monomial& operator/= (double num);
	monomial& operator/ (const monomial& m);
	monomial& operator/ (double num);

	friend std::ostream& operator<< (std::ostream& out, monomial m);
	friend std::istream& operator>> (std::istream& in, monomial& m);
};

