#pragma once
#include <iostream>
#include "clsMainMenueScreen.h"
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsShowCurrencyExchangeScreen.h"
using namespace std;
class clsShowUpdateRateScreen : protected clsScreen
{
	static void _PrintOneCurrency(clsCurrency Currency) {
		cout << "\n_____________________________\n";
		cout << "Countrey      : " << Currency.Country() << "\n";
		cout << "Currency Code : " << Currency.CurrencyCode() << "\n";
		cout << "Currency Name : " << Currency.CurrencyName() << "\n";
		cout << "Rate(1$)      : " << Currency.Rate();
		cout << "\n_____________________________\n";

	}

	

	static string _ReadCurrencyCode() {
		cout << "\nPlease Enter Currency Code : ";
		string Currency = clsInputValidate::ReadString();
		return Currency;
	}

public : 
	static void ShowUpdateRateScreen() {
		_HedarScreen("Update Rate");
		string CurrencyCode = _ReadCurrencyCode();

		while (!clsCurrency::IsCurrencyExistByCurrencyCode(CurrencyCode)) {
			cout << "\nCurrency is Not Exist Enter Anouther";
			string CurrencyCode = _ReadCurrencyCode();
		}

		clsCurrency CurrencyRate = clsCurrency::FindCurrencyCode(CurrencyCode);
		_PrintOneCurrency(CurrencyRate);

		char Answer = 'y';

		cout << "\nAre you sure you want to Update the Rate Of This Currency y/n ? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y') {
			float UpdateRate;
			cout << "\nUpdate Currency Rate\n";
			cout << "______________________\n";
			cout << "\nEntre New Currency Rate : ";
			UpdateRate = clsInputValidate::ReadFloatNumber();

			CurrencyRate.UpdateRate(UpdateRate);
			cout << "\nCurrency Rate Update Succfully\n";
			_PrintOneCurrency(CurrencyRate);

		}
	}
};

