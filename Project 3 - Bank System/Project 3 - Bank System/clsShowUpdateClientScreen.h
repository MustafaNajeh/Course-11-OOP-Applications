#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListClientScreen.h"
using namespace std;

class clsShowUpdateClientScreen : protected clsScreen
{

    static void _ReadUpdate(clsBankClient& Client) {

        cout << "Enter FirstName : ";
        Client.FirstName = clsInputValidate::ReadString();
        cout << "Enter LastName : ";
        Client.LastName = clsInputValidate::ReadString();
        cout << "Enter Email : ";
        Client.Email = clsInputValidate::ReadString();
        cout << "Enter Phone : ";
        Client.Phone = clsInputValidate::ReadString();
        cout << "Enter PinCode : ";
        Client.PinCode = clsInputValidate::ReadString();
        cout << "Enter AccountBalance : ";
        Client.AccountBalance = clsInputValidate::ReadDoubleNumber();

    }

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

public :
	static void ShowUpdateClientScreen() {

        if (!CheckAccessRights(clsUser::CanUpdateClient)) {
            return;
        }

		_HedarScreen("Update Client Screen");


        string AccountNumber = "";
        cout << "Please Enter Account Number\n";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsclientExist(AccountNumber)) {

            cout << "Sory, your AccountNumber is Not Exsist enter Agin\n";
            AccountNumber = clsInputValidate::ReadString();

        }

        clsBankClient Client = clsBankClient::FindClient(AccountNumber);
        _PrintClient(Client);
        cout << "\n_________________\n";
        cout << "\nUpdate Info";
        cout << "\n_________________\n";

        _ReadUpdate(Client);

        clsBankClient::enSaveClient SaveResult;

        SaveResult = Client.Save();


        switch (SaveResult) {

        case clsBankClient::SussccesChanges:
            _PrintClient(Client);
            cout << "\nUpdate Sussfuly";
            break;
        case clsBankClient::FaildChanges:
            cout << "Update Fild\n";
            break;
        }




	}



};

