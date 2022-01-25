/*
Name: Mohammedamaan Shaikh
Student ID: 157304197
Email: mishaikh3@myseneca.ca
OOP345 WS 3
*/
#pragma once
#include <iostream>
using namespace std;
namespace sdds{
	template<typename V, typename K>
	class Pair{
		K ke;
		V val;
	public:
		Pair() {};
		Pair(const K& key, const V& value) {
			ke = key;
			val = value;
		}
		const V& value() const {
			return val;
		}
		const K& key() const {
			return ke;
		}
		virtual void display(std::ostream& os) const{
			os << key() << " : " << val << std::endl;
		}
	};

	template<typename V, typename K>
	std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair){
		pair.display(os);
		return os;
	}

}
