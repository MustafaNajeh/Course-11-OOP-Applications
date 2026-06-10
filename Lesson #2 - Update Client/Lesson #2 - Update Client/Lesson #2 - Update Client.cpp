#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"

void ReadUpdate(clsBankClient& Client) {

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

void UpdateClient() {

    string AccountNumber = "";
    cout << "Please Enter Account Number\n";
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsclientExist(AccountNumber)) {

        cout << "Sory, your AccountNumber is Not Exsist enter Agin\n";
        AccountNumber = clsInputValidate::ReadString();

    }

    clsBankClient Client = clsBankClient::FindClient(AccountNumber);
    Client.Print();

    cout << "\n_________________\n";
    cout << "\nUpdate Info";
    cout << "\n_________________\n";

    ReadUpdate(Client);

    clsBankClient::enUpdateClient SaveResult;

    SaveResult = Client.Save();
    

    switch (SaveResult) {

    case clsBankClient::SussccesUpdate :
        Client.Print();
        cout << "\nUpdate Sussfuly";
        break;
    case clsBankClient::FieldUpdate:
        cout << "Update Fild\n";
        break;
    }




}

int main()
{
   
    UpdateClient();

    system("pause>0");
    return 0;
}