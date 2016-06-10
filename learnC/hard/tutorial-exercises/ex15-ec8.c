#include <stdio.h>

int
main(int argc, char *argv[])
{
	//pointer and ref
	int n = -400;
	int *x = &n;
	printf("x = %d, n = %d\n", *x, n);	

	//double indirection
	double y = -14.20345;
	double *z = &y;
	double **m = &z;
	printf("y = %f, m = %f\n", y, **m);	

	return 0;
}
