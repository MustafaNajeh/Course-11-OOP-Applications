#pragma once
#include <iostream>
#include "clsMainMenueScreen.h"
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsCurreniesListScreen.h"
#include "clsInputValidate.h"
using namespace std;
class clsFindCurrencyScreen : protected clsScreen
{

	static string _ReadCurrencyCode() {
		cout << "\nPlease Enter Currency Code : ";
		string Currency = clsInputValidate::ReadString();
		return Currency;
	}

	static string _ReadCurrencyCountry() {
		cout << "\nPlease Enter Country Name : ";
		string Currency = clsInputValidate::ReadString();
		return Currency;
	}

	static void _ShowResult(clsCurrency Currency) {
		if (!Currency.IsEmpty()) {
			cout << "\nCurrency Found.\n";
			_PrintOneCurrency(Currency);
		}
		else {
			cout << "\nCurrency Not Found.\n";
		}
	}

	static void _PrintOneCurrency(clsCurrency Currency) {
		cout << "\n_____________________________\n";
		cout << "Countrey      : " << Currency.Country() << "\n";
		cout << "Currency Code : " << Currency.CurrencyCode() << "\n";
		cout << "Currency Name : " << Currency.CurrencyName() << "\n";
		cout << "Rate(1$)      : " << Currency.Rate();
		cout << "\n_____________________________\n";

	}

public: 
	static void FindCurrencyScreen() {

		_HedarScreen("Find Currency");

		short Choise = 1;
		cout << "\nFind By: [1] Code or [2] Country ? : ";
		Choise = clsInputValidate::ReadShortNumberBetween(1, 2, "Please enter 1 or 2");

		if (Choise == 1) {

			clsCurrency CurrencyByCode = clsCurrency::FindCurrencyCode(_ReadCurrencyCode());
			_ShowResult(CurrencyByCode);
		}

		else {
			clsCurrency CurrencyByCountry = clsCurrency::FindCountry(_ReadCurrencyCountry());
			_ShowResult(CurrencyByCountry);

		}
	}
};

