#include <iostream>
#include "polynomial.h"


unsigned int specifyDeg(const char* str)
{
	unsigned int deg = 0;
	while (*str)
	{
		if (*str++ == 'x')
		{
			if (deg == 0)
			{
				deg = 1;
			}
			if (*str++ == '^')
			{
				char* endptr;
				long tmp = strtol(str, &endptr, 10);
				str = endptr;
				deg = tmp > (int)deg ? tmp : deg;
			}
		}
	}
	return deg;
}

char* delSpaces(const char* str)
{
	char* newStr = new char[strlen(str) + 1];
	char* tmpStr = newStr;
	while (*str)
	{
		if (*str != ' ' && *str != '\t')
			*tmpStr++ = *str;
		str++;
	}
	*tmpStr = 0;
	return newStr;
}


void polynomial::analyze(const char* str)
{
	char* newStr = delSpaces(str);
	deg = specifyDeg(newStr);
	allocate();
	readMonomials(newStr);
}

void polynomial::print()
{
	int tmpDeg = deg;

	if (tmpDeg == 0)
		std::cout << cof[0] << std::endl;
	else
	{
		do
		{
			if (cof[tmpDeg] != 0)
			{
				if (cof[tmpDeg] != 1)
					std::cout << cof[tmpDeg];

				std::cout << 'x';

				if (tmpDeg != 1)
					std::cout << '^' << tmpDeg;

				std::cout << " + ";
			}
		} while (--tmpDeg);

		if (cof[0] != 0)
			std::cout << cof[0];
	}

	std::cout << std::endl;
}

void polynomial::reallocate(int newSize)
{
	double* coefficient = new double[newSize + 1];
	for (int i = newSize; i >= 0; i--)
		coefficient[i] = 0;

	std::copy(cof, cof + deg + 1, coefficient);
	delete[] cof;
	cof = coefficient;
}

void polynomial::allocate()
{
	cof = new double[deg + 1];
	for (int i = 0; i <= deg; i++)
		cof[i] = 0;
}
char* polynomial::readMonomial(char* str)
{
	char* endPointer;
	double coefficient;
	int deg, sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else
	{
		if (*str == '+') str++;
	}
	if (*str == 'x')
		coefficient = 1;
	else
	{
		coefficient = strtod(str, &endPointer);
		str = endPointer;
	}
	if (*str != 'x')
		deg = 0;
	else
		if (*++str != '^')
			deg = 1;
		else
		{
			deg = strtol(++str, &endPointer, 10);
			str = endPointer;
		}
	cof[deg] += sign * coefficient;
	return str;
}
void polynomial::readMonomials(char* str)
{
	while (*str)
		str = readMonomial(str);

}
//-------------------------------------
//-------------constructors------------
//-------------------------------------
polynomial::polynomial()
{
	polynomial(0);
}
polynomial::polynomial(const polynomial& p)
{
	cof = 0;
	deg = p.deg;
	cof = new double[deg + 1];
	std::copy(p.cof, p.cof + p.deg + 1, cof);
}
polynomial::polynomial(const char* str)
{
	cof = 0;
	analyze(str);
}
polynomial::polynomial(double* tab, int newDeg)
{
	deg = newDeg;
	allocate();
	for (int i = deg - 1; i >= 0; i--)
		cof[i] = tab[i];
}
polynomial::polynomial(int newDeg)
{
	deg = newDeg;
	allocate();
}

