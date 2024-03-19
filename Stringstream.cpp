#include<iostream>
#include<string>
#include<sstream>
#include <unordered_map>
using namespace std;

int countWords(string str)
{
	stringstream s(str);
	string word;
	int count = 0;
	while (s >> word)
	{
		count++;
	}

	return count;
}

void freqOfWords(string str)
{
	unordered_map<string, int> mp;
	stringstream s(str);
	string word;
	
	while (s >> word)
	{
		mp[word]++;
	}

	for (const auto& m : mp)
	{
		cout << m.first << m.second << endl;
	}

}

int atoi_(string str)
{
	stringstream s(str);
	int a;
	s >> a;

	return a;
}

int main20()
{
	string str = "Nayana Sanjay Gadakh";
	cout << "Number of words:" << countWords(str) << endl;

	string str1 = "Nayana Sanjay Sanjay Gadakh Sanjay Gadakh";
	cout << "Words and frequency:" ;
	freqOfWords(str1);

	string str2 = "123";
	cout << "ATOI:" << atoi_(str2) << endl;

	cin.get();
	return 0;

}