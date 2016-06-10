/*
 * Prompt user for the radius of a circle and compute its area and circumference
 * (CircleComputation.cpp)
 */
#include <iostream>
using namespace std;
 
int main() {
   double radius, height, volume, area; // Declare 3 floating-point variables
   const double PI = 3.14159265;       // Declare and define PI
 
   cout << "Enter the radius height (separated by space): ";  // Prompting message
   cin >> radius >> height;                 // Read input into variable radius
 
   // Compute area and circumference
   area = 2.0 * radius * radius * PI + 2.0 * height * radius * PI;
   volume = height * radius * radius * PI;
 
   // Print the results
   cout << "The radius is: " << radius << endl;
   cout << "The area is: " << area << endl;
   cout << "The volume is: " << volume << endl;
 
   return 0;
}