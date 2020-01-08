#pragma once
#include "polynomial.h"

class monomial :public polynomial
{

public:
	monomial();
	~monomial();
	double operator[](int num);
};

