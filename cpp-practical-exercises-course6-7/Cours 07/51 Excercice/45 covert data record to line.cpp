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
string ReadString(string Message)
{
    string S1;
    cout << Message <<" ";
    getline(cin, S1);
    return S1;
}
sClient ReadInformatin(sClient Client) {
    cout << "Please Enter Client Data:\n\n";
    Client.AccountNumber = ReadString("Enter account number?");
    Client.PinCode = ReadString("Enter PinCode?");
    Client.Name = ReadString("Enter Name?");
    Client.Phone = ReadString("Enter Phone?");
    cout << "Enter AcountBalance?";
    cin >> Client.AccountBalance;
    return Client;
}
string ConvertDataToLine(sClient Client,string Seperator="#//#") {
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
}
int main()
{
    sClient Client;
    Client = ReadInformatin(Client);
    cout<< "Client Record for saving is:\n" << ConvertDataToLine(Client);
	return 0;
}