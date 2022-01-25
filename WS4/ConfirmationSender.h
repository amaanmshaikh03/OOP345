/*
Name: Mohammedamaan Shaikh
ID: 157304197
email: mishaikh3@myseneca.ca
OOP345 WS4 Prof Hong
*/

#pragma once
#include <iostream>
#include "Reservation.h"
using namespace std;
namespace sdds {
	class ConfirmationSender {
		const Reservation** reser{ nullptr };
		const Reservation** re{ nullptr };
		size_t reserveno{ 0u };
	public:
		ConfirmationSender();
		~ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& src);
		ConfirmationSender& operator=(const ConfirmationSender& src);
		ConfirmationSender(ConfirmationSender&& src);
		ConfirmationSender& operator=(ConfirmationSender&& src);
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend ostream& operator<<(ostream&, const ConfirmationSender& cs);
	};
}