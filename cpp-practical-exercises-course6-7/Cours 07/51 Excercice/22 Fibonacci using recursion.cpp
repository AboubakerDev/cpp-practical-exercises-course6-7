#include <iostream>
using namespace std;
void Fibonacci(int Number,int Prev1, int Prev2) {
	int FibNumber = 0;
	if (Number > 0) {
		FibNumber = Prev1 + Prev2;
		Prev2 = Prev1;
		Prev1 = FibNumber;
		cout << FibNumber << "  ";
		Fibonacci(Number-1,Prev1,Prev2);
	}
}
int main() {
	Fibonacci(10,0,1);
	return 0;
}
