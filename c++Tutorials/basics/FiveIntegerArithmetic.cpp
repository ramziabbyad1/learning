#include <iostream>
using namespace std;

int main() {
	int integer1, integer2, integer3, integer4, integer5;
	int sum, product;
	cout << "Enter five ints (seperated by space): ";
	cin >> integer1 >> integer2 >> integer3 >> integer4 >> integer5;

	cout << "Enter five ints (seperated by space): ";
	cin >> integer1;
	cin >> integer2;
	cin >> integer3;
	cin >> integer4;
	cin >> integer5;

	sum = integer1+integer2+integer3+integer4+integer5;
	product = integer1*integer2*integer3*integer4*integer5;

	cout << "The sum is: " << sum << endl;
	cout << "The product is: " << product << endl;

	return 0;
}