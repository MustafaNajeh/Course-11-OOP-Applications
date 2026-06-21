#pragma once
#include <iostream>
using namespace std;
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
class clsUpdateUserScreen : protected clsScreen
{
	static void _PrintUser(clsUser User) {

		cout << "\nInfo";
		cout << "\n______________________________";
		cout << "\nUserName        : " << User.UserName();
		cout << "\nPassword        : " << User.Password;
		cout << "\nFirstName      : " << User.FirstName;
		cout << "\nLastName       : " << User.LastName;
		cout << "\nFullName       : " << User.FullName();
		cout << "\nEmail          : " << User.Email;
		cout << "\nPhone          : " << User.Phone;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n______________________________";
	}

	static void _ReadUserInfo(clsUser& User) {

		cout << "Enter FirstName : ";
		User.FirstName = clsInputValidate::ReadString();
		cout << "Enter LastName : ";
		User.LastName = clsInputValidate::ReadString();
		cout << "Enter Email : ";
		User.Email = clsInputValidate::ReadString();
		cout << "Enter Phone : ";
		User.Phone = clsInputValidate::ReadString();
		cout << "Enter Password : ";
		User.Password = clsInputValidate::ReadString();

		User.Permissions = _ReadPermissions();

	}

	static int _ReadPermissions() {

		int Permissions = 0;
		char AddPermissions = 'Y';

		cout << "\nDo You Wnat To Give Full Access? Y/N ";
		cin >> AddPermissions;

		if (toupper(AddPermissions) == 'Y') {
			Permissions |= clsUser::ePermission::FullAccess;
		}

		else {
			cout << "Do You Wnat To Give Access To : \n";

			cout << "\nShow Client? y/n? ";
			cin >> AddPermissions;

			if (toupper(AddPermissions) == 'Y') {
				Permissions = Permissions | clsUser::ePermission::CanShowClientList;
			} // 0001 = 1

			cout << "\nAdd New Client? y/n? ";
			cin >> AddPermissions;

			if (toupper(AddPermissions) == 'Y') {
				Permissions |= clsUser::ePermission::CanAddNewClient;
			}
			//0001
			//0010
			//----
			//0011 = 3

			cout << "\nDelete Client ? y/n? ";
			cin >> AddPermissions;

			if (toupper(AddPermissions) == 'Y') {
				Permissions |= clsUser::ePermission::CanDeleteClient;
			}
			/*
			0011
			0100
			----
			0111 = 7

			*/


			cout << "\nUpdate Client ? y/n? ";
			cin >> AddPermissions;

			if (toupper(AddPermissions) == 'Y') {
				Permissions |= clsUser::ePermission::CanUpdateClient;
			}
			/*
			0111
			1000
			----
			1111 = 15


			*/
			cout << "\nFind User ? y/n? ";
			cin >> AddPermissions;

			if (toupper(AddPermissions) == 'Y') {
				Permissions |= clsUser::ePermission::CanFindClient;
			}
			cout << "\nCan Show Transactions ? y/n? ";
			cin >> AddPermissions;

			if (toupper(AddPermissions) == 'Y') {
				Permissions |= clsUser::ePermission::CanShowTransactionsMenue;
			}
			cout << "\nCan Show Mange Users ? y/n? ";
			cin >> AddPermissions;

			if (toupper(AddPermissions) == 'Y') {
				Permissions |= clsUser::ePermission::CanMangeUsers;
			}
			cout << "\nCan Show Login Registers ? y/n? ";
			cin >> AddPermissions;

			if (toupper(AddPermissions) == 'Y') {
				Permissions |= clsUser::ePermission::CanShowLoginRegisters;
			}
		}

		return Permissions;
	}

public:
	static void ShowUpdateUserScreen() {
		_HedarScreen("Update User Screen");


		string UserName = "";
		cout << "Please Enter Account Number\n";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName)) {

			cout << "Sory, your AccountNumber is Not Exsist enter Agin\n";
			UserName = clsInputValidate::ReadString();

		}

		clsUser User = clsUser::FindUser(UserName);
		_PrintUser(User);

		cout << "\n_________________\n";
		cout << "\nUpdate Info";
		cout << "\n_________________\n";

		char Answer = 'n';
		cout << "\ndo you want really update User y/n? \n";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {

			_ReadUserInfo(User);

			clsUser::enSaveClient SaveResult;

			SaveResult = User.Save();


			switch (SaveResult) {

			case clsUser::SussccesChanges:
				_PrintUser(User);
				cout << "\nUpdate Sussfuly";
				break;
			case clsUser::FaildChanges:
				cout << "Update Fild\n";
				break;
			}
		}

		else {
			cout << "\nUpdate cancled.\n";
		}

	}

};

