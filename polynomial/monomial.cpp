#include "monomial.h"

monomial::monomial()
{
}

monomial::~monomial()
{
}

double monomial::operator[](int num)
{
	return polynomial::cof[num];
}
