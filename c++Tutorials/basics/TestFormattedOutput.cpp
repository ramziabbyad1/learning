#include <iostream>
#include <iomanip>
using namespace std;

int
main()
{
	double pi = 3.14159265;
	cout << fixed << setprecision(4); //coming from iomanip gets 4 sig figs past decimal
	cout << pi << endl;
	cout << "|" << setw(8) << pi << "|" << setw(10) << pi << "|" << endl;
	
	cout << setfill('-');
	cout << "|" << setw(8) << pi << "|" << setw(10) << pi << "|" << endl;
	cout << scientific;
	cout << pi << endl;

	bool done = false;
	cout << done << endl; //1's and 0's
	cout << boolalpha; //true/false
	cout << done << endl;

	cout << "|" << pi << endl;

	return 0;
}
