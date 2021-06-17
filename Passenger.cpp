#include "Passenger.h"
bool IsCnicValid(long long& cnic)
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
bool DoesCnicAlreadyExist(Passenger* passenger_ptr, long long cnic)
{
	bool found(0);
	for (auto i = 0; i < 10; i++)
	{
		if (passenger_ptr[i].getCNIC() == cnic)
		{
			found = 1;
			return found;
		}
	}
	return 0;
}
void Passenger::Passenger_registration(Passenger* passenger_ptr)
{
	LOG("Please Enter your CNIC "); cin >> CNIC;
	IsCnicValid(CNIC);
	bool doesCnicExist = DoesCnicAlreadyExist(passenger_ptr, CNIC);
	LOG("Please enter your name ");
	cin.ignore(); getline(cin, name);

	lineEnd();
	LOG("Pick a Username:"); lineEnd();
	cin.ignore(); getline(cin, passenger_username);
	lineEnd();
	LOG("Pick a Password:"); lineEnd();
	cin.ignore(); getline(cin, passenger_password);

	string passTemp("");
	lineEnd();
	LOG("Re-Type password to confirm:"); lineEnd();
	cin.ignore(); getline(cin, passTemp);
	while (passTemp != passenger_password)
	{
		LOG("Password didn't match re-enter:"); lineEnd();
		cin.ignore(); getline(cin, passTemp);
	}


}