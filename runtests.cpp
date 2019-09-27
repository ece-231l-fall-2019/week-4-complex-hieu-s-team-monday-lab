#include <iostream>

// change the value below to 1 to run tests against your Complex class.
// change the value below to 0 to run tests against the built in std::complex.

#if 1
#include "Complex.h"
#else
#include <complex>
typedef std::complex<double> Complex;
#endif

void Assert(bool cond, std::string message)
{
	if (cond)
		std::cout << "Pass: " << message << std::endl;
	else
		std::cerr << "FAIL: " << message << std::endl;
}

int main()
{
	Complex z1(4, 3);

	Assert(z1.real() == 4, "real constructor");
	Assert(z1.imag() == 3, "real constructor");
	Assert(norm(z1) == 25, "complex norm");


	// TODO:
	// Write *at least* 20 more tests to fully test
	// your Complex class.
	
	Assert(z1 == Complex(4,3), "Comparison == (complex)");
	Assert(z1 == z1, "Comparison == (complex)");
	Assert(z1 != (5,7), "Comparison != (complex)");
	Assert(z1 != 3, "Comparison != (double)");
	z1 = Complex(3,0);
	Assert(z1 == 3, "Comparison == (double)");

	z1 = 5;
	Assert(z1 == 5, "Operator = (double)");
	z1 = Complex(4,3);
	Assert(z1 == Complex(4,3), "Operator = (complex)");
	z1 += Complex(4,3);
	Assert(z1 == Complex(8,6), "Operator +=");
	z1 -= Complex(4,3);
	Assert(z1 == Complex(4,3), "Operator -=");
	z1 *= Complex(4,3);
	Assert(z1 == Complex(16,9), "Operator *=");


	std::cout << norm(z1) << " : Expected Value: 2.646 " << std::endl;
	

	return 0;
}


