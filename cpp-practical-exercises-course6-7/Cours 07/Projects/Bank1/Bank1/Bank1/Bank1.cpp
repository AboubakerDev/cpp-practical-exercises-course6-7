#include <iostream>
#include <iomanip>  
#include <string>
#include<fstream>
#include <conio.h> 
#include<vector>
using namespace std;

const string ClientsFileName = "MyFile.txt";
struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

enum MainMenuOptions
{
    SHOW_CLIENT_LIST = 1,
    ADD_NEW_CLIENT,
    DELETE_CLIENT,
    UPDATE_CLIENT_INFO,
    FIND_CLIENT,
    EXIT_PROJECT
};

void PrintClientCard(sClient Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code : " << Client.PinCode;
    cout << "\nName : " << Client.Name;
    cout << "\nPhone : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
}

void PrintClientRecord(sClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void PrintAllClientsData(vector <sClient> vClients)
{
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout <<
        "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout <<
        "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    for (sClient Client : vClients)
    {
        PrintClientRecord(Client);
        cout << endl;
    }
    cout <<
        "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
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

void MainMenu()
{
    string text = "Main Minur Screen";
    int width = 60;

    cout << "================================================================" << endl;
    cout << setw((width + text.length()) / 2) << text << endl;
    cout << "===============================================================" << endl;
    int margin = 10;
    text = "[1] Show Client List.";
    cout << setw(margin) << "" << text << endl;
    text = "[2] Add New Client.";
    cout << setw(margin) << "" << text << endl;
    text = "[3] Delete Client.";
    cout << setw(margin) << "" << text << endl;
    text = "[4] Update Client Info.";
    cout << setw(margin) << "" << text << endl;
    text = "[5] Find Client.";
    cout << setw(margin) << "" << text << endl;
    text = "[6] Exit.";
    cout << setw(margin) << "" << text << endl;
    cout << "===============================================================" << endl;
    cout << "Choose what do want to do? [1 to 6]?\t";
}

string ReadString(string prompt = "")
{
    string input;
    cout << prompt << " ";
    getline(cin, input);
    return input;
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

sClient ReadInformatin(sClient Client, string AccountNumber) {
    Client.AccountNumber = AccountNumber;
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

void ScreenTitle(string text, int width = 40)
{
    cout << endl;
    cout << "---------------------------------------" << endl;
    cout << setw((width + text.length()) / 2) << text << endl;
    cout << "---------------------------------------" << endl;
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

bool FindClientByAccountNumber(string AccountNumber, sClient& Client)
{
    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    for (sClient C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }
    return false;
}

void AddClients() {
    sClient Client;
    string S;
    char Next = 'y';
    do {
        system("cls");
        ScreenTitle("Add New Clients Screen");
        cout << "Adding new client:\n\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string AccountNumber;
        do
        {
            AccountNumber = ReadString("Enter account number?");
            if (FindClientByAccountNumber(AccountNumber, Client)) {
                cout << "Client with [" << AccountNumber << "] already exists,";
            }
            else break;
        } while (true);

        Client = ReadInformatin(Client, AccountNumber);
        S = ConvertDataToLine(Client);
        SaveStringToFile("MyFile.txt", S);
        cout << "do you want add more clients?";
        cin >> Next;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (Next == 'y' || Next == 'Y');
}

void PressAnyKey()
{
    cout << "\n\n\nPress any key to go back to main menu...";
    _getch();
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
    for (sClient& C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForDelete = true;
            return true;
        }
    }
    return false;
}

vector <sClient> SaveCleintsDataToFile(string FileName, vector <sClient> vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);//overwrite
    string DataLine;
    if (MyFile.is_open())
    {
        for (sClient C : vClients)
        {
            if (C.MarkForDelete == false)
            {
                //we only write records that are not marked for delete.
                DataLine = ConvertDataToLine(C);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    return vClients;
}

bool DeleteClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
    sClient Client;
    char Answer = 'n';
    if (FindClientByAccountNumber(AccountNumber, Client))
    {
        PrintClientCard(Client);
        cout << "\n\nAre you sure you want delete this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            MarkClientForDeleteByAccountNumber(AccountNumber,
                vClients);
            SaveCleintsDataToFile(ClientsFileName, vClients);
            //Refresh Clients
            vClients = LoadCleintsDataFromFile(ClientsFileName);
            cout << "\n\nClient Deleted Successfully.";
            return true;
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber
            << ") is Not Found!";
        return false;
    }
}

string ReadClientAccountNumber()
{
    string AccountNumber = "";
    cout << "\nPlease enter AccountNumber? ";
    cin >> AccountNumber;
    return AccountNumber;
}

void DeleteClient()
{
    ScreenTitle("Delete Clients Screen");
    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    DeleteClientByAccountNumber(AccountNumber, vClients);
}

sClient ChangeClientRecord(string AccountNumber)
{
    sClient Client;
    Client.AccountNumber = AccountNumber;
    cout << "\n\nEnter PinCode? ";
    getline(cin >> ws, Client.PinCode);
    cout << "Enter Name? ";
    getline(cin, Client.Name);
    cout << "Enter Phone? ";
    getline(cin, Client.Phone);
    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;
    return Client;
}

bool UpdateClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
    sClient Client;
    char Answer = 'n';
    if (FindClientByAccountNumber(AccountNumber, Client))
    {
        PrintClientCard(Client);
        cout << "\n\nAre you sure you want update this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            for (sClient& C : vClients)
            {
                if (C.AccountNumber == AccountNumber)
                {
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }
            }
            SaveCleintsDataToFile(ClientsFileName, vClients);
            cout << "\n\nClient Updated Successfully.";
            return true;
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber
            << ") is Not Found!";
        return false;
    }
}

void UpdateClient()
{
    ScreenTitle("Update Client Info Screen", 50);
    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    UpdateClientByAccountNumber(AccountNumber, vClients);
}

void FindClient()
{
    ScreenTitle("Find Client Screen");
    sClient Client;
    string AccountNumber = ReadClientAccountNumber();
    if (!FindClientByAccountNumber(AccountNumber, Client))
    {
        cout << "\nClient with Account Number (" << AccountNumber
            << ") is Not Found!";
    }
    else
    {
        PrintClientCard(Client);
    }
}
void StartProject()
{
    system("cls");
    MainMenu();
    int choice;
    cin >> choice;
    switch (choice)
    {
    case SHOW_CLIENT_LIST:
        system("cls");
        PrintAllClientsData(LoadCleintsDataFromFile(ClientsFileName));
        PressAnyKey();
        StartProject();
        break;
    case ADD_NEW_CLIENT:
        system("cls");
        AddClients();
        PressAnyKey();
        StartProject();
        break;
    case DELETE_CLIENT:
        system("cls");
        DeleteClient();
        PressAnyKey();
        StartProject();
        break;
    case UPDATE_CLIENT_INFO:
        system("cls");
        UpdateClient();
        PressAnyKey();
        StartProject();
        break;
    case FIND_CLIENT:
        system("cls");
        FindClient();
        PressAnyKey();
        StartProject();
        break;
    case EXIT_PROJECT:
        system("cls");
        ScreenTitle("Program Ends :-)");
        break;
    default:
        cout << "Invalid choice!" << endl;
    }
}

int main()
{
    StartProject();
    return 0;
}

