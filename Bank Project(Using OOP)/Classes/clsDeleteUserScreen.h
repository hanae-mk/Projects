#pragma once
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"


class clsDeleteUserScreen : protected clsScreen
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

	static void ShowDeleteUserScreen()
	{
		
		_DrawScreenHeader("\t   Delete User Screen");
		
		string UserName = "";

		cout << "\nPlease Enter User Name ?";
		UserName = clsInputValidate<string>::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser is not found, choose another one : ";
			UserName = clsInputValidate<string>::ReadString();
		}

		clsUser User = User.Find(UserName);

		if (UserName == "Admin")
		{
			cout << "\nYou cannot Delete this User.\n";
			return;
		}

		_PrintUser(User);

		cout << "\nAre you sure you want to delete this User? Y/N?";
		char Answer = 'n';
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (User.Delete())
			{
				cout << "\nUser Deleted Successfully :-)\n";
				_PrintUser(User);
			}
			else
				cout << "\nError User was not deleted\n";
		}



	}


};

