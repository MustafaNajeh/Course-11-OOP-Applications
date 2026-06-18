#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListClientScreen.h"
#include "clsAddNewClient.h"
#include "clsShowDeleteClientScreen.h"
#include "clsShowUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsMenueScreen.h"
#include "clsManageUserScreen.h"
#include "GlobalObject.h"
//#include "clsLoginScreen.h"
using namespace std;

class clsMainMenueScreen : protected clsScreen
{
private:


	enum enMainMenue {
		ShowClientList = 1,
		AddNewClient = 2,
		DeleteClient = 3,
		UpdateClient = 4,
		FindClient = 5,
		Transactions = 6,
		MangeUser = 7,
		LogOut = 8

	};

	static short _ReadMainMenue() {
		short Choice;
		cout << clsUtil::Tabs(5) << "Chooes What Do you want to do ? [1 to 8]. ";
		Choice = clsInputValidate::ReadShortNumberBetween(1, 8, "Please enter bettewn 1 and 8");
		return Choice;
	}

	static void _BackToMainMenueScreen() {

		cout << "\nPress any key to go back to Main Menue...";
		system("pause>0");
		system("cls");
		MainMenueScreen();

	}

	static void _ShowClientListScrren() {

		/*cout << "Client List Scrren Will be here ...\n";*/
		clsListClientScreen::ClientList();

	}

	static void _ShowAddNewClientScrren() {
		//cout << "Add New Client Scrren Will be here ...\n";
		clsAddNewClient::ShowAddNewClientScreen();
	}

	static void _ShowDeleteClientScrren() {
		//cout << "Delete Client Scrren Will be here ...\n";
		clsShowDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScrren() {
		//cout << "Update Client Scrren Will be here ...\n";
		clsShowUpdateClientScreen::ShowUpdateClientScreen();

	}

	static void _ShowFindClientScrren() {
		//cout << "Find Client Scrren Will be here ...\n";
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsMenue() {
		//cout << "Transactions Menue Scrren Will be here ...\n";
		clsTransactionsMenueScreen::TransactionsMenueScreen();
	}

	static void _ShowUserMenueScreen() {
		//cout << "User Menue Scrren Will be here ...\n";

		clsManageUserScreen::ShowManageUserScreen();
	}

	static void _LoginOut() {

		//cout << "Login Scrren Will be here ...\n";
		CurrentObject = clsUser::FindUser("", "");

	}



	static void _PerformMainMenue(enMainMenue MainMenue) {

		switch (MainMenue) {

		case enMainMenue::ShowClientList:
			system("cls");
			_ShowClientListScrren();
			_BackToMainMenueScreen();
			break;
		case enMainMenue::AddNewClient:
			system("cls");
			_ShowAddNewClientScrren();
			_BackToMainMenueScreen();
			break;
		case enMainMenue::DeleteClient:
			system("cls");
			_ShowDeleteClientScrren();
			_BackToMainMenueScreen();
			break;
		case enMainMenue::UpdateClient:
			system("cls");
			_ShowUpdateClientScrren();
			_BackToMainMenueScreen();
			break;
		case enMainMenue::FindClient:
			system("cls");
			_ShowFindClientScrren();
			_BackToMainMenueScreen();
			break;
		case enMainMenue::Transactions:
			system("cls");
			_ShowTransactionsMenue();
			_BackToMainMenueScreen();
			break;
		case enMainMenue::MangeUser:
			system("cls");
			_ShowUserMenueScreen();
			_BackToMainMenueScreen();
			break;
		case enMainMenue::LogOut:
			system("cls");
			_LoginOut();
			//clsLoginScreen::ShowLoginScreen();
			break;
		}

	}




public:
	static void MainMenueScreen() {

		system("cls");
		_HedarScreen("Main Menue");

		cout << clsUtil::Tabs(5) << "===============================================\n";
		cout << clsUtil::Tabs(5) << "\t\t Main Menue Screen\n";
		cout << clsUtil::Tabs(5) << "===============================================\n";
		cout << clsUtil::Tabs(5) << "\t[1] Show Client List. \n";
		cout << clsUtil::Tabs(5) << "\t[2] AddNew Client. \n";
		cout << clsUtil::Tabs(5) << "\t[3] Delete Client. \n";
		cout << clsUtil::Tabs(5) << "\t[4] Uapdate Client Info. \n";
		cout << clsUtil::Tabs(5) << "\t[5] Find Client. \n";
		cout << clsUtil::Tabs(5) << "\t[6] Transactions.\n";
		cout << clsUtil::Tabs(5) << "\t[7] Mange Users.\n";
		cout << clsUtil::Tabs(5) << "\t[8] LogOut. \n";
		cout << clsUtil::Tabs(5) << "===============================================\n";
		_PerformMainMenue(enMainMenue(_ReadMainMenue()));
	}







};

