#pragma once
#include <string>
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

class clsTransactionsScreen : protected clsScreen
{
private:

    enum enTransactionsMenueOptions { eDeposit = 1, eWithdraw = 2, eShowTotalBalance = 3, 
                                      eTransfer = 4, eTransferLog = 5, eShowMainMenue = 6 };

    static short _ReadTransactionsMenueOption()
    {
        short TransactionsMenueOption = 0;

        cout << setw(37) << left << "" << "\tChoose what do you want to do? [1 to 6]?";
        TransactionsMenueOption = clsInputValidate<short>::ReadNumberBetween(1, 6, "Enter Number between 1 to 6?\n");

        return TransactionsMenueOption;

    }

    static void _GoBackToTransactionsMenue()
    {
        cout << "\n\n\nPress any key to go back to transactions menue...";

        system("pause>0");
        ShowTransactionsMenue();
    }  

    static void _ShowDepositScreen()
    {
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        clsTotalBalancesScreen::ShowTotalBalances();
    }

    static void _ShowTransferScreen()
    {
        clsTransferScreen::ShowTransferScreen();
    }

    static void _ShowTransferLogScreen()
    {
        clsTransferLogScreen::ShowTransferLogScreen();
    }
  
    static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionMenueOption)
    {
        switch (TransactionMenueOption)
        {
        case enTransactionsMenueOptions::eDeposit:
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;

        case enTransactionsMenueOptions::eWithdraw:
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;

        case enTransactionsMenueOptions::eShowTotalBalance:
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;

        case enTransactionsMenueOptions::eTransfer:
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenue();
            break;

        case enTransactionsMenueOptions::eTransferLog:
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionsMenue();
            break;

        case enTransactionsMenueOptions::eShowMainMenue:
        {
        }

        }
    }

public:

    static void ShowTransactionsMenue()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pShowTransactionsMenue))
            return;
        
        system("cls");
        _DrawScreenHeader("\tTransactions Screen");       
        cout << "\t\t\t\t\t==============================================\n";
        cout << "\t\t\t\t\t\tTransactions Menue Screen\n";
        cout << "\t\t\t\t\t==============================================\n";
        cout << "\t\t\t\t\t\t[1] Deposit.\n";
        cout << "\t\t\t\t\t\t[2] Withdraw.\n";
        cout << "\t\t\t\t\t\t[3] Total Balances.\n";
        cout << "\t\t\t\t\t\t[4] Transfer.\n";
        cout << "\t\t\t\t\t\t[5] Transfer Log.\n";
        cout << "\t\t\t\t\t\t[6] Main Menue.\n";
        cout << "\t\t\t\t\t==============================================\n";
        _PerformTransactionsMenueOption((enTransactionsMenueOptions)_ReadTransactionsMenueOption());

    }

};

