#pragma once
#include <iostream>
#include<string>


using namespace std;

class Airplanes
{
	string name;
	bool isLocal; // 10 local 5 international daily
	int availSeats;
public:
	Airplanes() : name(""), isLocal(0), availSeats(0) {}
	void setAvailSeats(int x) { availSeats = x; }
	int getAvailSeats() { return availSeats; }
	void setName(string x) { name = x; }
	string getName() { return name; }
};

