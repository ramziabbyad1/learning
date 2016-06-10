#include <iostream>
using namespace std;

/*
	Take note, c++ leaves values undefined after array declaration (garbage).
*/
int
main()
{
	//some array declarations..
	int marks[5];
	double numbers[10];
	const int SIZE = 9;
	float temps[SIZE];
	
	//some compilers support variable size array declaration
	int size;
	cout << "Enter length of the array: ";
	cin >> size;
	float values[size];

	cout << "Size of values[" 
		<< size << "] = " << sizeof(values)/sizeof(int) << endl; 
	for(int i = 0; i < size; i++)
		cout << "values[" << i << "] = " << values[i] << endl; //garbage

	int numbers2[3] = {11, 33, 44};
	int numbers3[] = {11, 33, 44};
	int numbers4[5] = {11, 33, 44}; // remaining elems zero
	//int numbers5[2] = {11, 33, 44}; // compiler error

	int numbers5[5] = {0}; // all elems 0
	int numbers6[5] = {}; // all elems 0

	for(int i = 0; i < 5; i++) {
		if( i < sizeof(numbers2)/sizeof(int) )
			cout << "numbers2[" << i << "] = " << numbers2[i] << endl;
		if( i < sizeof(numbers3)/sizeof(int) )
			cout << "numbers3[" << i << "] = " << numbers3[i] << endl;
		if( i < sizeof(numbers4)/sizeof(int) )
			cout << "numbers4[" << i << "] = " << numbers4[i] << endl;
		if( i < sizeof(numbers5)/sizeof(int) )
			cout << "numbers5[" << i << "] = " << numbers5[i] << endl;
		if( i < sizeof(numbers6)/sizeof(int) )
			cout << "numbers6[" << i << "] = " << numbers6[i] << endl;
	}	

	int const SIZE2 = 5;
	int a1[SIZE2];
	for(int i = 0; i < SIZE2; ++i) cout << a1[i] << " ";
	cout << endl;

	int a2[SIZE2] = {21, 22, 23, 24, 25};
	for(int i = 0; i < SIZE2; ++i) cout << a2[i] << " ";

	int a3[] = {31, 32, 33, 34, 35};
	int a3Size = sizeof(a3) / sizeof(int);
	cout << "Size is " << a3Size << endl;
	for(int i = 0; i < a3Size; ++i) cout << a3[i] << " ";
	cout << endl;

	int a4[SIZE2] = {41, 42};
	for(int i = 0; i < SIZE2; ++i) cout << a4[i] << " ";
	cout << endl;

	int a5[SIZE2] = {0};
	for(int i = 0; i < SIZE2; ++i) cout << a5[i] << " ";
	cout << endl;

	int a6[SIZE2] = {};
	for(int i = 0; i < SIZE2; ++i) cout << a6[i] << " ";
	cout << endl;

	cout << "Out of bound example" << endl;
	const int sz = 5;
	int nums[sz];

	numbers[88] = 999;
	cout << numbers[77] << endl;

	return 0;
}
