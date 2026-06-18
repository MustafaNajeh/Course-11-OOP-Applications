#include <iostream>
#include "clsUtil.h"
#include "clsUser.h"
#include "GlobalObject.h"

using namespace std;


#pragma once
class clsScreen 
{
protected:
	static void _HedarScreen(string Title, string SubTitle = " ") {

		cout << "\t\t\t\t\t-----------------------------------------------\n\n";
		cout << "\t\t\t\t\t\t\t " << Title << " \n\n";
		if (!(SubTitle == " ")) {
			cout << "\t\t\t\t\t\t\t " << SubTitle << " \n\n";
		}
		cout << "\t\t\t\t\t-----------------------------------------------\n\n";
	}

	static bool CheckAccessRights(clsUser::ePermission Permissions) {
		
		if (!CurrentObject.CheckAccessPermissions(Permissions)) {
			cout << "\t\t\t\t\t-----------------------------------------------\n\n";
			cout << "\t\t\t\t\t\t " << "Access Denied! Contatn Your Admin" << " \n\n";
			cout << "\t\t\t\t\t-----------------------------------------------\n\n";

			return false;
		}
		else {
			return true;
		}


	}

};

