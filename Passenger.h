#pragma once
#include <iostream>
#include <string>

using namespace std;

#define LOG(x) cout << x << " "
#define lineEnd() cout << endl



class Passenger
{
	string name;
	long long CNIC;
	string passenger_username;
	string passenger_password;
	bool VisaStatus;
public:
	Passenger() : name(""), CNIC(0), passenger_username(""), passenger_password(""), VisaStatus(0) {}
	~Passenger() {}
	void Passenger_registration(Passenger*);
	void generateData(Passenger*);

	void setName(string name) { this->name = name; }
	void setCNIC(long long cnic) { CNIC = cnic; }
	void setUserName(string str) { passenger_username = str; }
	void setPassword(string str) { passenger_password = str; }
	long long getCNIC() { return CNIC; }


};

