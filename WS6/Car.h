/*
Name: Mohammedamaan Shaikh
Student ID: 15730197
Email: mishaikh3@myseneca.ca
OOP345 NCC WS6
*/
#pragma once
#include <vector>
#include<cstring>
using namespace std;
#include <exception>
#include<iomanip>
#include "Vehicle.h"
namespace sdds {
	class Car :public Vehicle {
		enum class Condition{
			NEW,
			USED,
			BROKEN
		};
		string carmaker{};
		Condition carcondition{};
		double cartopspeed{};
		void cleaning(string& word);
	public:
		Car();
		Car(istream& is);
		string condition() const;
		double topSpeed() const;
		void display(ostream& out) const;
	};
}