#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsUtil.h"
#include "clsScreen.h"
#include <string>
#include <iomanip>

class clsTotalBalancesScreen : protected clsScreen
{
private:

    static void _PrintClientRecordBalanceLine(clsBankClient Client)
    {
        cout << "| " << setw(15) << Client.AccountNumber();
        cout << "| " << setw(35) << Client.FullName();
        cout << "| " << setw(15) << Client.
            AccountBalance;
    }

public:

    static void ShowTotalBalances()
    {
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        string Title = "\t     Balances List Screen";
        string Subtitle = "\t     ( " + to_string(vClients.size()) + " ) Client(s).";

        _DrawScreenHeader(Title, Subtitle);
        
        cout << "\n_________________________________________________________________________\n\n";
        cout << "| " << left << setw(15) << "Account Number ";
        cout << "| " << setw(35) << "Client Name ";
        cout << "| " << setw(15) << "Balance ";
        cout << "\n_________________________________________________________________________\n\n";

        double TotalBalances = clsBankClient::GetTotalBalances();

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In The System!";
        else

            for (clsBankClient& Client : vClients)
            {
                _PrintClientRecordBalanceLine(Client);
                cout << endl;
            }

        cout << "\n_________________________________________________________________________\n\n";

        cout << "\t\t\tTotal Balances = " << TotalBalances << endl;
        cout << "\t( " << clsUtil::NumberToText(TotalBalances) << " )\n";
    }



};

