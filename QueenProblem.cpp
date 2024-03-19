#include<iostream>

using namespace std;

//Backtracking problem

bool _isSafe(int** arr, int i, int j, int n)
{
	for (int row = 0; row < n; ++row)
	{
		if (arr[row][j] == 1)
		{
			return true;
		}
	}

	int row = i;
	int col = j;

	while (row >= 0 && col >= 0)
	{
		if (arr[row][col] == 1)
			return true;

		row--;
		col--;
	}

	row = i;
	col = j;

	while (row >= 0 && col < n)
	{
		if (arr[row][col] == 1)
			return true;

		row--;
		col++;
	}

	return false;

}

bool nQueen(int** arr, int i, int n)
{
	if (i >= n)
	{
		return true;
	}

	for (int col = 0; col < n; col++)
	{
		if (_isSafe(arr, i, col, n))
		{
			arr[i][col] = 1;

			if (nQueen(arr, i + 1, n))
			{
				return true;
			}

			arr[i][col] = 0;
		}
	}
	return false;
}