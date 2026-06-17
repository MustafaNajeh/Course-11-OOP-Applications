
#include <iostream>
#include "ClsBankClient.h"
#include "clsScreen.h"
#include <vector>
#include <string>
#include <iomanip>
#pragma once
class clsListClientScreen : protected clsScreen
{

	static void _PrintOneClient(clsBankClient& Client) {


		cout << clsUtil::Tabs(2) << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(10) << left << Client.PinCode;
		cout << "| " << setw(20) << left << Client.FullName();
		cout << "| " << setw(20) << left << Client.Email;
		cout << "| " << setw(12) << left << Client.Phone;
		cout << "| " << setw(12) << left << Client.AccountBalance;

	}

public :
	static void ClientList() {

		vector <clsBankClient> vClients = clsBankClient::GetClientList();
		string Title = "Client List Screen";
		string SubTitle = "("+to_string(vClients.size())+") " + "Client(s).";

		_HedarScreen(Title, SubTitle);

	
		cout
			<< "\n"<<clsUtil::Tabs(2) <<"_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << clsUtil::Tabs(2) << "| " << left << setw(15) << "Accout Number";
		cout  << "| " << left << setw(10) << "Pin Code";
		cout  << "| " << left << setw(20) << "Client Name";
		cout  << "| " << left << setw(20) << "Email";
		cout  << "| " << left << setw(12) << "Phone";
		cout  << "| " << left << setw(12) << "Balance";
		cout <<
			"\n"<<clsUtil::Tabs(2)<<"_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vClients.size() == 0) {
			cout << "sorry there are erroe in the system or the Client file are empty\n";
		}
		else {
			for (clsBankClient Client : vClients)
			{
				_PrintOneClient(Client);
				cout << endl;
			}
		}
		cout <<
			"\n" << clsUtil::Tabs(2)<<"_______________________________________________________";
		cout << "_________________________________________\n" << endl;








	}

};

