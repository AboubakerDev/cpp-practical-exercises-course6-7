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

string StringInvertCase(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
        S1[i] = isupper(S1[i]) ? tolower(S1[i]) : toupper(S1[i]);
    }
    return S1;
}

int main()
{
    string S1 = ReadString();
    cout << "Strinf after \n" << StringInvertCase(S1);
}