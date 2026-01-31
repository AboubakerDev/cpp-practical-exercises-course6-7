#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
const string ClientsFileName = "Clients.txt";
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
		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")
	{
		vString.push_back(S1); // it adds last word of the string.
	}
	return vString;
}
sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{
	sClient Client;
	vector<string> vClientData;
	vClientData = SplitString(Line, Seperator);
	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]);//cast string to double
	return Client;
}
vector <sClient> LoadClientsDataFromFile(string FileName)
{
	vector <sClient> vClients;
	fstream MyFile;
	MyFile.open(FileName, ios::in);//read Mode
	if (MyFile.is_open())
	{
		string Line;
		sClient Client;
		while (getline(MyFile, Line))
		{
			Client = ConvertLinetoRecord(Line);
			vClients.push_back(Client);
		}
		MyFile.close();
	}
	return vClients;
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
sClient ReadInformatinNewClient(sClient Client, string AccountNumber) {
	cout << "Adding new client:\n\n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	Client.AccountNumber = AccountNumber;
	Client.PinCode = ReadString("Enter PinCode?");
	Client.Name = ReadString("Enter Name?");
	Client.Phone = ReadString("Enter Phone?");
	cout << "Enter AcountBalance?";
	cin >> Client.AccountBalance;
	return Client;
}
void PrintClientCard(sClient Client)
{
	cout << "\nThe following are the client details:\n";
	cout << "\nAccout Number: " << Client.AccountNumber;
	cout << "\nPin Code : " << Client.PinCode;
	cout << "\nName : " << Client.Name;
	cout << "\nPhone : " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;
}
bool PrintAllClientsData(vector <sClient> vClients)
{
	if (vClients.empty())
	{
		cout << "Client with this acount number in not find!";
		return false;
	}
	else
	{
		for (size_t i = 0; i < vClients.size(); i++)
		{
			PrintClientCard(vClients[i]);
		}
		return true;
	}
}
vector <sClient> FindClientsByAccountNumber(vector <sClient> vClients, string AccountNumber)
{
	vector <sClient> vClients2;
	for (const sClient& Client : vClients)
	{
		if (Client.AccountNumber == AccountNumber)
			vClients2.push_back(Client);
	}
	return vClients2;
}
string ReadClientAccountNumber()
{
	string AccountNumber = "";
	cout << "\nPlease enter AccountNumber? ";
	cin >> AccountNumber;
	return AccountNumber;
}
bool ConfirmClientUpdate(sClient& NewClient,string AccountNumber)
{
	cout << "\n\nAre you sure you want update this client y/n?\t";
	char Confirm;
	cin >> Confirm;
	if (Confirm == 'y' || Confirm == 'Y')
	{
		NewClient = ReadInformatinNewClient(NewClient,AccountNumber);
		return true;
	}

	else
		return false;
}

vector <string> UpdateClientByAccountNumber(vector <sClient> vClients, sClient NewClient, string AccountNumber)
{
	vector <string> vClients2;
	for (size_t i = 0; i < vClients.size(); i++)
	{
		if (vClients[i].AccountNumber != AccountNumber)
			vClients2.push_back(ConvertDataToLine(vClients[i]));
		else
			vClients2.push_back(ConvertDataToLine(NewClient));
	}
	return vClients2;
}

void UpdateClient(string FileName, vector <sClient> vClients, sClient NewClient, string AccountNumber)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);
	if (MyFile.is_open())
	{
		for (string& Line : UpdateClientByAccountNumber(vClients, NewClient, AccountNumber))
		{
			MyFile << Line << endl;
		}
		MyFile.close();
		cout << "Client update successfully.";
	}
}
void UpdateClientWithAcountNumber(string AccountNumber)
{
	sClient NewClient;
	vector <sClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	vClients = FindClientsByAccountNumber(vClients, AccountNumber);
	if (PrintAllClientsData(vClients))
		if (ConfirmClientUpdate(NewClient, AccountNumber))
		{
			vClients = LoadClientsDataFromFile(ClientsFileName);
			UpdateClient(ClientsFileName, vClients, NewClient, AccountNumber);
		}
}
int main()
{
	UpdateClientWithAcountNumber(ReadClientAccountNumber());
	system("pause>0");
	return 0;
}