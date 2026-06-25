#pragma once
#include <iostream>
#include "clsMainMenueScreen.h"
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsCurreniesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsShowUpdateRateScreen.h"
using namespace std;

class clsShowCurrencyExchangeScreen : protected clsScreen
{

	enum enCurrencyExchange {
		ListCurrencies = 1,
		FindCurrency = 2,
		UpdateRate = 3,
		CurrencyCalculator = 4,
		MainMenue = 5
	};

	static short _ReadCurrencyExchange() {
		short Choice;
		cout << clsUtil::Tabs(5) << "Chooes What Do you want to do ? [1 to 5]. ";
		Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Please enter bettewn 1 and 5");
		return Choice;
	}

	static void _ListCurrencies() {
		//cout << "\n List Currencies Will be Here . . .\n";
		clsCurreniesListScreen::ShowCurreniesListScreen();
	}

	static void _FindCurrency() {
		//cout << "\n Find Currencies Will be Here . . .\n";
		clsFindCurrencyScreen::FindCurrencyScreen();
	}

	static void _UpdateRate() {
		//cout << "\n Update Rate Will be Here . . .\n";
		clsShowUpdateRateScreen::ShowUpdateRateScreen();
	}

	static void _CurrencyCalculator() {
		cout << "\n Currency Calculator Will be Here . . .\n";

	}

	static void _BackToCurrencyExchangeMenue() {
		cout << "\nPress any key to go Back To Currency Exchange Menue...";
		system("pause>0");
		system("cls");
		ShowCurrencyExchangeScreen();
	}

	static void _PerformCurrencyExchange(enCurrencyExchange CurrencyExchange) {

		switch (CurrencyExchange)
		{
		case enCurrencyExchange::ListCurrencies:
			system("cls");
			_ListCurrencies();
			_BackToCurrencyExchangeMenue();
			break;
		case enCurrencyExchange::FindCurrency:
			system("cls");
			_FindCurrency();
			_BackToCurrencyExchangeMenue();
			break;
		case enCurrencyExchange::UpdateRate:
			system("cls");
			_UpdateRate();
			_BackToCurrencyExchangeMenue();
			break;
		case enCurrencyExchange::CurrencyCalculator:
			system("cls");
			_CurrencyCalculator();
			_BackToCurrencyExchangeMenue();
			break;
		case enCurrencyExchange::MainMenue: {
			// Nothing
			}
		}
	}
public:

	static void ShowCurrencyExchangeScreen() {
		_HedarScreen("Currency Exchange");

		cout << clsUtil::Tabs(5) << "===============================================\n";
		cout << clsUtil::Tabs(5) << "\t\t Currency Exchange Screen\n";
		cout << clsUtil::Tabs(5) << "===============================================\n";
		cout << clsUtil::Tabs(5) << "\t[1] List Currencies. \n";
		cout << clsUtil::Tabs(5) << "\t[2] Find Currency. \n";
		cout << clsUtil::Tabs(5) << "\t[3] Update Rate. \n";
		cout << clsUtil::Tabs(5) << "\t[4] Currency Calculator. \n";
		cout << clsUtil::Tabs(5) << "\t[5] Main Menue. \n";
		cout << clsUtil::Tabs(5) << "===============================================\n";
		_PerformCurrencyExchange(enCurrencyExchange(_ReadCurrencyExchange()));
	}



};

