#include <iostream>
#include <string>

using namespace std;

int getVariant(string surname) {
	return surname.length() % 2 + 1;
}


int main() {
	string surname;

	cout << "input your surname (english or translit)\n";
	cin >> surname;
	cout << "Your variant: " << getVariant(surname);

	return 0;
}