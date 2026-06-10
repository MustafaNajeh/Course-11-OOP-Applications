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

void AddNewClient() {

    string AccountNumber = "";
    cout << "Please Enter Account Number\n";
    AccountNumber = clsInputValidate::ReadString();

    while (clsBankClient::IsclientExist(AccountNumber)) {

        cout << "Sory, your AccountNumber is Exsist enter Agin\n";
        AccountNumber = clsInputValidate::ReadString();

    }

    clsBankClient Client = clsBankClient::GetAddNewClientObject(AccountNumber);

    cout << "\n_______________________\n";
    cout << "\Add New Client Info";
    cout << "\n_______________________\n\n";

    ReadClientInfo(Client);

    clsBankClient::enSaveClient SaveResult;

    SaveResult = Client.Save();


    switch (SaveResult) {

    case clsBankClient::SussccesChanges:
        Client.Print();
        cout << "\n Add New Client Sussfuly";
        break;
    case clsBankClient::FaildChanges:
        cout << "\nAdd New Client Fild\n";
        break;
    case clsBankClient::FaildAddNewClientExists:
        cout << "\nFaild Add New Client Because Exists";
        break;
    }
}

int main()
{

    AddNewClient();

    system("pause>0");
    return 0;
}