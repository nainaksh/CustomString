#include<iostream>

using namespace std;

class Matrix
{
public:
	int r;
	int c;
	int** mtx;

	Matrix() :r(0), c(0)
	{
		mtx = nullptr;
	}

	Matrix(int pr, int pc) :r(pr), c(pc)
	{
		mtx = new int*[pr];

		for (int i = 0; i < pr; ++i)
		{
			mtx[i] = new int[pc];

			for (int j = 0; j < pc; ++j)
			{
				mtx[i][j] = 0;
			}
		}
	}

	~Matrix()
	{
		for (int i = 0; i < r; ++i)
		{
			delete[] mtx[i] ;
		}
		delete[] mtx;
	}

	Matrix(const Matrix &m)
	{
		r = m.r;
		c = m.c;

		mtx = new int*[r];

		for (int i = 0; i < r; ++i)
		{
			mtx[i] = new int[c];

			for (int j = 0; j < c; ++j)
			{
				mtx[i][j] = m.mtx[i][j];
			}
		}
	}

	void PrintMatrix()
	{
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				cout << mtx[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}

	void setValue(int row, int column, int val);
};

void Matrix::setValue(int row, int column, int val)
{
	if (row < this->r && column < this->c)
		this->mtx[row][column] = val;
	else
		cout << "Invalid!!!" << endl;
}


int main2()
{
	Matrix m1;
	m1.PrintMatrix();

	Matrix m2(3, 4);

	int arr[5][6];
	memset(arr, 0, sizeof(m2));

	int c = 1;
	for (int i = 0; i < m2.r; ++i)
	{
		for (int j = 0; j < m2.c; ++j)
		{
			m2.mtx[i][j] = c;
		}
		c++;
		cout << endl;
	}

	m2.PrintMatrix();

	m2.setValue(0, 2, 5);
	m2.PrintMatrix();

	m2.setValue(2, 2, 5);
	m2.PrintMatrix();

	m2.setValue(3, 0, 5);
	m2.PrintMatrix();

	int n;
	cin >> n;
	std::cin.get();
	return 0;

}
