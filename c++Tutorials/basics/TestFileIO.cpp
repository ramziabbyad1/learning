/*
	Read from input file output average to output file
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;
const char *FILE_IN = "in.txt";//note string doesn't re
const char *FILE_OUT = "out.txt";//note string doesn't re
int main() {
	ifstream fin; //input file stream
	ofstream fout;

	fin.open(FILE_IN);
	if (!fin.is_open()) {
		cerr << "error: open input file failed" << endl;
		abort();
	}

	int sum = 0, number, count = 0;
	while (!(fin.eof())) {
		fin >> number; //read space-delimited
		sum += number;
		++count;
	}
	double average = double(sum) / count;
	cout << "Count = " << count << " average = " << average << endl;
	fin.close();

	fout.open(FILE_OUT);
	if (!fout.is_open()) {
		cerr << "error: open file failed" << endl;
		abort();
	}
	fout << average;
	fout.close();
	return 0;
}

