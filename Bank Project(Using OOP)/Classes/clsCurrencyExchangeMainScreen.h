#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

class clsCurrencyExchangeMainScreen : protected clsScreen
{
private:

    enum enCurrenciesMainMenueOptions {eListCurrencies = 1, eFindCurrency = 2, eUpdateCurrencyRate = 3,
                                    eCurrencyCalculator = 4, eMainMenue = 5 };

    static short _ReadCurrenciesMainMenueOption()
    {
        short Option = 0;

        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]?";
        Option = clsInputValidate<short>::ReadNumberBetween(1, 5);

        return Option;
    }

    static void _GoBackToCurrenciesMenue()
    {
        cout << "\n\nPress any key to go back to Currencies Menue...";
        system("pause>0");

        ShowCurrenciesMenue();
    }

    static void _ShowCurrenciesScreen()
    {
        clsCurrenciesListScreen::ShowCurrenciesList();
    }

    static void _ShowFindCurrencyScreen()
    {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateCurrencyRateScreen()
    {
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }
    
    static void _PerformCurrenciesMainMenueOption(enCurrenciesMainMenueOptions CurrenciesMainMenueOptions)
    {
        switch (CurrenciesMainMenueOptions)
        {
        case enCurrenciesMainMenueOptions::eListCurrencies:
            system("cls");
            _ShowCurrenciesScreen();
            _GoBackToCurrenciesMenue();
            break;

        case enCurrenciesMainMenueOptions::eFindCurrency:
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrenciesMenue();
            break;

        case enCurrenciesMainMenueOptions::eUpdateCurrencyRate:
            system("cls");
            _ShowUpdateCurrencyRateScreen();
            _GoBackToCurrenciesMenue();
            break;

        case enCurrenciesMainMenueOptions::eCurrencyCalculator:
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrenciesMenue();
            break;

        case enCurrenciesMainMenueOptions::eMainMenue:
        {
        }

        }
    }

public:

	static void ShowCurrenciesMenue()
	{
		system("cls");
        _DrawScreenHeader("\tCurrency Exchange Main Screen");
        cout << setw(37) << left << "" << "==============================================\n";
        cout << setw(37) << left << "" << "\t   Currency Exchange Main Screen\n";
        cout << setw(37) << left << "" << "==============================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "==============================================\n";
        _PerformCurrenciesMainMenueOption((enCurrenciesMainMenueOptions)_ReadCurrenciesMainMenueOption());
	}

};

