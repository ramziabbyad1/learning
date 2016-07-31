#include <iostream>
using namespace std;

void selectionSort(int a[], int size);
void print(const int a[], int iMin, int iMax);

int main() {
	const int SIZE = 8;
	int a[SIZE] = {8, 4, 5, 3, 2, 9, 4, 1};
	
	print(a, 0, SIZE - 1);
	cout << endl;
	selectionSort(a, SIZE);
	print(a, 0, SIZE - 1);
	cout << endl;
}
/*
	invariant: on the kth pass, the first k elements of the array are sorted
	correctness: on the size pass, all elements are sorted
*/
void selectionSort(int a[], int size) {
	int temp;
	//leave room at end for searching
	for(int i = 0; i < size - 1; ++i) {
		print(a, 0, i - 1);
		print(a, i, size - 1);

		int minIndex = i;
		//search for smallest beginning at i
		for(int j = i + 1; j < size; ++j) {
			if (a[j] < a[minIndex]) minIndex = j;
		}
		if(minIndex != i) {
			int temp = a[minIndex];
			a[minIndex] = a[i];
			a[i] = temp;
		}

		cout << "=>";
		print(a, 0, i - 1);
		print(a, i, size - 1);
		cout << endl;
	}
}

void print(const int a[], int iMin, int iMax) {
	cout << "{";
	for(int i = iMin; i <= iMax; ++i) {
		cout << a[i];
		if(i < iMax) cout << ",";
	} 	
	cout << "} ";
}
