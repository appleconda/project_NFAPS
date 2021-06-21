#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "Airplanes.h"



using namespace std;
class FlightSchedule
{
	bool isLocal;
	string AirportName; // holds the name of the airport you are travelling to e.g., Lahore North
	string FlightName;
	double Distance;

	struct tm* arrivalTime;
	struct tm* DepartureTime;

	string DateTimeOfFlight;
	string Arrival_Time;
	string Departure_Time;


	int duration;
	int AvailSeats;
	int price;
public:
	FlightSchedule() : isLocal(1), arrivalTime(0), DepartureTime(0),
		FlightName(""), Departure_Time(""), Arrival_Time(""),
		duration(0), AirportName(""), DateTimeOfFlight(""),
		Distance(0), AvailSeats(), price(0) {}

	bool getisLocal() { return isLocal; }

	void setDuratation(double x) { duration = x; }
	int getDuration() { return duration; }

	string getFlightName() { return FlightName; }

	void setCityName(string x) { AirportName = x; }
	string getCityName() { return AirportName; }

	void FlightScheduleSetter(FlightSchedule*, string);

	string getDateTime() { return DateTimeOfFlight; }

	string getDeparture_time() { return Departure_Time; }
	string getArrival_time() { return Arrival_Time; }

	void setDeparture_Time(string x) { Departure_Time = x; }
	void setArrival_Tiem(string x) { Arrival_Time = x; }

	int getAvailSeats() { return AvailSeats; }
	void setAvailSeats(int x) { AvailSeats = x; }

	struct tm* getArrivalTimeTm() { return arrivalTime; }
	struct tm* getDepartureTimeTm() { return DepartureTime; }

	int getPrice() { return price; }
	void AvailSeatsDecrement() { AvailSeats--; }
};

