
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
char ReadChar()
{
    char C;
    cout << "Please Enter Your Char:\t";
    cin >> C;
    return C;
}
char InvertLetterCase(char char1)
{
    return isupper(char1) ? tolower(char1) : toupper(char1);
}
int NumbercharInString(string S, char C)
{
    int Counter = 0;
    for (short i = 0; i < S.length(); i++)
    {
        if (S[i] == C)
            Counter++;
    }
    return Counter;
}
int NumbercharInStringUsingOtherCase(string S, char C)
{
    int Counter = 0;
    for (short i = 0; i < S.length(); i++)
    {
        if (S[i] == C || S[i]== InvertLetterCase(C))
            Counter++;
    }
    return Counter;
}
int main()
{
    string S1 = ReadString();
    char C1 = ReadChar();
    cout << "\nNmber of: " << C1 << " is:  " << NumbercharInString(S1, C1);
    cout << "\nNmber of: " << C1 << " Or " << InvertLetterCase(C1) <<" is:  " << NumbercharInStringUsingOtherCase(S1, C1);
    cout << "\nNmber of: " << InvertLetterCase(C1) << " is:  " << NumbercharInString(S1, InretOtherCase(C1));
    return 0;
}