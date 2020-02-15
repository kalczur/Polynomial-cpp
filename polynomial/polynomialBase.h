#pragma once
class polynomialBase
{
protected:
	int deg;
	char* tmp = new char[30];
public:
	virtual double operator[](int) = 0;
	virtual double operator()(double num) = 0;
};

