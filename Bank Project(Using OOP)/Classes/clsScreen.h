#pragma once
#include <iostream>
#include "clsUser.h"
#include "Global.h"
#include "clsDate.h"

using namespace std;

class clsScreen
{
protected:

	static void _DrawScreenHeader(string Title, string Subtitle = "")
	{
		
		cout << "\t\t\t\t\t__________________________________________";
		cout << "\n\n\t\t\t\t\t" << Title;
		

		if (Subtitle != "")
		{
			cout << "\n\n\t\t\t\t\t" << Subtitle;			
		}

		cout << "\n\t\t\t\t\t__________________________________________\n\n";

		ShowDateAndLoggedInUser();
	}

	static bool CheckAccessRights(clsUser::enPermissions Permission)
	{
		if (!CurrentUser.CheckAccessPermission(Permission))
		{
			cout << "\t\t\t\t\t__________________________________________";
			cout << "\n\n\t\t\t\t\t    Access Denied! Contact your Admin.";
			cout << "\n\t\t\t\t\t__________________________________________";
			return false;
		}
		else
			return true;
	}

	static void ShowDateAndLoggedInUser()
	{
		cout << "\t\t\t\t\tUser : " << CurrentUser.UserName;
		cout << "\n\t\t\t\t\tDate : " << clsDate::DateToString(clsDate()) << "\n\n";
		

	}

};

