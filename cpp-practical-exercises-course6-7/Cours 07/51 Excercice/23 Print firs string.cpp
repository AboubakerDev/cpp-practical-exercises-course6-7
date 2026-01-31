#include <iostream>
#include <string>
using namespace std;
string ReadString()
{
    string S1;
    cout << "Please Enter Your String?\t";
    getline(cin, S1);
    return S1;
}
void PrintFirstLetterOfEachWord(string User_String) {

    cout << User_String[0] << endl;
    for (int i = 0; i < User_String.length(); i++) {
        if (User_String[i-1] == ' ')
            cout << User_String[i] << endl;

    }
}
int main()
{
    PrintFirstLetterOfEachWord(ReadString());
}