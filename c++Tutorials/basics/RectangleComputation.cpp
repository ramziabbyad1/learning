/*
 * Prompt user for the radius of a circle and compute its area and circumference
 * (CircleComputation.cpp)
 */
#include <iostream>
using namespace std;
 
int main() {
 
   int length, width;
   int area, perimeter;
   cout << "Enter the length width (separated by space): ";  // Prompting message
   cin >> length >> width;                 // Read input into variable radius
 
   // Compute area and perimeter
   area = length * width;
   circumference = 2.0 * length + 2.0 * width;
 
   // Print the results
   cout << "The area is: " << area << endl;
   cout << "The perimeter is: " << perimeter << endl;
 
   return 0;
}