/*
Name: Mohammedamaan Shaikh
Student ID: 157304197
Email: mishaikh3@myseneca.ca
OOP345NCC WS5
*/
#include <iostream>
#include <string>
#include "Movie.h"
using namespace std;
namespace sdds {
	const string& Movie::title() const {
		return titl;
	}
	Movie::Movie() {

	}
	Movie::Movie(const string& strMovie) {
		if (!strMovie.empty()) {
			string line = strMovie;
			titl = line.substr(0, line.find(','));
			line.erase(0, line.find(',') + 1);
			titl.erase(0, titl.find_first_not_of(' '));
			titl.erase(titl.find_last_not_of(' ') + 1);

			yea = stoi(line.substr(0, line.find(',')));
			line.erase(0, line.find(',') + 1);
			
			desc = line.substr(0, line.find('\n'));
			desc.erase(0, desc.find_first_not_of(' '));
			desc.erase(desc.find_last_not_of(' ') + 1);
		}
		else {
			*this = Movie();
		}
	}

	ostream& operator<<(ostream& os, const Movie& src) {
		os.width(40);
		os << right << src.titl << " | ";
		os.width(4);
		os << src.yea << " | ";
		os << left << src.desc << endl;
		return os;
	}
}
