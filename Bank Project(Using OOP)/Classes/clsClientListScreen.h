#pragma once

#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsUser.h"

class clsClientListScreen : protected clsScreen
{
private:

    static void _PrintClientRecordLine(clsBankClient Client)
    {
        cout << "| " << setw(10) << Client.AccountNumber();
        cout << "| " << setw(30) << Client.FullName();
        cout << "| " << setw(12) << Client.Phone;
        cout << "| " << setw(25) << Client.Email;
        cout << "| " << setw(10) << Client.PinCode;
        cout << "| " << setw(15) << Client.AccountBalance;
    }

public:

    static void ShowClientsList()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pListClients))
            return;
        
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        string Title = "\tClient List Screen";
        string Subtitle ="\t ( " + to_string(vClients.size()) + " ) Client(s).";
        _DrawScreenHeader(Title, Subtitle);
       
        cout << "\n______________________________________________________________________________________________________________\n\n";
        cout << "| " << left << setw(10) << "Acc Num ";
        cout << "| " << setw(30) << "Client Name ";
        cout << "| " << setw(12) << "Phone ";
        cout << "| " << setw(25) << "Email ";
        cout << "| " << setw(10) << "Pin Code ";
        cout << "| " << setw(15) << "Balance ";
        cout << "\n______________________________________________________________________________________________________________\n\n";

        if (vClients.size() == 0)
        {
            cout << "\t\t\t\tNo Clients Available In The System!";
        }

        else

            for (clsBankClient& Client : vClients)
            {
                _PrintClientRecordLine(Client);
                cout << endl;
            }

        cout << "\n______________________________________________________________________________________________________________\n\n";
    }
};

