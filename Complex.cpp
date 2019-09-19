#include "Complex.h"
#include <math.h>

Complex::Complex()
{
	_real = 0.0;
	_imag = 0.0;
}

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

double Complex::real() const {return _real;}
double Complex::imag() const {return _imag;}

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

Complex& Complex::operator-=(const Complex& z)
{
	_real -= z._real;
	_imag -= z._imag;
	
	return *this;
}

Complex& Complex::operator*=(const Complex& z)
{
	_real *= z._real;
	_imag = (_imag * z._imag * -1);
	
	return *this;
}

Complex& Complex::operator/=(const Complex& z)
{
	_real /= z._real;
	_imag /= z._imag;
	
	return *this;
}

Complex operator+(const Complex& a, const Complex& b)
{
	double addReal = (a.real() + b.real());
	double addImag = (a.imag() + b.imag());
	
	Complex res(addReal,addImag);
	
	return res;
}

Complex operator-(const Complex& a, const Complex& b)
{
	double minReal = (a.real() - b.real());
	double minImag = (a.imag() - b.imag());
	
	Complex res(minReal,minImag);

	return res;
}

Complex operator*(const Complex& a, const Complex& b)
{
	double x = (a.real() * b.real()) + (a.imag() * b.imag() * -1);
	double yi = (a.real() * b.imag()) + (a.imag() * b.real());
	
	Complex res(x, yi);
	
	return res;
}

Complex operator/(const Complex& a, const Complex& b)
{
	double topReal = ((a.real() * b.real()) + (a.imag() * (b.imag() * -1) * -1));
	double topImag = ((a.real() * b.imag()) + (a.imag() * b.real()));	
	double botReal = ((b.real() * b.real()) + (b.real() * (b.imag() * -1) * -1));
	double botImag = ((b.real() * (b.imag() * -1)) + (b.imag() * b.real()));
	
	Complex res ((topReal/botReal),(topImag/botImag));

	return res;
}

double norm(const Complex& z)
{
	double resReal = (z.real() * z.real());
	double resImag = (z.imag() * z.imag());
	double square = sqrt(resReal + resImag);

	return square;
}

Complex conj(const Complex& z)
{
	double resReal = z.real();
	double resImag = (z.imag() * -1);

	Complex res(resReal, resImag);
	
	return res;
	
}

bool operator==(const Complex& a, const Complex& b)
{
	if ((a.real() == b.real()) && (a.imag() == b.imag()))
	{
		return true;
	}
	else 
	{
		return false;
	}
}

bool operator==(const Complex& a, double r)
{
	if ((a.real() == r)||(a.imag() == r))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator!=(const Complex& a, const Complex& b)
{
	if ((a.real() != b.real()) && (a.imag() != b.imag()))
	{
		return true;
	}
	else 
	{
		return false;
	}
}
  
bool operator!=(const Complex& a, double r)
{
	if ((a.real() != r)||(a.imag() != r))
	{
		return true;
	}
	else
	{
		return false;
	}
}
std::ostream& operator<<(std::ostream& out, const Complex& z)
{
	out<<z.real()<<(z.imag() < 0? "-":"+")<<z.imag();
	return out;
}

