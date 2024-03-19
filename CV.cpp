#include<iostream>
#include<thread>
#include<condition_variable>
#include<mutex>

using namespace std;

int bal = 0;
mutex mtx;
condition_variable cv;

void addBalance(int x)
{
	unique_lock<mutex>lock(mtx);

	bal += x;
	cout << "Money added. Total balance is :" << bal << endl;

	cv.notify_one();
}

void debitBalance(int x)
{
	unique_lock<mutex>l(mtx);
	cv.wait(l, []() {return (bal != 0); });

	if (bal >= x)
	{
		bal -= x;
		cout << "Money withdraw. Total balance is :" << bal << endl;
	}
	else
	{
		cout << "Cannot withdraw!!" << endl;
	}
}

int main8()
{
	thread T1(debitBalance, 200);
	thread T2(addBalance, 300);

	T1.join();
	T2.join();

	cout << "Available balance is :" << bal << endl;

	int n;
	cin >> n;
	std::cin.get();

	return 0;
}