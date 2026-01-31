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
bool ِNumberExitInMatrixOrNo(int Matrix[3][3], short Rows, short cols, int Number) {
	for (size_t i = 0; i < Rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (Matrix[i][j] == Number)
				return true;
		}
	}
	return false;
}
int main()
{

	int Matrix[3][3] = { {15,0,0} ,{0,15,0}, {0,5,15} };
	FillMatrixWithRandomNumbers(Matrix, 3, 3);
	cout << "\nThe following is a 3x3 ordered matrix1:\n";
	PrintMatrix(Matrix, 3, 3);
	int Number;

	do {
		cout << "\nEnter the number to check in matrix:\t";
		cin >> Number;
		if (ِNumberExitInMatrixOrNo(Matrix, 3, 3, Number))
			cout << "Yes " << Number << " is exist";
		else
			cout << "NO " << Number << " is'nt exist";
	} while (true);



	system("pause>0");
}