/*
Name: Mohammedamaan Shaikh
Student ID: 157304197
OOP345 WS2
*/
#include <iostream>
#include "TimedEvents.h"
using namespace std;
namespace sdds {
	TimedEvents::TimedEvents() : start_time{}, end_time{}{
		initial = 0;
	}
	void TimedEvents::startClock() {
		start_time = chrono::steady_clock::now();
	}
	void TimedEvents::stopClock() {
		end_time = chrono::steady_clock::now();
	}
	void TimedEvents::addEvent(const char* evname) {
		if (initial < 10 and evname != nullptr) {
			arr[initial].event_name = evname;
			arr[initial].units = "nanoseconds";
			arr[initial].event_duration = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
			initial++;
		}
	}
	ostream& operator<<(ostream& os, const TimedEvents& te) {
		os << "--------------------------" << endl;
		os << "Execution Times:" << endl;
		os << "--------------------------" << endl;
		for (int i = 0; i < te.initial; i++) {
			os.width(21);
			os << left << te.arr[i].event_name;
			os.width(13);
			os << right << te.arr[i].event_duration.count();
			os << " " << te.arr[i].units << endl;
		}
		os << "--------------------------" << endl;
		return os;
	}
}