/*
Name: Mohammedamaan Shaikh
Student ID: 15730197
Email: mishaikh3@myseneca.ca
OOP345 NCC WS6
*/
#pragma once
#include <vector>
#include <list>
#include "Vehicle.h"
using namespace std;
namespace sdds {
	class Autoshop {
		vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(ostream& out) const;
		~Autoshop();
		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles);
	};

	template<typename T>
	inline void Autoshop::select(T test, std::list<const Vehicle*>& vehicles){
		vector<Vehicle*>::iterator i;
		for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
			if (test(*i)) {
				vehicles.push_back(*i);
			}
		}
	}
}