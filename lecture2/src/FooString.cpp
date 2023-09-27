#include "FooString.h"

#include <iostream>

FooString::FooString(const char* tbuf) {
	buf = new char[strlen(tbuf) + 1];
	std::strcpy(buf, tbuf);
}

FooString::~FooString() {
	delete[] buf;
}

void FooString::show() {
	std::cout << buf << "\n";
}

int FooString::length() {
	return strlen(buf);
}