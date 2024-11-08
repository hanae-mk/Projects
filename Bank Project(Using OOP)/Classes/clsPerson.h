#pragma once

#include <iostream>
#include <string>
using namespace std;

class clsPerson
{
private:

	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:

	//Parametirized constructor
	clsPerson(string FirstName, string LastName, string Email, string Phone)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
	}

	//Property set
	void setFirstName(string FirstName)
	{
		//Add new feature (go to video properties set/get course 10 min (12:35)
		_FirstName = FirstName;
	}

	//Property get
	string GetFirstName()
	{
		return _FirstName;
	}

	__declspec(property(get = GetFirstName, put = setFirstName)) string FirstName;

	void setLastName(string LastName)
	{
		//Add new feature (go to video properties set/get course 10 min (12:35)
		_LastName = LastName;
	}

	string GetLastName()
	{
		return _LastName;
	}

	string FullName()
	{
		return _FirstName + " " + _LastName;
	}

	__declspec(property(get = GetLastName, put = setLastName)) string LastName;

	void setEmail(string Email)
	{
		//Add new feature (go to video properties set/get course 10 min (12:35)
		_Email = Email;
	}

	string GetEmail()
	{
		return _Email;
	}

	__declspec(property(get = GetEmail, put = setEmail)) string Email;

	void setPhone(string Phone)
	{
		//Add new feature (go to video properties set/get course 10 min (12:35)
		_Phone = Phone;
	}

	string GetPhone()
	{
		return _Phone;
	}

	__declspec(property(get = GetPhone, put = setPhone)) string Phone;

	void SendEmail(string Subject, string Body)
	{
		cout << "\nThe following message sent successfully to email : " << _Email;
		cout << "\nSubject :" << Subject;
		cout << "\nBody :" << Body << endl;
	}

	void SendSMS(string TextMessage)
	{
		cout << "\nThe following SMS sent successfully to phone : " << _Phone << endl;
		cout << TextMessage << endl;
	}



};


