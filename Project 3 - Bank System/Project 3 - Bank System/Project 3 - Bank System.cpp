#include <iostream>
#include "clsMainMenueScreen.h"
#include "clsLoginScreen.h"
#include "clsUser.h"
using namespace std;

int main() {
	while (true) {
		clsLoginScreen::ShowLoginScreen();
	}
	system("pause>0");
}