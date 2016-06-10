#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/*
	Note, although we set input width here, this is not applied to any whitespace at the beginning of each part of the phone string.
	Hence, ( 512)  327-   6372, will produce the desired output
*/
int
main()
{
	string areaCode, phoneCode;
	string inStr;

	cout << "Enter your phone number in this form (xxx)xxx-xxxx : " ;
	cin.ignore(); // skip (
	cin >> setw(3) >> areaCode; //read 3 chars from stdin
	cout << "area code = " << areaCode << endl;
	cin.ignore(); //skip )
	cin >> setw(3) >> phoneCode;
	cout << "phone code = " << phoneCode << endl;
	cin.ignore(); //skip -
	cin >> setw(4) >> inStr;
	cout << "last 4 code = " << inStr << endl;
	phoneCode += inStr; //concat

	cout<< "Phone number is (" << areaCode << ")"
		<< phoneCode.substr(0,3) << "-"
		<< phoneCode.substr(3,4) << endl;

	return 0;
	
}
