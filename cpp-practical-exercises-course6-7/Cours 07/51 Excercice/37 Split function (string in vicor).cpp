
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
void PrintVector(const vector<string>& v) {
    for (string x : v) {
        cout << x << endl;
    }
}
vector<string> Split(string S,char Dil) { 
    bool test = false; //To avoid spaces at the beginning
    string sToken = "";
    vector<string> v;
    for (size_t i = 0; i < S.length(); i++)
    {
        if (S[i] != Dil) {
            sToken += S[i];
            test = true;
        }
        else if (test) {
            v.push_back(sToken);
            sToken = "";
            while (S[i + 1] == ' ')
                i++;
        }
    }
    return v;
}
int main()
{
    vector<string> v = Split(ReadString(),' ');
    cout << "Tokens= " << v.size() << endl;
    PrintVector(v);
    return 0;
}