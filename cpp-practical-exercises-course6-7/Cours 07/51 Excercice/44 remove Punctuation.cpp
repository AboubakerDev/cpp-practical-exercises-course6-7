#include <iostream>
#include <string>
#include <vector>

using namespace std;

string RemovePunctuation(string S1) {
	string S2 = "";
	for (size_t i = 0; i < S1.length() - 1; i++)
	{
		if (!ispunct(S1[i]))
			S2 += S1[i];
	}

	return S2;
}
int main()
{
	string S = "welcome to .JORDON , jordon: ! ?, ..is a nice :;country";
	cout << RemovePunctuation(S);
	return 0;
}