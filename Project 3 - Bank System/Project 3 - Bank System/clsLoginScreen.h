#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsMainMenueScreen.h"
#include "clsScreen.h"
#include "GlobalObject.h"
using namespace std;
class clsLoginScreen : protected clsScreen
{
	static bool _Login() {
		string UserName, Password;
		bool LoginFaild = false;
		short counter = 3;
		do {
			if (LoginFaild) {
				counter--;
				if (counter == 0) {
					cout << "\nYou Locked After 3 trails\n";
					return false;
				}
				cout << "\nInvalid UserName/Password.\n";
				cout << "You Have " << counter << " trails to Login.\n\n";
				
			}
			
			
			cout << "Enter UserName :";
			cin >> UserName;
			cout << "Enter Password :";
			cin >> Password;

			CurrentObject = clsUser::FindUser(UserName, Password);
			LoginFaild = CurrentObject.IsEmpty();


		} while (LoginFaild);

		clsMainMenueScreen::MainMenueScreen();
		return true;

	}
public :
	static bool ShowLoginScreen() {
		system("cls");
		_HedarScreen("Login Screen");
		return _Login();
		

	}
};

