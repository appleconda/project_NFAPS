#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>	
#include "Airport.h"





using namespace std;

class city
{
	string name;
	Airport* airport; // 2 for each city

public:
	city() : name("") { airport = new Airport[2]; }

	~city() { delete[] airport; }

	Airport* getAirport() { return airport; }
	void generateDataForLocal(city*);
	void PrintAllFlightSchedule(city*);
	void PrintOnlyOneCitySchedule(city*, int, int);
	void UpdateInformation(city*); // When Admin makes changes this function allows that
};

