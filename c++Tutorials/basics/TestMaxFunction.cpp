#include <iostream>
using namespace std;

int maximum(int, int);

int
main()
{
	cout << maximum(5, 8) << endl;
	int a = 6, b = 9, c;
	c = maximum(a, b);
	cout << c << endl;

	cout << maximum(c, 99) << endl;
}

int
maximum(int a, int b)
{
	return a >= b ? a : b;
}
