#pragma once
#include "clsScreen.h"
#include "clsString.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsFindCurrencyScreen : protected clsScreen
{
private:

	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\nCurrency Card :";
		cout << "\n_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.CurrencyRate;
		cout << "\n_____________________________";
	}

	static void _ShowResults(clsCurrency Currency)
	{		
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrencyCard(Currency);
		}
		else
			cout << "\nCurrency was Not Found :-(\n";
	}

public:

	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\t   Find Currency Screen");

		short Choice = 0;

		cout << "\nFind By : [1] Code or [2] Country ?";
		Choice = clsInputValidate<short>::ReadNumberBetween(1,2);

		if (Choice == 1)
		{
			string CurrencyCode = "";

			cout << "\nPlease Enter Currency Code : ";
			CurrencyCode = clsInputValidate<string>::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResults(Currency);
		}
		else
		{
			string Country = "";

			cout << "\nPlease Enter Country Name : ";
			Country = clsString::UpperAllString(clsInputValidate<string>::ReadString());
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			_ShowResults(Currency);
			
		}
	}
};

