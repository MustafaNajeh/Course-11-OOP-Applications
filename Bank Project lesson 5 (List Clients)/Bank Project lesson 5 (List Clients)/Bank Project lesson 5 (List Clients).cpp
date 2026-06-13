#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>
void PrintOneClient(clsBankClient& Client) {


	cout << "| " << setw(15) << left <<Client.AccountNumber();
	cout << "| " << setw(10) << left <<Client.PinCode;
	cout << "| " << setw(20) << left <<Client.FullName();
	cout << "| " << setw(20) << left  << Client.Email;
	cout << "| " << setw(12) << left <<Client.Phone;
	cout << "| " << setw(12) << left <<Client.AccountBalance;

}

void ShowClientList() {

	vector <clsBankClient> vClients = clsBankClient::GetClientList();

	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(20) << "Client Name";
	cout << "| " << left << setw(20) << "Email";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	if (vClients.size() == 0) {
		cout << "sorry there are erroe in the system or the Client file are empty\n";
	}
	else {
		for (clsBankClient Client : vClients)
		{
			PrintOneClient(Client);
			cout << endl;
		}
	}
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;


}

int main()
{

	ShowClientList();
    
    system("pause>0");
    return 0;
}