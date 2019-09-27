#include "Complex.h"
#include <math.h>

Complex::Complex()
{
	_real = 0.0;
	_imag = 0.0;
}

//Constructors
Complex::Complex(double re, double im) 
{
	_real = re;
	_imag = im;
}

Complex::Complex(const Complex& z) 
{
	_real = z.real();
	_imag = z.imag();
}

//Access Values
double Complex::real() const {return _real;}
double Complex::imag() const {return _imag;}

//Assignment
Complex& Complex::operator=(double r)
{
	_real = r;
	_imag = r;

	return *this;
}

Complex& Complex::operator=(const Complex& z)
{
	_real = z._real;
	_imag = z._imag;

	return *this;
}

Complex& Complex::operator+=(const Complex& z)
{
	_real += z._real;
	_imag += z._imag;
	
	return *this;
}

