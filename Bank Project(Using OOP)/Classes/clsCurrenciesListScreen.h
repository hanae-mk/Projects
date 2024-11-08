#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"

class clsCurrenciesListScreen : protected clsScreen
{
private:

	static void _PrintCurrencyRecordLine(clsCurrency Currency)
	{
		cout << "| " << setw(30) << Currency.Country();
		cout << "| " << setw(12) << Currency.CurrencyCode();
		cout << "| " << setw(45) << Currency.CurrencyName();
		cout << "| " << setw(15) << Currency.CurrencyRate;
	}

public:

	static void ShowCurrenciesList()
	{
		vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();
		
		string Title = "\t    Currencies List Screen";
		string Subtitle = "\t    ( " + to_string(vCurrencies.size()) + " ) Currency.";
		
		_DrawScreenHeader(Title, Subtitle);

		cout << "\n______________________________________________________________________________________________________________\n\n";
		cout << "| " << left << setw(30) << "Country ";
		cout << "| " << setw(12) << "Code ";
		cout << "| " << setw(45) << "Name ";
		cout << "| " << setw(15) << "Rate/(1$) ";
		cout << "\n______________________________________________________________________________________________________________\n\n";
	
		if (vCurrencies.size() == 0)
			cout << "\n\t\t\t\tNo Currencies Available In The System!\n";
		else
		
		for (clsCurrency& C : vCurrencies)
		{
			_PrintCurrencyRecordLine(C);
			cout << endl;
		}
	
	
	
	}



	

};

