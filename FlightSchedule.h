#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "Airplanes.h"



using namespace std;
class FlightSchedule
{
	int numberofHours;
	string AirportName; // holds the name of the airport you are travelling to e.g., Lahore North
	double Distance;

	struct tm* arrivalTime;
	struct tm* DepartureTime;

	string DateTimeOfFlight;
	string Arrival_Time;
	string Departure_Time;

	Airplanes airplane;
	int duration;
public:
	FlightSchedule() : numberofHours(0), arrivalTime(0), DepartureTime(0),
		duration(0), AirportName(""), DateTimeOfFlight(""),
		Distance(0) {}

	//void setNumberOfHours(int x) { numberofHours = x; }
	//int getNumberofHours() { return numberofHours; }

	//void setDuratation(double x) { duration = x; }
	int getDuration() { return duration; }
	Airplanes getAirplane() { return airplane; }
	void setCityName(string x) { AirportName = x; }
	string getCityName() { return AirportName; }
	void FlightScheduleSetter(FlightSchedule*, string);
	string getDateTime() { return DateTimeOfFlight; }
	string getDeparture_time() { return Departure_Time; }
	string getArrival_time() { return Arrival_Time; }

};

