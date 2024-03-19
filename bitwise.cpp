#include<iostream>
#include<string>
using namespace std;

int findOdd(int arr[], int n)
{
	int res = 0, i;
	for (i = 0; i < n; i++)
	{
		res = res ^ arr[i];
		cout << res << endl;
	}
	return res;
}

int main12()
{
	int a = 9; //1001
	int b = 6; // 110

	(b & 1) ? (cout << "Odd") : (cout << "Even");

	cout << "Left shift:" << (b << 1) << endl;
	cout << "Left shift2:" << (b << 2) << endl;
	cout << "Left shift3:" << (b << 3) << endl;

	cout << "Right shift:" << (b >> 1) << endl;

	cout << "NOT:" << (~b) << endl;


	string ch = "PQRST";
	
	for (auto c : ch)
	{
		c = (c | ' ');
		cout << c;
	}

	cout << endl;

	ch = "abcdef";

	for (auto c : ch)
	{
		c = (c & '_');
		cout << c;
	}
	cout << endl;

	int arr[] = { 12, 12, 14, 90, 14, 14, 14 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "The odd occurring element is  " << findOdd(arr, n);


	cin.get();
	return 0;
}