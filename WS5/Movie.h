/*
Name: Mohammedamaan Shaikh
Student ID: 157304197
Email: mishaikh3@myseneca.ca
OOP345NCC WS5
*/

#pragma once
#include <string>
#include "SpellChecker.h"
using namespace std;
namespace sdds {
	class Movie {
		string titl{};
		size_t yea{};
		string desc{};
	public:
		Movie();
		const string& title() const;
		Movie(const string& strMovie);
		template <typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(titl);
			spellChecker(desc);
		}
		friend ostream& operator<<(ostream& os, const Movie& src);
	};
}