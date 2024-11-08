#pragma once

#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"

class clsDeleteClientScreen : protected clsScreen
{
private:

	//Every screen has it own print because it's could be different from screen to screen
	static void _PrintUser(clsBankClient Client) //Same Signature Overriding
	{
		cout << "\nClient Card:";
		cout << "\n_________________________________\n";
		cout << "\nFirst Name :" << Client.FirstName;
		cout << "\nLast Name  :" << Client.LastName;
		cout << "\nFull Name  :" << Client.FullName();
		cout << "\nEmail      :" << Client.Email;
		cout << "\nPhone      :" << Client.Phone;
		cout << "\nAcc Number :" << Client.AccountNumber();
		cout << "\nPin Code   :" << Client.PinCode;
		cout << "\nAcc Number :" << Client.AccountBalance;
		cout << "\n_________________________________\n";
	}

public:

	static void ShowDeleteClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
			return;
		
		_DrawScreenHeader("\tDelete Client Screen");

		string AccountNumber = "";

		cout << "\nPlease Enter Account Number ?";
		AccountNumber = clsInputValidate<string>::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not found, Please enter another one : ";
			AccountNumber = clsInputValidate<string>::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintUser(Client);

		char Answer = 'n';

		cout << "\n\nAre you sure you want delete this client? Y/N?";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{

			if (Client.Delete())
			{
				cout << "\nClient Deleted Successfully :-)\n";
				_PrintUser(Client);
			}
			else
				cout << "Error Client was not deleted\n";

		}
	}



};

