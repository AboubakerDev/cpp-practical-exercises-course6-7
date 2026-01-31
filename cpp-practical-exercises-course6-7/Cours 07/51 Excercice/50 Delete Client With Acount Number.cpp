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
sClient ConvertLinetoRecord(string Line, string Seperator ="#//#")
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
vector <sClient> LoadCleintsDataFromFile(string FileName)
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
bool ConfirmClientDelete()
{
	cout << "\n\nAre you sure you want delete this client y/n?\t";
	char Confirm;
	cin >> Confirm;
	if (Confirm == 'y' || Confirm == 'Y')
		return true;
	else
		return false;
}

vector <string> RemoveClientByAccountNumber(vector <sClient> vClients, string AccountNumber)
{
	vector <string> vClients2;
	for (const sClient& Client : vClients)
	{
		if (Client.AccountNumber != AccountNumber)
			vClients2.push_back(ConvertDataToLine(Client));
	}
	return vClients2;
}

void DeleteClient(string FileName,vector <sClient> vClients, string AccountNumber)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);
	if (MyFile.is_open())
	{
		for (string& Line : RemoveClientByAccountNumber(vClients, AccountNumber))
		{
			MyFile << Line << endl;
		}
		MyFile.close();
		cout << "Client delete successfully.";
	}
}
void DeleteClientWithAcountNumber(string AccountNumber)
{
	vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
	vClients = FindClientsByAccountNumber(vClients, AccountNumber);
	if (PrintAllClientsData(vClients))
		if (ConfirmClientDelete())
		{
			vClients = LoadCleintsDataFromFile(ClientsFileName);
			DeleteClient(ClientsFileName, vClients, AccountNumber);
		}	
}
int main()
{ 
	DeleteClientWithAcountNumber(ReadClientAccountNumber());
	system("pause>0");
	return 0;
}