#include <iostream>
using namespace std;

int main() {
	int firstInt;
	int secondInt;
	int sum, difference, product, quotient;
	cout << "Enter first second int(seperated by space): ";
	cin >> firstInt >> secondInt;

	sum = firstInt + secondInt;
	difference = firstInt -secondInt;
	product = firstInt*secondInt;
	quotient = firstInt/secondInt;

	cout << "The sum is: " << sum << endl;
	cout << "The difference is: " << difference << endl;
	cout << "The product is: " << product << endl;
	cout << "The quotient is: " << quotient << endl;

	return 0;
}