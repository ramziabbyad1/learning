#include <iostream>
#include <cstdlib> //rand()/srand()
#include <ctime> //time()
using namespace std;

int main() {
	cout << "RAND_MAX is " << RAND_MAX << endl;

	//here you get same sequence due to lack of seeding the generator	
	for(int i = 0; i < 10; ++i) {
		cout << rand() % 100 << " ";
	}
	cout << endl;

	//seed random number generator with current time in ms
	srand(time(0));
	//different sequences will evolve over time due to the seeding
	for(int i = 0; i < 10; ++i) {
		cout << rand() % 100 << " ";
	}
	cout << endl;
}

