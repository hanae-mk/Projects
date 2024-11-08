#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsFindUserScreen : protected clsScreen
{
private:

	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n_________________________________\n";
		cout << "\nFirst Name  :" << User.FirstName;
		cout << "\nLast Name   :" << User.LastName;
		cout << "\nFull Name   :" << User.FullName();
		cout << "\nEmail       :" << User.Email;
		cout << "\nPhone       :" << User.Phone;
		cout << "\nUser Name   :" << User.UserName;
		cout << "\nPassword    :" << User.Password;
		cout << "\nPermissions :" << User.Permissions;
		cout << "\n_________________________________\n";
	}

public:

	static void ShowFindUserScreen()
	{
		_DrawScreenHeader("\t  Find User Screen");

		string UserName = "";
		cout << "\nPlease Enter User UserName?";
		UserName = clsInputValidate<string>::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser is not found, choose another one :";
			UserName = clsInputValidate<string>::ReadString();
		}

		clsUser User = clsUser::Find(UserName);

		if (!User.IsEmpty())
		{
			cout << "\nUser Found :-)\n";			
		}
		else
		{
			cout << "\nUser was NOT Found :-(\n";
		}

		_PrintUser(User);

	}


};

