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
bool CheckIdentity(int Matrix[3][3], short Rows, short cols) {
	for (size_t i = 0; i < Rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (i == j && Matrix[i][j] != 1)
					return false;
			
			else if (i != j && Matrix[i][j] != 0)
					return false;
		}
		return true;
	}
}
int main()
{

	int Matrix[3][3] = { {1,0,0} ,{0,1,0}, {0,0,1} };
	//FillMatrixWithRandomNumbers(Matrix, 3, 3);
	cout << "\nThe following is a 3x3 ordered matrix1:\n";
	PrintMatrix(Matrix, 3, 3);

	

	if (CheckIdentity(Matrix, 3, 3))
		cout << "\nYes the  matrix is identity\n";
	else
		cout << "\nNo the  matrix is't identity\n";



	system("pause>0");
}