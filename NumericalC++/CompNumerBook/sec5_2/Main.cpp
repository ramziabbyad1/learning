#include <iostream>
#include <iomanip>
#include <cfloat>
#include <cmath>
#include <limits>
#include "trap.h"
#include "additional_fns.h"
#include <string>
using namespace std;
#define _USE_MATH_DEFINES

void
print_results(string rule_name, string fn_name, 
	double a, double b, double result, long grid_size, double expected) {

	double h = (b - a) / double(grid_size);
	cout << setprecision(2);
	cout << "Using rule: " << rule_name << endl;
	cout << "Integrated function: " << fn_name << endl;
	cout << "From a = " << a << " to b = " << b << endl;
	cout << "With grid size: " << grid_size << endl;
	cout << fixed;
	cout.precision(DBL_DIG);
	cout << "With step size: " << h << endl;
	cout << "Gives result : " << result <<  endl;

	cout << "The expected result is: " << expected << endl;	
	cout << "The relative error is: " << abs((expected - result)/expected)*100 
	<<  " %"	<< endl << endl;
}

double compute_pi(long grid_size) {
	double a = 0, b = 1;
	
	return 4*trap(integrand_arctan, a, b, grid_size);
}

int
main()
{
	double b = M_PI, a = 0;	
	long n = 10;	
	double expected_result = 2;
	double result = trap(sin, a, b, n);	
	print_results("trapezoid", "sin(x)", a, b, result, n, expected_result);

	n = 50;
	result = trap(sin, a, b, n);	
	print_results("trapezoid", "sin(x)", a, b, result, n, expected_result);

	n = 10000;
	result = trap(sin, a, b, n);	
	print_results("trapezoid", "sin(x)", a, b, result, n, expected_result);

	a = 0, b = 1;
	n = 10; expected_result = exp(1) - 1;
	result = trap(exp, a, b, n);
	print_results("trapezoid", "e(x)", a, b, result, n, expected_result);
	
	n = 100;		
	result = trap(exp, a, b, n);
	print_results("trapezoid", "e(x)", a, b, result, n, expected_result);
	
	n = 1000;		
	result = trap(exp, a, b, n);
	print_results("trapezoid", "e(x)", a, b, result, n, expected_result);

	a = 0, b = 1;
	n = 10; expected_result = atan(1) - .5*log(2);
	result = trap(atan, a, b, n);
	print_results("trapezoid", "arctan(x)", a, b, result, n, expected_result);

	a = 0, b = 1;
	n = 1000; expected_result = atan(1) - .5*log(2);
	result = trap(atan, a, b, n);
	print_results("trapezoid", "arctan(x)", a, b, result, n, expected_result);

	n = 10; expected_result = M_PI;
	a = 0, b = 1;
	result = compute_pi(n);
	print_results("trapezoid", "integrand_arctan", a, b, result, n, expected_result);

	n = 10000; expected_result = M_PI;
	a = 0, b = 1;
	result = compute_pi(n);
	print_results("trapezoid", "integrand_arctan", a, b, result, n, expected_result);

	n = 1000000; expected_result = 0.772095785481998;
	a = 0, b = .8;
	result = trap(Si, a, b, n);
	print_results("trapezoid", "Si(x)", a, b, result, n, expected_result);

	n = 100; expected_result = sqrt(M_PI_2);
	a = 0, b = 10;
	result = trap(Gaussian, a, b, n);
	print_results("trapezoid", "Guassian(x)", a, b, result, n, expected_result);

	n = 100; expected_result = expected_result;
	a = .0001, b = 1;
	result = trap(alt_gauss, a, b, n);
	print_results("trapezoid", "transformed gauss", a, b, result, n, expected_result);
/*
	//These take a very long time to run
	n = 10000000; expected_result = M_PI_2;
	a = 0.00001, b = 10000;
	result = trap(sin_fn, a, b, n);
	print_results("trapezoid", "Si(x)", a, b, result, n, expected_result);

	//needs an extrmely fine grid
	n = 1000000000; expected_result = M_PI_2;
	a = 0.0001, b = 10;
	result = trap(alt_Si, a, b, n);
	print_results("trapezoid", "transformed Si(x)", a, b, result, n, expected_result);
*/

	n = 1000000; expected_result = .5 * sqrt(M_PI_2);
	a = 0, b = 1000;
	result = trap(fresnel_sine, a, b, n);
	print_results("trapezoid", "sin(x^2)", a, b, result, n, expected_result);

	//Testing the error of Si, via comparison to erf
	n = 59; expected_result = .5 * sqrt(M_PI) * erf(1);
	a = 0, b =1;
	result = trap(half_gaussian, a, b, n);
	print_results("trapezoid", "Si(1)", a, b, result, n, expected_result);

	return 0;
}
