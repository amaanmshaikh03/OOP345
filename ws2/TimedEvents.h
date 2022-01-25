/*
Name: Mohammedamaan Shaikh
Student ID: 157304197
OOP345 WS2
*/
#pragma once
#include <iostream>
#include <chrono>
using namespace std;
namespace sdds {
	
	class TimedEvents {
		int initial = 0;
		chrono::time_point<chrono::steady_clock> start_time;
		chrono::time_point<chrono::steady_clock> end_time;
		struct Event {
			string event_name;
			string units;
			chrono::duration<double, nano> event_duration;
		} arr[10];
	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void addEvent(const char* evname);
		friend ostream& operator<<(ostream& os, const TimedEvents& te);
	};

}