/*
Name: Mohammedamaan Shaikh
Student ID: 15730197
Email: mishaikh3@myseneca.ca
OOP345 NCC WS6
*/
#pragma once
#include "Car.h"
namespace sdds{
	class Racecar : public Car{
		double m_booster{0};
	public:
		explicit Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;
	};
}