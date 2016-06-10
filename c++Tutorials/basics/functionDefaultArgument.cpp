#include <iostream>
using namespace std;

int fun1(int = 1, int = 2, int = 3);
int fun2(int, int, int = 3);

int main() {
	cout << fun1(4,5,6) << endl;
	cout << fun1(4, 5) << endl;
	cout << fun1(4) << endl;
	cout << fun1() << endl;

	cout << fun2(4,5,6) << endl;
	cout << fun2(4,5) << endl;
	//cout << fun2(4) << endl;

	return 0;
}

int fun1(int n1, int n2, int n3) {
	return n1 + n2 + n3;
}

int fun2(int n1, int n2, int n3) {
	return n1 + n2 + n3;
}
