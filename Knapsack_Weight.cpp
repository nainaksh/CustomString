#include <iostream>
#include<vector>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int dp[102][1002];
int tb[102][1002];

//0/1 KNAPSACK EXAMPLE

int KnapsackTabulation(int wt[], int val[], int W, int n)
{
	//vector<vector<int>> tb(n + 1, vector<int>(W + 1));
	if (W == 0 || n == 0)
	{
		return 0;
	}

	for (int i = 0; i < (n + 1); i++)
	{
		for (int j = 0; j < (W + 1); j++)
		{
			if (i == 0 || j == 0)
			{
				tb[i][j] = 0;
			}

			else if (wt[i - 1] <= j)
			{
				tb[i][j] = max(val[i - 1] + tb[i - 1][j - wt[i - 1]], tb[i - 1][j]);
			}
			else if (wt[i - 1] > j)
			{
				tb[i][j] = tb[i - 1][j];
			}
		}
	}
	return tb[n][W];
}

int KnapsackMemoization(int wt[], int val[], int W, int n)
{
	if (W == 0 || n == 0)
	{
		return 0;
	}

	if (dp[n][W] != -1)
	{
		return dp[n][W];
	}

	if (wt[n - 1] <= W)
	{
		return dp[n][W] = max(val[n - 1] + KnapsackMemoization(wt, val, W - wt[n - 1], n - 1), KnapsackMemoization(wt, val, W, n - 1));
	}
	else if (wt[n - 1] > W)
	{
		return dp[n][W] = KnapsackMemoization(wt, val, W, n - 1);
	}

}

int KnapsackRecursion(int wt[], int val[], int W, int n)
{
	if (W == 0 || n == 0)
	{
		return 0;
	}

	if (wt[n - 1] <= W)
	{
		return max(val[n - 1] + KnapsackRecursion(wt, val, W - wt[n - 1], n - 1), KnapsackRecursion(wt, val, W, n - 1));
	}
	else if (wt[n - 1] > W)
	{
		return KnapsackRecursion(wt, val, W, n - 1);
	}

}

int main13()
{
	int wt[] = { 10, 20, 30 };
	int val[] = { 60, 100, 120 };
	int W = 50;

	memset(dp, -1, sizeof(dp));

	int size = sizeof(wt) / sizeof(wt[0]);

	int profit1 = KnapsackRecursion(wt, val, W, size);
	cout << "Max profit:" << profit1<<endl;

	int profit2 = KnapsackMemoization(wt, val, W, size);

	cout << "Max profit:" << profit2<<endl;

	int profit3 = KnapsackTabulation(wt, val, W, size);
	cout << "Max profit:" << profit3 << endl;


	cin.get();
	return 0;
}