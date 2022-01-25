/*
Name: Mohammedamaan Shaikh
Student ID: 157304197
Email: mishaikh3@myseneca.ca
OOP345 WS 3
*/
#pragma once
#include <iostream>
using namespace std;
namespace sdds{
	template <size_t s, typename T>
	class Set {
		static size_t current;
		T arr[s];
	public:
		size_t size() const {
			return current;
		}
		const T& get(size_t idx) const {
			return arr[idx];
		}
		void operator+=(const T& item) {
			if (current < s) {
				arr[current] = item;
				current++;
			}
		}
	};
	template <size_t s, typename T>
	size_t Set<s, T>::current = 0;
}