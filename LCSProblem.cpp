#include<iostream>
#include<string>
using namespace std;

int _max(int a, int b) { return (a > b) ? a : b; }

//LongestCommonSubsequence 
int LCSRecursive(string X, string Y, int m, int n)
{
	if (m == 0 || n == 0)
	{
		return 0;
	}

	if (X[m - 1] == Y[n - 1])
	{
		return 1 + LCSRecursive(X, Y, m - 1, n - 1);
	}
	else
	{
		return _max(LCSRecursive(X, Y, m - 1, n), LCSRecursive(X, Y, m, n - 1));
	}
}

int ap[100][100];

int LCSMemoization(string X, string Y, int m, int n)
{
	if (m == 0 || n == 0)
	{
		return 0;
	}

	if (ap[m][n] != -1)
	{
		return ap[m][n];
	}

	if (X[m - 1] == Y[n - 1])
	{
		return ap[m][n] = 1 + LCSMemoization(X, Y, m - 1, n - 1);
	}
	else
	{
		return ap[m][n] = _max(LCSMemoization(X, Y, m - 1, n), LCSMemoization(X, Y, m, n - 1));
	}
}

int bp[100][100];

int LCSTabulation(string X, string Y, int m, int n)
{
	for (int i = 0; i < m + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			if (i == 0 || j == 0)
			{
				bp[i][j] = 0;
			}
			else if (X[i - 1] == Y[j - 1])
			{
				bp[i][j] = 1 + bp[i - 1][j - 1];
			}
			else
			{
				bp[i][j] = _max(bp[i - 1][j], bp[i][j - 1]);
			}
		}
	}
	return bp[m][n];
}

int LCSubstringTabulation(string X, string Y, int m, int n)
{
	int result = 0;
	for (int i = 0; i < m + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			if (i == 0 || j == 0)
			{
				bp[i][j] = 0;
			}
			else if (X[i - 1] == Y[j - 1])
			{
				bp[i][j] = 1 + bp[i - 1][j - 1];
				result = _max(result, bp[i][j]);
			}
			else
			{
				bp[i][j] = 0;
			}
		}
	}
	return result;
}

int LPS(string s, int n)
{
	string s1 = s;
	reverse(s.begin(),s.end());

	return LCSTabulation(s, s1, n, n);
}

void PrintLCS(string X, string Y, int m, int n)
{
	for (int i = 0; i < m + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			if (i == 0 || j == 0)
			{
				bp[i][j] = 0;
			}

			else if (X[i - 1] == Y[j - 1])
			{
				bp[i][j] = 1 + bp[i - 1][j - 1];
			}
			else
			{
				bp[i][j] = _max(bp[i][j - 1], bp[i - 1][j]);
			}
		}
	}
	int i = m;
	int j = n;
	string s;
	while (i > 0 || j > 0)
	{
		if (X[i-1] == Y[j-1])
		{
			s.push_back(X[i-1]);
			i--;
			j--;
		}
		else
		{
			if (bp[i][j - 1] > bp[i - 1][j])
			{
				j--;
			}
			else
			{
				i--;
			}
		}
	}
	reverse(s.begin(), s.end());
	cout << "LCS: " << s << endl;
}

int main16()
{
	string a = "abxycedf";
	string b = "abzytcemnd";

	//cout << "LCS:" << LCSRecursive(a, b, a.size(), b.size()) << endl;

	//memset(ap, -1, sizeof(ap));
	//cout << "LCS Memoization:" << LCSMemoization(a, b, a.size(), b.size()) << endl;

	cout << "LCS Tabulation:" << LCSTabulation(a, b, a.size(), b.size()) << endl;

	PrintLCS(a, b, a.size(), b.size());
	//cout << "LCSubstring Tabulation:" << LCSubstringTabulation(a, b, a.size(), b.size()) << endl;

	//string c = "zabcbxbyaz";
	//cout << "LPS Tabulation:" << LPS(c,c.size()) << endl;

	cin.get();
	return 0;
}