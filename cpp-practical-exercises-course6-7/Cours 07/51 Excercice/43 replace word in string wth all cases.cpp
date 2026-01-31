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
vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord; // define a string variable
    // use find() function to get the position of the delimiters
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length()); /* erase() until
        positon and move to next word. */
    }
    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }
    return vString;
}
string LowerAllString(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
        S1[i] = tolower(S1[i]);
    }
    return S1;
}

vector<string> ReplaceWord(vector<string> v, string StringToReplace, string ReplaceTo,bool Machcase=true) {
    for (string& S : v) {
        if (Machcase) {
            if (S == StringToReplace)
                S = ReplaceTo;
        }
        else
        {
            if (LowerAllString(S) == LowerAllString(StringToReplace))
                S = ReplaceTo;
        }
    }
    return v;
}
void PrintVector(const vector<string>& v)
{
    for (const string& s : v)
    {
        cout << s << " ";
    }
}
int main()
{
    string S = "welcome to JORDON , jordon is a nice country";
    string StringToReplace = "JORDON", ReplaceTo = "USA";
    vector<string> v = SplitString(S," ");
    v = ReplaceWord(v, StringToReplace, ReplaceTo);
    cout << "After replace with mach case:\n";
    PrintVector(v);
    v = ReplaceWord(v, StringToReplace, ReplaceTo,false);
    cout << "\nAfter replace with dont mach case:\n";
    PrintVector(v);
    return 0;
}