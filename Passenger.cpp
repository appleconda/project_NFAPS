#include "Passenger.h"


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
void Passenger::generateData(Passenger* passenger_ptr, city* city_ptr)
{
	srand(time(0));
	int randomCityIndex(0), randomAirportIndex(0), randomFlightSchedule(0);
	long long cnic = 8130275782227;
	for (auto i = 0; i < 10; i++)
	{
		passenger_ptr[i].name = "Name # " + to_string(i + 1);
		passenger_ptr[i].CNIC = cnic + i;
		passenger_ptr[i].passenger_username = "Username " + to_string(i + 1);
		passenger_ptr[i].passenger_password = "Password" + to_string(i + 1);
		for (auto k = 0; k < 5; k++)
		{
			randomCityIndex = rand() % 5;
			randomAirportIndex = rand() % 1;
			randomFlightSchedule = rand() % 15;
			passenger_ptr[i].flights.push_back(city_ptr[randomCityIndex].getAirport()[randomAirportIndex].getFlightSchedule()[randomFlightSchedule]);
			passenger_ptr[i].howManyflightsBooked++;
		}
	}
}
void DoesCnicAlreadyExist(Passenger* passenger_ptr, long long& cnic, int passenger_count)
{

	for (auto i = 0; i < passenger_count; i++)
	{
		if (passenger_ptr[i].getCNIC() == cnic)
		{
			cout << "CNIC already exists, Re-enter "; cin >> cnic;
			DoesCnicAlreadyExist(passenger_ptr, cnic, passenger_count);
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
void Passenger::Passenger_registration(Passenger* passenger_ptr, int& passenger_count)
{
	passenger_count++;
	Passenger passenger;
	LOG("Please Enter your CNIC "); cin >> CNIC;
	IsCnicValid(CNIC);
	DoesCnicAlreadyExist(passenger_ptr, CNIC, passenger_count);

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

	passenger_ptr[passenger_count] = passenger;
}

void Passenger::PrintFlightSchedule()
{
	cout << left << setw(10) << "Choice";
	cout << left << setw(10) << "Flight #"
		<< left << setw(20) << "Flying To"
		<< left << setw(30) << "Departure Time"
		<< left << setw(30) << "Duration in Hours"
		<< left << setw(40) << "Arrival Time"
		<< left << setw(0) << "Avail Seats" << endl;
	int count(0);
	for (auto i : flights)
	{
		cout << left << setw(10) << count + 1;
		cout << left << setw(10) << i.getFlightName()
			<< left << setw(20) << i.getCityName()
			<< left << setw(30) << i.getDeparture_time()
			<< left << setw(30) << i.getDuration()
			<< left << setw(40) << i.getArrival_time()
			<< left << setw(0) << i.getAvailSeats();
		cout << endl;
		count++;

	}
}

void DisplayAirportNames(string AirportNames[])
{
	cout << left << setw(20) << "Choice #"
		<< left << setw(20) << "Airport Names" << endl;

	for (auto i = 0; i < 10; i++)
	{
		cout << left << setw(20) << i + 1
			<< left << setw(20) << AirportNames[i] << endl;

	}
}


void Passenger::PassengerBooking(city* city_ptr)
{
	string AirportNames[] = { "Islamabad North", "Islamabd South", "Lahore North",
						"Lahore South", "Quetta North", "Quetta South",
						"Peshawar North", "Peshawar South", "Karachi North",
						"Karachi South" };
	DisplayAirportNames(AirportNames);
	cout << endl;
	cout << "Please Enter the airport you will be departing from "; int choice(0); cin >> choice;
	int cityIndex(0); int airportIndex(0);
	for (auto i = 0; i < 5; i++)
	{
		for (auto k = 0; k < 2; k++)
		{
			if (city_ptr[i].getAirport()[k].getName() == AirportNames[choice - 1])
			{
				cityIndex = i; airportIndex = k;
			}
		}
	}
	char Charchoice = 'N';
	PrintOnlyOneCitySchedule(city_ptr, cityIndex, airportIndex);
	do
	{
		cout << "Please Enter the flight you want to pick "; int choice1(0); cin >> choice1;
		cout << endl;

		if (city_ptr[cityIndex].getAirport()[airportIndex].getFlightSchedule()[choice1 - 1].getisLocal() == 0)
		{
			if (VisaStatus == 1)
			{
				flights.push_back(city_ptr[cityIndex].getAirport()[airportIndex].getFlightSchedule()[choice1 - 1]);
				howManyflightsBooked++;
				cout << "Do you wish to pick other flight? Y/N? "; cin >> Charchoice;
			}
			else
			{
				cout << "You need a visa to book this flight" << endl;
				cout << "Do you wish to pick other flight? Y/N? "; cin >> Charchoice;
			}
		}
		else
		{
			flights.push_back(city_ptr[cityIndex].getAirport()[airportIndex].getFlightSchedule()[choice1 - 1]);
			howManyflightsBooked++;
			cout << "Do you wish to pick other flight? Y/N? "; cin >> Charchoice;

		}
	} while (Charchoice == 'Y' || Charchoice == 'y');



}

void Passenger::PassengerLogIn(city* city_ptr, Passenger* passenger_ptr, int Passenger_count)
{
	string userPasswrod("");
	bool accessGranted(0);
	string userName;
	bool found(0);
	auto i = 0;
	do
	{
		cout << "Enter your Username ";  cin.ignore(); getline(cin, userName);
		for (i = 0; i < Passenger_count + 1; i++)
		{
			if (userName == passenger_ptr[i].passenger_username)
			{
				found = 1;
				cout << "Please Enter your Password "; cin >> userPasswrod;

				if (userPasswrod == passenger_ptr[i].passenger_password)
				{
					accessGranted = 1;
				}
				else
				{
					cout << "Wrong Password Try Again";
					break;
				}

			}
		}
		if (found == 0)
			cout << "No Such Username Exist try again" << endl;
	} while (accessGranted == 0);

	cout << "------------------------------" << endl;
	cout << left << setw(20) << "|Choice|"
		<< left << setw(20) << "|Options|" << endl;
	cout << left << setw(20) << "1"
		<< left << setw(20) << "Book a Flight" << endl;
	cout << left << setw(20) << "2"
		<< left << setw(20) << "View your Booked Flights" << endl;
	cout << left << setw(20) << "3"
		<< left << setw(20) << "Delete a booked Flight" << endl;
	cout << left << setw(20) << "4"
		<< left << setw(20) << "View Total Number of Flights booked" << endl;
	cout << "------------------------------" << endl;
	cout << "Enter Your choice "; int choice(0); cin >> choice;
	int choice1(0);
	switch (choice)
	{
	case 1:
		passenger_ptr[i].PassengerBooking(city_ptr);
		break;
	case 2:
		passenger_ptr[i].PrintFlightSchedule();
		break;
	case 3:
		passenger_ptr[i].PrintFlightSchedule();
		cout << endl << "Enter your choice ";  cin >> choice1;
		passenger_ptr[i].flights.erase(flights.begin() + choice1);
		cout << "Successful Deletion" << endl;
		passenger_ptr[i].PrintFlightSchedule();
		break;
	case 4:
		cout << "Total Number of flights booked are " << passenger_ptr[i].howManyflightsBooked << endl;
		break;
	default:
		break;
	}
}