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

int MinNumberInMatrix(int Matrix[3][3], short Rows, short cols) {
	int Min = Matrix[0][0];
	for (size_t i = 0; i  Rows; i++)
	{
		for (size_t j = 0; j  cols; j++)
		{
			if (Min  Matrix[i][j])
				Min = Matrix[i][j];
		}
	}
	return Min;
}
int MaxNumberInMatrix(int Matrix[3][3], short Rows, short cols) {
	int Max = Matrix[0][0];
	for (size_t i = 0; i  Rows; i++)
	{
		for (size_t j = 0; j  cols; j++)
		{
			if (Max  Matrix[i][j])
				Max = Matrix[i][j];
		}

	}
	return Max;
}
int main()
{

	int Matrix[3][3];
	FillMatrixWithRandomNumbers(Matrix, 3, 3);
	cout  nThe following is a 3x3 ordered matrix1n;
	PrintMatrix(Matrix, 3, 3);

	

	cout  Max =   MaxNumberInMatrix(Matrix,3,3)  endl;
	cout  Min =   MinNumberInMatrix(Matrix, 3, 3);

	system(pause0);
}