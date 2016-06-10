#include <iostream>
using namespace std;

int
main()
{
	int i1 = 2147483647; // max int..
	cout << "i1 = " << i1 << endl;
	cout << "i1 + 1 = " << i1 + 1 << endl;
	cout << "i1 + 2 = " << i1 + 2 << endl;
	cout << "i1 * 2 = " << i1 * 2 << endl;
	cout << "i1 * 3 = " << i1 * 3 << endl;
	cout << "i1 * i1 = " << i1 * i1 << endl;

	int i2 = -2147483648;
	cout << "i2 = " << i2 << endl;
	cout << "i2 - 1 = " << i2 - 1 << endl;
	cout << "i2 - 2 = " << i2 - 2 << endl;
	cout << "i2 * 2 = " << i2 * 2 << endl;
	cout << "i2 * 3 = " << i2 * 3 << endl;
	cout << "i2 * i2 = " << i2 * i2 << endl;
	return 0;
}
