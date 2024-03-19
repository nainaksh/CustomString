#include<iostream>

using namespace std;

extern int max(int a, int b);

int MaxContgiousSum(int arr[], int size)
{
	int max_count = arr[0];
	int max_so_far = arr[0];

	for (int i = 0; i < size; i++)
	{
		max_count = max(arr[i], arr[i] + max_count);
		max_so_far = max(max_count, max_so_far);
	}

	return max_so_far;
}