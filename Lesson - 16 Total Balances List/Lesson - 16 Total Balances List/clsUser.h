#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

using namespace std;

class clsUser : public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNew = 2 };
	enMode _Mode;

	string _AccountNumber;
	string _Password;
	int _Permissions;
	bool _MarkForDelete = false;


	static clsUser _ConvertLineToRecordObjectForUser(string Line, string Seperator = "//##//") {

		vector <string> vUser;
		vUser = clsString::Split(Line, Seperator);

		return clsUser(enMode::UpdateMode, vUser[0], vUser[1], vUser[2], vUser[3], vUser[4], vUser[5], stod(vUser[6]));
	}

	static clsUser _GetEmptyUserObject() {
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static string _ConvertRecordToLineForUser(clsUser User, string delim = "//##//") {

		string sRecord;

		sRecord += User.FirstName + delim;
		sRecord += User.LastName + delim;
		sRecord += User.Email + delim;
		sRecord += User.Phone + delim;
		sRecord += User.UserName() + delim;
		sRecord += User.Password + delim;
		sRecord += to_string(User._Permissions);

		return sRecord;

	}

	static vector <clsUser> _LoadFileContentToVectorForUser() {
		vector <clsUser> vUser;
		fstream MyFile;

		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open()) {

			string Line;

			while (getline(MyFile, Line)) {


				clsUser User = _ConvertLineToRecordObjectForUser(Line);

				vUser.push_back(User);

			}

			MyFile.close();
		}
		return vUser;
	}

	static vector <clsUser> _SaveDataClientsToFileForUser(vector<clsUser>& vUser) {

		fstream MyFile;

		MyFile.open("Users.txt", ios::out);
		string Line;
		if (MyFile.is_open()) {



			for (clsUser& C : vUser) {
				if (C._MarkForDelete == false) {
					Line = _ConvertRecordToLineForUser(C);
					MyFile << Line << endl;
				}
			}

			MyFile.close();
		}
		return vUser;
	}

	void _AddLinesToFiles(string Line) {
		fstream MyFile;

		MyFile.open("Users.txt", ios::out | ios::app);

		if (MyFile.is_open()) {

			MyFile << Line << endl;

			MyFile.close();
		}

	}

	void _AddNew() {
		_AddLinesToFiles(_ConvertRecordToLineForUser(*this));
	}

	void _Update() {
		vector <clsUser> _vUser;
		_vUser = _LoadFileContentToVectorForUser();

		for (clsUser& C : _vUser) {
			if (C.UserName() == UserName()) {

				C = *this;
				break;
			}
		}

		_SaveDataClientsToFileForUser(_vUser);


	}

public:
	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone
		, string AccountNumber, string Password, int Permissions) :
		clsPerson(FirstName, LastName, Email, Phone) {

		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_Password = Password;
		_Permissions = Permissions;
	}

	enum ePermission {
		FullAccess = -1,
		CanShowClientList = 1,
		CanAddNewClient = 2,
		CanDeleteClient = 4,
		CanUpdateClient = 8,
		CanFindClient = 16,
		CanShowTransactionsMenue = 32,
		CanMangeUsers = 64
	};

	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

	string UserName() {
		return _AccountNumber;
	}

	bool GetMarkForDelete() {
		return _MarkForDelete;
	}

	void setPassword(string Password) {
		_Password = Password;
	}

	string getPassword() {
		return _Password;
	}

	__declspec (property(get = getPassword, put = setPassword))string Password;


	void setPermissions(int Permissions) {
		_Permissions = Permissions;
	}

	int getPermissions() {
		return _Permissions;
	}

	__declspec (property(get = getPermissions, put = setPermissions))int Permissions;


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
			if (IsUserExist(UserName())) {
				return enSaveClient::FaildAddNewClientExists;
			}

			_AddNew();
			return enSaveClient::SussccesChanges;


		}
	}

	static clsUser FindUser(string AccounNumber) {

		fstream MyFile;

		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open()) {

			string Line;

			while (getline(MyFile, Line)) {

				clsUser User = _ConvertLineToRecordObjectForUser(Line);
				if (User.UserName() == AccounNumber) {
					MyFile.close();
					return User;
				}


			}


		}
		return _GetEmptyUserObject();
	}

	bool Delete() {
		vector <clsUser> _vUser;
		_vUser = _LoadFileContentToVectorForUser();

		for (clsUser& U : _vUser) {
			if (U.UserName() == UserName()) {
				U._MarkForDelete = true;
				break;
			}
		}

		_SaveDataClientsToFileForUser(_vUser);
		*this = _GetEmptyUserObject();

		return true;



	}

	static clsUser FindUser(string UserName, string Password) {

		fstream MyFile;

		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open()) {

			string Line;

			while (getline(MyFile, Line)) {

				clsUser User = _ConvertLineToRecordObjectForUser(Line);
				if (User.UserName() == UserName && User.Password == Password) {
					MyFile.close();
					return User;
				}


			}


		}
		return _GetEmptyUserObject();
	}

	static bool IsUserExist(string UserName) {

		clsUser Client = clsUser::FindUser(UserName);
		return (!Client.IsEmpty());

	}

	static clsUser GetAddNewUserObject(string UserName) {
		return clsUser(enMode::AddNew, "", "", "", "", UserName, "", 0);
	}

	static vector <clsUser> GetUserList() {

		return _LoadFileContentToVectorForUser();

	}

	
};





