
//Every Method doesn't modify a member in object we set it as "static" 
//so every user can use the method
//NOTE : YOU SHOULD NEVER HAVE PUBLIC VARIABLES IN CLASS
//IT's OK TO HAVE PUBLIC FUNCTIONS/METHODS IN YOUR CLASS BUT ALWAYS SET VARIABLES/Members 
//AS PRIVATE for security

#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsPerson.h"
#include <vector>
#include <fstream>
#include "Global.h"
using namespace std;

class clsBankClient : public clsPerson
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	string _AccountNumber = "";
	double _AccountBalance;
	string _PinCode;
	bool _MarkForDelete = false;
	

	//ABSTRACTION

	static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#")
	{
		vector <string> vClientData;
		vClientData = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
			vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

	}

	static string _ConvertClientObjectToLine(clsBankClient& Client, string Seperator = "#//#")
	{
		string ClientRecord = "";

		ClientRecord += Client.FirstName + Seperator;
		ClientRecord += Client.LastName + Seperator;
		ClientRecord += Client.Email + Seperator;
		ClientRecord += Client.Phone + Seperator;
		ClientRecord += Client.AccountNumber() + Seperator;		
		ClientRecord += Client.PinCode + Seperator;
		ClientRecord += to_string(Client.AccountBalance);

		return ClientRecord;
	}

	static vector <clsBankClient> _LoadClientsDataFromFile()
	{
		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line); //Stores Every Line In Object
				vClients.push_back(Client); // And  add every object in vector
			}

			MyFile.close();
		}

		return vClients;
	}

	static void _SaveClientsDataToFile(vector <clsBankClient> vClients)
	{

		fstream MyFile;
		MyFile.open("Clients.txt", ios::out); //overwrite mode delets all data so we can't 
		//write while (getline(MyFile, Line))
		string DataLine = "";

		if (MyFile.is_open())
		{
			for (clsBankClient& C : vClients)
			{
				if (C.MarkForDelete() == false)
				{
					DataLine = _ConvertClientObjectToLine(C);
					MyFile << DataLine << endl;
				}
			}

			MyFile.close();
		}
	}

	//This Method modifies members in object so should NOT define it as static 
	void _Update()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile(); //return vector loaded with objects (in the past vector loaded with structures)

		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == AccountNumber()) //Every  C here is an object in vector
			{
				//C is data in file     *this is the updated information in memory				

				C = *this;
				break;
			}
		}

		_SaveClientsDataToFile(_vClients);
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	static void _AddDataLineToFile(string DataLine)
	{
		fstream MyFile;

		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;
		}

		MyFile.close();
	}

	string _PrepareTransferLogInRecord(double Amount, clsBankClient DestinationClient, string UserName, string Seperator = "#//#")
	{
		string TransferLogRecord = "";

		TransferLogRecord += clsDate::GetSystemDateTimeString() + Seperator;
		TransferLogRecord += AccountNumber() + Seperator;
		TransferLogRecord += DestinationClient.AccountNumber() + Seperator;
		TransferLogRecord += to_string(Amount) + Seperator;
		TransferLogRecord += to_string(AccountBalance) + Seperator;
		TransferLogRecord += to_string(DestinationClient.AccountBalance) + Seperator;
		TransferLogRecord += UserName;

		return TransferLogRecord;

	}

	void _RegisterTransferLog(double Amount, clsBankClient DestinationClient, string UserName)
	{
		string DataLine = _PrepareTransferLogInRecord(Amount, DestinationClient, UserName);

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in | ios::app);

		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;
			MyFile.close();
		}
	}

	struct stTransferLogRecord;
	static stTransferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
	{
		vector <string> vTransferLogRecord = clsString::Split(Line, Seperator);

		stTransferLogRecord TransferLogRecord;

		TransferLogRecord.DateTime = vTransferLogRecord[0];
		TransferLogRecord.SourceAccountNumber = vTransferLogRecord[1];
		TransferLogRecord.DestinationAccountNumber = vTransferLogRecord[2];
		TransferLogRecord.Amount = stod(vTransferLogRecord[3]);
		TransferLogRecord.SourceBalanceAfter = stod(vTransferLogRecord[4]);
		TransferLogRecord.DestinationBalanceAfter = stod(vTransferLogRecord[5]);
		TransferLogRecord.UserName = vTransferLogRecord[6];

		return TransferLogRecord;

	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}


