#include "Passenger.h"
int passenger_count = 10;
void IsCnicValid(long long& cnic)
{
	// should be of 13 charadcters
	// finding length
	string str = to_string(cnic);
	int size = str.length();
	while (size > 13)
	{
		LOG("Please enter 13 digits "); lineEnd();
		cin >> cnic;
	}
}
void Passenger::generateData(Passenger* passenger_ptr)
{
	long long cnic = 8130275782227;
	for (auto i = 0; i < 10; i++)
	{
		passenger_ptr[i].name = "Name # " + to_string(i + 1);
		passenger_ptr[i].CNIC = cnic + i;
		passenger_ptr[i].passenger_username = "Username # " + to_string(i + 1);
		passenger_ptr[i].passenger_password = "Password" + to_string(i + 1);
	}
}
void DoesCnicAlreadyExist(Passenger* passenger_ptr, long long& cnic)
{

	for (auto i = 0; i < passenger_count; i++)
	{
		if (passenger_ptr[i].getCNIC() == cnic)
		{
			cout << "CNIC already exists, Re-enter "; cin >> cnic;
			DoesCnicAlreadyExist(passenger_ptr, cnic);
		}
	}


}
void PasswordValidity(string& password)
{
	string str("");
	bool found_Numberic = 0;
	bool found_SpecialChar = 0;
	bool found_UpperCase = 0;
	bool found_LowerCase = 0;

	for (auto i = 0; i < password.length(); i++)
	{
		str.push_back(password[i]);
		if (str.find_first_not_of("!£$%&*") == std::string::npos)
		{
			found_SpecialChar = 1;
			break;
		}
		else
		{
			found_SpecialChar = 0;
		}
		str.clear();
	}
	for (auto i = 0; i < password.length(); i++)
	{
		str.push_back(password[i]);
		if (str.find_first_not_of("1234567890") == std::string::npos)
		{
			found_Numberic = 1;
			break;
		}
		else
		{
			found_Numberic = 0;
		}
		str.clear();
	}
	for (auto i = 0; i < password.length(); i++)
	{
		str.push_back(password[i]);
		if (str.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == std::string::npos)
		{
			found_UpperCase = 1;
			break;
		}
		else
		{
			found_UpperCase = 0;
		}
		str.clear();
	}
	for (auto i = 0; i < password.length(); i++)
	{
		str.push_back(password[i]);
		if (str.find_first_not_of("abcdefghijklmnopqrstuvwxyz") == std::string::npos)
		{
			found_LowerCase = 1;
			break;
		}
		else
		{
			found_LowerCase = 0;
		}
		str.clear();
	}

	if (found_Numberic == 0 || found_SpecialChar == 0 || found_UpperCase == 0 || found_LowerCase == 0)
	{
		cout << "Please include all Numeric, Special char, UpperCase and LowerCase" << endl;
		cin.ignore(); getline(cin, password);
		PasswordValidity(password);
	}

}
void Passenger::Passenger_registration(Passenger* passenger_ptr)
{
	passenger_count++;
	Passenger passenger;
	LOG("Please Enter your CNIC "); cin >> CNIC;
	IsCnicValid(CNIC);
	DoesCnicAlreadyExist(passenger_ptr, CNIC);

	LOG("Please enter your name ");
	cin.ignore(); getline(cin, passenger.name);

	lineEnd();
	LOG("Pick a Username:"); lineEnd();
	cin.ignore(); getline(cin, passenger.passenger_username);
	lineEnd();
	LOG("Pick a Password:"); lineEnd();
	string password("");
	PasswordValidity(password);
	passenger.passenger_password = password;

	string passTemp("");
	lineEnd();
	LOG("Re-Type password to confirm:"); lineEnd();
	cin.ignore(); getline(cin, passTemp);
	if (passTemp.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRS!£$%&*1234567890") != std::string::npos)
	{
		std::cerr << "Error\n";
	}
	while (passTemp != passenger.passenger_password)
	{
		cout << ("Password didn't match re-enter:"); lineEnd();
		cin.ignore(); getline(cin, passTemp);
	}

	passenger_ptr[passenger_count + 1] = passenger;
}