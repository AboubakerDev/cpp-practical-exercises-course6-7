
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

short PrintAllWords(string S) {
    bool test = false; //To avoid spaces at the beginning
    short Counter = 0;
    cout << "Number of words in string is:\n";
    for (size_t i = 0; i < S.length(); i++)
    {
        if (S[i] != ' ') {
            test = true;
        }
        else if (test) {
            Counter++;
            while (S[i + 1] == ' ')
                i++;
        }
    }
    return Counter;
}
int main()
{
    cout << PrintAllWords(ReadString());
    return 0;
}