#pragma once

class FooString {
	char* buf;
public:
	FooString(const char* tbuf);
	~FooString();

	void show();
	int length(); //������� 1 - ���������� ����� ������ ������� 0
};