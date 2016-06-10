#include <iostream>
using namespace std;

void fun(int, int, int);
void fun(double, int);
void fun(int, double);

extern "C" void fun(int, int, int, int);

int main() {
	fun(1,2,3);
	fun(1.0, 2);
	fun(1, 2.0);
	fun(1.1, 2, 3);

	fun(1,2,3,4) ;// no matching fun
//	fun(1,2,3,4) // no matching fun
//	fun(1, 2); // fun(int, int) ambiguous
//	fun(1.0, 2.0); //fun(double, dobule)  error ambiguous
}

void fun(int n1, int n2, int n3) {
	cout << "version 1" << endl;
}

void fun(double n1, int n2) {
	cout << " version 2" << endl;
}

void fun(int n1, double n2) {
	cout << "version 3" << endl;
}

void fun(int n1, int n2, int n3, int n4) {
	cout << "version 4" << endl;
}
