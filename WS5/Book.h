/*
Name: Mohammedamaan Shaikh
Student ID: 157304197
Email: mishaikh3@myseneca.ca
OOP345NCC WS5
*/
#pragma once
#include <iostream>
#include <string>
using namespace std;
namespace sdds {
	class Book {
		string aut{};
		string tit{};
		string coun{};
		size_t yea{};
		double pri{};
		string des{};
	public:
		Book();
		const string& title() const;
		const string& country() const;
		const size_t& year() const;
		double& price();
		Book(const string& strBook);
		friend ostream& operator<<(ostream& os, Book& src);
		template <typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(des);
		}
	};
}
