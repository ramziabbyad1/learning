#include <iostream>
using namespace std;
void printArray(const int[][3], int);

int
main()
{
	int myArray[][3] = {{8, 2, 4}, {7, 5, 2}};

	printArray(myArray, 2);
	return 0;
}

void printArray(const int array[][3], int rows) 
{
	for(int i = 0; i < rows; ++i) {
		for(int j = 0; j < 3; ++j) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}
