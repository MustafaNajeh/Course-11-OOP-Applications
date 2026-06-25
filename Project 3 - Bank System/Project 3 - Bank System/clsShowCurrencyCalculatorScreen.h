#pragma once
#include <iostream>
#include "clsMainMenueScreen.h"
#include "clsCurrency.h"
#include "clsScreen.h"
using namespace std;

class clsShowCurrencyCalculatorScreen : protected clsScreen
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
		string Currency = clsInputValidate::ReadString();
		return Currency;
	}

	static clsCurrency _GetCurrencyObject() {
		string CurrencyCode = _ReadCurrencyCode();

		while (!clsCurrency::IsCurrencyExistByCurrencyCode(CurrencyCode)) {
			cout << "\nCurrency is Not Exist Enter Anouther :";
			CurrencyCode = _ReadCurrencyCode();
		}

		 clsCurrency Currency = clsCurrency::FindCurrencyCode(CurrencyCode);
		 return Currency;
	}

	static void _CurrencyCalculator(clsCurrency Currency1 , clsCurrency Currency2,float Amount) {

		cout << "\nConvert From:";
		_PrintOneCurrency(Currency1);
		
		float AmountInUSD = Currency1.ConvertToUSD(Amount);

		cout << "\n" << Amount << " " << Currency1.CurrencyCode() << " = " <<
			AmountInUSD << " USD" << "\n";
		
		if (Currency2.CurrencyCode() == "USD") {
			return;
		}

		cout << "\nConverting From USD To :";
		_PrintOneCurrency(Currency2);

		float AmountInCurrency2 = Currency1.ConvertToAnoutherCurrency(Amount, Currency2);

		cout << Amount << " " << Currency1.CurrencyCode() << " = " <<
			 AmountInCurrency2 << " " << Currency2.CurrencyCode();
	}

public:
	static void ShowCurrencyCalculatorScreen() {
		char Answer = 'n';
		do {
			system("cls");
			_HedarScreen("Currency Calculator");

			cout << "\nPlease Enter Currency1 Code : ";
			clsCurrency Currency1 = _GetCurrencyObject();

			cout << "\nPlease Enter Currency2 Code : ";
			clsCurrency Currency2 = _GetCurrencyObject();

			float Amount;
			cout << "\nEnter Amount To Exchange: ";
			Amount = clsInputValidate::ReadFloatNumber();

			_CurrencyCalculator(Currency1, Currency2, Amount);
			
			cout << "\nDo You Want To Perform Anouther Calculation? y/n : ";
			cin >> Answer;

		} while (Answer == 'y' || Answer == 'Y');
		
	}
};

