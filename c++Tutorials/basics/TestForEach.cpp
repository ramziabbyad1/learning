#include <iostream>
using namespace std;

//foreach loops are only allowed in c++11,
//only compile using -std=c++0x or -std=c++11
int
main()
{
	int numbers[] = {11, 22, 33, 44, 55};
	
	for(int number : numbers) {
		cout << number << endl;
	}

	//you can modify in foreach!
	for(int &number: numbers) {
		number = 99;
	}

	for(int number: numbers) {
		cout << number << endl;
	}

	return 0;
}
