#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

void LoadDataFromFileToVector(string NameFile, vector <string>& V) {
	fstream MyFile;
	MyFile.open("MyFile.txt", ios::in);
	string Line;

	if (MyFile.is_open()) {

		while (getline(MyFile, Line)) {
			V.push_back(Line);
		}
		MyFile.close();
	}
}

void SaveVectorToFile(string NameFile,vector <string> V) {
	fstream MyFile;
	MyFile.open("MyFile.txt", ios::out);
	if (MyFile.is_open()) {
		for (string &Line : V)
		{
			if (Line != "") {
				MyFile << Line << endl;
			}
		}
		MyFile.close();
	}
 }

void DeleteRecordFromFile(string FileName,string Record){
	vector <string> v1;
	LoadDataFromFileToVector(FileName, v1);

	for (string& Line : v1)
	{
		if (Line == Record) {
			Line = "";
		}
	}
	SaveVectorToFile(FileName, v1);
}

void PrintFileContent(string FileName) {
	fstream MyFile;
	MyFile.open("MyFile.txt", ios::in);
	string Line;

	if (MyFile.is_open()) {

		while (getline(MyFile, Line)) {
			cout << Line << endl;
		}
		MyFile.close();
	}
}

int main()
{
	vector <string> vFileContenet{ "0","1","2","","5"};
	SaveVectorToFile("MyFile.txt", vFileContenet);
	cout << "File Content Before Delete.\n";
	PrintFileContent("MyFile.txt");
	DeleteRecordFromFile("MyFile.txt", "8");
	cout << "\n\nFile Content After Delete.\n";
	PrintFileContent("MyFile.txt");
	return 0;
}