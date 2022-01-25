/*
Name: Mohammedamaan Shaikh
Student ID: 15730197
Email: mishaikh3@myseneca.ca
OOP345 NCC WS6
*/
#include "Car.h"
using namespace std;
namespace sdds {
	Car::Car(){
	}
	Car::Car(istream& is) {
        string line;
        getline(is, line, ',');
        carmaker = line.substr(0, line.find(','));
        cleaning(carmaker);
        getline(is, line, ',');
        cleaning(line);
        char condition = line.substr(0, line.find(','))[0];
        switch (condition){
        case '\0':
        case 'N':
        case 'n':
            carcondition = Condition::NEW;
            break;
        case 'B':
        case 'b':
            carcondition = Condition::BROKEN;
            break;
        case 'U':
        case 'u':
            carcondition = Condition::USED;
            break;
        default:
            throw "Invalid record!";
        }
        getline(is, line, ',');
        try{
            cartopspeed = stod(line);
        }
        catch (invalid_argument& error){
            throw "Invalid record!";
        }
    }
    std::string Car::condition() const    {
        return carcondition == Condition::NEW ?
            "new" : carcondition == Condition::BROKEN ?
            "broken" : "used";
    }
	double Car::topSpeed() const {
		return cartopspeed;
	}
	void Car::display(std::ostream& out) const {
		out << "| ";
		out << right << setw(10) << carmaker << " | ";
		out << left << setw(6) << condition() << " | ";
		out << setw(6) << fixed << setprecision(2) << topSpeed() << " |";
	}
    void Car::cleaning(std::string& word){
        while (word[0] == ' ') {
            word.erase(0, 1);
        }
        if (word.size() >= 1){
            while (word[word.size() - 1] == ' ') {
                word.erase(word.size() - 1, 1);
            }
        }
    }
}
