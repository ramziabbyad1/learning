//  Numerical Methods II, Spring 2012, Courant Institute

//  Jonathan Goodman, goodman@cims.nyu.edu, started February, 2012  (Enter your own data here)

//  C++ code for Assignment 3,

//  The header file heat.h

//   Documentation of these routines is in the source files


int vtkWriter( double u[], int nx, int ny);

int ellipticSolver( double u[], int nx, int ny, double Lx, double Ly, double a, double b, int numIterations, double Dmax);

int interpolation( double u[], int nx, int ny);

int NewtonSolver( double u[], int nx, int ny);


