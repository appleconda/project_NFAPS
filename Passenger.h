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
public:
	void Passenger_registration();
};

