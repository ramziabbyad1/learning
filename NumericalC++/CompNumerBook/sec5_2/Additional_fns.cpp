
#include <cmath>
using namespace std;

double integrand_arctan(double x) 
{
	return 1. / (1 + x*x);
}

double Si(double x) 
{
	if (x == 0) return 1;
	return sin(x)/x;
}

double Gaussian(double x)
{
	return exp(-x*x/2);
}

double alt_gauss(double t)
{
	return exp(-log(t) * log(t) / 2) / t;
}

double sin_fn(double x) 
{
	return sin(x)/x;
}

double alt_Si(double t)
{
	return sin(1 / t) / t;
}

double fresnel_sine(double x)
{
	return sin(x * x);
}

double half_gaussian(double x)
{
	return exp(-x*x);
}
