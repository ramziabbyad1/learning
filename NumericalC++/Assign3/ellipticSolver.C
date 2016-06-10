//  Numerical Methods II, Spring 2012, Courant Institute

//  Jonathan Goodman, goodman@cims.nyu.edu, started February, 2012  (Enter your own data here)

//  C++ code for Assignment 3,

//  Source file ellipticSolver.C.  Solve the elliptic PDE for assignment 3.



using namespace std;

#include <iostream>
#include "heat.h"

#define D(u) (a + b*(u))                       // A macro that gives the diffusion coefficient


int ellipticSolver( double u[],                // The array containing the solution.  Allocated outside, contains initial...
                                               // ...guess on arrival.
                    int    nx,                 // The number of mesh points in the x direction
                    int    ny, 
                    double Lx,                 // The size of the box in the x direction, the width
                    double Ly, 
                    double a,                  // Diffusion coefficient is a + b*u
                    double b, 
                    int    numIterations,      // Return after numIterations iterations.
                    double Dmax  ){            // The largest diffusion coefficient in the problem.
                    
   cout << "Hello from elliptic solver" << endl;
   
   int ix, iy;                        // indices into the array 
   int pixiy,                         // pointer into the u array for the present cell.  pixiy = nx*iy + ix
       pixm1, pixp1, piym1, piyp1;    // pointers into the array for the value (ix-1,iy), (ix+1,iy), etc.
   double fxl, fxr, fyb, fyt;         // Fluxes on the boundary edges of a cell, fxl = x-flux on the left, etc.
   double du, ub;                     // The derivative of u normal to a cell, the average of u across a cell edge ub = uBar
   double dx, dy;                     // Dimensions of a cell.  dx = x spacing, dy = y spacing.
   dx = Lx/( (double) nx );
   dy = Ly/( (double) ny );
   
   double epsilon = 1./(  (2.*Dmax/dx) + (2.*Dmax/dy)  ); // How much flux to add in one iteration
   
   for (int iteration = 0; iteration < numIterations; iteration++) {     // The outer loop over iterations
   
      for (iy = 1; iy <= ny; iy++){                                      // The outer loop in y, skip the ghost cells
      
         pixiy = nx*iy;                //  The first index on this row is ix = 0, iy
         pixm1 = pixiy - 1;            //  The x variable moves faster.  x neighbors are actal neighbors 
         pixp1 = pixiy + 1;
         piym1 = pixiy - nx;           //  The rows above and below are offset by nx
         piyp1 = pixiy + nx;
         
         for ( ix = 0; ix < nx; ix++) {
            
            if ( ix != 0 ) {                                   // The flux in the x direction for the left cell edge
               du = ( u[pixiy] - u[pixm1] ) / dx;
               ub = .5*( u[pixm1] + u[pixiy] );
               fxl = -D(ub)*du;
              }
            else
               fxl = 0.;                                       // Neumann (zero flux) boundary condition at the left edge of the domain
               
            if ( ix != (nx-1) ) {                              // The flux in the x direction for the right cell edge
               du = ( u[pixp1] - u[pixiy] ) / dx;
               ub = .5*( u[pixp1] + u[pixiy] );
               fxr = -D(ub)*du;
              }
            else
               fxr = 0.;                                       // Neumann (zero flux) boundary condition at the right edge of the domain
               
            du = ( u[pixiy] - u[piym1] ) / dy;                 // The flux in the y direction for the botom cell edge
            ub = .5*( u[piym1] + u[pixiy] );
            fyb = -D(ub)*du;
            
            du = ( u[piyp1] - u[pixiy] ) / dy;                 // The flux in the y direction for the top cell edge
            ub = .5*( u[piyp1] + u[pixiy] );
            fyt = -D(ub)*du;
                        
            u[pixiy] += epsilon*( fxl - fxr + fyb - fyt);      //  Use the fluxes to update the cell value
            
            pixiy++;                                           //  Update the pointers when you're done with this cell
            pixp1++;                                           //  We did not use pixp1 on the right edge ...
            pixm1++;                                           //  ... so it's OK that it pointed to a bad place.
            piyp1++;
            piym1++;
            
           }  // end of the ix loop
                      
        }     // end of the iy loop
     }        // end of the iteration loop
         
   
   return 0;
  }