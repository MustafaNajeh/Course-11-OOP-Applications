#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include <string>
#include <iomanip>
using namespace std;
class clsShowLoginRegisterList : protected clsScreen
{

	static void _PrintOneUser(clsUser::sLoginRegisterRecord& User) {


		cout << clsUtil::Tabs(2) << "| " << setw(20) << left << User.UserName;
		cout << "| " << setw(30) << left << User.DateTime;
		cout << "| " << setw(15) << left << User.Password;
		cout << "| " << setw(10) << left << User.Permissions;

	}

public :

	static void ShowLoginRegisterList() {

		if (!CheckAccessRights(clsUser::CanShowLoginRegisters)) {
			return;
		}

		vector<clsUser::sLoginRegisterRecord> vLoginRegisters = clsUser::GetContatLoginRegisterRecord();
		string subTitle = "(" + to_string(vLoginRegisters.size()) + ") " + "Logs(s).";
		_HedarScreen("Login Register List",subTitle);

		

		cout <<
			"\n" << clsUtil::Tabs(2) << "_______________________________________________________";
		cout << "_____________________________________________\n" << endl;
		cout << clsUtil::Tabs(2) << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(30) << "Date/Time";
		cout << "| " << left << setw(15) << "Password";
		cout << "| " << left << setw(10) << "Permissions";
		cout <<
			"\n" << clsUtil::Tabs(2) << "_______________________________________________________";
		cout << "_____________________________________________\n" << endl;
		if (vLoginRegisters.size() == 0) {
			cout << "sorry there are erroe in the system or the Client file are empty\n";
		}
		else {
			for (clsUser::sLoginRegisterRecord Logs : vLoginRegisters)
			{
				_PrintOneUser(Logs);
				cout << endl;
			}
		}
		cout <<
			"\n" << clsUtil::Tabs(2) << "_______________________________________________________";
		cout << "_____________________________________________\n" << endl;

	}

};