polynomial::~polynomial()
{
	delete[] cof;
}
//-------------------------------------
//--------------operators--------------
//-------------------------------------
polynomial& polynomial::operator=(const polynomial& p)
{
	if (deg != p.deg)
	{
		deg = p.deg;
		reallocate(p.deg);
	}

	for (int i = 0; i <= deg; i++)
		cof[i] = p.cof[i];

	return *this;
}
//----------------| + |------------------
polynomial& polynomial::operator+=(const polynomial& p)
{
	if (p.deg > deg)
	{
		reallocate(p.deg);
		deg = p.deg;
	}

	for (int i = deg; i >= 0; i--)
		cof[i] += p.cof[i];

	return *this;
}
polynomial& polynomial::operator+=(double num)
{
	cof[0] += num;
	return *this;
}
polynomial polynomial::operator+(const polynomial& p)
{
	polynomial newP(*this);
	newP *= p;
	return newP;
}
polynomial polynomial::operator+(double num)
{
	polynomial newP(*this);
	newP += num;
	return newP;
}
//----------------| - |------------------
polynomial& polynomial::operator-=(const polynomial& p)
{
	if (p.deg > deg)
	{
		reallocate(p.deg);
		deg = p.deg;
	}

	for (int i = deg; i >= 0; i--)
		cof[i] -= p.cof[i];

	return *this;
}
polynomial& polynomial::operator-=(double num)
{
	cof[0] -= num;
	return *this;
}
polynomial polynomial::operator-(const polynomial& p)
{
	polynomial newP(*this);
	newP -= p;
	return newP;
}
polynomial polynomial::operator-(double num)
{
	polynomial newP(*this);
	newP -= num;
	return newP;
}
//----------------| * |------------------
polynomial& polynomial::operator*=(const polynomial& p)
{
	int newDeg = deg + p.deg;
	reallocate(newDeg);

	for (int i = deg; i >= 0; i--)
		for (int j = p.deg; j >= 0; j--)
			cof[i + j] = cof[i] * p.cof[j];

	deg = newDeg;
	return *this;
}
polynomial& polynomial::operator*=(double num)
{
	for (int i = deg; i >= 0; i--)
		cof[i] *= num;

	return *this;
}
polynomial polynomial::operator*(const polynomial& p)
{
	polynomial newP(*this);
	newP *= p;
	return newP;
}
polynomial polynomial::operator*(double num)
{
	polynomial newP(*this);
	newP *= num;
	return newP;
}
//----------------| / |------------------ <-TO DO

polynomial& polynomial::operator/=(const polynomial& p)
{
	polynomial tmpMain = *this;
	int tmpDeg = deg;
	double tmpP = p.cof[0] * -1;
	
	cof[tmpDeg - 1] = tmpMain[tmpDeg];
	tmpDeg--;

	while (tmpDeg--)
	{
		cof[tmpDeg] = (cof[tmpDeg + 1] * tmpP) + tmpMain.cof[tmpDeg+1];
	}

	cof[deg] = 0;

	return *this;
}
polynomial& polynomial::operator/=(double num)
{
	for (int i = deg; i >= 0; i--)
		cof[i] /= num;

	return *this;
}
polynomial polynomial::operator/(const polynomial& p)
{
	polynomial newP(*this);
	newP /= p;
	return newP;
}
polynomial polynomial::operator/(double num)
{
	polynomial newP(*this);
	newP /= num;
	return newP;
}
//--------------| [] () |----------------
double polynomial::operator[](int num)
{
	if (num < 0 || num > deg)
		return 0;

	return cof[num];
}
polynomial polynomial::operator()(int num)
{
	if (deg == 0)
		return 0;

	polynomial tmp = *this;
	polynomial deriv(deg);

	while (num--)
	{
		if (tmp.deg == 0)
			return 0;

		deriv.deg--;

		for (int i = tmp.deg; i > 0; i--)
			deriv.cof[i - 1] = tmp.cof[i] * i;

		tmp = deriv;
	}

	return deriv;
}
//----------------| << >> |----------------
std::ostream& operator<<(std::ostream& out, polynomial p)
{
	unsigned deg = p.deg;

	if (deg == 0)
	{
		out << p[0];
		return out;
	}

	for (int i = deg; i > 0; i--)
	{
		if (p[i] != 0)
		{
			out << p[i] << 'x';
			if (i != 1) out << '^' << i;
			out << " + ";
		}
	}

	if (p[0] != 0)
		out << p[0];

	return out;
}

std::istream& operator >> (std::istream& in, polynomial& p)
{
	in >> p.tmp;
	delete[] p.cof;
	p.analyze(p.tmp);

	return in;
}