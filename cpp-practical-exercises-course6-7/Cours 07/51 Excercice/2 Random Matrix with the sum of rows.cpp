#include<iostream>
#include <random>
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
			cout << RandomMatrix[i][j] << "\t";
		}
		cout << endl;
	}
}
void PrintArray(int Array[3], short length) {
	for (size_t i = 0; i < length; i++)
	{
		cout << Array[i]<< "\t";
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
void SumOfRowsMatrix(int RandomMatrix[3][3], short Rows , short Cols, int SumOfRowsMatrix[3]) {
	for (int i = 0 ; i < Cols; i++)
	{
		SumOfRowsMatrix[i] = 0;
	}
	for (int i = 0; i < Cols; i++)
	{
		for (int j = 0; j < Rows; j++)
		{
           SumOfRowsMatrix[i] += RandomMatrix[i][j];
		}
	}
}
int main()
{

	int RandomMatrix[3][3];
	FillMatrixWithRandomNumbers(RandomMatrix, 3, 3);
	PrintMatrix(RandomMatrix, 3, 3); 
	int Array[3];
	SumOfRowsMatrix(RandomMatrix,3,3, Array);
	PrintArray(Array,3);

	return 0;
}