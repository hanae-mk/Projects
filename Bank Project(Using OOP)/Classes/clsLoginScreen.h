#pragma once

#include <iostream>
#include "Global.h"
#include "clsUser.h"
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsLoginScreen : protected clsScreen
{
private:

    static bool _Login()
    {
        bool LoginFailed = false; //Flag
        string UserName, Password;
        short FailedLoginCount = 3;

        do
        {
            system("cls");
            _DrawScreenHeader("\t       Login Screen");      

            if (LoginFailed)
            {
                cout << "Invalid UserName/Password!\n";
                cout << "You have " << --FailedLoginCount << " Trial(s) to login.\n";

                if (FailedLoginCount == 0)
                {
                    cout << "\nYou are Locked after 3 failed trails\n";
                    return false;
                }
            }

            cout << "\nEnter UserName?";
            UserName = clsInputValidate<string>::ReadString();

            cout << "Enter Password?";
            Password = clsInputValidate<string>::ReadString();

            CurrentUser = clsUser::Find(UserName, Password);

            LoginFailed = CurrentUser.IsEmpty();

        } while (LoginFailed);

        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
        return true;
    }

public:
    
    static bool ShowLoginScreen()
    {
        return _Login();
    }


};

