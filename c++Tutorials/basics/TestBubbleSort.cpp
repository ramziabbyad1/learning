#include <iostream>
using namespace std;

void print(const int a[], int size);
void displayArr(const int arr[], const int size);
void swap(int & a, int & b);
void bubbleSort(int arr[], const int size);
void bubbleSortFast(int arr[], const int size);

int main() {
	int a = -9, b = 4;
	cout << "Before swap a = " << a << " b = " << b << endl;
	swap(a, b);
	cout << "After swap a = " << a << " b = " << b << endl;
	int arr[] = {1,2,3,4, -1, 1, 0, -9, 3, 4, 2, -1, 5, -100, -75, 400, 2, 26, 55, -1000, -2000, -3000, -4000, -5000};
	int arr2[] = {1,2,3,4, -1, 1, 0, -9, 3, 4, 2, -1, 5, -100, -75, 400, 2, 26, 55, -1000, -2000, -3000, -4000, -5000};
	displayArr(arr,sizeof(arr)/sizeof(int));
	bubbleSort(arr, sizeof(arr)/sizeof(int));
	displayArr(arr,sizeof(arr)/sizeof(int));
	
	bubbleSortFast(arr2, sizeof(arr2)/sizeof(int));
	displayArr(arr2, sizeof(arr2)/sizeof(int));
}

void
displayArr(const int arr[], const int size) {
	for(int i = 0 ; i < size; ++i) {
		cout << arr[i] << " ";
	}	
	cout << endl;
}

//naive bubbleSort
void bubbleSort(int arr[], const int size) {
	int unsorted_index = size - 1;
	int i = 0;
	bool swapped = true;
	int count = 0;
	while( swapped ) {
		++count;
		swapped = false;
		for(int run = 0; run < size - 1 - i; ++run) {
			++count;
			if(arr[run] < arr[run+1]) {
				swap(arr[run], arr[run+1]);
				swapped = true;
			}
		}
		++i;
	}
	cout << "Slow count = " << count << endl;
}

//fast bubble sort
void bubbleSortFast(int arr[], const int size) {
	int unsorted_index = size - 1;
	int i = 0;
	int newn;
	int count = 0;
	bool sorted = true;
	while( unsorted_index > 0 && sorted) {
		++count;
		newn = 0;
		sorted = false;
		for(int run = 0; run < unsorted_index; ++run) {
			++count;
			if(arr[run] < arr[run+1]) {
				swap(arr[run], arr[run+1]);
				newn = run + 1; //write to newn to mark the last swap
				//all elems after last swap sorted 
				//use this to terminate the outter loop
				sorted = true;
			}
		}
		if (unsorted_index > newn)
			unsorted_index = newn;
		else
			unsorted_index--;
	}
	cout << "Fast count = " << count << endl;
}

void bubbleSortTut(int a[], int size) {
	bool done = false;
	int pass = 0;
	int temp;

	while(!done) {
		cout << "PASS " << ++pass << " ..." << endl; //trace

		for(int i = 0; i < size - 1; ++i) {
			if(a[i] > a[i+1]) {
				print(a, size);
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
				done = false;
				cout << "=> ";
				print(a, size);
				cout << endl;
			}
		}
	}
}

void print(const int a[], int size) {
	cout << "{";
	for(int i = 0; i < size; ++i) {
		cout << a[i];
		if(i < size - 1) cout << ",";
	}
	cout << "}";
}

void swap(int & a, int & b) {
	int  temp = a;
	a = b;
	b = temp;
}

