#pragma once
#include <string>
#include <fstream>
#include <vector>
#include "clsString.h"

class clsCurrency
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	double _Rate;
	
	static clsCurrency _ConvertLineToCurrencyObject(string Line, string Seperator = "#//#")
	{
		vector <string> vCurrencyData = clsString::Split(Line, Seperator);

		return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stod(vCurrencyData[3]));
	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
	{
		string CurrencyRecord = "";

		CurrencyRecord += Currency.Country() + Seperator;
		CurrencyRecord += Currency.CurrencyCode() + Seperator;
		CurrencyRecord += Currency.CurrencyName() + Seperator;
		CurrencyRecord += to_string(Currency.CurrencyRate);

		return CurrencyRecord;

	}

	static vector <clsCurrency> _LoadCurrencyDataFromFile()
	{
		vector <clsCurrency> vCurrencies;
		
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				vCurrencies.push_back(Currency);

			}

			MyFile.close();
		}

		return vCurrencies;
		
	}

	static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrencies)
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);

		string DataLine = "";

		if (MyFile.is_open())
		{
			for (clsCurrency& C : vCurrencies)
			{
				DataLine = _ConvertCurrencyObjectToLine(C);
				MyFile << DataLine << endl;
			}

			MyFile.close();
		}
	}

	void _Update()
	{
		vector <clsCurrency> vCurrencies = _LoadCurrencyDataFromFile();

		for (clsCurrency& C : vCurrencies)
		{
			if (C.CurrencyCode() == CurrencyCode())
			{
				C = *this;
				break;
			}
		}

		_SaveCurrencyDataToFile(vCurrencies);
	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

public:

	clsCurrency (enMode Mode, string Country, string CurrencyCode, string CurrencyName, double Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	bool IsEmpty()
	{
		return _Mode == enMode::EmptyMode;
	}

	string Country()
	{
		return _Country;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	void UpdateRate(double NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	void SetCurrencyRate(double CurrencyRate)
	{
		_Rate = CurrencyRate;
	}

	double Rate() 
	{
		return _Rate;
	}

	__declspec(property(put = SetCurrencyRate, get = Rate)) double CurrencyRate;

	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);
		
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

				if (Currency.CurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();
		}

		return _GetEmptyCurrencyObject();

	}

	static clsCurrency FindByCountry(string CountryName)
	{
		CountryName = clsString::UpperAllString(CountryName);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

				if (clsString::UpperAllString(Currency.Country()) == CountryName)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();
		}

		return _GetEmptyCurrencyObject();

	}

	static bool IsCurrencyExists(string CurrencyCode)
	{
		clsCurrency Currency = FindByCode(CurrencyCode);
		return (!Currency.IsEmpty());
	}

	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrencyDataFromFile();
	}

	double ConvertToUSD(double Amount)
	{
		return (double)(Amount / Rate());
	}

	double ConvertToOtherCurrency(double Amount, clsCurrency Currency2)
	{
		double AmountInUSD = ConvertToUSD(Amount);

		if (Currency2.CurrencyCode() == "USD")
		{
			return AmountInUSD;
		}
			
		return (double)(ConvertToUSD(Amount) * Currency2.Rate());
	}

	

	

};

