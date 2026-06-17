#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListClientScreen.h"
using namespace std; 
class clsFindClientScreen : protected clsScreen
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


public :
	static void ShowFindClientScreen() {
		_HedarScreen("Find Client Screen");


        string AccountNumber = "";
        cout << "Please Enter Account Number\n";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsclientExist(AccountNumber)) {

            cout << "Sory, your AccountNumber is Not Exsist enter Agin\n";
            AccountNumber = clsInputValidate::ReadString();

        }

        clsBankClient Client = clsBankClient::FindClient(AccountNumber);
      
        if (!Client.IsEmpty()) {

            cout << "\nFind Client Sussccfuly.\n";


        }
        else {
            cout << "\nFind Client Faild.\n";
        }
        _PrintClient(Client);



	}




};

