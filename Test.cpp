#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

int dp[1000][1000];
int countFamilyLogins(vector<string> logins) {
	int count = 0;
	int n = logins.size();

	for (int i = 0; i<n + 1; i++)
	{
		for (int j = 0; j<n + 1; j++)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = 0;
			}

			else if (logins[i - 1] != logins[j - 1])
			{
				string s = logins[i - 1];
				string t = logins[j - 1];
				int flag = 1;
				for (int k = 0; k<s.size(); k++)
				{
					if (s[k] != t[k] + 1 && t[k] != s[k] + 1)
					{
						flag = 0;
						break;
					}
				}
				if (flag == 1)
				{
					count++;
					//dp[i][j] = 1 + dp[i - 1][j - 1];
				}
			}
			else {
				//dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}

	return count;
}

long findTotalImbalance(vector<int> rank) {
	sort(rank.begin(), rank.end());
	int count = 0;
	for (int i = 0; i<rank.size(); i++)
	{
		for (int j = 1; j < rank.size(); j++)
		{
			if (rank[j] - rank[i] > 1)
			{
				count++;
			}
		}
	}
	return count;
}

string ReverseWords(string originalString) {
	vector<string> result;
	istringstream iss(originalString);
	for (std::string originalString; iss >> originalString; )
		result.push_back(originalString);

	string newString;

	for_each(begin(result), end(result), [&newString](string word)
	{
		string spChars;
		for (int i = word.size(); i >= 0; i--)
		{
			if ((word[i] >= 65 && word[i] <= 90) || (word[i] >= 97 && word[i] <= 122) || (word[i] >= 48 && word[i] <= 57))
				newString = newString + word[i];
			else
				spChars = spChars + word[i];
		}
		newString = newString + spChars + " ";
	});
	return newString;
}


string formatAsCustomString(string date, int number) {

	stringstream s;
	s << number;
	string num = s.str();
	string str = num.substr(num.length() - 5);

	string year = date.substr(2, 2);
	string month = date.substr(5, 2);
	string day = date.substr(8);

	return str + '-' + year + month + day;
}

bool isFibo(int valueToCheck, int previousValue, int currentValue)
{
	if (currentValue > valueToCheck)
		return false;

	if (valueToCheck == currentValue)
	{
		return true;
	}
		return isFibo(valueToCheck, previousValue + currentValue, currentValue);
}


int main31()
{
	//vector<string> s = { "corn","horn","dpso","eqtp","corn" };

	//cout << countFamilyLogins(s);
	//vector<int>a = { 4,4,1,3,2 };
	//cout << findTotalImbalance(a);
	//std::string s{ "nayana gadakh" };
	//cout << ReverseWords(s);

	//string a{ "1990-12-22" };
	//int b = 123451234512345;
	//cout << formatAsCustomString(a, b);

	//cout << isFibo(3, 0, 1);


	cin.get();
	return 0;
}
