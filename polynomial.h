#pragma once

class polynomial
{
private:
	int deg;
	double* cof;
	char* tmp = new char[30];
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

	polynomial operator() (int num);
	double operator[] (int num);

	friend std::ostream& operator<< (std::ostream& ostr, polynomial p);
	friend std::istream& operator>> (std::istream& in, polynomial& p);
};
