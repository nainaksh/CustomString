#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;
class MyString
{
	char* str;
	int length;

public:
	MyString() :str(nullptr),length(0)
	{
		cout << "Constrctor called"<<endl;
		str = new char[1];
		str[0] = '\0';
	}

	MyString(const char* p)
	{
		cout << "Parameterized constructor called" << endl;
		if (p == nullptr)
		{
			length = 0;
			str = new char[1];
			str[0] = '\0';
		}
		else
		{
			length = strlen(p);
			str = new char[length + 1];
			length = strlen(p);
			strcpy_s(str, length, p);
			str[length] = '\0';
		}
	}

	MyString(const MyString &p)
	{
		cout << "Copy Constrctor called" << endl;
		length = p.length;
		str = new char[length + 1];
		strcpy_s(str, length, p.str);
		str[length] = '\0';
	}

	MyString(MyString && p)
	{
		cout << "Move Constrctor called" << endl;
		length = p.length;
		str = p.str;
		p.length = 0;
		p.str = nullptr;
	}

	MyString& operator = ( MyString &p)
	{
		cout << "Assignment operator called" << endl;
		if (this != &p)
		{
			if (str)
			{
				delete[] str;
			}
			length = p.length;
			str = new char[length + 1];
			strcpy_s(str, length, p.str);
			str[length] = '\0';
		}
		return *this;
	}

	MyString& operator = (MyString &&p)
	{
		cout << "Move assignment operator called" << endl;
		if (this != &p)
		{
			if (str)
			{
				delete[] str;
			}
			length = p.length;
			str = p.str;
			
			p.length = 0;
			p.str = nullptr;
		}
		return *this;
	}

	int size()
	{
		return length;
	}

	MyString operator+(const MyString &p)
	{
		cout << "Plus operator called" << endl;
		MyString total;
		total.length = this->length + p.length;
		total.str = new char[total.length+1];
		strcpy_s(total.str, total.length, this->str);
		strcat_s(total.str, total.length, p.str);
		total.str[total.length] = '\0';
		return total;
	}

	~MyString()
	{
		delete[]str;
		str = nullptr;
	}

	void Print()
	{
		cout << str;
	}
};

int main4()
{
	MyString S1("Nayana");
	S1.Print();
	MyString S2;
	S2 = S1;
	S2.Print();

	MyString S3("Akash");
	S3.Print();

	MyString S4 = S3;
	S4.Print();

	MyString S5 = S2 + S4;
	S5.Print();

	MyString S6 = move(S1);
	S6.Print();

	MyString S7;
	S7 = move(S3);
	S7.Print();

	int n = 0;
	/*char* arr[2] = { "Even","Odd" };
	cout << "Enter No.";
    cin >> n;

	cout << arr[(n % 2)];*/


	cin >> n;
	//std::cin.get();
	return 0;

}