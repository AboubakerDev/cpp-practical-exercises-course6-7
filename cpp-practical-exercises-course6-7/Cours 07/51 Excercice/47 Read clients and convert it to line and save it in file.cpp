#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include <limits>

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

string ConvertDataToLine(sClient Client, string Seperator = "#//#") {
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
}


sClient ReadInformatin(sClient Client) {
    cout << "Adding new client:\n\n";
    /*cin.ignore(numeric_limits<streamsize>::max(), '\n');*/
    Client.AccountNumber = ReadString("Enter account number?");
    Client.PinCode = ReadString("Enter PinCode?");
    Client.Name = ReadString("Enter Name?");
    Client.Phone = ReadString("Enter Phone?");
    cout << "Enter AcountBalance?";
    cin >> Client.AccountBalance;
    return Client;
}

void SaveStringToFile(string NameFile, string S) {
    fstream MyFile;
    MyFile.open("MyFile.txt", ios::app);
    if (MyFile.is_open()) {
        MyFile << S << endl;
        MyFile.close();
        cout << "\n\nClient Added successfully, ";
    }
}

void AddClients() {
    sClient Client;
    string S;
    char Next = 'y';
    do {
        system("cls");
        Client = ReadInformatin(Client);
        S = ConvertDataToLine(Client);
        SaveStringToFile("MyFile.txt", S);
        cout << "do you want add more clients?";
        cin >> Next;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (Next == 'y' || Next == 'Y');
}

int main()
{
    AddClients();
    return 0;
}