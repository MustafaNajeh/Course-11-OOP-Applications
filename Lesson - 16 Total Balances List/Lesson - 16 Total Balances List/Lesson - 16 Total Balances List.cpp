#include <iostream>
#include "clsMainMenueScreen.h"
#include "clsUser.h"
using namespace std;
 
static void _PrintClient(clsUser Client) {

    cout << "\nInfo";
    cout << "\n______________________________";
    cout << "\nAccountNumber  : " << Client.AccountNumber();
    cout << "\nPinCode        : " << Client.Password;
    cout << "\nFirstName      : " << Client.FirstName;
    cout << "\nLastName       : " << Client.LastName;
    cout << "\nFullName       : " << Client.FullName();
    cout << "\nEmail          : " << Client.Email;
    cout << "\nPhone          : " << Client.Phone;
    cout << "\nAccountBalance : " << Client.Permissions;
    cout << "\n______________________________";
}

static void _ReadUser(clsUser& User) {

    cout << "Enter FirstName : ";
    User.FirstName = clsInputValidate::ReadString();
    cout << "Enter LastName : ";
    User.LastName = clsInputValidate::ReadString();
    cout << "Enter Email : ";
    User.Email = clsInputValidate::ReadString();
    cout << "Enter Phone : ";
    User.Phone = clsInputValidate::ReadString();
    cout << "Enter PinCode : ";
    User.Password = clsInputValidate::ReadString();
    cout << "Enter AccountBalance : ";
    User.Permissions = clsInputValidate::ReadDoubleNumber();

}

int main() {

	//clsUser User = clsUser::FindUser("A100");
 //   _PrintClient(User);

    /*clsUser User1 = clsUser::GetAddNewUserObject("A11");
    _ReadUser(User1);

    User1.Save();
    _PrintClient(User1);*/

    clsUser Majud = clsUser::FindUser("A11");
    Majud.Delete();

	system("pause>0");
}