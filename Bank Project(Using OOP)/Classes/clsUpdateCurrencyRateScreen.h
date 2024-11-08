#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsUpdateCurrencyRateScreen : protected clsScreen
{
private:

	static double _ReadRate()
	{
		cout << "\nEnter New Rate : ";

		double NewRate = 0;
		NewRate = clsInputValidate<double>::ReadNumber();

		return NewRate;
	}
	
	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\nCurrency Card :";
		cout << "\n_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.CurrencyRate;
		cout << "\n_____________________________\n";
	}

public:

	static void ShowUpdateCurrencyRateScreen()
	{
		_DrawScreenHeader("\t   Update Currency Screen");

		string CurrencyCode = "";

		cout << "\nPlease Enter Currency Code : ";
		CurrencyCode = clsInputValidate<string>::ReadString();

		while (!clsCurrency::IsCurrencyExists(CurrencyCode))
		{
			cout << "\nCurrency Not Found, Please Enter Another Currency Code ?";
			CurrencyCode = clsInputValidate<string>::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrencyCard(Currency);

		cout << "\n\nAre you sure you want to update the rate of this Currency? Y/N?";
		char Answer = 'n';
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			cout << "\n\nUpdate Currency Rate : ";
			cout << "\n____________________\n";	

			Currency.UpdateRate(_ReadRate());

			cout << "\nCurrency Rate Updated Successfully :-)\n";

			_PrintCurrencyCard(Currency);

		}
	}

};

