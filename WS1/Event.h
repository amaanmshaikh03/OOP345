#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>
extern unsigned int g_sysClock;
namespace sdds {
	class Event {
		char* descrip;
		unsigned int evst;
	public:
		Event();
		Event(const Event& a);
		Event& operator=(const Event& A);
		~Event();
		void display();
		void set(char* arr = nullptr);
	};
}
#endif