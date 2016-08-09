#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>

using namespace std;

/*For the newton form*/
void coeff(int n, double *x, double *y, double *a) {
	for(int i = 0; i < n; ++i) {
		a[i] = y[i];
	}	

	for(int i = 1; i < n; ++i) {
		for(int j = n - 1; j >= i; --j) {
			a[j] = (a[j] - a[j-1]) / (x[j] - x[j-i]);
		}
	}
}

double eval(int n, double *a, double *x, double t) {
	double result = a[n];

	//use nested multiplication for complexity
	for(int i = n-1; i >= 0; --i) {
		result *= ( t - x[i] );
		result += a[i];
	}

	return result;
}

void init_eql_spc(int n, double low, double hi, double (*f)(double), 
	double *x, double *y) {

	double h = (hi - low) / (n-1);

	for(int i = 0; i < n; ++i) {
		x[i] = low + i*h;
		y[i] = f(x[i]);
	}
}

void print_abs_diff(int n, double *eval_result, double *y) {
	cout << "ABSOLUTE ERROR: " << endl;
	for(int i = 0; i < n; ++i) {
		cout << abs( y[i] - eval_result[i] ) << endl;
	}
}

void print_array(int n, string var, double *a) {
	cout << var << "[0]=" << a[0];
	for(int i = 1; i < n; ++i) {
		cout << "," << var << "[" << i << "]=" << a[i];  	
	}
	cout << endl;
}


int main() {

	/*
		Problem 4.1.1
	*/
	int n = 5;
	double *a =(double *)malloc(sizeof(double) * n);
	double *x =(double *)malloc(sizeof(double) * n);
	double *y =(double *)malloc(sizeof(double) * n);

	x[0] = 1.; x[1] = 2.; x[2] = 3.; x[3] = -4.; x[4] = 5.;
	y[0] = 2.; y[1] = 48.; y[2] = 272.; y[3] = 1182.; y[4] = 2262.;

	coeff(n, x, y, a);
	
	cout << "The newton coefficients are: ";
	print_array(n, "a", a);	
	cout << endl;

	// p(-1) = 12
	double result = eval(n, a, x, -1);

	cout << "p(-1) = " << result << endl;
	cout << endl;

	free(a); free(x); free(y);


	/*
		Problem 4.1.2
	*/

	int n2 = 11;
	double *a2 = (double *) malloc(sizeof(double) * n2);
	double *x2 = (double *) malloc(sizeof(double) * n2);
	double *y2 = (double *) malloc(sizeof(double) * n2);
	double low = 1, hi = 6;

	init_eql_spc(n2, low, hi, atan, x2, y2);

	cout << "x2 scale is: " << endl;
	print_array(n2, "x2", x2);
	cout << endl;
	cout << "atan(1:6) = ";
	print_array(n2, "y2", y2);
	cout << endl;

	coeff(n, x2, y2, a2);
	
	cout << "The Newton coefficients a2, are: ";
	print_array(n2, "a2", a2); //a2[5-10] = 0
	
	low = 0; hi = 8;	
	int eval_len = 33;
	double *eval_grid   = (double *) malloc(sizeof(double) * eval_len);
	double *eval_result = (double *) malloc(sizeof(double) * eval_len);
	double *eval_f = (double *) malloc(sizeof(double) * eval_len);
	init_eql_spc(eval_len, low, hi, atan, eval_grid, eval_f); 

	for(int i = 0; i < eval_len; ++i) {
		eval_result[i] = eval(n2, x2, a2, eval_grid[i]);
	}

	print_abs_diff(eval_len, eval_result, eval_f); //wildly inaccurate, especially past the interpolation boundary

	

	free(x2); free(y2); free(a2);
	free(eval_grid); free(eval_result); free(eval_f);

	/*
		Compare the 10th order polynomial interpolant to exp at 100 equally spaced points in [0,2]
	*/
	int n3 = 10;
	double *x3   = (double *) malloc(sizeof(double) * n3);
	double *y3 = (double *) malloc(sizeof(double) * n3);
	double *a3 = (double *) malloc(sizeof(double) * n3);
	low = 0; hi = 2;
	
	cout << "Init eql spc" << endl;	
	init_eql_spc(n3, low, hi, exp, x3, y3);

	cout << "x3 scale is: " << endl;
	print_array(n3, "x3", x3);
	cout << endl;
	cout << "exp(1:10) = ";
	print_array(n3, "y3", y3);
	cout << endl;
	coeff(n3, x3, y3, a3);

	eval_len = 100;
	double *eval_grid3   = (double *) malloc(sizeof(double) * eval_len);
	double *eval_result3 = (double *) malloc(sizeof(double) * eval_len);
	double *eval_f3 = (double *) malloc(sizeof(double) * eval_len);
	init_eql_spc(n3, low, hi, exp, eval_grid3, eval_f3);

	for(int i = 0; i < eval_len; ++i) {
		eval_result3[i] = eval(n3, x3, a3, eval_grid3[i]);
	}

	print_abs_diff(eval_len, eval_result3, eval_f3); //wildly inaccurate, especially past the interpolation boundary

	free(x3); free(y3); free(a3);
	free(eval_grid3); free(eval_result3); free(eval_f3);

	return 0;
}
