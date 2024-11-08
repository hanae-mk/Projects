#pragma once

#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsUtil.h"

class clsListUsersScreen : protected clsScreen
{
private:
   
    static void _PrintLoginRegisterRecordLine(clsUser User)
    {
        cout << setw(8) << left << "" << "| " << setw(12) << left << User.UserName;
        cout << "| " << setw(25) << left << User.FullName();
        cout << "| " << setw(12) << left << User.Phone;
        cout << "| " << setw(20) << left << User.Email;       
        cout << "| " << setw(10) << left << clsUtil::DecryptText(User.Password);
        cout << "| " << setw(12) << left << User.Permissions;

    }

public:

    static void ShowUsersList()
    {
        vector <clsUser> vUsers = clsUser::GetUsersList();

        string Title = "\t   User List Screen";
        string Subtitle = "\t    ( " + to_string(vUsers.size()) + " ) User(s).";
        _DrawScreenHeader(Title, Subtitle);

        cout << setw(8) << left << "" << "\n\t______________________________________________________________________________________________________________\n\n";
        cout << setw(8) << left << "" << "| " << left << setw(12) << "User Name";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t______________________________________________________________________________________________________________\n\n";

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Users Available In The System!";

        else

            for (clsUser& User : vUsers)
            {
                _PrintLoginRegisterRecordLine(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t______________________________________________________________________________________________________________\n\n";
    }
};

