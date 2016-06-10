#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int
main()
{
	string msg = "Hello World";
	cout << msg << endl;
	cout << msg.length() << endl;
	cout << msg.size() << endl;
	cout << msg.at(1) << endl;
	cout << msg[1] << endl;
	cout << msg.empty() << endl;
	cout << msg.substr(3, 3) << endl;

	cout << msg.replace(3, 3, "why") << endl;
	cout << msg.append("end") << endl;
	cout << msg + "end" << endl;
	cout << msg.insert(3, "insert") << endl;

	string msg1;
	cout << "Is msg1 empty before assign ? " << msg1.empty() << endl;
	msg1 = msg; //copy
	cout << msg1 << endl;
	cout << "Another way to copy..." << endl;	
	string msg2(msg1 + "aaa");
	cout << "msg2 = " << msg2 << endl;

	cout << "Comparing msg2 to msg1 = " << msg2.compare(msg1) << endl;
	cout << "Same compare using ==, <, >, and != " << endl;
	cout << boolalpha;
	cout << "== : " << (msg2 == msg1) << endl; 
	//sweet! not supposed to do it in java
	cout << "> : " << (msg2 > msg1) << endl;
	cout << "< : " << (msg2 < msg1) << endl;
	cout << "!= : " << (msg2 != msg1) << endl;
	cout << "Enter a line: ";
	getline(cin, msg);
	cout << msg << endl;

	//from algorithm
	string str("Hello World");
	replace(str.begin(), str.end(), 'l', '_');
	cout << str << endl;

	cout << "Another difference from java you can do ";
	cout << "str.at(2) = 'F' ..." << endl;
	str.at(2) = 'F';
	cout << "str = " << str << endl;
	cout << "Also, unlike java you can do str[3]='5'" << endl;
	str[3] = '5';
	cout << "str = " << str << endl;
	cout << "Conclusion: string's are mutable in c++" << endl;
	
}
