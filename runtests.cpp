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
	Complex z2(4,3);
	Complex a1(7,3);
	Complex a2(3,0);

	Assert(z1 == z1);
	Assert(z1 == z2);
	Assert(z1 != a1);
	Assert(z1 != 3);
	Assert(a2 == 3);

	z1 = 5;
	Assert(z1 == 5);
	z1 = (4,3);
	Assert(z1 = z2);
	

	return 0;
}


