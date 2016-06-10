//  Numerical Methods II, Spring 2012, Courant Institute

//  Jonathan Goodman, goodman@cims.nyu.edu, started February, 2012  (Enter your own data here)

//  C++ code for Assignment 3,

//  Source file main.C, the main() for the main executable



using namespace std;

#include <iostream>
#include <math.h>
#include "heat.h"

//   Problem parameters

#define Lx 2.   /*   The width of the domain                      */
#define Ly 1.   /*   The height of the domain                     */

#define uTop 3. /*   The temperature at the top                   */
#define uBot .2 /*   The minimum temperature at the bottom        */
#define h    2.5 /*   The temperature fluctuation at the bottom    */

#define a  0.   /*   The parameters of the diffusion coefficient  */
#define b  1.   /*   The parameters of the diffusion coefficient  */

#define dx .02   /*   The grid box size, in the x direction        */
#define dy .02   /*   The grid box size, in the y direction        */



#define D(u) (a + b*(u)) 

int main(){

   cout << "Hello world" << endl;


   int     nx,  ny;                        // Tne number of cells in the x and y directions
   double dnx, dny;
   dnx = ((double) Lx)/((double) dx);      // The number of cells in the x direction, computed in floating point
   dny = ((double) Ly)/((double) dy);      // The number of cells in the y direction, computed in floating point
   nx  = (int) ( dnx + .5 );               // Round to the nearest integer: add .5 then round down
   ny  = (int) ( dny + .5 );
      
   int NumberOfCells = nx*( ny+2 );        // The total number of cells in the mesh, including a row of...
                                           // ...ghost cells on the top and bottom rows.
                                           

   double *u;                              // The grid values, to be allocated at run time
   try  {                                  // Array allocation in a try/catch block to catch allocation failure
      u = new( double[NumberOfCells] );
     }
   catch (bad_alloc&)  {
      cout << "Main could not allocate u.  NumberOfCells = " << NumberOfCells << endl;
      return(1);                           //  Report failure and quit
     }
   
   
//  Set the initial temperature distribution

   int ix, iy;                                    // Integer indices in the x and y directions
   
   double  uInt;                                  // The u value for a given row (y value)
   double duInt;                                  // The u value offset between different y value rows
   duInt = ( uTop - uBot ) / ( (double) (ny+1) ); // Use linear interpolation between uBot and uTop
   uInt = uBot;
   for ( iy = 0; iy < ny+2; iy++) {               // Fill in the rest of the u array, starting from the bottom row
      for ( ix = 0; ix < nx; ix++ )
         u[iy*nx + ix] = uInt;
      uInt += duInt;
     }
   
   double x = .5*dx;                              // dx/2 is the x coordinate of the first grid point
   for ( ix = 0; ix < nx; ix++ ){
      u[ix] = uBot + .5*h*( 1. + cos(M_PI*x) );   // The bottom boundary values
      x    += dx;
     }
      
     
          
//   Call the elliptic solver 

   int numIterations = 500000;
   double Dmax = D(uTop);                                   // The largest diffusion coefficient in the problem
   ellipticSolver( u, nx, ny, Lx, Ly, a, b, numIterations, Dmax);   
   
   
   vtkWriter( u, nx, ny+2);
   
  }