#include <iostream>
#include "clsUtil.h"
using namespace std;


#pragma once
class clsScreen 
{
protected:
	static void _HedarScreen(string Title, string SubTitle = " ") {

		cout << "\t\t\t\t\t-----------------------------------------------\n\n";
		cout << "\t\t\t\t\t\t\t " << Title << " \n\n";
		if (!(SubTitle == " ")) {
			cout << "\t\t\t\t\t\t\t " << Title << " \n\n";
		}
		cout << "\t\t\t\t\t-----------------------------------------------\n\n";
	}

};

