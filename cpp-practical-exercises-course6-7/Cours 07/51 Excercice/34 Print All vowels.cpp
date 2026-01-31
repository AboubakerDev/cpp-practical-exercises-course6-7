
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
void CountAllVowls(string S) {
    cout << "Vowels in string are: ";
    for (size_t i = 0; i < S.length(); i++)
    {
        if (IsVowl(S[i]))
            cout << S[i] << " ";
    }
}
int main()
{
    CountAllVowls(ReadString());
    return 0;
}