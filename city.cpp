#include "city.h"

#define MAX_NUM_OF_SECONDS (24*60*60)

string countries[] = { "Afghanistan", "United States", "United Kingdom", "China", "India",
						"Iran", "Palestine", "South Africa", "Australia", "Azerbaijan",
						"Bangaladesh", "Bahrain", "Canada", "El Salvador", "Ecudor", "Jordan",
						"Kenya", "Mexico", "Morocco", "Nepal", "Netherlands", "North Korea", "Japan"
						, "Norway", "New Zealand" };
double countriesDistance[] = { 425, 12352, 6211.02, 3284.45, 1452.78, 1501.93, 3236.92, 8362.39,9235.43,
								2246.35, 2205.71,1896.81, 10386.92, 14578.76, 15348.86, 3160.86, 4738.8,
								13946.9, 7116.22, 1447.59, 5657.79, 5293.61, 6303.07, 5524.98,1338.45 };
double TimeTaken[] = { .47, 13.54, 6.81, 3.6, 1.59, 1.65, 3.55, 9.17, 10.12, 2.46, 2.42, 2.08,
							11.38, 15.98, 16.82, 3.46, 5.19, 15.28, 7.8, 1.59, 6.2, 5.8, 6.91, 6.05, 14.67 };
string AirportNames[] = { "Islamabad North", "Islamabd South", "Lahore North",
						"Lahore South", "Quetta North", "Quetta South",
						"Peshawar North", "Peshawar South", "Karachi North",
						"Karachi South" };

string cityName[] = { "Islamabad", "Lahore", "Quetta", "Peshawar", "Karachi" };
string cityNameExt[] = { "North", "South" };


int IndexFinder(string name)
{
	for (auto i = 0; i < 10; i++)
	{
		if (name == AirportNames[i])
			return i;
	}
	return -1;
}

struct tm* GetTimeAndDate()
{
	unsigned int now_seconds = (unsigned int)time(NULL);
	unsigned int rand_seconds = (rand() * rand()) % (MAX_NUM_OF_SECONDS + 1);
	time_t       rand_time = (time_t)(now_seconds + rand_seconds);
	return localtime(&rand_time);
}

void FlightSchedule::FlightScheduleSetter(FlightSchedule* flights, string Airport_name)
{
	srand((unsigned int)time(NULL));
	srand(time(0));
	int RandomIndex(0);
	// First we do this for domestic flights; need to create 10 domestic flights
	// for example airport name Islamabad North
	// AirportName = Islamabad 
	int index = IndexFinder(Airport_name);
	for (auto i = 0; i < 10; i++) // loop for 'flights' which are 10
	{
		do
		{
			RandomIndex = rand() % 10;
		} while (RandomIndex == index);

		flights[i].AirportName = AirportNames[RandomIndex];
		struct tm* ptr = GetTimeAndDate();
		flights[i].DepartureTime = ptr;
		flights[i].DateTimeOfFlight = asctime(ptr);

		int random = (rand() % 500) + 100;
		flights[i].Distance = random;
		flights[i].duration = random / 100;

	}
	for (auto i = 10; i < 15; i++) // for international flights
	{
		RandomIndex = rand() % 25;
		flights[i].AirportName = countries[RandomIndex];
		struct tm* ptr = GetTimeAndDate();
		flights[i].DepartureTime = ptr;
		flights[i].DateTimeOfFlight = asctime(ptr);
		flights[i].Distance = countriesDistance[RandomIndex];
		flights[i].duration = TimeTaken[RandomIndex];
	}
}

void city::generateDataForLocal(city* city_ptr_Local)
{
	srand(time(0));
	// cities: Islamabad, Lahore, Quetta, Peshawar, Karachi

	int count(0);
	for (auto i = 0; i < 5; i++)
	{
		city_ptr_Local[i].name = cityName[i];
		for (auto j = 0; j < 2; j++)
		{
			if (count > 1)
				count = 0;
			city_ptr_Local[i].airport[j].setName(cityName[i] + " " + cityNameExt[count]);
			count++;
		}
	}
	FlightSchedule flight;
	FlightSchedule* flights;
	for (auto i = 0; i < 5; i++)
	{
		for (auto j = 0; j < 2; j++)
		{
			flights = city_ptr_Local[i].airport[j].getFlightSchedule();
			for (auto k = 0; k < 15; k++)
			{
				flight.FlightScheduleSetter(flights, city_ptr_Local[i].airport[j].getName());
			}
		}
	}

}

void city::PrintAllFlightSchedule(city* city_ptr)
{
	for (auto i = 0; i < 5; i++)
	{
		cout << "-------------" << city_ptr[i].name << "-----------------" << endl;

		for (auto l = 0; l < 2; l++)
		{

			if (l == 0)
			{
				cout << left << setw(30) << setfill(' ') << "*****Ariport # 1******"
					<< left << setw(30) << setfill(' ') << city_ptr[i].airport[l].getName() << endl;
			}
			else
			{
				cout << left << setw(30) << setfill(' ') << "******Ariport # 2******"
					<< left << setw(30) << setfill(' ') << city_ptr[i].airport[l].getName() << endl;
			}

			cout << endl << "**Printing the Flight Schedule**" << endl << endl;
			cout << left << setw(30) << setfill(' ') << "Arrival City"
				<< left << setw(30) << setfill(' ') << "Date And time Specifications" << endl;
			for (auto k = 0; k < 15; k++)
			{
				cout << left << setw(30) << setfill(' ') << city_ptr[i].airport[l].getFlightSchedule()[k].getCityName()
					<< left << setw(30) << setfill(' ') << city_ptr[i].airport[l].getFlightSchedule()[k].getDateTime() << endl;
			}
		}
	}

}


