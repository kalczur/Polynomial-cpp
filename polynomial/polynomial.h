#pragma once
#include "polynomialBase.h"
#include <iostream>

class polynomial : public polynomialBase
{
private:
	double* cof;
	void allocate();
	void reallocate(int newSize);
	char* readMonomial(char* str);
	void readMonomials(char* str);
public:
	polynomial();
	polynomial(double* tab, int newDeg);
	polynomial(int newDeg);
	polynomial(const char* str);
	polynomial(const polynomial& p);
	~polynomial();
	void analyze(const char* str);
	void print();
	polynomial derivative(int num);

	polynomial& operator=(const polynomial& p);

	polynomial& operator+= (const polynomial& p);
	polynomial& operator+= (double num);
	polynomial operator+ (const polynomial& p);
	polynomial operator+ (double num);

	polynomial& operator-= (const polynomial& p);
	polynomial& operator-= (double num);
	polynomial operator- (const polynomial& p);
	polynomial operator- (double num);

	polynomial& operator*= (const polynomial& p);
	polynomial& operator*= (double num);
	polynomial operator* (const polynomial& p);
	polynomial operator* (double num);

	polynomial& operator/= (const polynomial& p);
	polynomial& operator/= (double num);
	polynomial operator/ (const polynomial& p);
	polynomial operator/ (double num);

	virtual double operator() (double num);
	virtual double operator[] (int num);

	friend std::ostream& operator<< (std::ostream& ostr, polynomial p);
	friend std::istream& operator>> (std::istream& in, polynomial &p);
};

