#includeiostream
#include random
#include iomanip
using namespace std;


void PrintMatrix(int RandomMatrix[3][3], short Rows, short cols) {
	for (size_t i = 0; i  Rows; i++)
	{
		for (size_t j = 0; j  cols; j++)
		{
			cout  setw(3)  RandomMatrix[i][j];
		}
		cout  endl;
	}
}
int RandomInt(int From, int Into) {
	stdrandom_device rd;
	stdmt19937 gen(rd());
	stduniform_int_distribution dis(From, Into);
	return dis(gen);
}
void FillMatrixWithRandomNumbers(int RandomMatrix[3][3], short Rows, short cols) {
	for (size_t i = 0; i  Rows; i++)
	{
		for (size_t j = 0; j  cols; j++)
		{
			RandomMatrix[i][j] = RandomInt(1, 10);
		}
	}
}
bool ِNumberExitInMatrixOrNo(int Matrix[3][3], short Rows, short cols, int Number) {
	for (size_t i = 0; i  Rows; i++)
	{
		for (size_t j = 0; j  cols; j++)
		{
			if (Matrix[i][j] == Number)
				return true;
		}
	}
	return false;
}
void InterSectedNumbersInTwoMatrix(int Matrix1[3][3], int Matrix2[3][3], short Rows, short cols) {
	for (size_t i = 0; i  Rows; i++)
	{
		for (size_t j = 0; j  cols; j++)
		{
			if (ِNumberExitInMatrixOrNo(Matrix2,3,3, Matrix1[i][j]))
				cout  Matrix1[i][j]  t;
		}
		cout  endl;
	}
}
int main()
{

	int Matrix1[3][3];
	int Matrix2[3][3];
	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout  nThe following is a 3x3 ordered matrix1n;
	PrintMatrix(Matrix1, 3, 3);

	FillMatrixWithRandomNumbers(Matrix2, 3, 3);
	cout  nThe following is a 3x3 ordered matrix2n;
	PrintMatrix(Matrix2, 3, 3);
	

	cout  InterSected numbers in two matrixn;
	InterSectedNumbersInTwoMatrix(Matrix1, Matrix2, 3, 3);
	
	system(pause0);
}