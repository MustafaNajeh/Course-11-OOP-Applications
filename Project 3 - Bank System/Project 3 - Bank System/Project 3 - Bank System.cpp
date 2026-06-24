#include <iostream>
#include "clsMainMenueScreen.h"
#include "clsLoginScreen.h"
#include "clsUser.h"
#include "clsCurrency.h"
using namespace std;

static void _PrintOneCurrency(clsCurrency Currency) {
	cout << "\n_____________________________\n";
	cout << "Countrey      : " << Currency.Country() << "\n";
	cout << "Currency Code : " << Currency.CurrencyCode() << "\n";
	cout << "Currency Name : " << Currency.CurrencyName() << "\n";
	cout << "Rate          : " << Currency.Rate();
	cout << "\n_____________________________\n";

}

int main() {

	
	clsCurrency Currency1 =	clsCurrency::FindCountry("iraq");
	_PrintOneCurrency(Currency1);

	clsCurrency Currency2 = clsCurrency::FindCurrencyCode("irr");
	_PrintOneCurrency(Currency2);

	Currency1.UpdateRate(1600);
	_PrintOneCurrency(Currency1);



	/*while (true) {

		if (!clsLoginScreen::ShowLoginScreen()) {
			break;
		}

	}*/
	system("pause>0");

}
