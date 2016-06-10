/*
 * Test arithmetic operations (TestArithmetics.cpp)
 */
#include <iostream>
using namespace std;
 
int main() {
 
   int number1, number2, number3;  // Declare 2 integer variable number1 and number2
   int sum, difference, product, quotient, remainder;  // declare 5 int variables
 
   // Prompt user for the two numbers
   cout << "Enter three integers (separated by space): ";
   cin >> number1 >> number2 >> number3;
 
   // Do arithmetic Operations
   sum = number1 + number2 + number3;
   difference = number1 - number2;
   product = number1 * number2 * number3;
   quotient = number1 / number2;
   remainder = number1 % number2;
 
   cout << "The sum, difference, product, quotient and remainder of "
        << number1 << " and " << number2 << " are "
        << sum << ", "
        << difference << ", "
        << product << ", "
        << quotient << ", and "
        << remainder << endl;
 
   // Increment and Decrement
   ++number1;    // Increment the value stored in variable number1 by 1
                 // same as "number1 = number1 + 1"
   --number2;    // Decrement the value stored in variable number2 by 1
                 // same as "number2 = number2 - 1"
   cout << "number1 after increment is " << number1 << endl;
   cout << "number2 after decrement is " << number2 << endl;
 
   quotient = number1 / number2;
   cout << "The new quotient of " << number1 << " and " << number2
        << " is " << quotient << endl;

  cout << "31 * number1 + 17 * number2 + 87 * number3 = " << 31 * number1 + 17 * number2 + 87 * number3 << endl;
 
   return 0;
}