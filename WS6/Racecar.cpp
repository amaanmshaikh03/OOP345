/*
Name: Mohammedamaan Shaikh
Student ID: 15730197
Email: mishaikh3@myseneca.ca
OOP345 NCC WS6
*/
#include "Racecar.h"
using namespace std;
namespace sdds{
	Racecar::Racecar(istream& in) : Car(in) {
		string booster;
		getline(in, booster, '\n');
		try{
			m_booster = stod(booster);
		}
		catch (invalid_argument& error) {
			throw "Invalid number";
		}
	}
	void Racecar::display(ostream &out) const {
		Car::display(out);
		out << "*";
	}
	double Racecar::topSpeed() const {
		return Car::topSpeed() * (1 + m_booster);
	}
}