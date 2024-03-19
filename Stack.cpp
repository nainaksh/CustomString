#include <iostream>
#include<queue>
using namespace std;

#define MAX 1000
class Stack
{
public:
	int arr[MAX];
	int N;

	Stack():N(-1)
	{
	}

	void push(int a)
	{
		if (N > MAX - 1)
		{
			cout<< "stack is full";
			return;
		}
		arr[++N] = a;
	}

	void pop()
	{
		arr[--N];
	}

	int top()
	{
		return arr[N];
	}

	int size()
	{
		return N;
	}

	bool isEmpty()
	{
		return (N < 0);
	}

};

class Stack1
{
	queue<int> q1, q2;
	int N;

public:
	Stack1()
	{
		N = 0;
	}

	void push(int a)
	{
		q2.push(a);
		N++;
		while (!q1.empty())
		{
			q2.push(q1.front());
			q1.pop();
		}

		queue<int>temp = q1;
		q1 = q2;
		q2 = temp;
	}

	void pop()
	{
		q1.pop();
		N--;
	}

	int top()
	{
		return q1.front();
	}

	int size()
	{
		return N;
	}
};


void PrintElements(Stack S1)
{
	if(S1.isEmpty())
	{
		return;
	}

	int x = S1.arr[S1.N];
	S1.pop();

	cout << x << ' ';

	PrintElements(S1);

	cout << endl;
}

void PrintElements1(Stack1 S1)
{
	if (S1.size() < 0)
	{
		return;
	}

	while (S1.size() > 0)
	{
		cout << S1.top() << " ";
		S1.pop();
	}
	cout << endl;
}


int main18()
{
	class Stack1 s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	//print all elements in stack :
	cout << "Elements present in stack : " << endl;
	PrintElements1(s);

	cout << "top Element stack : " << s.top() << endl;

	s.pop();
	cout << "Pop element from the stack : " << endl;
	PrintElements1(s);
	cout << "top Element stack : " << s.top() << endl;

	std::cin.get();
	return 0;
}
