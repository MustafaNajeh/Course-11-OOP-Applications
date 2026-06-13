#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsUtil.h"
void PrintOwnClintForBalancesList(clsBankClient Cleint) {

	cout << "| " << setw(20) << left << Cleint.AccountNumber();
	cout << "| " << setw(50) << left << Cleint.FullName();
	cout << "| " << setw(30) << left << Cleint.AccountBalance;

}

void ShowTotalBalancesList() {

	vector <clsBankClient> vClients = clsBankClient::GetClientList();

	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(20) << "Accout Number";
	cout << "| " << left << setw(50) << "Client Name";
	cout << "| " << left << setw(30) << "Balance";
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	if (vClients.size() == 0) {
		cout << "sorry there are erroe in the system or the Client file are empty\n";
	}
	else {
		for (clsBankClient Client : vClients)
		{
			PrintOwnClintForBalancesList(Client);
			cout << endl;

		}
	}
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	double TotalBalnaces = clsBankClient::GetTotalBalances();
	cout << "\t\t\t\t\tTotal Balances =" << TotalBalnaces << endl;
	cout <<"\t\t\t\t( " << clsUtil::NumbersToText(TotalBalnaces) <<")";







}

int main()
{

	ShowTotalBalancesList();

	system("pause>0");
	return 0;
}