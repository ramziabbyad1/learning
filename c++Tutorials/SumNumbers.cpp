/*
 * Sum from 1 to a given upperbound and compute their average (SumNumbers.cpp)
 */
#include <iostream>
using namespace std;
 
int main() {
   int sum = 0;     // Store the accumulated sum
   int upperbound;
   cout << "Enter the upperbound: ";
   cin >> upperbound;
 
   // Sum from 1 to the upperbound
   for (int number = 1; number <= upperbound; ++number) {
      sum += number;
   }
   cout << "Sum is " << sum << endl;
   cout << "Average is " << (double)sum / upperbound << endl;
 
   // Sum only the odd numbers
   int count = 0;     // counts of odd numbers
   sum = 0;           // reset sum
   for (int number=1; number <= upperbound; number=number+2) {
      ++count;
      sum += number;
   }
   cout << "Sum of odd numbers is " << sum << endl;
   cout << "Average is " << (double)sum / count << endl;
}