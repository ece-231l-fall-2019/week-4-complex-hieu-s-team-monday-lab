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

//Math Operators
Complex operator+(const Complex& a, const Complex& b) 
{
	double addReal = (a.real() + b.real()); //(a + c)
	double addImag = (a.imag() + b.imag()); //(bi + di)
	
	Complex res(addReal,addImag);
	
	return res;
}

Complex operator-(const Complex& a, const Complex& b)
{
	double minReal = (a.real() - b.real()); //(a - c)
	double minImag = (a.imag() - b.imag()); //(bi - di)
	
	Complex res(minReal,minImag);

	return res;
}

Complex operator*(const Complex& a, const Complex& b) //(a + bi)*(c + di) 
{
	double x = (a.real() * b.real()) + (a.imag() * b.imag() * -1); //x = (a*c)+(bi*di*-1)
	double yi = (a.real() * b.imag()) + (a.imag() * b.real()); //yi = (a*di)+(bi*c)
	
	Complex res(x, yi);
	
	return res;
}

Complex operator/(const Complex& a, const Complex& b) //(a + bi)/(c + di) * (c - di)/(c - di)
{
	double topReal = ((a.real() * b.real()) + (a.imag() * (b.imag() * -1) * -1)); //z = (a * c) + (-1 * (bi * di *-1)
	double topImag = ((a.real() * b.imag()* -1) + (a.imag() * b.real())); //wi = (a * di * -1) + (bi * c)
	double botReal = ((b.real() * b.real()) + (b.real() * (b.imag() * -1) * -1)); //y = (c * c) + (di *di * -1)
	
	Complex res ((topReal/botReal),(topImag/botReal)); //(z/y), (wi/y)

	return res;
}

//Squared magnitude of x
double norm(const Complex& z)
{
	double resReal = (z.real() * z.real()); //(x^2)
	double resImag = (z.imag() * z.imag()); //(yi^2 * -1) 
	double res = (resReal + resImag); //sqrt(x + y)

	return res;
}

//Conjucate
Complex conj(const Complex& z)
{
	double resReal = z.real(); //x
	double resImag = (z.imag() * -1); //yi * -1

	Complex res(resReal, resImag); //(x - yi)
	
	return res;
	
}

//Comparisons
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
	if ((a.real() != b.real()) || (a.imag() != b.imag()))
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

//Outputs (x *+ or -* yi)
std::ostream& operator<<(std::ostream& out, const Complex& z)
{
	out<<z.real()<<(z.imag() < 0? "-":"+")<<z.imag();
	return out;
}

