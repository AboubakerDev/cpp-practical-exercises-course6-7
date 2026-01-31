
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
bool IsVowl(char C) {
    C =tolower(C) ;
      return (C == 'a' || C == 'o' || C == 'u' || C == 'i' || C == 'e');
}
short CountAllVowls(string S) {
    short counter = 0;
    for (size_t i = 0; i < S.length(); i++)
    {
        if (IsVowl(S[i]))
            counter++;
    }
    return counter;
}
int main()
{
    cout << "vowls number is: " << CountAllVowls(ReadString());
    return 0;
}