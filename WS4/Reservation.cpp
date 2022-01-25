/*
Name: Mohammedamaan Shaikh
ID: 157304197
email: mishaikh3@myseneca.ca
OOP345 WS4 Prof Hong
*/

#include <iostream>
#include <string>
#include "Reservation.h"
using namespace std;
namespace sdds {
	Reservation::Reservation() {
		reserveID = "";
		reserveName = "";
		email = "";
		day = 0;
		hour = 0;
		noofp = 0;
	}
	Reservation::Reservation(const string& res) {
		string s = res;
		reserveID = s.substr(0, s.find(':'));
		s.erase(0, s.find(':') + 1);
		reserveName = s.substr(0, s.find(','));
		s.erase(0, s.find(',') + 1);
		email = s.substr(0, s.find(','));
		s.erase(0, s.find(',') + 1);
		noofp = stoi(s.substr(0, s.find(',')));
		s.erase(0, s.find(',') + 1);
		day = stoi(s.substr(0, s.find(',')));
		s.erase(0, s.find(',') + 1);
		hour = stoi(s.substr(0, s.find(',')));

		reserveID.erase(reserveID.find_last_not_of(' ') + 1);
		reserveID.erase(0, reserveID.find_first_not_of(' '));
		reserveName.erase(reserveName.find_last_not_of(' ') + 1);
		reserveName.erase(0, reserveName.find_first_not_of(' '));
		email.erase(email.find_last_not_of(' ') + 1);
		email.erase(0, email.find_first_not_of(' '));
	}
	ostream& operator<<(ostream& os, const Reservation& res){
		os << "Reservation ";
		os.width(10);
		os << right << res.reserveID << ":";
		os << " ";
		os.width(20);
		os << right << res.reserveName;
		os << "  ";
		os << "<";
		string a = res.email;
		a += ">";
		os.width(20);
		os << left << a << "   ";
		if (res.hour <= 9 && res.hour >= 6) {
			os << "Breakfast";
		}
		else if (res.hour <= 15 && res.hour >= 11) {
			os << "Lunch";
		}
		else if (res.hour <= 21 && res.hour >= 17) {
			os << "Dinner";
		}
		else {
			os << "Drinks";
		}
		os << " on day " << res.day << " @ " << res.hour << ":00 for " << res.noofp;
		if (res.noofp == 1) {
			os << " person.";
		}
		else {
			os << " people.";
		}
		os << endl;
		return os;
	}
}