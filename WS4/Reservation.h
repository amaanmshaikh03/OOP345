/*
Name: Mohammedamaan Shaikh
ID: 157304197
email: mishaikh3@myseneca.ca
OOP345 WS4 Prof Hong
*/

#pragma once
#include <iostream>
using namespace std;
namespace sdds {
	class Reservation {
		string reserveID;
		string reserveName;
		string email;
		int noofp;
		int day;
		int hour;
	public:
		Reservation();
		Reservation(const string& res);
		friend ostream& operator<<(ostream& os, const Reservation& res);
	};
}
