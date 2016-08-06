#include <iostream>
using namespace std;

enum Color {
	RED, GREEN, BLUE
} myColor;

enum DeckOfCard {
	SPADE, DIAMOND, CLUB, HEART
}

int main() {
	myColor = RED;
	cout << "myColor = " << myColor << endl;
	Color yourColor;
	yourColor = GREEN;
	cout << "yourColor = " << yourColor << endl;
}
