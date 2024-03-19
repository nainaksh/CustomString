#include <iostream>

using namespace std;

class Vector
{
public:
	int size;
	int capacity;
	int* arr;

	Vector() :size(0), capacity(1)
	{
		arr = new int[1];
	}

	void push_back(int val)
	{
		if (size == capacity)
		{
			int *temp = new int[capacity * 2];
			for (int i = 0; i < capacity; ++i)
			{
				temp[i] = arr[i];
			}
			delete[]arr;
			arr = temp;
			capacity *= 2;
		}

		arr[size] = val;
		size++;
	}

	void pop()
	{
		arr[--size];
	}

	void Display()
	{
		for (int i = 0; i < size; ++i)
		{
			cout << arr[i];
		}
	}
};