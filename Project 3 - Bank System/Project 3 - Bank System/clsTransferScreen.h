#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsTransactionsMenueScreen.h"
using namespace std;
class clsTransferScreen : protected clsScreen
{
	static void _PrintSimpleCard(clsBankClient Client) {
		cout << "\nClient Card\n";
		cout << "\n_____________________\n";
		cout << "Acc.Num  :" << Client.AccountNumber()<<"\n";
		cout << "FullName :" << Client.FullName() << "\n";
		cout << "Balance  :" << Client.AccountBalance << "\n";
		cout << "_____________________\n";
	}

	static string _ReadAccountNumber() {
		cout << "\nPlease Enter AccountNumber To Transfer From: ";

		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsclientExist(AccountNumber)) {

			cout << "Sorry, your AccountNumber is Not Exsist enter Agin :";
			AccountNumber = clsInputValidate::ReadString();

		}
		return AccountNumber;
	}

	static float _ReadAmount(clsBankClient ClientSourse) {
		float Amount;
		cout << "\nEnter Transfer Amount? :";
		Amount = clsInputValidate::ReadIntNumber();

		while (Amount > ClientSourse.AccountBalance ) {
			cout << "Amount Exeeds the Balance ,enter anouthr Amount :";
			Amount = clsInputValidate::ReadIntNumber();

		}
		return Amount;
	}

	
public:
	static void ShowTransferScreen() {
		_HedarScreen("Transfer Screen");
		
		

		clsBankClient ClientSource = clsBankClient::FindClient(_ReadAccountNumber());
		_PrintSimpleCard(ClientSource);

		clsBankClient ClientDestination = clsBankClient::FindClient(_ReadAccountNumber());
		_PrintSimpleCard(ClientDestination);

		float Amount = _ReadAmount(ClientSource);
		
		char Answer = 'n';
		cout << "Do You Want Really To Accept This Action? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {

			if (ClientSource.Transfer(Amount, ClientDestination)) {
				cout << "\nTransfer Sussccfly.\n";

				_PrintSimpleCard(ClientSource);
				_PrintSimpleCard(ClientDestination);

			}
			else  {
				cout << "\nTransfer Faild.\n";
			}

		}

	}

};

