#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
void Print_in(int** a, const int rowCount, const int colCount, int i, int j);
void Sort(int** a, const int rowCount, const int colCount, int i, int j);
void Change(int** a, const int row1, const int row2, const int colCount, int tmp, int j);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& K, int i, int j);
void Calc_in(int** a, const int rowCount, const int colCount, int& S, int& K, int i, int j);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -26;
	int High = 23;
	int rowCount = 8;
	int colCount = 6;
	int i = 0, j = 0;
	int tmp = 0;
	int S = 0;
	int K = 0;
	int** Q = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		Q[i] = new int[colCount];
	Create(Q, rowCount, colCount, Low, High, i, j);
	cout << endl;
	Print(Q, rowCount, colCount, i, j);
	cout << endl;
	Sort(Q, rowCount, colCount, i, j);
	cout << endl;
	Print(Q, rowCount, colCount, i, j);
	cout << endl;
	Calc(Q, rowCount, colCount, S, K, i, j);
	cout << "S = " << S << endl;
	cout << "K = " << K << endl;
	cout << endl;
	Print(Q, rowCount, colCount, i, j);
	cout << endl;
	for (int i = 0; i < rowCount; i++)
		delete[] Q[i];
	delete[] Q;
	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
	if (i < rowCount) {
		if (j < colCount) {
			a[i][j] = Low + rand() % (High - Low + 1);
			Create(a, rowCount, colCount, Low, High, i, j + 1);
		}
		Create(a, rowCount, colCount, Low, High, i + 1, j);
	}
}

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	if (i < rowCount)
	{
		Print_in(a, rowCount, colCount, i, j);
		cout << endl;
		Print(a, rowCount, colCount, i + 1, j);
	}
}

void Print_in(int** a, const int rowCount, const int colCount, int i, int j)
{
		if (j < colCount) {
			cout << setw(4) << a[i][j];
			Print_in(a, rowCount, colCount, i, j + 1);
		}
}

void Sort(int** a, const int rowCount, const int colCount, int i, int j)
{
	if (i < colCount - 1) {
		if(j < colCount - i - 1) {
			if ((a[0][j] > a[0][j + 1])
				||
				(a[0][j] == a[0][j + 1] &&
					a[1][j] < a[1][j + 1])
				||
				(a[0][j] == a[0][j + 1] &&
					a[1][j] == a[1][j + 1] &&
					a[2][j] > a[2][j + 1]))
				Change(a, j, j + 1, rowCount, 0, 0);
			Sort(a, rowCount, colCount, i, j + 1);
		}
		Sort(a, rowCount, colCount, i + 1, j);
	}

}

void Change(int** a, const int col1, const int col2, const int rowCount, int tmp, int j)
{

	if( j < rowCount)
	{
		tmp = a[j][col1];
		a[j][col1] = a[j][col2];
		a[j][col2] = tmp;
		Change(a, col1, col2, rowCount, tmp, j + 1);
	}
}

void Calc_in(int** a, const int rowCount, const int colCount, int& S, int& K, int i, int j)
{
	if (j < colCount) {
		if (!(a[i][j] % 2 == 0 && a[i][j] > 0)) {
			S += a[i][j];
			a[i][j] = 0;
			K++;
		}
		Calc_in(a, rowCount, colCount, S, K, i, j + 1);
	}
}

void Calc(int** a, const int rowCount, const int colCount, int& S, int& K, int i, int j)
{

	if (i < rowCount) {
		Calc_in(a, rowCount, colCount, S, K, i, j);
		Calc(a, rowCount, colCount, S, K, i + 1, j);
	}

}