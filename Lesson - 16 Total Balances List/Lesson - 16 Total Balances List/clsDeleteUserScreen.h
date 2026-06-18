#pragma once
#include <iostream>
using namespace std;
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
class clsDeleteUserScreen : protected clsScreen 
{

    static void _PrintUser(clsUser User) {

        cout << "\nInfo";
        cout << "\n______________________________";
        cout << "\nUserName        : " << User.UserName();
        cout << "\nPassword        : " << User.Password;
        cout << "\nFirstName      : " << User.FirstName;
        cout << "\nLastName       : " << User.LastName;
        cout << "\nFullName       : " << User.FullName();
        cout << "\nEmail          : " << User.Email;
        cout << "\nPhone          : " << User.Phone;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n______________________________";
    }

public:



    static void ShowDeleteClientScreen() {

        _HedarScreen("Delete User Screen");
        string AccountNumber = "";
        cout << "Please Enter UserName\n";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(AccountNumber)) {

            cout << "Sory, your UserName is Not Exsist enter Agin\n";
            AccountNumber = clsInputValidate::ReadString();

        }

        clsUser Client = clsUser::FindUser(AccountNumber);
        _PrintUser(Client);

        char Answer = 'y';

        cout << "\ndo you want really to delete this account y/n? : ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y') {

            if (Client.Delete()) {
                _PrintUser(Client);
                cout << "\ndeleted sussccfuly.\n";
            }

            else {
                cout << "\ndeleted Faild.\n";

            }
        }

    }


};

