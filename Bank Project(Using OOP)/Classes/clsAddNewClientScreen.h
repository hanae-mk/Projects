#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsAddNewClientScreen: protected clsScreen
{
private:

    static void _ReadClientInfo(clsBankClient& Client) //I can send object by reference
    {

        cout << "\nEnter First Name?";
        Client.FirstName = clsInputValidate<string>::ReadString();

        cout << "\nEnter Last Name?";
        Client.LastName = clsInputValidate<string>::ReadString();

        cout << "\nEnter Email?";
        Client.Email = clsInputValidate<string>::ReadString();

        cout << "\nEnter Phone?";
        Client.Phone = clsInputValidate<string>::ReadString();

        cout << "\nEnter Pin Code?";
        Client.PinCode = clsInputValidate<string>::ReadString();

        cout << "\nEnter Account Balance?";
        Client.AccountBalance = clsInputValidate<double>::ReadNumber();

        cout << "\n-----------------------";

    }

    static void _PrintUser(clsBankClient Client) //Same Signature Overriding
    {
        cout << "\nClient Card:";
        cout << "\n_________________________________\n";
        cout << "\nFirst Name  :" << Client.FirstName;
        cout << "\nLast Name   :" << Client.LastName;
        cout << "\nFull Name   :" << Client.FullName();
        cout << "\nEmail       :" << Client.Email;
        cout << "\nPhone       :" << Client.Phone;
        cout << "\nAcc Number  :" << Client.AccountNumber();
        cout << "\nPin Code    :" << Client.PinCode;
        cout << "\nAcc Balance :" << Client.AccountBalance; 
        cout << "\n_________________________________\n";
    }

public:

    static void ShowAddNewClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
            return;
        
        _DrawScreenHeader("\t Add New Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter Account Number : ";
        AccountNumber = clsInputValidate<string>::ReadString();

        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is already used, Choose another account number : ";
            AccountNumber = clsInputValidate<string>::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::svSuccessed:
            cout << "\nAccount Added Successfully :-)\n";
            _PrintUser(NewClient);
            break;

        case clsBankClient::enSaveResults::svFailedEmptyObject:
            cout << "\nError Account was not saved because it's Empty :-(\n";
            break;

        case clsBankClient::enSaveResults::svFailedAccountNumberExists:
            cout << "\nAccount Number is already used\n";
            break;

        }
    }






};

