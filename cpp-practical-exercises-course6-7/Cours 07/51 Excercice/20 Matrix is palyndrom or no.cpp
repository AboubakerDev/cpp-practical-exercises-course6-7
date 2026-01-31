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

bool IsPalyndromMatrix(int Matrix[3][3], short Rows, short Cols) {
	for (size_t i = 0; i < Rows; i++)
	{
		for (size_t j = 0; j < Cols/2; j++)
		{
			if (Matrix[i][j] != Matrix[i][Cols - 1 - j])
				return false;
				
		}
	}
	return true;
}
int main()
{

	int Matrix[3][3] = { {1,2,1},{4,5,4},{0,2,0} };
	FillMatrixWithRandomNumbers(Matrix, 3, 3);
	cout << "\nThe following is a 3x3 ordered matrix1:\n";
	PrintMatrix(Matrix, 3, 3);

	if (IsPalyndromMatrix(Matrix,3,3))
		cout << "Yes is Palyndrom";
	else
		cout << "No is'nt palyndrom";

	system("pause>0");
}