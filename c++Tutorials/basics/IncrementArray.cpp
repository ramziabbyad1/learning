#include <iostream>
using namespace std;

void inc(int array[], int size);
void  print(int array[], int size);
/* Arrays are passed by reference to economize on large copy routines*/
int main() {
	int a1[] = {8,4,5,3,2};
	
	print(a1, 5);
	inc(a1, 5);
	print(a1, 5);
}

void inc(int array[], int size) {
	for(int i = 0; i < size; ++i) {
		array[i]++; // side effect
	}
}

void print(int array[], int size) {
	cout << "{";
	for(int i = 0; i < size; ++i) {
		cout << array[i];
		if(i < size - 1) {
			cout << ",";
		}
	}
	cout << "}" << endl;
}
