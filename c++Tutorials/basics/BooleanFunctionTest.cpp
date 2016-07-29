#include <iostream>
using namespace std;

//bool can be replaced by int and it compiles
bool isOdd(int);

int main() {
	cout << boolalpha; //print bool as true false
	cout << isOdd(5) << endl;
	cout << isOdd(6) << endl;
	cout << isOdd(-5) << endl;

}

bool isOdd(int number) {
	if(number % 2 != 0) {
		return true;
	}
	else {
		return false;
	}
}
