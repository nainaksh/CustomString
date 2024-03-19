#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

mutex m;

class Base
{
public:
	void fun(int x);
	static void fun1(int x);

	void operator ()(int x)
	{
		while (x-->0)
			cout << "Functor value:" << x << endl;
	}
};

void Base::fun1(int x)
{
	while (x-->0)
		cout << "Static fun value:" << x << endl;
}

void Base::fun(int x)
{
	while(x-->0)
		cout << "Base class value:" << x << endl;
}

void fun2(int x)
{
	std::unique_lock<mutex> lock(m, defer_lock);
	lock.lock();
	while (x-->0)
		cout << "Global fun value:" << x << endl;
}


int main7()
{
	//global function
	thread T1(fun2, 20);

	//static member function
	thread T2(&Base::fun1, 6);

	//class member fucntion
	Base bb;
	thread T3(&Base::fun, bb, 6);

	//functor
	thread T4(Base(), 3);

	//lamda function
	thread T5([](int x) {
		m.lock();
		while (x--> 0)
		{
			cout << "Base class value:" << x << endl;
		}
		m.unlock();
	},10);

	T1.join();
	T5.join();
	
	int n;
	cin >> n;
	std::cin.get();

	return 0;
}
