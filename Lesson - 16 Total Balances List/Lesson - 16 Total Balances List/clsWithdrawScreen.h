#pragma once
#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "ClsBankClient.h"
using namespace std;
class clsWithdrawScreen : protected clsScreen
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

    static string _ReadAccountNumber(string& AccountNumber) {
        cout << "please enter your Account number.\n";
        AccountNumber = clsInputValidate::ReadString();
        return AccountNumber;
    }

public:
    static void ShowWithdrawScreen() {
        _HedarScreen("Withdraw Screen");

        string AccountNumber = "";
        _ReadAccountNumber(AccountNumber);

        while (!clsBankClient::IsclientExist(AccountNumber)) {

            cout << "Sory, your AccountNumber [" << AccountNumber << "] is Not Exsist enter Agin\n";
            AccountNumber = clsInputValidate::ReadString();

        }
        clsBankClient Client = clsBankClient::FindClient(AccountNumber);

        _PrintClient(Client);

        cout << "\nplease enter Withdraw Amount?\n";
        double Amount = clsInputValidate::ReadDoubleNumber();

        if (Amount > Client.AccountBalance) {
            cout << "\nyour AccountBalance is nout enough!\n";
            cout << "AccountBalance :" << Client.AccountBalance << endl;

            return;
        }
      
        char Answer = 'y';
        cout << "\nAre you sure about That y/n : ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y') {

            if (Client.Withdraw(Amount)) {
                cout << "\b\withdraw sussccfuly your new AccountBalance :" << Client.AccountBalance << endl;
            }
            else {
                cout << "\nyour accountblanace is not enough!\n";
                cout <<"AccountBalance :" << Client.AccountBalance << endl;
            }
        }

        else {
            cout << "\nDeposit Cancled\n";
        }

    }
};

