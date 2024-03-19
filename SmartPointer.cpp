#include<iostream>
#include<string_view>
using namespace std;

class myString
{
	char* str;

public:
	myString()
	{
		str = new char[1];
		str[0] = '/0';
	}

	myString(const char* s)
	{
		int size = strlen(s);
		str = new char[size + 1];
		strcpy_s(str, size, s);
	}

	myString(const myString& ss)
	{
		int size = strlen(ss.str);
		str = new char[size + 1];
		strcpy_s(str, size, ss.str);
	}
};

int main38()
{
	return 0;
}