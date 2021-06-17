#pragma once
#include <iostream>
#include <string>

using namespace std;

#define LOG(x) cout << x << " "
#define lineEnd() cout << endl


class Admin
{
	string name;
	string username;
	string password;
public:
	Admin() :name(""), username(""), password("") {}


};

