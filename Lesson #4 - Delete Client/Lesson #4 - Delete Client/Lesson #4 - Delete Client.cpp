#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"

void ReadClientInfo(clsBankClient& Client) {

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

void DeleteClient() {

    string AccountNumber = "";
    cout << "Please Enter Account Number\n";
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsclientExist(AccountNumber)) {

        cout << "Sory, your AccountNumber is Not Exsist enter Agin\n";
        AccountNumber = clsInputValidate::ReadString();

    }

    clsBankClient Client = clsBankClient::FindClient(AccountNumber);
    Client.Print();

    char Answer = 'y';

    cout << "\ndo you want really to delete this account? : ";
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y') {

        if (Client.Delete()) {
            Client.Print();
            cout << "\ndeleted sussccfuly.\n";
        }

        else {
            cout << "\ndeleted Faild.\n";

        }
    }

}

int main()
{

    DeleteClient();

    system("pause>0");
    return 0;
}