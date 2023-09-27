#pragma once

class FooString {
	char* buf;
public:
	FooString(const char* tbuf);
	~FooString();

	void show();
	int length(); //вариант 1 - возвращает длину строки включая 0
};