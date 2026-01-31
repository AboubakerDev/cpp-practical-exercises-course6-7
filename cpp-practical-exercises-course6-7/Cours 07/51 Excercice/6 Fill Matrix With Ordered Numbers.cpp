#include<iostream>
#include <random>
#include <iomanip>
using namespace std;
void FillMatrixWithOrderedNumbers(int OrderedMatrix[3][3], short Rows, short cols) {
	int s = 1;
	for (size_t i = 0; i < Rows; i++)
	{
		
		for (size_t j = 0; j < cols; j++)
		{
			OrderedMatrix[i][j] = s;
			s++;
		}
		
	}
		cout << endl;
	}


void PrintMatrix(int RandomMatrix[3][3], short Rows, short cols) {
	for (size_t i = 0; i < Rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			cout << setw(3) << RandomMatrix[i][j];
		}
		cout << endl;
	}
}

int main()
{

	int Matrix[3][3];
	FillMatrixWithOrderedNumbers(Matrix,3,3);
	cout << "\nThe following is a 3x3 ordered matrix:\n";
	PrintMatrix(Matrix, 3, 3);
	
	system("pause>0");
}