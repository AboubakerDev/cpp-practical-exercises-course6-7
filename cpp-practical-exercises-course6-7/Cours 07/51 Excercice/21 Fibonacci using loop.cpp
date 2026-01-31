#include <iostream>
using namespace std;
void printArray(int Array[], int Length) {
	for (int i = 0; i < Length; i++) {        
		cout << Array[i] << "\t";
	}
}
void Fibonacci(int Array[], int Length) {
	Array[0] = 1;
	Array[1] = 1;
	for (int i = 2; i < Length; i++) {
		Array[i] = Array[i-1]+ Array[i-2];
	}
}
int main() {
	int Array[100];
	int Number;
	int i = 1;
	do {
		cout << "\n"<< i <<":\t";
		/*cin >> Number;*/
		Fibonacci(Array, i);
		printArray(Array, i);
		i++;
	} while (i<15);
	return 0;
}