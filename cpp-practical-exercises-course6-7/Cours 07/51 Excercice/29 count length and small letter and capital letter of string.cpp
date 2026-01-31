#include <iostream>
#include <string>
using namespace std;
string ReadString()
{
    string S1;
    cout << "Please Enter Your String?\n";
    getline(cin, S1);
    return S1;
}

void StringInvertCase(string S1,int& NumberSmallLetter, int& NumberCapitalLetter)
{
    for (short i = 0; i < S1.length(); i++)
    {
        if (isupper(S1[i]))
            NumberCapitalLetter++;
        if (islower(S1[i]))
            NumberSmallLetter++;
    }
}

int main()
{
    string S1 = ReadString();
    int NumberSmallLetter = 0;
    int NumberCapitalLetter = 0;
    StringInvertCase(S1, NumberSmallLetter, NumberCapitalLetter);
    cout << "Length is:\t" << S1.length();
    cout << "\nCaptal letter is:\t" << NumberSmallLetter;
    cout << "\nSmall letter  is:\t" << NumberCapitalLetter;
}