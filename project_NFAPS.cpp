#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <string>
#include <vector>
#include "Passenger.h"

using namespace std;

void DisplayMenu();
int main()
{
	Passenger passenger;
	city cities;

	Passenger* passenger_ptr = new Passenger[100];
	int passengerCount(0);

	city* city_ptr = new city[5];
	cities.generateDataForLocal(city_ptr);

	passenger.generateData(passenger_ptr, city_ptr);
	passengerCount = 9;




	cities.PrintAllFlightSchedule(city_ptr);

	cout << endl;
	cout << endl;
	cities.UpdateInformation(city_ptr);



	delete[] city_ptr, passenger_ptr;

}
}