#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std; 
#define _USE_MATH_DEFINES

double 
trap_naive(double (*f)(double), double a, double b, long n) 
{
	double sum = .5 * ( f(a) + f(b) );
	double h = ( b - a ) / n;
	double x;
	int i;
	for(i = 1, x = a; i <= n - 1; i++, x = a + i*h) {
		sum += f(x);
	}

	sum *= h;

	return sum;
}

double
gaussian(double x)
{
	return 1. / exp(x * x);
}

void
display_res(string name, double integral, double a, double b, long n)
{
	cout << "name of integral = " << name << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "n = " << n << endl;
	cout << "integral  = " << integral << endl;
}

double
Si(double x)
{
	if(x == 0)
	{
		return 1;
	}
	return sin(x) / x;
}

int
main()
{
	double a, b;
	long n;
	a = 0; b = 1; n = 60;
	double gausInt = trap_naive(gaussian, a, b, n); 

	display_res("gaussian", gausInt, a, b, n);

	a = 0; b = 1; n = 6;
	double SiInt = trap_naive(Si, a, b, n);

	display_res("Si", SiInt, a, b, n);
}
