#pragma once
#include <iostream>
#include <string>
#include <vector>

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
	vector<FlightSchedule> flights;
	FlightSchedule CurrentBooking;

public:
	Passenger() : name(""), CNIC(0), passenger_username(""), passenger_password(""),
		VisaStatus(0), howManyflightsBooked(0) {}
	~Passenger() {}

	void Passenger_registration(Passenger*, int&);
	void generateData(Passenger*, city*);

	//void setciy_ptr(city* city_ptr) { this->city_ptr = city_ptr; }
	void setName(string name) { this->name = name; }
	void setCNIC(long long cnic) { CNIC = cnic; }
	void setUserName(string str) { passenger_username = str; }
	void setPassword(string str) { passenger_password = str; }
	long long getCNIC() { return CNIC; }

	void PrintFlightSchedule();
	void PassengerBooking(city*);
	void PassengerLogIn(city*, Passenger*, int);
};

