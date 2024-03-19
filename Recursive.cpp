#include<iostream>
#include<string>
using namespace std;

//Recursive examples

void reverseString(string str)
{
	if (str.length() == 0)
	{
		return;
	}

	char ch = str[0];
	reverseString(str.substr(1));

	cout << ch;
}

void stringPermutation(string str, string ans)
{
	if (str.length() == 0)
	{
		cout << ans << endl;
		return;
	}

	for (int i = 0; i < str.length(); i++)
	{
		char ch = str[i];
		string rest = str.substr(0, i) +  str.substr(i + 1);

		stringPermutation(rest, ans+ch);
	}
}

int countNumberofPaths(int s, int e)
{
	if (s == e)
		return 1;

	if (s > e)
		return 0;

	int count = 0;
	for (int i = 1; i < 6; i++)
	{
		count+= countNumberofPaths(s + i, e);
	}
	return count;
}

int CountNumberOfPossiblePathInMatrix(int n, int i, int j)
{
	if (i == n - 1 && j == n - 1)
	{
		return 1;
	}
	if (i >= n || j >= n)
	{
		return 0;
	}

	return CountNumberOfPossiblePathInMatrix(n, i + 1, j) + CountNumberOfPossiblePathInMatrix(n, i, j + 1);
}

bool isSafe(int** arr, int i, int j, int n)
{
	if (i < n && j < n && arr[i][j]==1)
	{
		return true;
	}
	return false;
}

bool ratInMaze(int** arr, int i, int j, int n, int** solArr)
{
	if (i == n - 1 && j == n - 1)
	{
		solArr[i][j] = 1;
		return true;
	}

	if (isSafe(arr, i, j, n - 1))
	{
		solArr[i][j] = 1;

		if (ratInMaze(arr, i + 1, j, n, solArr))
		{
			return true;
		}
		if (ratInMaze(arr, i, j+1, n, solArr))
		{
			return true;
		}

		solArr[i][j] = 0;
		return false;
	}
	return false;
}


int main33()
{
	int a = 9;

	int* b = &a;

	string s{ "abcd" };
	reverseString(s);
	cout << endl;

	stringPermutation(s, "");
	/*int* c = *a;

	int* d = &b;

	int &e = a;
	int &f = b;*/

	cin.get();
	return 0;

}