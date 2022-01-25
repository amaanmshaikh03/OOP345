/*
Name: Mohammedamaan Shaikh
Student ID: 15730197
Email: mishaikh3@myseneca.ca
OOP345 NCC WS6
*/
#include <sstream>
#include <iostream>
#include <string>
#include "Utilities.h"
using namespace std;
namespace sdds {
	Vehicle* createInstance(istream& is) {
		Vehicle* newVehicle = nullptr;
		char readChar = '\0';
		do {
			is.get(readChar);
		} while (readChar == ' ' && is);
		char comma = '\0';
		do{
			is.get(comma);
		} while (comma != ',' && is);
		string line;
		if (getline(is, line)){
			stringstream ss(line);
			switch (readChar){
			case 'C':
			case 'c':
				newVehicle = new Car(ss);
				break;
			case 'R':
			case 'r':
				newVehicle = new Racecar(ss);
				break;
			default:
				throw readChar;
			}
		}
		return newVehicle;
	}
}