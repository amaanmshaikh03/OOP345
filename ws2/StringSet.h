/*
Name: Mohammedamaan Shaikh
Student ID: 157304197
OOP345 WS2
*/
#pragma once
#include <iostream>
#include <string>
using namespace std;
namespace sdds {
	class StringSet {
		string* string_name = nullptr;
		size_t count = 0;
	public:
		StringSet();
		StringSet(const char* file_name);
		StringSet(StringSet& ss);
		StringSet(StringSet&& ss);
		StringSet& operator=(const StringSet& ss);
		StringSet& operator=(StringSet&& ss);
		~StringSet();
		size_t size();
		string operator[](size_t index) const;
	};
}