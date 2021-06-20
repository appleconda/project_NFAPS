#pragma once
#include <iostream>
#include <string> 
#include "FlightSchedule.h"

using namespace std;
class Airport
{
	string name;
	string cityName;
	FlightSchedule* Flights_ptr;

public:
	Airport() : name(""), cityName("") { Flights_ptr = new FlightSchedule[15]; }
	~Airport() { delete[] Flights_ptr; }
	void setName(string name) { this->name = name; }
	string getName() { return name; }
	void generateDataOfDomesticFlights();
	FlightSchedule* getFlightSchedule() { return Flights_ptr; }
};

