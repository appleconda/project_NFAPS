#define _NO_CRT_SECURE_WARNINGS
#include <iostream> 
#include <string>
#include <vector>
#include "Passenger.h"
using namespace std;


int main()
{
	Passenger passenger;
	Passenger* passenger_ptr;

	passenger_ptr = new Passenger[100];
	passenger.generateData(passenger_ptr);
	passenger.Passenger_registration(passenger_ptr);

	delete[] passenger_ptr;

}