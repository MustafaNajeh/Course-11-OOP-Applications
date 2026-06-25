#pragma once
#include <iostream>
#include "clsMainMenueScreen.h"
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsShowCurrencyExchangeScreen.h"
using namespace std;
class clsCurreniesListScreen : protected clsScreen
{
	static void _PrintOneCurrency(clsCurrency Currency) {

		cout << clsUtil::Tabs(1)
			<< "| " << setw(30) << left << Currency.Country();
		cout << "| " << setw(10) << left << Currency.CurrencyCode();
		cout << "| " << setw(45) << left << Currency.CurrencyName();
		cout << "| " << setw(15) << left << Currency.Rate();

	}
public:
	static void ShowCurreniesListScreen() {
		vector <clsCurrency> vCurrency = clsCurrency::GetListCurrency();
		string SubTitle = "(" + to_string(vCurrency.size()) + ") " + "Currency(s).";
		_HedarScreen("Currency List", SubTitle);

		cout
			<< "\n" << clsUtil::Tabs(1) << "_______________________________________________________";
		cout << "_______________________________________________\n" << endl;
		cout << clsUtil::Tabs(1)
			<< "| " << setw(30) << left << "Country";
		cout << "| " << left << setw(10) << "Code";
		cout << "| " << left << setw(45) << "Name";
		cout << "| " << left << setw(15) << "Rate/(1$)";
		cout <<
			"\n" << clsUtil::Tabs(1) << "_______________________________________________________";
		cout << "_______________________________________________\n" << endl;

		if (vCurrency.size() == 0) {
			cout << "sorry there are erroe in the system or the Currencies file are empty\n";
		}
		else {
			for (clsCurrency R : vCurrency)
			{
				_PrintOneCurrency(R);
				cout << endl;
			}
		}
		cout <<
			"\n" << clsUtil::Tabs(1) << "_______________________________________________________";
		cout << "_______________________________________________\n" << endl;










	}








};

