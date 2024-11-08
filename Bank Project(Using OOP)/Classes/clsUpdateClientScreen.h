#pragma once

#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

class clsUpdateClientScreen : protected clsScreen
{
private:

    static void _ReadClientInfo(clsBankClient& Client) //I can send object by reference
    {

        cout << "\nEnter First Name?";
        Client.FirstName = clsInputValidate<string>::ReadString();
        //Object              //User Interface (UI)


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
   
    static void _PrintUser(clsBankClient Client) 
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

    static void ShowUpdateClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClient))
            return;
        
        _DrawScreenHeader("\tUpdate Client Screen");
        
        string AccountNumber = "";

        cout << "\nPlease Enter Client Account Number?";
        AccountNumber = clsInputValidate<string>::ReadString(); //this function instead of cin >> 

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one :";
            AccountNumber = clsInputValidate<string>::ReadString(); //cin >> Acc num
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber); //Object full of info
        _PrintUser(Client);

        cout << "\n\nAre you sure you want update this client? Y/N?";
        char Answer = 'n';
        cin >> Answer;

        //you can add new feature here is to ask user what do you want to update exactly
        //because if the user want to update just phone number he will must re-enter
        //f. name l.name acc balance email pincode...

        if (toupper(Answer) == 'Y')
        {
            cout << "\n\nUpdate Client Info :";
            cout << "\n-----------------------\n";

            _ReadClientInfo(Client);

            clsBankClient::enSaveResults SaveResults;
            SaveResults = Client.Save();

            switch (SaveResults)
            {
            case clsBankClient::enSaveResults::svSuccessed:
                cout << "\nAccount Updated Successfully :-)\n";
                _PrintUser(Client);
                break;

            case clsBankClient::enSaveResults::svFailedEmptyObject:
                cout << "\nError Account was not saved because it's empty\n";
                break;
            }
        }
    }
};

