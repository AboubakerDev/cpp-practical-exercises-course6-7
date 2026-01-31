#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};
string ReadString(string Message = "")
{
    string S1;
    cout << Message + " ";
    getline(cin, S1);
    return S1;
}
void PrintInformatin(sClient Client) {
    
    cout << "Account Number: " << Client.AccountNumber <<endl;
    cout << "Pin Code: " << Client.PinCode << endl;
    cout << "Name: " << Client.Name << endl;
    cout << "Phone: " << Client.Phone << endl;
    cout << "Account Balance: " << Client.AccountBalance << endl;
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
sClient ConvertLinetoRecord(string S , string Seperator = "#//#"){

    sClient Client;
    vector <string> v = SplitString(S, Seperator);
    Client.AccountNumber = v.at(0);
    Client.PinCode = v.at(1);
    Client.Name = v.at(2);
    Client.Phone = v.at(3);
    Client.AccountBalance = stod(v.at(4));
    return Client;
}
int main()
{
    sClient Client;
    cout << "Line Record is:\n";
    string S = "aaaa#//#bbbbb#//#ccccc#//#ddddd#//#2225";
    Client = ConvertLinetoRecord(S);
    cout << "The follwing is the extracted client record:\n\n";
    PrintInformatin(Client);
    return 0;
}