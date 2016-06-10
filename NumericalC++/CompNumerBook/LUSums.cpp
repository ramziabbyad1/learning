#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std; //max/min_element
#define _USE_MATH_DEFINES
//1 D right and left rectangle rules
//for Descr functions
long
compute_n(double (*f)(double), double a, double b, double eps) ;

//Works only for decreasing functions
double 
LUSumsDecr(double (*f)(double), double a, double b, 
		double eps, long *n, double *lower_sum, double *upper_sum)
{
	if(*n == 0)
		*n = compute_n(f, a, b, eps);	

	cout << "computed n.." << endl;
	cout << "f(a) = " << f(a) << " f(b) = " << f(b) << endl;
	cout << "a = " << a << " b = " << b 
		<< " eps = " << eps << " *n = " << (*n) << endl;
	long subintervals = *n;
	double h = (b - a) / double(subintervals);
	double sum = 0;
	long i;
	double x;
	for(i = subintervals, x = b; i >= 1; i--, x-=h) {
		sum += f(x);
	}	
	*lower_sum = sum * h;
	*upper_sum = *lower_sum + h * (f(a) - f(b));
	double LU = (*upper_sum + *lower_sum) / 2;
	return LU;
}

double 
LUSumsIncr(double (*f)(double), double a, double b, 
		double eps, long *n, double *lower_sum, double *upper_sum)
{
	if(*n == 0)
		*n = compute_n(f, b, a, eps);	

	cout << "computed n.." << endl;
	cout << "f(a) = " << f(a) << " f(b) = " << f(b) << endl;
	cout << "a = " << a << " b = " << b 
		<< " eps = " << eps << " *n = " << (*n) << endl;
	long subintervals = *n;
	double h = (b - a) / double(subintervals);
	double sum = 0;
	long i;
	double x;
	for(i = 0, x = a; i <= subintervals-1; i++, x+=h) {
		sum += f(x);
	}	
	*lower_sum = sum * h;
	*upper_sum = *lower_sum + h * (f(b) - f(a));
	double LU = (*upper_sum + *lower_sum) / 2;
	return LU;
}

long
compute_n(double (*f)(double), double a, double b, double eps) 
{
	cout << "made it to compute_n" << endl;
	long n = (long )( ( f(a)-f(b) )*(b - a) / (2*eps) ) + 1;
	n = abs(n);
	cout << " n computed = " << n << endl;;
 	return n;
}

double
li(double t)
{
	if(t > 0) {
		return 1.0/log(t);
	}
	else {
		cout << "Error calculating li(" << t << ")" << endl;
		abort();
	}
}

double 
sine_ex(double x)
{
	double y;
	if (x == 0) {
		y = 1;
	}
	else {
		y = sin(x)/x;
	}
	//cout << "f(" << x << ") = " << y << endl;;
	return y; 
}

//longegrand of line longegral of ellipse
//after trig sub
double
ellipse_1(double theta)
{
	return .5*sqrt( 1 + 3*sin(theta)*sin(theta) );
}

double
magnetic_field_intensity(double l, double r, double x, double theta)
{
	double H = 
		( (4*l*r) / (r*r - x*x) ) 
			* sqrt( 1 - (x/r)*(x/r)*sin(theta)*sin(theta) );
	return H;
}

double
ellipse_2(double theta)
{
	double current = 15.3; 
	double loop_radius = 120;
	double x = 84;
	return magnetic_field_intensity(current, loop_radius, x, theta);
}

void
display_results(double LU, double a, double b, double eps, 
		long n, double lower_sum, double upper_sum) 
{
	cout << "The value of n after function call is : " << n << endl;
	cout << "lower_sum = " << lower_sum << endl;
	cout << "upper_sum = " << upper_sum << endl;
	cout << "LU = " << LU << endl;

}


int
main()
{
	double a = 0; double b = 1; 
	double eps = .5 * pow(10., -5.); //for 5 decimals of accuracy LU = .946097
	//long n = 800; // LU = .9468
	long n = 0;
	double lower_sum, upper_sum;
	cout << "computing Si(200)" << endl;
	double LU = LUSumsDecr(sine_ex, a, b, eps, &n, &lower_sum, &upper_sum);

	display_results(LU, a, b, eps, n, lower_sum, upper_sum);
	
	n = 0;
	a = 2; b=200;
	eps = .5 * pow(10, -4);
	cout << fixed << setprecision(12);
	// remarkably, due to the scale of h*(f(a) - f(b))
	// n is the same for both si(x) and li(x)
	// this is a form of quadrature: the process of fitting a rectangle
	// to the area under a curve
	cout << "computing li(200)" << endl;
	double LU2 = LUSumsDecr(li, a, b, eps, &n, &lower_sum, &upper_sum);
	
	display_results(LU2, a, b, eps, n, lower_sum, upper_sum);

	//elliptic longegrals
	n = 0;
	a = 0; b = M_PI_2; //pi/2
	//let's make eps smaller
	eps = .5 * pow(10, -7);
	cout << "a = " << a << endl;
	//computing perimeter of y^2 + 4*x*2 = 1, after trig sub
	double LU3 = LUSumsIncr(ellipse_1, a, b, eps, &n, &lower_sum, &upper_sum);
	
	display_results(LU3, a, b, eps, n, lower_sum, upper_sum);

	cout << "The circumference of the first ellipse is ~ " << 4*LU3 << endl;

	eps = .5 * pow(10, -10);
	n = 0;
	
	double LU4 = LUSumsDecr(ellipse_2, a, b, eps, &n, &lower_sum, &upper_sum);
	
	display_results(LU4, a, b, eps, n, lower_sum, upper_sum);

	
	cout << "The magnetic field intensity is ~ " << LU4 << endl;

	return 0;
}
