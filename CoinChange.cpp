#include<iostream>

using namespace std;

int dp1[100][1000];

int min(int a, int b) { return (a < b) ? a : b; }

//UNBOUNDED KNAPSACK

int CoinSumWays(int arr[], int n, int s)
{
	for (int i = 0; i < s + 1; i++)
	{
		dp1[0][i] = 0;
	}
	for (int i = 0; i < n + 1; i++)
	{
		dp1[i][0] = 1;
	}

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < s + 1; j++)
		{
			if (arr[i - 1] <= j)
			{
				dp1[i][j] = dp1[i][j - arr[i - 1]] + dp1[i - 1][j];
			}
			else
			{
				dp1[i][j] = dp1[i - 1][j];
			}
		}
	}
	return dp1[n][s];
}

int SumWithMinCoins(int arr[], int n, int s)
{
	for (int i = 0; i < n + 1; i++)
	{
		dp1[i][0] = 0;
	}

	for (int i = 1; i < s + 1; i++)
	{
		dp1[0][i] = INT_MAX - 1;
		if (s / arr[0] == 1)
		{
			dp1[1][i] = 1;
		}
		else
		{
			dp1[1][i] = INT_MAX - 1;
		}
	}
	

	for (int i = 2; i < n + 1; i++)
	{
		for (int j = 1; j < s + 1; j++)
		{
			if (arr[i - 1] <= j)
			{
				dp1[i][j] = min(dp1[i][j - arr[i - 1]] + 1, dp1[i - 1][j]);
			}
			else
			{
				dp1[i][j] = dp1[i - 1][j];
			}
		}
	}
	return dp1[n][s];
}

int main15()
{
	int arr[] = { 1,2,3 };
	int size = sizeof(arr) / sizeof(arr[0]);

	int sum = 5;
	int cnt = SumWithMinCoins(arr, size, sum);

	cout << "Number of ways to get sum of coins 5:" << cnt << endl;

	cin.get();
	return 0;
}