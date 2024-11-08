#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

class clsTransferScreen : protected clsScreen
{
private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card : ";
		cout << "\n____________________________\n";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n____________________________\n";

	}

	static string _ReadAccountNumber(string Destination)
	{
		string AccountNumber;

		cout << "\nPlease Enter Account Number to Transfer " << Destination << " : ";
		AccountNumber = clsInputValidate<string>::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, Please Enter Another Account Number?";
			AccountNumber = clsInputValidate<string>::ReadString();
		}

		return AccountNumber;
	}

	static double _ReadAmount(clsBankClient SourceClient)
	{
		double Amount = 0;
		
		cout << "\n\nEnter Transfer Amount ?";
		Amount = clsInputValidate<double>::ReadNumber();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAccount Exceeds the available Balance, Enter another Amount ?";
			Amount = clsInputValidate<double>::ReadNumber();
		}

		return Amount;
	}

public:

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t  Transfer Screen");

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("From"));

		_PrintClient(SourceClient);
		
		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("To"));

		_PrintClient(DestinationClient);

		double Amount = _ReadAmount(SourceClient);

		char Answer = 'y';

		cout << "\nAre you sure you want to perform this operation? y/n?";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.UserName))
			{
				cout << "\nTransfer Done Successfully\n";
			}
			else
				cout << "\nTransfer Failed.\n";

		}

		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);
		

	}
};

