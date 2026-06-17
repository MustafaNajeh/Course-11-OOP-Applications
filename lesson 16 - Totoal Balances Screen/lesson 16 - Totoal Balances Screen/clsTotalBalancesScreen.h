#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "ClsBankClient.h"
#include <iomanip>
using namespace std;
class clsTotalBalancesScreen : protected clsScreen
{

	static void _PrintOwnClintForBalancesList(clsBankClient Cleint) {

		cout << clsUtil::Tabs(2) << "| " << setw(20) << left << Cleint.AccountNumber();
		cout << "| " << setw(50) << left << Cleint.FullName();
		cout << "| " << setw(30) << left << Cleint.AccountBalance;

	}

public :

	static void TotalBalancesScreen() {
		
		_HedarScreen("Total Balances List");


		vector <clsBankClient> vClients = clsBankClient::GetClientList();

		cout << "\n\t\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
		cout <<
			"\n"<<clsUtil::Tabs(2)<<"_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << clsUtil::Tabs(2) << "| " << left << setw(20) << "Accout Number";
		cout << "| " << left << setw(50) << "Client Name";
		cout << "| " << left << setw(30) << "Balance";
		cout <<
			"\n" << clsUtil::Tabs(2) <<"_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vClients.size() == 0) {
			cout << "sorry there are erroe in the system or the Client file are empty\n";
		}
		else {
			for (clsBankClient Client : vClients)
			{
				_PrintOwnClintForBalancesList(Client);
				cout << endl;
			}
		}
		cout <<
			"\n" << clsUtil::Tabs(2) <<"_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		double TotalBalnaces = clsBankClient::GetTotalBalances();
		cout << "\t\t\t\t\t\tTotal Balances = " << TotalBalnaces << endl;
		cout << "\t\t\t\t\t( " << clsUtil::NumbersToText(TotalBalnaces) << ")\n";

	}
};

