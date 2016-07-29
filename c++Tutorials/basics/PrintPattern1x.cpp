/* Print exercise patterns */
#include <iostream>
using namespace std;

void printA(int n) {
   for(int row = 0; row < n; ++row) {
      if(row % 2 == 0) {
         cout << " ";      
      }
      for(int col = 0; col < n; ++col) {
         if(col % 2 == 0) {
            cout << "# ";
         }
         else {
            cout << "* ";
         }
      }
      cout << endl;
   }
}

void printB(int size) {
   for(int row = 0; row < size; row++) {
      for(int col = 0; col < size - row; col++) {
         cout << "# ";
      }
      cout << endl;
   }
}

void printC(int size) {
   for(int row = 0; row < size; row++) {
      for(int col = 0; col < row; col++) {
         cout << "  ";
      }
      for(int col = row; col < size; col++) {
         cout << "# ";
      }
      cout << endl;
   }
}

//watch out for # of digits >= 2; size > 10
void printD(int size) {
   for(int row = 1; row <= size; ++row) {
      for(int col = row; col >= 1; --col) {
         cout << col << " ";
      }
      cout << endl;
   }
}

//watch out for # of digits >= 2; size > 10
void printE(int size) {
   for(int row = 1; row <= size; ++row) {
      for(int col = 1; col <= size - row; ++col) {
         cout << "  ";
      }
      for(int col = 1; col <= row; ++col) {
         cout << col << " ";
      }
      cout << endl;
   }
}

int main() {
   int size;
   char letter;
   cout << "Enter letter code, size to choose pattern and size: ";
   cin >> letter >> size;
   cout << endl;
   switch(letter) {
      case 'a':
         printA(size); break;
      case 'b':
         printB(size); break;
      case 'c':
         printC(size); break;
      case 'd':
         printD(size); break;
      case 'e':
         printE(size); break;
      default:
         cout << "Unknown letter code" << endl;
   }
   return 0;
}