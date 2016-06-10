#include <iostream>
#include <string>
#include <limits>
using namespace std;

int
main()
{
	//char msg[] = {'H', 'e', 'l', 'l', 'o', '\0'};
	//const char *msg2 = "Howdy";
	string message("Hello"); //defined under std namespace
	//string message('H'); //no
	//string message(msg2); //works
	//string message = msg; //this works too!
	//string message(msg); //this too
	//message(msg);
	cout << message << endl;
	cout << "numeric_limits from limits header" << endl;
	cout << "numeric_limits<streamsize>::max() = "
		 << numeric_limits<streamsize>::max() << endl;

	cout << "Enter a message (no space):";
	cin >> message;
	cout << message << endl;
	
	//if you don't flush cin, getline will read the previous line from what
	//hasn't been pulled out via >>
	//in other words, it gets the rest of cin
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Enter a message (with spaces): ";
	getline(cin, message);
	cout << message << endl;

	return 0;
	
}
