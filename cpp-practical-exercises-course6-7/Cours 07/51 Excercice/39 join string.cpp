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
string Join(vector<string> V, string Separator) {
    string S="";
    for (size_t i = 0; i < V.size(); i++)
    {
        S += V[i];
        if(i != V.size() - 1)
        S += Separator;
    }
    return S;
}
int main()
{
    vector <string> S = {"aaa","bbb","ccc"};
    string Separator = ReadString();
    cout << "join:\n" << Join(S, Separator);
    return 0;
}