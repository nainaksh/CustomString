#include<iostream>

using namespace std;

extern int max(int a, int b);
extern int min(int a, int b);

int eggDrop(int e, int f)
{
	if (e == 0)
		return f;

	if (f == 0 || f == 1)
		return f;

	int mn = INT_MAX;

	for (int k = 1; k <= f; k++)
	{
		int temp = 1 + max(eggDrop(e - 1, k - 1), eggDrop(e, f - k));
		mn = min(mn, temp);
	}

	return mn;
}

int main17()
{
	int egg = 3;
	int floor = 5;

	cout << "Min number of possibilities:" << eggDrop(egg, floor) << endl;

	cin.get();
	return 0;
}