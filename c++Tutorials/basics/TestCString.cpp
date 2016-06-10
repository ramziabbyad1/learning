#include <iostream>
using namespace std;

int
main()
{
	char msg[256];

	cout << "Enter a message (with space)" << endl;
	cin.getline(msg, 256); //read up to 255 characters
	cout << msg << endl;

	for(int i = 0; msg[i] != '\0'; ++i) {
		cout << msg[i];
	}
	cout << endl;

	cout << "Enter a word (without space)" << endl;
	cin >> msg;
	cout << msg << endl;

	for(int i = 0; msg[i] != '\0'; ++i) {
		cout << msg[i];
	}
	cout << endl;

	return 0;
}
