#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsCurrencyCalculatorScreen : protected clsScreen
{
private:

	static double _ReadAmount()
	{
		double Amount = 0;

		cout << "\nEnter Amount to Exchange : ";
		Amount = clsInputValidate<double>::ReadNumber();

		return Amount;
	}
	
	static clsCurrency _GetCurrency(string Message)
	{
		string CurrencyCode = "";
		cout << Message << endl;

		CurrencyCode = clsInputValidate<string>::ReadString();

		while (!clsCurrency::IsCurrencyExists(CurrencyCode))
		{
			cout << "\nCurrency Not Found, Please Enter Another Currency Code?\n";
			CurrencyCode = clsInputValidate<string>::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		return Currency;

	}

	static void _PrintCalculationsResults(double Amount, clsCurrency CurrencyFrom, clsCurrency CurrencyTo)
	{
		
		_PrintCurrencyCard(CurrencyFrom, "\nConvert From :");
		
		double AmountInUSD = CurrencyFrom.ConvertToUSD(Amount);

		cout << "\n" << Amount << " " << CurrencyFrom.CurrencyCode() << " = " 
			<< AmountInUSD << " USD\n";

		if (CurrencyTo.CurrencyCode() == "USD")
		{
			return;
		}

		double AmountInOtherCurrency = CurrencyFrom.ConvertToOtherCurrency(Amount, CurrencyTo);

		cout << "\nConverting from USD to : \n";

		_PrintCurrencyCard(CurrencyTo, "\nConvert To :");

		cout << "\n" << Amount << " " << CurrencyFrom.CurrencyCode() << " = "
			<< AmountInOtherCurrency << CurrencyTo.CurrencyCode();
	}

	static void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card")
	{
		cout << Title << endl;
		cout << "\n_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.CurrencyRate;
		cout << "\n_____________________________\n";
	}

public:

	static void ShowCurrencyCalculatorScreen()
	{
		char Continue = 'y';

		while (toupper(Continue) == 'Y')
		{ 
		     system("cls");

		     _DrawScreenHeader("\t    Calculator Currency Screen");
		     
			 clsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency 1 Code :");
			 clsCurrency CurrencyTo = _GetCurrency("\nPlease Enter Currency 2 Code :");

		    /* string Currency1Code = "";
		     cout << "\nPlease Enter Currency 1 Code : \n";
		     Currency1Code = clsInputValidate::ReadString();
		     
		     while (!clsCurrency::IsCurrencyExists(Currency1Code))
		     {
		     	cout << "\nCurrency Not Found, Please Enter Another Currency Code?\n";
		     	Currency1Code = clsInputValidate::ReadString();
		     }
		     
		     clsCurrency Currency1 = clsCurrency::FindByCode(Currency1Code);
		     
		     string Currency2Code = "";
		     cout << "\nPlease Enter Currency 2 Code : \n";
		     Currency2Code = clsInputValidate::ReadString();
		     
		     while (!clsCurrency::IsCurrencyExists(Currency2Code))
		     {
		     	cout << "\nCurrency Not Found, Please Enter Another Currency Code?\n";
		     	Currency2Code = clsInputValidate::ReadString();
		     }
		     
		     clsCurrency Currency2 = clsCurrency::FindByCode(Currency2Code);*/

			/* double Amount = 0;

			 cout << "\nEnter Amount to Exchange : ";
			 Amount = clsInputValidate::ReadDblNumber();
		     */

			 double Amount = _ReadAmount();
		     
		    /* cout << "\nConvert From : \n";
		     _PrintCurrency(CurrencyFrom);*/
		     
		    /* double Amount1 = Amount / Currency1.Rate();*/
		    /* cout << "\n" << Amount << " " << Currency1.CurrencyCode() << " = " << Amount1 << " USD\n";*/
		     
		    /* if (Currency2.CurrencyCode() != "USD")
		     {
		     	cout << "\nConverting from USD to : \n";
		     
		     	cout << "\nTo : \n";
		     
		     	_PrintCurrency(Currency2);
		     
		     	double Amount2 = Amount1 * Currency2.Rate();
		     	cout << "\n" << Amount << " " << Currency1.CurrencyCode() << " = " << Amount2 
		     		 << " " << Currency2.CurrencyCode();
		     */
			 _PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo);
		     
		     cout << "\n\nDo you want to perform another calculation? Y/N?";
		     cin >> Continue;

		}


	} 
	


};

