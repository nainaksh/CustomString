#include<iostream>

using namespace std;

void swapLocal(int& a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void BubbleSort(int arr[], int n)
{
	if (n == 0 || n == 1)
	{
		return;
	}
	for (int i = 0; i < n-1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			swapLocal(arr[i], arr[i + 1]);
		}
	}

	BubbleSort(arr, n - 1);
}

int* BubbleSortSingleLoop(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			swapLocal(arr[i], arr[i + 1]);
			i = -1;
		}
	}

	return arr;
}

void SelectionSort(int arr[], int n)
{
	int i, j, min;

	for (i = 0; i < n- 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}

		if (min != i) {
			swapLocal(arr[min], arr[i]);
		}
	}
}

void insertionSort(int arr[], int n)
{
	int i, j, key;

	for (int i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while  ( j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

int Partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j < high; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swapLocal(arr[i], arr[j]);
		}
	}
	swapLocal(arr[i + 1], arr[high]);
	return i + 1;
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = Partition(arr, low, high);
		quickSort(arr, pi + 1, high);
		quickSort(arr, low, pi - 1);
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main21()
{
	int arr1[] = { 2,5,3,2,7,4,9,1, 4 };
	int size = sizeof(arr1) / sizeof(arr1[0]);

	//BubbleSort(arr1, size);
	//SelectionSort(arr1, size);
	//insertionSort(arr1, size);
	//quickSort(arr1, 0, size-1);
	//printArray(arr1, size);

	int* res;
	res = BubbleSortSingleLoop(arr1, size);
	printArray(arr1, size);

	cin.get();
	return 0;
}