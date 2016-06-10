#include <iostream>
using namespace std;
//we do not alter any of these variables
int linearSearch(const int a[], const int size, const int key);

int main() {
	const int SIZE = 8;
	int a1[SIZE] = {8,4,5,3,2,9,4,1};

	cout << linearSearch(a1, SIZE, 8) << endl;
	cout << linearSearch(a1, SIZE, 4) << endl;
	cout << linearSearch(a1, SIZE, 99) << endl;
}
// you can leave the constants out here and the func prototype will be overridde//n
int linearSearch(const int a[], const int size, const int key) {
	//key = 4; //assign to read-only
	for(int i = 0; i < size; ++i) {
		if(a[i] == key) return i;
	}
	return size;
}