public:

	struct stTransferLogRecord
	{
		string DateTime;
		string SourceAccountNumber;
		string DestinationAccountNumber;
		double Amount;
		double SourceBalanceAfter;
		double DestinationBalanceAfter;
		string UserName;

	};

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone,
		string AccountNumber, string PinCode, double AccountBalance)
		: clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	bool MarkForDelete()
	{
		return _MarkForDelete;
	}

	string AccountNumber()
	{
		return _AccountNumber; //Read Only Property
	}

	void SetPinCode(string PinCode)
	{
		//Add new feature (go to video properties set/get course 10 min (12:35)
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(double AccountBalance)
	{
		//Add new feature (go to video properties set/get course 10 min (12:35)
		_AccountBalance = AccountBalance;
	}

	double GetAccountBalance()
	{
		return _AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance))double AccountBalance;

	static clsBankClient Find(string AccountNumber) //Load Clients + bool Find
	{
		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in); //Read Mode

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);

				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}

				vClients.push_back(Client);
			}

			MyFile.close();
		}

		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in); //Read Mode

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);

				if (Client.AccountNumber() == AccountNumber && Client._PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}

				vClients.push_back(Client);
			}

			MyFile.close();
		}

		return _GetEmptyClientObject();
	}

	enum enSaveResults { svFailedEmptyObject = 0, svSuccessed = 1, svFailedAccountNumberExists = 2 };

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:                        //We didn't write the error message
			return enSaveResults::svFailedEmptyObject; //Always Seperate UI from the object itself

		case enMode::UpdateMode:
			_Update(); //Abstraction
			return enSaveResults::svSuccessed;

		case enMode::AddNewMode:

			//This will add new record to file or database
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFailedAccountNumberExists;
			}
			else
			{
				_AddNew();

				//We need to set the mode to update after add new
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSuccessed;
			}

		//There is not delete mode in Save() Method

		}
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return (!Client.IsEmpty());
	}

	bool Delete()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C._MarkForDelete = true;
				break;
			}
		}

		_SaveClientsDataToFile(_vClients);

		*this = _GetEmptyClientObject();
		//Current Object
		return true;

	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	static vector <clsBankClient> GetClientsList()
	{
	    return _LoadClientsDataFromFile();
	}

	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	bool Withdraw(double Amount)
	{
		if (Amount > _AccountBalance)
			return false;
		else
		{
			_AccountBalance -= Amount;
			Save();
		}
	}

	bool Transfer(double Amount, clsBankClient &DestinationClient, string UserName)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		
		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTransferLog(Amount, DestinationClient, UserName);
		return true;

	}

	static double GetTotalBalances()
	{
		vector <clsBankClient> vClients = GetClientsList();
		double TotalBalances = 0;

		for (clsBankClient& Client : vClients)
		{
			TotalBalances += Client._AccountBalance;
		}

		return TotalBalances;
	}

	static vector <stTransferLogRecord> GetTransferLogList()
	{
		vector <stTransferLogRecord> vTransferLogRecord;

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line = "";
			stTransferLogRecord TransferLogRecord;

			while (getline(MyFile, Line))
			{
				TransferLogRecord = _ConvertTransferLogLineToRecord(Line); //Stores Every Line In Object
				vTransferLogRecord.push_back(TransferLogRecord); // And  add every object in vector
			}

			MyFile.close();
		}

		return vTransferLogRecord;
	}

};
