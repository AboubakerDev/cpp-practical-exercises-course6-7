
#include <iostream>
#include <string>
#include <vector>

using namespace std;
string ReadString()
{
    string S1;
    cout << "Please Enter Your String?\n";
    getline(cin, S1);
    return S1;
}
string TrimLeft(string S1) {
    string S2="";
    int i = 0;
    while (S1[i] == ' ') {
        i++;
    }
    for (int j = i; j < S1.length(); j++)
    {
        S2 += S1[j];
    }
    return S2;
}
string TrimRight(string S1) {
    string S2 = "";
    int i = S1.length();
    while (S1[i] == ' ') {
        i--;
    }
    for (int j = 0; j < i; j++)
    {
        S2 += S1[j];
    }
    return S2;
}
string Trim(string S1) {
    S1 = TrimRight(S1);
    S1 = TrimLeft(S1);
    return S1;
}
int main()
{
    string S = ReadString();
    cout << "Tirm left is:\n" << TrimLeft(S) << endl;
    cout << "Tirm right is:\n" << TrimRight(S) << endl;
    cout << "Tirm is:\n" << Trim(S) << endl;
    return 0;
}