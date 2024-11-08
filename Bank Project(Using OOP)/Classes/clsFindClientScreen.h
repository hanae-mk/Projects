#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsFindClientScreen : protected clsScreen
{
private:

	static void _PrintUser(clsBankClient Client)
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

public :
	
	static void ShowFindUserScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
			return;
		
		_DrawScreenHeader("\tFind Client Screen");
        
		string AccountNumber = "";
		cout << "\nPlease Enter Account Number?";		
		AccountNumber = clsInputValidate<string>::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not found, choose another one :";
			AccountNumber = clsInputValidate<string>::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		if (!Client.IsEmpty())
		{
			cout << "\nClient Found :-)\n";
		}
		else
		{
			cout << "\nClient was NOT Found :-(\n";
		}

		   _PrintUser(Client);
		
	}


};

