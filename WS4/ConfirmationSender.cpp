/*
Name: Mohammedamaan Shaikh
ID: 157304197
email: mishaikh3@myseneca.ca
OOP345 WS4 Prof Hong
*/
#include <iostream>
#include "ConfirmationSender.h"
using namespace std;
namespace sdds {
	ConfirmationSender::ConfirmationSender() {
		
	}
	ConfirmationSender::~ConfirmationSender() {
		delete[] reser;
		reser = nullptr;
		delete[] re;
		re = nullptr;
	}
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		bool ok = false;
		for (size_t i = 0; i < reserveno; i++) {
			if(ok == false){
				if (reser[i] == &res) {
					ok = true;
				}
			}
		}
		if (ok == false) {
			
			re = new const Reservation*[reserveno + 1];
			for (size_t i = 0; i < reserveno; i++) {
				re[i] = reser[i];
			}
			delete[] reser;
			re[reserveno] = &res;
			reserveno++;
			reser = move(re);
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		for (size_t i = 0; i < reserveno; i++) {
			if (reser[i] == &res) {
				reser[i] = nullptr;
				reserveno--;
			}
		}
		return *this;
	}
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& src) {
		*this = src;
	}
	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src) {
		if (this != &src){
			reserveno = src.reserveno;
			if (src.reser != nullptr){
				reser = new const Reservation* [reserveno];
				for (size_t i = 0; i < reserveno; i++){
					reser[i] = src.reser[i];
				}
			}
			else{
				reser = nullptr;
			}
		}
		return *this;
	}
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src) {
		*this = move(src);
	}
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src) {
		if (src.reser != nullptr) {
			swap(reser, src.reser);
			reserveno = src.reserveno;
			src.reserveno = 0;
			src.reser = nullptr;
		}
		return *this;
	}
	ostream& operator<<(ostream& os, const ConfirmationSender& cs){
		os << "--------------------------\n";
		os << "Confirmations to Send\n";
		os << "--------------------------\n";
		if (cs.reserveno == 0){
			os << "There are no confirmations to send!\n";
		}
		else{
			for (size_t i = 0; i < cs.reserveno; i++){
				if (cs.reser[i] != nullptr){
					os << *cs.reser[i];
				}
			}
		}
		os << "--------------------------\n";
		return os;
	}
}