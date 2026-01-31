#include<iostream>
#include <random>
#include <iomanip>
using namespace std;
int RandomInt(int From, int Into) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(From, Into);
	return dis(gen);
}
void PrintMatrix(int RandomMatrix[3][3], short Rows, short cols) {
	for (size_t i = 0; i < Rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			cout << setw(3) <<  RandomMatrix[i][j];
		}
		cout << endl;
	}
}

void FillMatrixWithRandomNumbers(int RandomMatrix[3][3], short Rows, short cols) {
	for (size_t i = 0; i < Rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			RandomMatrix[i][j] = RandomInt(0, 100);
		}
	}
}
int RowSum(int arr[3][3], short RowNumber, short Cols)
{
	int Sum = 0;
	for (short j = 0; j <= Cols - 1; j++)
	{
		Sum += arr[RowNumber][j];
	}
	return Sum;
}
int ColSum(int arr[3][3] , short Rows, short ColNumber)
{
	int Sum = 0;
	for (short j = 0; j <= Rows - 1; j++)
	{
		Sum += arr[j][ColNumber];
	}
	return Sum;
}
void PrintEachRowSum(int arr[3][3], short Rows, short Cols, int Array[])
{
	//cout << "\nThe the following are the sum of each row in thematrix:\n";
		for (short i = 0; i < Rows; i++)
		{
			Array[i] = RowSum(arr, i, Cols);
			//cout << " Row " << i + 1 << " Sum = " << RowSum(arr, i,Cols) << endl;
		}
}
void PrintEachColSum(int arr[3][3], short Rows, short Cols, int Array[])
{
	//cout << "\nThe the following are the sum of each row in thematrix:\n";
	for (short j = 0; j < Rows; j++)
	{
		Array[j] = ColSum(arr, Cols,j);
		//cout << " Row " << i + 1 << " Sum = " << RowSum(arr, i,Cols) << endl;
	}
}
void PrintArray(int Array[3], short length) {
	for (size_t i = 0; i < length; i++)
	{
		cout << "Row " << i+1 << " sum = " << Array[i] << "\n";
	}
}
int main()
{

	int RandomMatrix[3][3];
	int Array[3];
	FillMatrixWithRandomNumbers(RandomMatrix, 3, 3);
	cout << "\nThe following is a 3x3 random matrix:\n";
	PrintMatrix(RandomMatrix, 3, 3);
	/*PrintEachRowSum(RandomMatrix,3,3, Array);*/
	/*cout << "\nThe the following are the sum of each row in thematrix:\n";
	PrintArray(Array,3);*/
	PrintEachColSum(RandomMatrix, 3, 3, Array); 
	cout << "\nThe the following are the sum of each col in thematrix:\n";
	PrintArray(Array, 3);
	return 0;
}