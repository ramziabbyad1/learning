//  Numerical Methods II, Spring 2012, Courant Institute

//  Jonathan Goodman, goodman@cims.nyu.edu, started February, 2012  (Enter your own data here)

//  C++ code for Assignment 3,

//  Source file main.C, the main() for the main executable



using namespace std;

#include <iostream>
#include "heat.h"
#include "visit_writer.h"                 //   Header file for the plot program VisIt


int vtkWriter( double u[], int nx, int ny){

   cout << "vtk says Hello" << endl;
   
   int nz        = 1;                      // For a 2D plot
   int dims[3]   = { nx, ny, nz };         // The number of mesh points in each direction
   int vardim[1] = { 1 };                  // The number of fields being plotted
   
   int NumberOfCells = nx*ny;              // Assume ny here includes ghost cells, so it my be ny+2 from outside
   float *us;                              // An array of the same dimensions as u but single precision
   try  {                                  // Array allocation in a try/catch block to catch allocation failure
      us = new( float[NumberOfCells] );
     }
   catch (bad_alloc&)  {
      cout << "vtkWriter could not allocate u.  NumberOfCells = " << NumberOfCells << endl;
      return(1);                            //  Report failure and quit
     }

   for ( int i = 0; i < NumberOfCells; i++)
      us[i] = (float) u[i];                 //  Cast the double precision variable to single precision
   
   float *data[1] = { us };
   int centering[1] = { 1 };
   const char *varnames[1] = { "Temperature" };
   write_regular_mesh("TemperatureField", 0, dims, 1, vardim, centering, varnames, data);
   
  }