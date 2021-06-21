#pragma once
#include <iostream>
#include <string>
#include "city.h"

using namespace std;

#define LOG(x) cout << x << " "
#define lineEnd() cout << endl



class Passenger : public city
{
	string name;
	long long CNIC;
	string passenger_username;
	string passenger_password;
	bool VisaStatus;
	int howManyflightsBooked;
	FlightSchedule* flights;
	FlightSchedule CurrentBooking;
	city* city_ptr;
public:
	Passenger() : name(""), CNIC(0), passenger_username(""), passenger_password(""),
		VisaStatus(0), howManyflightsBooked(0), city_ptr(0)
	{
		flights = new FlightSchedule[10];
	}
	~Passenger() { delete[] flights; }
	void Passenger_registration(Passenger*);
	void generateData(Passenger*, city*);

	void setciy_ptr(city* city_ptr) { this->city_ptr = city_ptr; }
	void setName(string name) { this->name = name; }
	void setCNIC(long long cnic) { CNIC = cnic; }
	void setUserName(string str) { passenger_username = str; }
	void setPassword(string str) { passenger_password = str; }
	long long getCNIC() { return CNIC; }

	void PassengerBooking();
};

