#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsTransactionsMenueScreen.h"
using namespace std;
class clsShowTransferLogScreen : protected clsScreen
{
	static void _PrintOneRecord(clsBankClient::sTransferLog Client) {


		cout << clsUtil::Tabs(2)
		<< "| " << setw(20) << left << Client.DateTime;
		cout << "| " << setw(10) << left << Client.SourceAccount;
		cout << "| " << setw(10) << left << Client.DestinationAccount;
		cout << "| " << setw(10) << left << Client.Amount;
		cout << "| " << setw(13) << left << Client.SourceBalance;
		cout << "| " << setw(13) << left << Client.DestinationBalance;
		cout << "| " << setw(10) << left << Client.User;

	}

public:

	static void ShowTransferLogScreen() {
		vector <clsBankClient::sTransferLog> vLogTransfer = clsBankClient::LoadFileTransferLog();
		string SubTitle = "(" + to_string(vLogTransfer.size()) + ") " + "Record(s).";
		_HedarScreen("Trasfer Log",SubTitle);


		cout
			<< "\n" << clsUtil::Tabs(2) << "_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << clsUtil::Tabs(2) 
			<< "| " << setw(20) << left << "Date/Time";
		cout << "| " << left << setw(10) << "s.Acct";
		cout << "| " << left << setw(10) << "d.Acct";
		cout << "| " << left << setw(10) << "Amount";
		cout << "| " << left << setw(13) << "s.Balance";
		cout << "| " << left << setw(13) << "d.Balance";
		cout << "| " << left << setw(10) << "User";
		cout <<
			"\n" << clsUtil::Tabs(2) << "_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vLogTransfer.size() == 0) {
			cout << "sorry there are erroe in the system or the Client file are empty\n";
		}
		else {
			for (clsBankClient::sTransferLog R : vLogTransfer)
			{
				_PrintOneRecord(R);
				cout << endl;
			}
		}
		cout <<
			"\n" << clsUtil::Tabs(2) << "_______________________________________________________";
		cout << "_________________________________________\n" << endl;




	}






};

