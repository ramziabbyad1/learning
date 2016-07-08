double 
trap(double (*f)(double), double a, double b, long n) 
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
