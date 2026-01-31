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
string Join(string S1[], int Length, string Separator) {
    string S2 = "";
    for (size_t i = 0; i < Length; i++)
    {
        S2 += S1[i];
        if (i != Length - 1)
            S2 += Separator;
    }
    return S2;
}
string Join(vector<string> V, string Separator) {
    string S = "";
    for (size_t i = 0; i < V.size(); i++)
    {
        S += V[i];
        if (i != V.size() - 1)
            S += Separator;
    }
    return S;
}
int main()
{
    vector <string> S = { "aaa","bbb","ccc" };
    string S2[3] = {"AAA","BBB","CCC"};
    string Separator = ReadString();
    cout << "join:\n" << Join(S, Separator) <<endl;
    cout << "join:\n" << Join(S2,3, Separator);
    return 0;
}