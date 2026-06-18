#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsUser.h"
#include "clsUtil.h"
#include <iomanip>
#include "clsScreen.h"
using namespace std;
class clsUsersListScreen : protected clsScreen
{
	static void _PrintOneUser(clsUser& User) {


		cout << clsUtil::Tabs(2) << "| " << setw(15) << left << User.UserName();
		cout << "| " << setw(10) << left << User.Password;
		cout << "| " << setw(20) << left << User.FullName();
		cout << "| " << setw(20) << left << User.Email;
		cout << "| " << setw(12) << left << User.Phone;
		cout << "| " << setw(12) << left << User.Permissions;

	}

public:

	static void ShowUsersListScreen() {
		vector <clsUser> vUser = clsUser::GetUserList();
		string SubTitle = "\n\t\t\t\t\t\t   Users List (" + to_string(vUser.size()) + ") User(s).";
		_HedarScreen("Users List",SubTitle);
		
		cout <<
			"\n" << clsUtil::Tabs(2) <<"_______________________________________________________";
		cout << "_____________________________________________\n" << endl;
		cout << clsUtil::Tabs(2) << "| " << left << setw(15) << "UserName";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(12) << "Permissions";
		cout <<
			"\n" << clsUtil::Tabs(2) <<"_______________________________________________________";
		cout << "_____________________________________________\n" << endl;
		if (vUser.size() == 0) {
			cout << "sorry there are erroe in the system or the Client file are empty\n";
		}
		else {
			for (clsUser User : vUser)
			{
				_PrintOneUser(User);
				cout << endl;
			}
		}
		cout <<
			"\n" << clsUtil::Tabs(2) <<"_______________________________________________________";
		cout << "_____________________________________________\n" << endl;

	}




};

