#include<iostream>
#include <random>
using namespace std;
int RandomInt(int From,int Into) {
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
			cout << RandomMatrix[i][j] << " ";
		}
		cout << endl;
	}
}
void FillMatrixWithRandomNumbers(int RandomMatrix[3][3], short Rows, short cols) {
	for (size_t i = 0; i < Rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			RandomMatrix[i][j] = RandomInt(0,100);
		}
	}
}
int main()
{
	
	int RandomMatrix[3][3];
	FillMatrixWithRandomNumbers(RandomMatrix,3,3);
	PrintMatrix(RandomMatrix,3,3);
	
	return 0;
}