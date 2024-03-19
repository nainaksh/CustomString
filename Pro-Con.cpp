#include<iostream>
#include<thread>
#include<condition_variable>
#include<mutex>
#include<deque>

using namespace std;

mutex mtx1;
condition_variable cv1;
std::deque<int>vec;
int Maxbuffer = 50;

void Producer(int x)
{
	while (x)
	{
		unique_lock<mutex>lck(mtx1);
		cv1.wait(lck, [=]() {return (vec.size() < Maxbuffer ); });
		vec.push_front(x);
		cout << "Produced:" << x << endl;
		x--;
		lck.unlock();
		cv1.notify_one();
	}
}

void Consumer()
{
	while (true)
	{
		unique_lock<mutex>lck(mtx1);
		cv1.wait(lck, []() {return (vec.size() > 0); });
		int y = vec.back();
		vec.pop_back();
		cout << "Consumed" << y << endl;
		lck.unlock();
		cv1.notify_one();
	}
}

int main9()
{
	thread T1(Producer, 100);
	thread T2(Consumer);

	T1.join();
	T2.join();
	
	int n;
	cin >> n;
	std::cin.get();

	return 0;
}