/*
Name: Mohammedamaan Shaikh
Student ID: 157304197
Email: mishaikh3@myseneca.ca
OOP345 WS 3
*/

#pragma once
#include <iostream>
#include "Set.h"
using namespace std;
namespace sdds {
	template <size_t N, class T>
	class SetSummable : public Set<N, T> {
	public:
		T accumulate(const string& filter) const {
			T a(filter);
			for (size_t i = 0; i < this->size(); i++) {
				if (a.isCompatibleWith(this->get(i))) {
					a += this->get(i);
				}
			}
			return a;
		}
	};
}