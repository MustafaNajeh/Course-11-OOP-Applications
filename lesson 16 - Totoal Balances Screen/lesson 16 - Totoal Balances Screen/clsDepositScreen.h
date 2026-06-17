#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "ClsBankClient.h"
using namespace std;

class clsDepositScreen : protected clsScreen
{
    static void _PrintClient(clsBankClient Client) {

        cout << "\nInfo";
        cout << "\n______________________________";
        cout << "\nAccountNumber  : " << Client.AccountNumber();
        cout << "\nPinCode        : " << Client.PinCode;
        cout << "\nFirstName      : " << Client.FirstName;
        cout << "\nLastName       : " << Client.LastName;
        cout << "\nFullName       : " << Client.FullName();
        cout << "\nEmail          : " << Client.Email;
        cout << "\nPhone          : " << Client.Phone;
        cout << "\nAccountBalance : " << Client.AccountBalance;
        cout << "\n______________________________";

    }

    static string _ReadAccountNumber(string &AccountNumber) {
        cout << "please enter your Account number.\n";
        AccountNumber = clsInputValidate::ReadString();
        return AccountNumber;
    }

public:
	static void ShowDepositScreen() {
		_HedarScreen("Deposit Screen");

        string AccountNumber = "";
        _ReadAccountNumber(AccountNumber);

        while (!clsBankClient::IsclientExist(AccountNumber)) {

            cout << "Sory, your AccountNumber ["<<AccountNumber<<"] is Not Exsist enter Agin\n";
            AccountNumber = clsInputValidate::ReadString();

        }
        clsBankClient Client = clsBankClient::FindClient(AccountNumber);
        
        _PrintClient(Client);

        cout << "\nplease enter Deposit Amount?\n";
        double Amount = clsInputValidate::ReadDoubleNumber();

        char Answer = 'y';
        cout << "\nAre you sure about That y/n : ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y') {

            Client.Deposit(Amount);
            cout << "\b\nDeposit sussfuly your new AccountBalance :" << Client.AccountBalance << endl;

        }
             
        else {
            cout << "\nDeposit Cancled\n";
        }
        
	}

};

