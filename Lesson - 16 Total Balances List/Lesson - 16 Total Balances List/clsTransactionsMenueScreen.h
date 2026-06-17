#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
using namespace std;



class clsTransactionsMenueScreen : protected clsScreen
{
	enum enTransactionsMenue {

		Deposit = 1,
		Withdraw = 2,
		TotalBalance = 3,
		MainMenue = 4

	};

	static short _ReadTransationsMenue() {
		short Choice;
		cout << clsUtil::Tabs(5) << "Chooes What Do you want to do ? [1 to 4]. ";
		Choice = clsInputValidate::ReadShortNumberBetween(1, 4, "Please enter bettewn 1 and 4");
		return Choice;
	}

	static void _BackToTransactionMenue() {

		cout << "\nPress any key to go back to Transactions Menue...";
		system("pause>0");
		system("cls");
		TransactionsMenueScreen();

	}

	static void _ShowDepositScreen() {
		clsDepositScreen::ShowDepositScreen();
		//cout << "Show Deposit Screen Will be Here\n";
	}

	static void _ShowWithdrawScreen() {
		//cout << "Show Withdraw Screen Will be Here\n";
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowListAndTotalBalances() {
		clsTotalBalancesScreen::TotalBalancesScreen();
		//cout << "Show List And Total Balances Screen Will be Here\n";

	}

	static void _PerformTransactionsMenue(enTransactionsMenue TransactionsMenue) {

		switch (TransactionsMenue)
		{

		case enTransactionsMenue::Deposit:
			system("cls");
			_ShowDepositScreen();
			_BackToTransactionMenue();
			break;

		case enTransactionsMenue::Withdraw:
			system("cls");
			_ShowWithdrawScreen();
			_BackToTransactionMenue();
			break;

		case enTransactionsMenue::TotalBalance:
			system("cls");
			_ShowListAndTotalBalances();
			_BackToTransactionMenue();
			break;

		case enTransactionsMenue::MainMenue:

			break;
		}
	
	}


public:
	static void TransactionsMenueScreen() {

		_HedarScreen("Transactions Menue");


		cout << clsUtil::Tabs(5) << "===============================================\n";
		cout << clsUtil::Tabs(5) << "\t Transactions Menue Screen\n";
		cout << clsUtil::Tabs(5) << "===============================================\n";
		cout << clsUtil::Tabs(5) << "\t[1] Deposit. \n";
		cout << clsUtil::Tabs(5) << "\t[2] WithDraw. \n";
		cout << clsUtil::Tabs(5) << "\t[3] Total Balance. \n";
		cout << clsUtil::Tabs(5) << "\t[4] Main Menue. \n";
		cout << clsUtil::Tabs(5) << "===============================================\n";

		_PerformTransactionsMenue(enTransactionsMenue(_ReadTransationsMenue()));

	}

};


