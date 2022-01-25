/*
Name: Mohammedamaan Shaikh
Student ID: 157304197
Email: mishaikh3@myseneca.ca
OOP345 WS 3
*/


#pragma once
#include <iostream>
#include <cstring>
#include "Pair.h"
using namespace std;
namespace sdds {
	template<class V, class K>
	class PairSummable : public Pair<V, K> {
		static V initial;
		static size_t minch;
	public:
		PairSummable() {}
		PairSummable(const K& key, const V& value = initial) : Pair<V, K>(key, value) {
			if (key.size() > minch) {
				minch = key.size();
			}
		}
		bool isCompatibleWith(const PairSummable<V, K>& b) const {
			bool ok = false;
			if (this->key() == b.key()) {
				ok = true;
			}
			return ok;
		}
		PairSummable& operator+=(const PairSummable<V, K>& ps) {
			if (this->key() == ps.key()) {
				PairSummable nsp(this->key(), this->value() + ps.value());
				*this = nsp;
			}
			return *this;
		}
		void display(ostream& os) const {
            os.width(minch);
            os << left;
            Pair<V, K>::display(os);
            os.width(0);
            os << right;
        }
		
	};
	template<> 
	string PairSummable<string, string>::initial = "";
	
	template<> 
	int PairSummable<int, string>::initial = 0;

	template<typename V, typename K>
	size_t PairSummable<V, K>::minch = 0;
	
	template<>
	PairSummable<string, string>& PairSummable<string, string>::operator+=(const PairSummable& ps) {
		if (this->key() == ps.key()) {
			std::string delimiter = "";
			if (this->value() != ""){
				delimiter = ", ";
			}
			PairSummable obj(this->key(), this->value() + delimiter + ps.value());
			*this = obj;
		}
		return *this;
	}
}