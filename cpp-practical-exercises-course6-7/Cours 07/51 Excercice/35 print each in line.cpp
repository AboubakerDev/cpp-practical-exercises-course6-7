
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

void PrintAllWords(string S) {
    bool test = false; //To avoid spaces at the beginning
    cout << "Words in string are:\n";
    for (size_t i = 0; i < S.length(); i++)
    {
        if (S[i] != ' ') {
            cout << S[i];
            test = true;
        }
        else if(test){
            cout << endl;
            while (S[i + 1] == ' ')
                i++;
        }
    }
}
int main()
{
    PrintAllWords(ReadString());
    return 0;
}