#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

using namespace std;

class clsBankClient : public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1 , AddNew = 2 };
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkForDelete = false;


	static clsBankClient _ConvertLineToRecordObject(string Line, string Seperator = "//##//" ){

		vector <string> vClient;
		vClient = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::UpdateMode, vClient[0], vClient[1], vClient[2], vClient[3], vClient[4], vClient[5], stod(vClient[6]));
	}

	static clsBankClient _GetEmptyClientObject() {
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static string _ConvertRecordToLine(clsBankClient Clint, string delim = "//##//") {

		string sRecord;

		sRecord += Clint.FirstName + delim;
		sRecord += Clint.LastName + delim;
		sRecord += Clint.Email + delim;
		sRecord += Clint.Phone + delim;
		sRecord += Clint.AccountNumber() + delim;
		sRecord += Clint.PinCode + delim;
		sRecord += to_string(Clint.AccountBalance);

		return sRecord;

	}

	static vector <clsBankClient> _LoadFileContentToVector() {
		vector <clsBankClient> vClint;
		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open()) {

			string Line;
			
			while (getline(MyFile, Line)) {


				clsBankClient client = _ConvertLineToRecordObject(Line);

				vClint.push_back(client);

			}

			MyFile.close();
		}
		return vClint;
	}

	static vector <clsBankClient> _SaveDataClientsToFile(vector<clsBankClient>& vClint) {

		fstream MyFile;

		MyFile.open("Clients.txt", ios::out);
		string Line;
		if (MyFile.is_open()) {



			for (clsBankClient& C : vClint) {
				if (C._MarkForDelete == false) {
					Line = _ConvertRecordToLine(C);
					MyFile << Line << endl;
				}
			}

			MyFile.close();
		}
		return vClint;
	}

	void _AddLinesToFiles(string Line) {
		fstream MyFile;

		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open()) {

			MyFile << Line << endl;

			MyFile.close();
		}

	}

	 string _GetLogLineTransfer( clsBankClient DestinationClient, float CurrentAmount, string delim = "//##//") {
		string Record;

		Record = clsDate::GetSystemDateTime() + delim;
		Record += AccountNumber() + delim;
		Record += DestinationClient.AccountNumber() + delim;
		Record += to_string(CurrentAmount) + delim;
		Record += to_string(AccountBalance) + delim;
		Record += to_string(DestinationClient.AccountBalance) + delim;
		Record += CurrentObject.UserName();

		return Record;
	}

	 void _AddLogsTrasfer( clsBankClient DestinationClient, float CurrentAmount) {
		string Line = _GetLogLineTransfer( DestinationClient, CurrentAmount);
		fstream MyFile;

		MyFile.open("LogsTrasfer.txt", ios::out | ios::app);

		if (MyFile.is_open()) {

			MyFile << Line << endl;

			MyFile.close();
		}
	}


	void _AddNew() {
		_AddLinesToFiles(_ConvertRecordToLine(*this));
	}

	void _Update() {
		vector <clsBankClient> _vClient;
		_vClient = _LoadFileContentToVector();

		for (clsBankClient& C : _vClient) {
			if (C.AccountNumber() == AccountNumber()) {

				C = *this;
				break;
			}
		}

		_SaveDataClientsToFile(_vClient);


	}

public:
	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone
		, string AccountNumber, string Pincode, float AccountBalance) :
		clsPerson(FirstName, LastName, Email, Phone) {

		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = Pincode;
		_AccountBalance = AccountBalance;

	}

	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

	string AccountNumber() {
		return _AccountNumber;
	}

	void setPinCode(string PinCode) {
		_PinCode = PinCode;
	}

	bool GetMarkForDelete() {
		return _MarkForDelete;
	}

	string getPinCode() {
		return _PinCode;
	}

	__declspec (property(get = getPinCode, put = setPinCode))string PinCode;


	void setAccountBalance(float AccountBalance) {
		_AccountBalance = AccountBalance;
	}

	float getAccountBalance() {
		return _AccountBalance;
	}

	__declspec (property(get = getAccountBalance, put = setAccountBalance))float AccountBalance;


	enum enSaveClient {
		SussccesChanges = 0,
		FaildChanges = 1,
		FaildAddNewClientExists

	};
	
	enSaveClient Save() {
		switch (_Mode)
		{
		case enMode::EmptyMode:
			return enSaveClient::FaildChanges;

		case enMode::UpdateMode:
			_Update();
			return enSaveClient::SussccesChanges;
		case enMode::AddNew:
			if (IsclientExist(AccountNumber())) {
				return enSaveClient::FaildAddNewClientExists;
			}

			_AddNew();
			return enSaveClient::SussccesChanges;
	

		}
	}



	static clsBankClient FindClient(string AccounNumber) {

		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open()) {

			string Line;

			while (getline(MyFile, Line)) {

				clsBankClient clint = _ConvertLineToRecordObject(Line);
				if (clint.AccountNumber() == AccounNumber) {
					MyFile.close();
					return clint;
				}


			}


		}
		return _GetEmptyClientObject();
	}

	bool Delete() {
		vector <clsBankClient> _vClient;
		_vClient = _LoadFileContentToVector();

		for (clsBankClient& C : _vClient) {
			if (C.AccountNumber() == AccountNumber()) {
				C._MarkForDelete = true;
				break;
			}
		}

		_SaveDataClientsToFile(_vClient);
		*this = _GetEmptyClientObject();

		return true;



	}

	static clsBankClient FindClient(string AccounNumber, string PinCode) {

		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open()) {

			string Line;

			while (getline(MyFile, Line)) {

				clsBankClient clint = _ConvertLineToRecordObject(Line);
				if (clint.AccountNumber() == AccounNumber && clint.PinCode == PinCode) {
					MyFile.close();
					return clint;
				}


			}


		}
		return _GetEmptyClientObject();
	}

	static bool IsclientExist(string AccountNumber) {

		clsBankClient Client = clsBankClient::FindClient(AccountNumber);
		return (!Client.IsEmpty());

	}

	static clsBankClient GetAddNewClientObject(string AccountNumber) {
		return clsBankClient(enMode::AddNew, "", "", "", "", AccountNumber, "", 0);
	}

	static vector <clsBankClient> GetClientList() {

		return _LoadFileContentToVector();

	}

	static double GetTotalBalances() {
		vector <clsBankClient> _vClient = _LoadFileContentToVector();
		double TotalBalances = 0;
		for (clsBankClient& C : _vClient) {
			TotalBalances += C.AccountBalance;
		}
		return TotalBalances;
	}


	void Deposit(double amount) {
		AccountBalance += amount;
		Save();
	}

	bool Withdraw(double amount) {
		if (amount > AccountBalance)
		{
			return false;
		}
		else {
			AccountBalance -= amount;
			Save();
			return true;
		}
	}


	bool Transfer(float Amount, clsBankClient& DestenationClient) {

		if (Amount > AccountBalance) {
			return false;
		}

		Withdraw(Amount);
		DestenationClient.Deposit(Amount);
		_AddLogsTrasfer(DestenationClient, Amount);
		return true;
	}









};



