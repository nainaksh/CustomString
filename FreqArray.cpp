#include<iostream>
#include<unordered_map>
using namespace std;

//find 1st repeating element

// {2,4,6,8,9}
// {4,6,9}

bool IsSubset(int arr1[], int arr2[], int m, int n)
{
	unordered_map<int, int>mp;

	for (int i = 0; i < m; i++)
	{
		mp[arr1[i]]++;
	}

	for (const auto& p : mp)
	{
		cout << p.first << " " << p.second << endl;
	}

	for (int i = 0; i < n; i++)
	{
		if (mp[arr2[i]] > 0)
		{
			mp[arr2[i]]--;
		}
		else
		{
			return false;
		}
	}
	return true;
}

void GetFrequencyArray(int arr[], int size)
{
	unordered_map<int, int>mp;

	for (int i = 0; i < size; ++i)
	{
		mp[arr[i]]++;
	}

	for (const auto& p : mp)
	{
		cout << p.first << " " << p.second << endl;
	}
}

int majorityElement(const vector<int> &A) {
	std::unordered_map<int, int>mp;

	int n1 = A.size();
	for (int i = 0; i<n1; ++i)
	{
		mp[A[i]]++;
	}

	for (const auto& p : mp)
	{
		if (p.second > n1 / 2)
		{
			return p.first;
		}
	}

	return 0;
}


int main11()
{
	int a[5] = { 4,4,6,8,8 };
	int b[4] = { 4,6,4,4 };

	if (IsSubset(a, b, 5, 4))
	{
		cout << "Subset!!!"<<endl;
	}
	else
	{
		cout << "Not Subset!!!" << endl;
	}

	int x[] = { 1,3,4,5,2,6,4,3,1,6,4 };

	int size = sizeof(x) / sizeof(x[0]);

	GetFrequencyArray(x, size);


	cin.get();
	return 0;
}