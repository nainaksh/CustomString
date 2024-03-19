#include<iostream>
#include<vector>
using namespace std;
//arr[1,5,6,10,1,2]
//find min difference of subset sum

//0/1 KNAPSACK EXAMPLE

bool dp[100][1000];
int tp[100][1000];
bool sp[100][1000];


void Display(vector<int>vec)
{
	for (const auto& v : vec)
	{
		cout << v << "  ";
	}
	cout << endl;
}

void PrintSubsets(int arr[], int n, int s, vector<int> v)
{
	if (n == 0 && s != 0)
	{
		v.push_back(arr[n]);
		if (arr[n] == s)
			Display(v);
		return;
	}

	if(n==0 && s==0)
	{
		Display(v);
		return;
	}

	if (dp[n-1][s])
	{
		PrintSubsets(arr, n-1, s, v);
	}

	if (s >= arr[n-1] && dp[n-1][s - arr[n -1]])
	{
		v.push_back(arr[n-1]);
		PrintSubsets(arr, n - 1, s - arr[n-1], v);
	}
}

void PrintSubsetSum(int arr[], int n, int s)
{
	for (int i = 0; i < s + 1; i++)
	{
		dp[0][i] = false;
	}

	for (int i = 0; i < n + 1; i++)
	{
		dp[i][0] = true;
	}

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < s + 1; j++)
		{
			if (arr[i - 1] <= j)
			{
				dp[i][j] = (dp[i - 1][j - arr[i - 1]]) || (dp[i - 1][j]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	if (dp[n][s] == false)
	{
		cout << "No subset present" << endl;
	}

	vector<int> vec;
	PrintSubsets(arr, n, s, vec);
}

bool isSubsetSum(int arr[], int n, int s)
{
	for (int i = 0; i < s + 1; i++)
	{
		dp[0][i] = false;
	}

	for (int i = 0; i < n + 1; i++)
	{
		dp[i][0] = true;
	}

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < s + 1; j++)
		{
			if (arr[i - 1] <= j)
			{
				dp[i][j] = (dp[i - 1][j - arr[i - 1]]) || (dp[i - 1][j]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp[n][s];
}

int SubsetSumCount(int arr[], int n, int s)
{
	for (int i = 0; i < s + 1; i++)
	{
		tp[0][i] = 0;
	}

	for (int i = 0; i < n + 1; i++)
	{
		tp[i][0] = 1;
	}

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < s + 1; j++)
		{
			if (arr[i - 1] <= j)
			{
				tp[i][j] = (tp[i - 1][j - arr[i - 1]]) + (tp[i - 1][j]);
			}
			else
			{
				tp[i][j] = tp[i - 1][j];
			}
		}
	}

	return tp[n][s];
}

bool EqualSumPartition(int arr[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}

	if (sum % 2 != 0)
	{
		return false;
	}

	return isSubsetSum(arr, size, sum / 2);
}

int minDifferenceSubsetCount(int arr[], int n)
{
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		s += arr[i];
	}

	for (int i = 0; i < s + 1; i++)
	{
		sp[0][i] = false;
	}

	for (int i = 0; i < n + 1; i++)
	{
		sp[i][0] = true;
	}

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < s + 1; j++)
		{
			if (arr[i - 1] <= j)
			{
				sp[i][j] = (sp[i - 1][j - arr[i - 1]]) || (sp[i - 1][j]);
			}
			else
			{
				sp[i][j] = sp[i - 1][j];
			}
		}
	}

	int diff = INT16_MAX;

	for (int i = s / 2; i >= 0; i--)
	{
		if (sp[n][i])
		{
			diff = s - 2 * i;
			break;
		}
	}

	return diff;
}

int subsetWithGivenDiffCount(int arr[], int size, int diff)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}

	int s = (sum + diff) / 2;

	return SubsetSumCount(arr, size, s);
}

int main23()
{
	int arr[] = { 5,6,10,1};
	int sum = 11;
	
	int size = sizeof(arr) / sizeof(arr[0]);

	if (isSubsetSum(arr, size, sum))
	{
		cout << "Subset found" << endl;
	}
	else
	{
		cout << "Subset not found" << endl;
	}

	PrintSubsetSum(arr, size, sum);

	//Subset sum count
	//int cnt = SubsetSumCount(arr, size, sum);
	//cout << "Subset count: " << cnt << endl;

	////Equal Partition

	//int arr1[] = { 1,5,6,10,4 };
	//int size1 = sizeof(arr1) / sizeof(arr1[0]);

	//if (EqualSumPartition(arr1, size1))
	//{
	//	cout << "Partition found" << endl;
	//}
	//else
	//{
	//	cout << "Partition not found" << endl;
	//}

	////The minimum difference between 2 sets

	//int arr2[] = { 3, 1, 4, 2, 2, 1 };
	//int size2 = sizeof(arr2) / sizeof(arr2[0]);

	//int cnt2 = minDifferenceSubsetCount(arr2, size2);
	//cout << "The minimum difference between 2 sets is:" << cnt2 << endl;

	////count subsets with given difference
	//int arr3[] = { 1,1,2,3 };
	//int size3 = sizeof(arr3) / sizeof(arr3[0]);
	//int diff = 1;
	//int cnt3 = subsetWithGivenDiffCount(arr3, size3, diff);
	//cout << "The number of subsets with given difference:" << cnt3 << endl;

	cin.get();
	return 0;
}