#include <iostream>
#include "clsBankClient.h";
using namespace std;

int main()
{


	clsBankClient Client1 = clsBankClient::FindClient("978");
	Client1.Print();

	clsBankClient Client2 = clsBankClient::FindClient("A101","1234");
	Client2.Print();

	cout <<endl<< clsBankClient::IsclientExist("27809");


	system("pause>0");
	return 0;
}

