/* Print exercise patterns */
#include <iostream>
using namespace std;

int main() {
   for(int mult = 1; mult <= 9; ++mult) {
      for(int num = 1; num <= 9; ++num) {
         int prod = num * mult;
         if (prod < 10){
            cout << " " << prod << " ";
         }
         else {
            cout << prod << " ";
         }
      }
      cout << endl;
   }
   return 0;
}