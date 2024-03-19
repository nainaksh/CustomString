#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
* Complete the 'getBingoNumber' function below.
*
* The function is expected to return an INTEGER.
* The function accepts following parameters:
*  1. 2D_INTEGER_ARRAY mat
*  2. INTEGER_ARRAY arr
*/

bool checkRows(vector<vector<int>> mat)
{
	bool flag;
	for (int j = 0; j < mat.size(); j++)
	{
		flag = true;
		for (int k = 0; k < mat[j].size(); k++)
		{
			if (mat[j][k] != 0)
			{
				flag =  false;
				break;
			}
		}
		if (flag)
			return flag;
	}
	return flag;
}

bool checkColumns(vector<vector<int>> mat)
{
	bool is_col_out_of_bounds = false;
	bool flag;

	for (size_t col = 0; !is_col_out_of_bounds; col++)
	{
		is_col_out_of_bounds = true;
		for (size_t row = 0; row<mat.size(); row++)
		{
			if (col < mat[row].size())
			{
				is_col_out_of_bounds = false;
				flag = true;

				if (mat[row][col] != 0)
				{
					flag = false;
					break;
				}
			}
		}
		if (flag)
			return flag;
	}
	return flag;
}

int getBingoNumber(vector<vector<int>> mat, vector<int> arr) {

	int count =0 ;

	for (int i = 0; i < arr.size(); ++i)
	{
		for (int j = 0; j < mat.size(); j++)
		{
			for (int k = 0; k < mat[j].size(); k++)
			{
				if (arr[i] == mat[j][k] && mat[j][k] != 0)
				{
					int num;
					num = mat[j][k];
					mat[j][k] = 0;
					if (checkRows(mat) || checkColumns(mat))
					{
						return num;
					}
					break;
				}
			}
		}
	}

	return 0;
}

int main26()
{
	int mat_rows, mat_columns;
	cout << "Enter rows and columns:";
	cin >> mat_rows >> mat_columns;

	vector<vector<int>> mat(mat_rows);
	cout << "Enter Matrix elements:";

	int mat_row_temp_temp;
	int mat_row_temp;
	int matSize = mat_rows*mat_columns;

	/*for (int k = 0; k < matSize; k++)
	{
		cin >> mat_row_temp_temp;
		mat_row_temp.push_back(mat_row_temp_temp);
	}
*/

	for (int i = 0; i < mat_rows; i++) {
		mat[i].resize(mat_columns);

		for (int j = 0; j < mat_columns; j++) {
			cin >> mat_row_temp;
			mat[i][j] = mat_row_temp;
		}
	}
	cout << "Enter Array size:";

	int arr_count;
	cin>> arr_count;


	cout << "Enter Array Elements:";

	vector<int> arr(arr_count);

	for (int i = 0; i < arr_count; i++) {
		string arr_item_temp;
		getline(cin, arr_item_temp);

		int arr_item;
		cin >>arr_item;

		arr[i] = arr_item;
	}

	int result = getBingoNumber(mat, arr);

	
	cout << "Result:" << result << endl;

	cin.get();
	int n;
	cin >> n;
	return 0;
}

string ltrim(const string &str) {
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), static_cast<int(*)(int)>(isspace))
	);

	return s;
}

string rtrim(const string &str) {
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), static_cast<int(*)(int)>(isspace)).base(),
		s.end()
	);

	return s;
}

vector<string> split(const string &str) {
	vector<string> tokens;

	string::size_type start = 0;
	string::size_type end = 0;

	while ((end = str.find(" ", start)) != string::npos) {
		tokens.push_back(str.substr(start, end - start));

		start = end + 1;
	}

	tokens.push_back(str.substr(start));

	return tokens;
}
