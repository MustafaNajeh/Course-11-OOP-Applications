#pragma once

#include <iostream>
using namespace std;
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListClientScreen.h"
#include "clsAddNewClient.h"
//
class clsShowDeleteClientScreen : protected clsScreen
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

public:

   static void ShowDeleteClientScreen() {

       _HedarScreen("Delete Client Screen");
        string AccountNumber = "";
        cout << "Please Enter Account Number\n";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsclientExist(AccountNumber)) {

            cout << "Sory, your AccountNumber is Not Exsist enter Agin\n";
            AccountNumber = clsInputValidate::ReadString();

        }

        clsBankClient Client = clsBankClient::FindClient(AccountNumber);
        _PrintClient(Client);

        char Answer = 'y';

        cout << "\ndo you want really to delete this account? : ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y') {

            if (Client.Delete()) {
                _PrintClient(Client);
                cout << "\ndeleted sussccfuly.\n";
            }

            else {
                cout << "\ndeleted Faild.\n";

            }
        }

    }





};

