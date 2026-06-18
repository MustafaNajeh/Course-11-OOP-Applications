#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsAddNewClient : protected clsScreen
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

    static void _ReadClientInfo(clsBankClient& Client) {

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


public:

	static void  ShowAddNewClientScreen() {

        if (!CheckAccessRights(clsUser::CanAddNewClient)) {
            return;
        }

		_HedarScreen("Add New Client");

        string AccountNumber = "";
        cout << "Please Enter Account Number\n";
        AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsclientExist(AccountNumber)) {

            cout << "Sory, your AccountNumber is Exsist enter Agin\n";
            AccountNumber = clsInputValidate::ReadString();

        }

        clsBankClient Client = clsBankClient::GetAddNewClientObject(AccountNumber);


        _ReadClientInfo(Client);

        clsBankClient::enSaveClient SaveResult;

        SaveResult = Client.Save();


        switch (SaveResult) {

        case clsBankClient::SussccesChanges:
           
            cout << "\n Add New Client Sussfuly";
            _PrintClient(Client);
            break;
        case clsBankClient::FaildChanges:
            cout << "\nAdd New Client Fild\n";
            break;
        case clsBankClient::FaildAddNewClientExists:
            cout << "\nFaild Add New Client Because Exists";
            break;
        }



	}

};

