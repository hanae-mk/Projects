#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "clsScreen.h"
#include "clsUser.h"

class clsLoginRegisterScreen : protected clsScreen
{
private:

    static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
    {
        cout << setw(8) << left << "" << "| " << setw(25) << left << LoginRegisterRecord.DateTime;
        cout << "| " << setw(15) << left << LoginRegisterRecord.UserName;
        cout << "| " << setw(15) << left << LoginRegisterRecord.Password;
        cout << "| " << setw(15) << left << LoginRegisterRecord.Permissions;
    }

public:
    
    static void ShowLoginRegisterScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pShowLogInRegister))
        {
            return;
        }

        vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();

        string Title = "\t   Login Register List Screen";
        string Subtitle = "\t    ( " + to_string(vLoginRegisterRecord.size()) + " ) Record(s).";

        _DrawScreenHeader(Title, Subtitle);

        cout << setw(8) << left << "" << "\n\t______________________________________________________________________________________________________________\n\n";
        cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
        cout << "| " << left << setw(15) << "UserName";
        cout << "| " << left << setw(15) << "Password";
        cout << "| " << left << setw(15) << "Permissions";
        cout << setw(8) << left << "" << "\n\t______________________________________________________________________________________________________________\n\n";

        if (vLoginRegisterRecord.size() == 0)
            cout << "\t\t\t\tNo Logins Available In The System!";

        else

            for (clsUser::stLoginRegisterRecord& Record : vLoginRegisterRecord)
            {
                _PrintLoginRegisterRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t______________________________________________________________________________________________________________\n\n";


    }

};

