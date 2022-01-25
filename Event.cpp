#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Event.h"
using namespace std;
unsigned int g_sysClock = 0;
namespace sdds {
	Event::Event() {
		descrip[0] = '\0';
		evst = 0;
	}
	Event::Event(const Event& a) {
		operator = (a);
	}
	Event& Event::operator=(const Event& a) {
		if (this != &a) {
			if (a.descrip != nullptr && a.descrip[0] != '\0') {
				descrip = new char[strlen(a.descrip) + 1];
				strcpy(descrip, a.descrip);
				evst = a.evst;
			}
		}
		return *this;
	}
	Event::~Event() {
		delete[] descrip;
	}
	void Event::display() {
		static int counter = 1;
		if (descrip[0] != '\0') {
			unsigned int h{ 0 };
			unsigned int m{ 0 };
			unsigned int s{ g_sysClock };
			while(s >= 3600){
				s -= 3600;
				h++;
			}
			while (s >= 60) {
				s = s - 60;
				m++;
			}
			cout.fill(0);
			cout.width(2);
			cout << counter << ". ";
			cout.width(2);
			cout << h << ":";
			cout.width(2);
			cout << m << ":";
			cout.width(2);
			cout << s << " => " << descrip << endl;
		}
		else {
			cout.width(2);
			cout << counter << ". | No Event |" << endl;
		}
		counter++;
	}

	void Event::set(char* arr) {
		if (arr[0] != '\0') {
			descrip = new char[strlen(arr) + 1];
			strcpy(descrip, arr);
			evst = g_sysClock;
		}
		else {
			descrip[0] = '\0';
		}
	}
}