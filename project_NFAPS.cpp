#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <string>
#include <vector>
#include "Passenger.h"
#include "city.h"
using namespace std;


int main()
{
	Passenger passenger;
	//Passenger* passenger_ptr;

	//passenger_ptr = new Passenger[100];
	//passenger.generateData(passenger_ptr);
	//passenger.Passenger_registration(passenger_ptr);
	city cities;
	city* city_ptr = new city[5];
	cities.generateDataForLocal(city_ptr);
	cities.PrintAllFlightSchedule(city_ptr);

	cout << endl;
	cout << endl;
	cities.UpdateInformation(city_ptr);



	delete[] city_ptr;

}