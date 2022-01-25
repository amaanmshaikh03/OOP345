/*
Name: Mohammedamaan Shaikh
ID: 157304197
email: mishaikh3@myseneca.ca
OOP345 WS4 Prof Hong
*/

#include <iostream>
#include "Restaurant.h"

using namespace std;
namespace sdds {
	Restaurant::Restaurant() {
		
	}
	Restaurant::~Restaurant() {
		delete[] reserves;
		reserves = nullptr;
	}
	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) {
		delete[] reserves;
		reserves = new Reservation[cnt];
		resno = cnt;
		for (size_t i = 0; i < cnt; i++) {
			reserves[i] = *reservations[i];
		}
	}
	Restaurant::Restaurant(const Restaurant& src) {
		*this = src;
	}
	Restaurant& Restaurant::operator=(const Restaurant& src) {
		if (this != &src) {
			resno = src.resno;
			delete[] reserves;
			reserves = nullptr;
			reserves = new Reservation[resno];
			for (size_t i = 0; i < resno; i++) {
				reserves[i] = src.reserves[i];
			}
		}
		return *this;
	}
	Restaurant::Restaurant(Restaurant&& src) {
		*this = move(src);
	}
	Restaurant& Restaurant::operator=(Restaurant&& src) {
		if (this != &src) {
			resno = src.resno;
			reserves = src.reserves;
			src.reserves = nullptr;
			src.resno = 0;
		}
		return *this;
	}
	size_t Restaurant::size() const {
		return resno;
	}
	ostream& operator<<(ostream& os, const Restaurant& res) {
		static int count = 0;
		os << "--------------------------" << endl;
		os << "Fancy Restaurant (" << count + 1 << ")" << endl;
		os << "--------------------------" << endl;
		if (res.resno == 0) {
			os << "This restaurant is empty!" << endl;
		}
		else {
			for (size_t i = 0; i < res.resno; i++) {
				os << res.reserves[i];
			}
		}
		os << "--------------------------" << endl;
		count++;
		return os;
	}
}