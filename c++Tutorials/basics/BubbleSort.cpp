#include <iostream>
#include <string>
using namespace std;

void bubbleSort(int a[], int size);
void print(const int a[], int size, bool swapping);
void print_error(string error);
bool swap(int a[], int j, int k, int size);
void bubbleSortFaster(int a[], int size);

int main() {
	const int SIZE = 8;
	int a[] = {8, 4, 5, 3, 2, 9, 4, 1};
	int b[] = {8, 4, 5, 3, 2, 9, 4, 1};

	print(a, SIZE, false);
	cout << endl;
	bubbleSort(a, SIZE); //loops 56 times
	print(a, SIZE, false);
	cout << endl;

	print(b, SIZE, false);
	cout << endl;
	bubbleSortFaster(b, SIZE); //loops only 21 times!
	print(b, SIZE, false);
	cout << endl;
}

/*
	Bubble sort
	invariant: at the kth pass of the outter loop, the last k elements in the array are sorted
	correctness: when the algorithm terminates, it has passed through the array 	making no swaps, hence each pair of elements satisfies the order condition
	improvements: since the last k elements are already sorted, we can skip 
	them!
*/

void bubbleSort(int a[], int size) {
	bool done = false;
	int pass = 0;

	while(!done) {
		cout << "PASS " << ++pass << "..." << endl;  //trace
		done = true;
		//bounds must be 1 less size for correct swapping
		for(int i = 0; i < size - 1; ++i) {
			if(a[i] > a[i+1]) {
				print(a, size, true); //print before swap state
				bool success = swap(a, i, i+1, size);
				if(!success) {
					print_error("Swap fail!");
					break;
				}
				done = false;
				cout << "=> ";
				print(a, size, false); //print after swap state
				cout << endl;
			}
		}
	}
	cout << "complexity (slow): " << pass*(size-1) << " loop iterations!" << endl;
}

void bubbleSortFaster(int a[], int size) {
	bool done = false;
	int pass = 0;
	int complexity = 0;
	int last_swap_index = size - 1;
	while(!done) {
		cout << "PASS " << ++pass << "..." << endl;  //trace
		done = true;
		int loop_control = last_swap_index;
		for(int i = 0; i < loop_control; ++i) {
			if(a[i] > a[i+1]) {
				last_swap_index = i + 1;
				print(a, size, true); //print before swap state
				bool success = swap(a, i, i+1, size);
				if(!success) {
					print_error("Swap fail!");
					break;
				}
				done = false;
				cout << "=> ";
				print(a, size, false); //print after swap state
				cout << endl;
			}
		}
		cout << "last swap index = " << last_swap_index << endl;
		loop_control = last_swap_index;
		complexity += last_swap_index - 1;
	}
	cout << "complexity (fast): " << complexity << " loop iterations!" << endl;
}

void print_error(string error) {
	cout << error << endl;
}

bool swap(int a[], int j, int k, int size) {
	int temp;
	if(j < size && k < size){
		temp = a[j];
		a[j] = a[k];
		a[k] = temp;
		return true;
	}
	else {
		//wait for abort error passing
		return false;
	}
}

void print(const int a[], int size, bool swapping) {
	if (swapping) cout << "swapping ";
	cout << "{";
	for(int i = 0; i < size; ++i) {
		cout << a[i];
		if (i < size - 1) cout << ",";
	}
	cout << "} ";
}
