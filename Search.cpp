#include <iostream>

using namespace std;

extern void swapLocal(int& a, int &b);

extern void BubbleSort(int arr[], int n);

extern void printArray(int arr[], int n);

bool BinarySearch(int arr[], int l, int r, int key)
{
	BubbleSort(arr, r);

	int mid;
	if (r >= l)
	{
		mid = (l + r - 1) / 2;
	}

	if (key == arr[mid])
	{
		return true;
	}

	if (key < arr[mid])
	{
		BinarySearch(arr, l, mid - 1, key);
	}

	if (key > arr[mid])
	{
		BinarySearch(arr, mid + 1, r, key);
	}	
}

int main22()
{
	int arr1[] = { 2,5,3,2,7,4,9,1, 4 };
	int size = sizeof(arr1) / sizeof(arr1[0]);

	int key = 7;
	if (BinarySearch(arr1, 0, size, key))
	{
		cout << "Found:" << key<<endl;
	}
	else
	{
		cout << "Not Found:" << key << endl;
	}

	printArray(arr1, size);

	cin.get();
	return 0;
}