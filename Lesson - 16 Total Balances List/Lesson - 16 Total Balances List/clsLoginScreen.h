#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsMainMenueScreen.h"
#include "clsScreen.h"
#include "GlobalObject.h"
using namespace std;
class clsLoginScreen : protected clsScreen
{
	static void _Login() {
		string UserName, Password;
		bool LoginFaild = false;
		do {

			if (LoginFaild) {
				cout << "\nInvalid UserName/Password.\n";
			}
			 
			cout << "Enter UserName :";
			cin >> UserName;
			cout << "Enter Password :";
			cin >> Password;

			CurrentObject = clsUser::FindUser(UserName, Password);
			LoginFaild = CurrentObject.IsEmpty();


		} while (LoginFaild);

		clsMainMenueScreen::MainMenueScreen();


	}
public :
	static void ShowLoginScreen() {
		system("cls");
		_HedarScreen("Login Screen");
		_Login();
		

	}
};

