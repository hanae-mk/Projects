#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"

class clsTransferLogScreen : protected clsScreen
{
private:

    static void _PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransferLogRecord)
    {
        cout << setw(8) << left << "" << "| " << setw(25) << left << TransferLogRecord.DateTime;
        cout << "| " << setw(10) << left << TransferLogRecord.SourceAccountNumber;
        cout << "| " << setw(10) << left << TransferLogRecord.DestinationAccountNumber;
        cout << "| " << setw(10) << left << TransferLogRecord.Amount;
        cout << "| " << setw(10) << left << TransferLogRecord.SourceBalanceAfter;
        cout << "| " << setw(10) << left << TransferLogRecord.DestinationBalanceAfter;
        cout << "| " << setw(10) << left << TransferLogRecord.UserName;
    }

public:

	static void ShowTransferLogScreen()
	{
        
        vector <clsBankClient::stTransferLogRecord> vTransferLogRecord = clsBankClient::GetTransferLogList();
		
		string Title = "\t   Transfer Log List Screen";
		string Subtitle = "\t   ( " + to_string(vTransferLogRecord.size()) + " ) Record(s).";

		_DrawScreenHeader(Title, Subtitle);

        cout << setw(8) << left << "" << "\n\t______________________________________________________________________________________________________________\n\n";
        cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
        cout << "| " << left << setw(10) << "s.AccNum";
        cout << "| " << left << setw(10) << "d.AccNum";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(10) << "User";
        cout << setw(8) << left << "" << "\n\t______________________________________________________________________________________________________________\n\n";

        if (vTransferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Transfers Available In The System!";

        else

            for (clsBankClient::stTransferLogRecord& Record : vTransferLogRecord)
            {
                _PrintTransferLogRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t______________________________________________________________________________________________________________\n\n";




	}

};

