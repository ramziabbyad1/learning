/*
 * Sum harmonics Series (HarmonicSeriesSum.cpp)
 */
#include <iostream>
using namespace std;
 
int main() {
   long maxDenominator;  // max denominator to sum to
   double sum = 0.0;    // For accumulating sum in double

   // Prompt user for the maxDenominator
   cout << "Max denom N = ";
   cin >> maxDenominator;
 
   long denominator = 1;
   while (denominator <= maxDenominator) {
      // Beware that int/int gives int
      sum = sum + 1.0/denominator;
      ++denominator;  // next
   }
   // Print the sum
   cout << "N = " << maxDenominator << endl;
   cout << "harmonic sum = " << sum << endl;
}