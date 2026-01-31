#include <iostream>
#include <string>
#include <vector>
#include<fstream>

using namespace std;

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

int NumberOfClientes(string NameFile) {
    fstream MyFile;
    MyFile.open("MyFile.txt", ios::in);
    int Count = 0;
    string Line;
    if (MyFile.is_open())
    {
        while (getline(MyFile, Line))
        {
            Count++;
        }
        MyFile.close();
    }
    return Count;
}

void Table(string NameFile)
{
    cout << "                            Client list (" << NumberOfClientes(NameFile) << ") client (s)." << endl;
    cout << "______________________________________________________________________________________________\n";
    cout << "\n|Account Number    |Pin Code    |Name               |Phone      |Balance    \n";
    cout << "______________________________________________________________________________________________\n";

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

sClient ConvertLinetoRecord(string S, string Seperator = "#//#") {

    sClient Client;
    vector <string> v = SplitString(S, Seperator);
    Client.AccountNumber = v.at(0);
    Client.PinCode = v.at(1);
    Client.Name = v.at(2);
    Client.Phone = v.at(3);
    Client.AccountBalance = stod(v.at(4));
    return Client;
}

void PrintClient(sClient Client)
{
    cout << "| " << Client.AccountNumber << "                ";
    cout << "| " << Client.PinCode << "          ";
    cout << "| " << Client.Name << "                 ";
    cout << "| " << Client.Phone << "         ";
    cout << "| " << Client.AccountBalance << endl;
}

void ShowClients(string NameFile)
{
    Table(NameFile);
    fstream MyFile;
    MyFile.open("MyFile.txt", ios::in);
    string Line;
    sClient Client;
    if (MyFile.is_open())
    {
        while (getline(MyFile, Line))
        {
            Client = ConvertLinetoRecord(Line);
            PrintClient(Client);
        }
        MyFile.close();
    }
}

int main()
{
    ShowClients("MyFile.txt");
    return 0;
}