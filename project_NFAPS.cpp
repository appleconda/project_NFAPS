#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <string>
#include <vector>
#include "Passenger.h"
#include "Admin.h"

using namespace std;


int main()
{
	Passenger passenger;
	city cities;
	Admin admin;

	Admin* admin_ptr = new Admin[10];
	Passenger* passenger_ptr = new Passenger[100];
	int passengerCount(0);

	city* city_ptr = new city[5];
	cities.generateDataForLocal(city_ptr);

	admin.AdminGenerateData(admin_ptr);

	passenger.generateData(passenger_ptr, city_ptr);
	passengerCount = 9;

	cout << " New-PAK Airline Flight System (NPAFS)" << endl;
	cout << "---------------------------------------" << endl;
	cout << "Would you like to countinue to as a Passenger or Admin? Enter P or A ";
	char PassengerOrAdmin;
	cin >> PassengerOrAdmin;
	string Username("");
	string Password("");
	bool found(0);

	if (PassengerOrAdmin == 'P' || PassengerOrAdmin == 'p')
	{
	jump:
		cout << endl;
		cout << "------------------------------" << endl;
		cout << left << setw(20) << "|Choice|"
			<< left << setw(20) << "|Options|" << endl;
		cout << left << setw(20) << "1"
			<< left << setw(20) << "Log In" << endl;
		cout << left << setw(20) << "2"
			<< left << setw(20) << "Register" << endl;
		cout << left << setw(20) << "3"
			<< left << setw(20) << "View Schedule of all flights" << endl;

		cout << "------------------------------" << endl;
		cout << "Enter your choice "; int menuChoice(0); cin >> menuChoice;
		switch (menuChoice)
		{
		case 1:
			passenger.PassengerLogIn(city_ptr, passenger_ptr, passengerCount);
			break;
		case 2:
			passenger.Passenger_registration(passenger_ptr, passengerCount);
			cout << "Registration successfull" << endl;
			goto jump;
			break;
		case 3:
			cities.PrintAllFlightSchedule(city_ptr);
			break;
		default:
			break;
		}
	}
	else
	{
		do
		{
			cout << "Enter your username ";
			cin.ignore(1000, '\n');
			getline(cin, Username);
			cout << endl;
			cout << "Enter your Password ";
			//cin.ignore(1000, '\n');
			getline(cin, Password);
			cout << endl;
			found = admin.AdminVerification(admin_ptr, Username, Password);
		} while (found == 0);

		admin.UpdateInformation(city_ptr);
	}

	/*cities.PrintAllFlightSchedule(city_ptr);

	cout << endl;
	cout << endl;
	cities.UpdateInformation(city_ptr);*/



	delete[] city_ptr, passenger_ptr;

}
