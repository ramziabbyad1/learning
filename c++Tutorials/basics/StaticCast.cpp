#include <iostream>
using namespace std;

int main()
{
	double d = 5.5;
	int i = static_cast<int>(d);
	float f = static_cast<float>(i);
	long l = static_cast<long>(d);
	cout << "static_cast<int>(" << d <<") = " << i <<endl;
	cout << "static_cast<float>(" << i <<") = " << f <<endl;
	cout << "static_cast<long>(" << d <<") = " << l <<endl;
}
