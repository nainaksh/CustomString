#include <iostream>
#include <stack>

using namespace std;

class Queue
{
public:
	int front, rear;
	int capacity;
	int *arr;

	Queue(int c):front(0), rear(0)
	{
		capacity = c;
		arr = new int[c];
	}

	~Queue()
	{
		delete[] arr;
	}

	void push(int val)
	{
		if (capacity == rear)
		{
			cout << "Queue is full";
			return;
		}
		arr[rear] = val;
		rear++;
	}

	void pop()
	{
		if (capacity == front)
		{
			cout << "Queue is empty";
		}

		for (int i = 0; i < (rear - 1); i++)
		{
			arr[i] = arr[i+1];
		}
		rear--;
	}

	void Display()
	{
		for (int i = front; i < rear; i++)
		{
			cout << arr[i]<<" ";
		}
	}

};

class Queue1
{
	stack<int> s1,s2;

public:
	Queue1(){}
	~Queue1(){}

	void push(int val)
	{
		s1.push(val);
	}

	void pop()
	{
		if (s1.empty() && s2.empty())
		{
			cout << "Empty Queue!!!";
			return;
		}

		while (s2.empty())
		{
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
		}

		s2.pop();
	}

	void Display()
	{
		stack<int> p = s1;
		while (!p.empty())
		{
			cout << p.top() << " ";
			p.pop();
		}
	}

};

int main6()
{
	Queue1 q;
	q.push(10);

	q.push(2);
	q.push(4);
	q.push(6);
	q.push(8);
	q.push(10);

	q.Display();
	cout << endl;
	q.pop();

	q.Display();

	int n;
	cin >> n;
	std::cin.get();
	return 0;
}
