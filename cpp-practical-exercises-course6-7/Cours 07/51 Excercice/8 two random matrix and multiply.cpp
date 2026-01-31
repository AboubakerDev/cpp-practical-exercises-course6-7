#include<iostream>
#include <random>
#include <iomanip>
using namespace std;


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
int RandomInt(int From, int Into) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(From, Into);
	return dis(gen);
}
void FillMatrixWithRandomNumbers(int RandomMatrix[3][3], short Rows, short cols) {
	for (size_t i = 0; i < Rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			RandomMatrix[i][j] = RandomInt(1, 10);
		}
	}
}
void MultiplyMatrix(int Matrix1[3][3], int Matrix2[3][3], int MatrixResult[3][3], short Rows, short cols) {
	for (size_t i = 0; i < Rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			MatrixResult[i][j]=Matrix1[i][j]* Matrix2[i][j];
		}
		cout << endl;
	}
}
int main()
{

	int Matrix1[3][3];
	int Matrix2[3][3];
	int MatrixResult[3][3];
	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "\nThe following is a 3x3 ordered matrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	FillMatrixWithRandomNumbers(Matrix2, 3, 3);
	cout << "\nThe following is a 3x3 ordered matrix2:\n";
	PrintMatrix(Matrix2, 3, 3);

	MultiplyMatrix(Matrix1, Matrix2, MatrixResult,3,3);
	cout << "\nThe following is the multiblication of matrix1 * matrix2:\n";
	PrintMatrix(MatrixResult, 3, 3);
	
	system("pause>0");
}