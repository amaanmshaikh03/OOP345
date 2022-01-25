/*
Name: Mohammedamaan Shaikh
Student ID: 157304197
Email: mishaikh3@myseneca.ca
OOP345NCC WS5
*/
#include <iostream>
#include "Book.h"
using namespace std;
namespace sdds {
	Book::Book() {
	}
	const string& Book::title() const {
		return tit;
	}

	const string& Book::country() const {
		return coun;
	}

	const size_t& Book::year() const {
		return yea;
	}

	double& Book::price() {
		return pri;
	}

	Book::Book(const string& strBook) {
		string line = strBook;
		aut = line.substr(0, line.find(','));
		line.erase(0, line.find(',') + 1);
		aut.erase(0, aut.find_first_not_of(' '));
		aut.erase(aut.find_last_not_of(' ') + 1);

		tit = line.substr(0, line.find(','));
		line.erase(0, line.find(',') + 1);
		tit.erase(0, tit.find_first_not_of(' '));
		tit.erase(tit.find_last_not_of(' ') + 1);

		coun = line.substr(0, line.find(','));
		line.erase(0, line.find(',') + 1);
		coun.erase(0, coun.find_first_not_of(' '));
		coun.erase(coun.find_last_not_of(' ') + 1);

		pri = stod(line.substr(0, line.find(',')));
		line.erase(0, line.find(',') + 1);

		yea = stoi(line.substr(0, line.find(',')));
		line.erase(0, line.find(',') + 1);

		des = line.substr(0, line.find('\n'));
		des.erase(0, des.find_first_not_of(' '));
		des.erase(des.find_last_not_of(' ') + 1);
	}

	ostream& operator<<(ostream& os, Book& src) {
		os << right;
		os.width(20);
		os << src.aut << " | ";
		os.width(22);
		os << src.title() << " | ";
		os.width(5);
		os << src.country() << " | ";
		os.width(4);
		os << src.year() << " | ";
		os.width(6);
		os << fixed;
		os.precision(2);
		os << src.price() << " | ";
		os << left << src.des << endl;
		return os;
	}
}