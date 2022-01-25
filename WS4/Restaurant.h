/*
Name: Mohammedamaan Shaikh
ID: 157304197
email: mishaikh3@myseneca.ca
OOP345 WS4 Prof Hong
*/

#pragma once
#include "Reservation.h"
using namespace std;
namespace sdds {
	
	class Restaurant {
		Reservation* reserves{ nullptr };
		size_t resno{ 0u };
	public:
		Restaurant();
		Restaurant(const Reservation* reservations[], size_t cnt);
		~Restaurant();
		Restaurant(const Restaurant& src);
		Restaurant& operator=(const Restaurant& src);
		Restaurant(Restaurant&& src);
		Restaurant& operator=(Restaurant&& src);
		size_t size() const;
		friend ostream& operator<<(ostream& os, const Restaurant& res);
	};
}