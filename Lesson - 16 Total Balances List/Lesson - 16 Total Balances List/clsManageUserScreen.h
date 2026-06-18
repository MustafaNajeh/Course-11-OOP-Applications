#pragma once
#include <iostream>
using namespace std;
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUsersListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
class clsManageUserScreen : protected clsScreen
{
	enum enUesrsMenue {
		ListUesrs = 1,
		AddNewUser = 2,
		DeleteUser = 3,
		UpdateUser = 4,
		FindUser = 5,
		MainMenueForUser = 6

	};
	
	static short _ReadManageUserMenue() {
		short Choice;
		cout << clsUtil::Tabs(5) << "Chooes What Do you want to do ? [1 to 6]. ";
		Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Please enter bettewn 1 and 6");
		return Choice;
	}

	static void _BackToUserMenue() {

		cout << "\nPress any key to go back to User Menue...";
		system("pause>0");
		system("cls");
		ShowManageUserScreen();

	}

	static void _ShowUsersList() {
		//cout << "Show User List Screen Will be here ...\n";
		clsUsersListScreen::ShowUsersListScreen();

	}
	static void _ShowAddNewUserScreen() {
		//cout << "Show Add New User Screen Will be here ...\n";
		clsAddNewUserScreen::ShowAddNewClientScreen();
	}
	static void _ShowUserDeleteScreen(){
		//cout << "Show User Delete Screen Will be here ...\n";
		clsDeleteUserScreen::ShowDeleteClientScreen();
	}
	static void _ShowUpdateUserScreen() {
		cout << "Show User Update Screen Will be here ...\n";

	}
	static void _ShowFindUserScreen() {
		cout << "Show User Find Screen Will be here ...\n";

	}

	static void _PerformUserMenue(enUesrsMenue UserMenue) {

		switch (UserMenue) {

		case enUesrsMenue::ListUesrs:
			system("cls");
			_ShowUsersList();
			_BackToUserMenue();
			break;

		case enUesrsMenue::AddNewUser:
			system("cls");
			_ShowAddNewUserScreen();
			_BackToUserMenue();
			break;

		case enUesrsMenue::DeleteUser:
			system("cls");
			_ShowUserDeleteScreen();
			_BackToUserMenue();
			break;

		case enUesrsMenue::UpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_BackToUserMenue();
			break;

		case enUesrsMenue::FindUser:
			system("cls");
			_ShowFindUserScreen();
			_BackToUserMenue();
			break;

		case enUesrsMenue::MainMenueForUser:
			// nothing because the back main menue exist in thier.
			break;
		}



	}


public:
	static void ShowManageUserScreen() {
		_HedarScreen("Manage User Screen");

		cout << clsUtil::Tabs(5) << "===============================================\n";
		cout << clsUtil::Tabs(5) << "\t\t User Menue Screen\n";
		cout << clsUtil::Tabs(5) << "===============================================\n";
		cout << clsUtil::Tabs(5) << "\t[1] Show Users List. \n";
		cout << clsUtil::Tabs(5) << "\t[2] Add New User. \n";
		cout << clsUtil::Tabs(5) << "\t[3] Delete User. \n";
		cout << clsUtil::Tabs(5) << "\t[4] Uapdate User Info. \n";
		cout << clsUtil::Tabs(5) << "\t[5] Find User. \n";
		cout << clsUtil::Tabs(5) << "\t[6] Main Menue.\n";
		cout << clsUtil::Tabs(5) << "===============================================\n";
		_PerformUserMenue(enUesrsMenue(_ReadManageUserMenue()));
	}






};

