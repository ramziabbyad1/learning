#include <iostream>
#include <string>
using namespace std;

//more string IO fun
int
main()
{
	string message("Bonjour");
	cout << message << endl;

	cout << "Enter a number,";
	cout << " and one multiple of that number (w/ space)";

	//this works..	
	int first_num, second_num;
	cin >> first_num >> second_num;
	cout << "first num = " << first_num 
			<< " second_num = " << second_num
			<< endl;

	/*
	this fails, as getline expects a string
	int second_num;
	getline(cin, second_num); 
	cout << "second num = " << second_num << endl;
	*/

}
