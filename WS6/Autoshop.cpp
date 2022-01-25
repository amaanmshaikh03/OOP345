/*
Name: Mohammedamaan Shaikh
Student ID: 15730197
Email: mishaikh3@myseneca.ca
OOP345 NCC WS6
*/
#include "Autoshop.h"
#include "Car.h"
using namespace std;
namespace sdds { 
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle) { 
		m_vehicles.push_back(theVehicle);
		return *this;
	}
	void Autoshop::display(ostream& out) const { 
		out << "--------------------------------\n";
		out << "| Cars in the autoshop!        |\n";
		out << "--------------------------------\n";
		vector<Vehicle*>::iterator i;
		for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
			(*i)->display(out);
			out << std::endl; 
		}
		out << "--------------------------------\n"; 
	}
	Autoshop::~Autoshop() { 
		vector<Vehicle*>::iterator i;
		for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++) { 
			delete* i; 
		}
	}
}