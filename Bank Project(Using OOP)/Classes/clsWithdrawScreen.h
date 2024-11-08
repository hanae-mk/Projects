#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"
using namespace std;


class clsWithdrawScreen : protected clsScreen
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
        cout << "\nAcc Balance :" << Client.AccountBalance;
        cout << "\n_________________________________\n";
    }

public:

    static void ShowWithdrawScreen()
    {
        _DrawScreenHeader("\tWithdraw Screen");

        string AccountNumber = "";
        cout << "\nPlease Enter Account Number?";
        AccountNumber = clsInputValidate<string>::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = clsInputValidate<string>::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintUser(Client);

        double Amount = 0;
        cout << "\n\nPlease enter withdraw amount?";
        Amount = clsInputValidate<double>::ReadNumber();

        cout << "\nAre you sure you want perform this transaction? Y/N?";
        char Answer = 'n';
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            if (!Client.Withdraw(Amount))
            {
                cout << "\nCannot withdraw, Insuffecient Balance!\n";
                cout << "\nAmount to withdraw is : " << Amount;
                cout << "\nYour Balance is : " << Client.AccountBalance;
            }
            else
            {
                //Client.Withdraw(Amount);
                cout << "\n\nDone Successfully.";
                cout << "New Balance is : " << Client.AccountBalance << endl;
            }
        }
        else 
            cout << "\nOperation was cancelled " << endl;
    }



};


