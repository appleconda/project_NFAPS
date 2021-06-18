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
	cin.ignore(); getline(cin, passenger.passenger_password);

	string passTemp("");
	lineEnd();
	LOG("Re-Type password to confirm:"); lineEnd();
	cin.ignore(); getline(cin, passTemp);
	while (passTemp != passenger.passenger_password)
	{
		LOG("Password didn't match re-enter:"); lineEnd();
		cin.ignore(); getline(cin, passTemp);
	}

	passenger_ptr[passenger_count + 1] = passenger;
}