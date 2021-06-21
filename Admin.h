#pragma once
#include <iostream>
#include <string>
#include "city.h"
using namespace std;

#define LOG(x) cout << x << " "
#define lineEnd() cout << endl


class Admin : public city
{
	string name;
	string username;
	string password;
public:
	Admin() :name(""), username(""), password("") {}
	void AdminGenerateData(Admin*);
	bool AdminVerification(Admin*, string Username, string Password);
};

