#include "monomial.h"

monomial::monomial(double a = 0, int b = 0)
{
	cof = a;
	deg = b;
}
monomial::monomial(const monomial& m)
{
	cof = m.cof;
	deg = m.deg;
}
monomial::monomial(const char* str)
{
	char* endPointer;
	int deg, sign = 1;

	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;

	if (*str == 'x')
		cof = 1;
	else
	{
		cof = strtod(str, &endPointer);
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
	cof += sign * cof;
}

double monomial::operator[] (int num) {
	if (num != deg)
		return 0;
	else
		return cof;
}

int monomial::getDeg()
{
	return deg;
}

monomial& monomial::operator*= (const monomial& m)
{
	cof *= m.cof;
	deg += m.deg;

	return *this;
}
monomial& monomial::operator*= (double num)
{
	cof *= num;
	return *this;
}
monomial& monomial::operator* (const monomial& m)
{
	return *this *= m;
}
monomial& monomial::operator* (double num)
{
	return *this *= num;
}

monomial& monomial::operator/= (const monomial& m)
{
	if (m.cof && m.deg > deg)
	{
		cof /= m.cof;
		deg -= m.deg;
	}

	return *this;
}
monomial& monomial::operator/= (double num)
{
	if (num)
		cof /= num;
	return *this;
}
monomial& monomial::operator/ (const monomial& m)
{
	return *this /= m;
}
monomial& monomial::operator/ (double num)
{
	return *this /= num;
}

//----------------| << >> |----------------
std::ostream& operator<<(std::ostream& out, monomial m)
{
	out << m.cof;
	if (m.deg)
		out << "x^" << m.deg;

	return out;
}

std::istream& operator >> (std::istream& in, monomial& m)
{
	in >> m.tmp;
	monomial::monomial(m.tmp);
	return in;
}