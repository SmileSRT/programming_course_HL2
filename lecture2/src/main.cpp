#include "FooString.h"

#include <iostream>


bool checkLengthString(const char* testString, int correctAnswer) {
	FooString test(testString);
	if (test.length() != correctAnswer) {
		return false;
	}
	else {
		return true;
	}
}


int main() {
	FooString str("test string");
	str.show(); //test to show string

	//test to check string length
	if (checkLengthString("test", 4) && checkLengthString("te st", 5) && checkLengthString("  ", 2) && checkLengthString("", 0)) {
		std::cout << "tests passed\n";
	}
	else {
		std::cout << "tests failed\n";
		return 1;
	}

	return 0;
}