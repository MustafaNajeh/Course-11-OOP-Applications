#include <iostream>
#include "clsMainMenueScreen.h"
#include "clsLoginScreen.h"
#include "clsUser.h"
using namespace std;

int main() {

	while (true) {

		if (!clsLoginScreen::ShowLoginScreen()) {
			break;
		}

	}
	system("pause>0");

}
