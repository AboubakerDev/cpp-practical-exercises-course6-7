
#include <iostream>
#include <string>
using namespace std;

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
int main()
{
    char C1 = ReadChar();
    if (IsVowl(C1)) 
        cout << C1 << " is vowl";
    else
        cout << C1 << " is'nt vowl";
    return 0;
}