#include <iostream>
using namespace std;
/*
	Does what it sounds like, search beginning with 2nd element and place the element in it's correct position by searching through the previously built list
	invariant: after the kth search, the first k elements are sorted
	correctness: the algorithm performs size of a searches, so the array must be sorted by the end
*/
void insertionSort(int a[], int size);
void print(const int a[], int iMin, int iMax);

int main() {
	const int SIZE = 8;
	int a[SIZE] = {8, 4, 5, 3, 2, 9, 4, 1};
	
	print(a, 0, SIZE - 1);
	cout << endl;
	insertionSort(a, SIZE);
	print(a, 0, SIZE - 1);
	cout << endl;
}
//complexity = O(n^2) geometric
void insertionSort(int a[], int size) {
	int temp;
	//choose an element
	for (int i = 1; i < size; ++i) {

		print(a, 0, i - 1);
		print(a, i, size - 1);
		cout << endl;
		// search the previous elements
		for (int prev = 0; prev < i; ++prev) {
			// put in proper position
			if (a[i] < a[prev]) {
				temp = a[i];
				for (int shift = i; shift > prev; --shift) {
					a[shift] = a[shift-1];
				} 
				a[prev] = temp;
				break;
			}
		}
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
