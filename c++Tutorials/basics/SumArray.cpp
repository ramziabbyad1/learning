#include <iostream>
using namespace std;

int sum(int array[], int size);
void print(int array[], int size);

int main() {
	int a1[] = {8, 4, 5, 3, 2};
	print(a1, 5);
	cout << "sum is " << sum(a1, 5) << endl;
}

int sum(int array[], int size) {
	int sum = 0;
	for(int i = 0; i < size; ++i) {
		sum += array[i];
	}
	return sum;
}

void print(int array[], int size) {
	cout << "{";
	for(int i = 0; i < size; i++) {
		cout << array[i];
		if( i < size - 1) {
			cout << ",";
		}
	}
	cout << "}" << endl;
}
