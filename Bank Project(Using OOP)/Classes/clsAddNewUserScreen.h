#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

using namespace std;

class clsAddNewUserScreen : protected clsScreen
{
private:

	static void _ReadUserInfo(clsUser& User)
	{

		cout << "\nEnter First Name : ";
		User.FirstName = clsInputValidate<string>::ReadString();

		cout << "\nEnter Last Name : ";
		User.LastName = clsInputValidate<string>::ReadString();

		cout << "\nEnter Email : ";
		User.Email = clsInputValidate<string>::ReadString();

		cout << "\nEnter Phone : ";
		User.Phone = clsInputValidate<string>::ReadString();

		cout << "\nEnter Password : ";
		User.Password = clsInputValidate<string>::ReadString();

		cout << "\nEnter Permission : ";
		User.Permissions = _ReadPermissionsToSet();

	}

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
	
	static int _ReadPermissionsToSet()
	{
		int Permissions = 0;
		char Answer = 'y';

		cout << "\nDo you want to give full access? Y/N?";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
			return clsUser::enPermissions::pAll;

		cout << "\nDo you want to give access to :\n";

		cout << "\nShow Client List? y/n?";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
			Permissions += clsUser::enPermissions::pListClients;

		cout << "\nAdd New Client? y/n?";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
			Permissions += clsUser::enPermissions::pAddNewClient;

		cout << "\nDelete Client? y/n?";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
			Permissions += clsUser::enPermissions::pDeleteClient;

		cout << "\nUpdate Client? y/n?";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
			Permissions += clsUser::enPermissions::pUpdateClient;

		cout << "\nFind Client? y/n?";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
			Permissions += clsUser::enPermissions::pFindClient;

		cout << "\nShow Transactions? y/n?";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
			Permissions += clsUser::enPermissions::pShowTransactionsMenue;

		cout << "\nManage Users? y/n?";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
			Permissions += clsUser::enPermissions::pShowManageUsersMenue;

		cout << "\nShow Login Register? y/n?";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
			Permissions += clsUser::enPermissions::pShowLogInRegister;

		return Permissions;
	}
		
public:

	static void ShowAddNewUserScreen()	
	{
		_DrawScreenHeader("\t   Add New User Screen");
		
		string UserName = "";

		cout << "\nPlease Enter UserName : ";
		UserName = clsInputValidate<string>::ReadString();

		while (clsUser::IsUserExist(UserName))
		{
			cout << "\nUserName is already used, Choose another one : ";
			UserName = clsInputValidate<string>::ReadString();
		}

		clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

		_ReadUserInfo(NewUser);
		
		clsUser::enSaveResults SaveResult;

		SaveResult = NewUser.Save();

		switch (SaveResult)
		{
		case clsUser::enSaveResults::svSucceeded:
			cout << "\nUser Added Successfully :-)\n";
			_PrintUser(NewUser);
			break;

		case clsUser::enSaveResults::svFaildEmptyObject:
			cout << "\nError User was not saved because it's Empty :-(\n";
			break;

		case clsUser::enSaveResults::svFaildUserExists:
			cout << "\nUserName is already used\n";
			break;

		}


		





	}



};

