#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

//const int TOTAL_COUNT = 2000000; //2 mil close to INT_MAX convergence is nearly uniform
const int TOTAL_COUNT = 20000000; //convergence improves as TOTAL_COUNT -> INFINITY
const int NUM_FACES = 6;
int frequencies[6] = {0}; //0 array

int main() {
	srand(time(0)); //cstdlib and ctime

	for(int i = 0; i < TOTAL_COUNT; ++i) {
		++frequencies[rand() % 6];
	}

	cout << fixed << setprecision(2);
	for(int i = 0; i < NUM_FACES; i++) {
		cout << i + 1 << ": " << frequencies[i]
			 << " (" << 100.0 * frequencies[i] / TOTAL_COUNT << "%)" << endl;
	}
}
