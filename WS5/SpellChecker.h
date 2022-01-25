/*
Name: Mohammedamaan Shaikh
Student ID: 157304197
Email: mishaikh3@myseneca.ca
OOP345NCC WS5
*/

#pragma once
#include <string>
using namespace std;
const int MAX = 6;
namespace sdds {
	class SpellChecker {
		string m_badWords[MAX];
		string m_goodWords[MAX];
		int count[MAX]{ 0 };
	public:
		SpellChecker(const char* filename);
		void operator()(string& text);
		void showStatistics(ostream& out);
	};
}