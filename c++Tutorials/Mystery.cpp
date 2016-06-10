/* A mystery series (Mystery.cpp) */
#include <iostream>
using namespace std;
 /*
   if (number + 1) % 3 == 0 it initiates the following arithmetic sequence
   +5
   +4
   -1
   -2
   Upon closer inspection, the algorithm prints all 2<= numbers <= 131 s.t. numbers % 3 != 0
   The interesting thing, is it does this iteratively. How?
   it jumps forward twice and backwards twice, missing the multiple of three in between.
   if (number + 1) % 3 == 0
   => (number + 5)   = 1 (mod 3)
      (number + 9)   = 2 (mod 3)
      (number + 8)   = 1 (mod 3)
      (number + 6)   = 2 (mod 3)
      (number + 11)  = 1 (mod 3)
      etc..
 */
int main() {
   int number = 1;
   while (true) {
      ++number;
      if ((number % 3) == 0) continue;
      if (number == 133) break;
      if ((number % 2) == 0) {
         number += 3;
      } else {
         number -= 3;
      }
      cout << number << " ";
   }
   cout << endl;
   return 0;
}