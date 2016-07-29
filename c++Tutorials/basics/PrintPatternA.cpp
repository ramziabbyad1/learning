
#include <iostream>
using namespace std;

int main() {
	for(int i = 0; i < 5; i++) {
		if(i % 2 == 0) cout << "*****" << endl;
		else	
			cout << " *****" << endl;
		
	}
	cout << "* * * * * \n" 
	<< " * * * * *\n" 
	<< "* * * * * \n"
	<< " * * * * *\n"
	<< "* * * * * \n" << endl; 
	return 0;
}