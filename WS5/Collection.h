/*
Name: Mohammedamaan Shaikh
Student ID: 157304197
Email: mishaikh3@myseneca.ca
OOP345NCC WS5
*/
#pragma once
#include <iostream>
#include <string>
using namespace std;
namespace sdds {
	template <typename T>
	class Collection {
		string nam;
		T* ite{};
		size_t cnt{};
		void (*observe)(const Collection<T>&, const T&) { nullptr };
	public:
		Collection(const string& name) {
			nam = name;
			ite = nullptr;
			cnt = 0;
			observe = nullptr;
		}

		~Collection() {
			delete[] ite;
			ite = nullptr;
		}

		Collection(Collection&) = delete;

		Collection& operator=(Collection&) = delete;

		const string& name() const {
			return nam;
		}

		size_t size() const {
			return cnt;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			observe = observer;
		}

		Collection<T>& operator+=(const T& item) {
			bool ok = false;

			for (size_t i = 0; i < cnt; ++i) {
				if (ite[i].title() == item.title()) {
					ok = true;
				}
			}
			if (!ok) {
				if (cnt == 0) {
					cnt++;
					ite = new T[cnt];
					ite[0] = item;
				}
				else {
					T* temp = new T[cnt];
					for (size_t i = 0; i < cnt; ++i) {
						temp[i] = ite[i];
					}
					delete[] ite;
					cnt++;
					ite = new T[cnt];
					for (size_t j = 0; j < cnt - 1; ++j) {
						ite[j] = temp[j];
					}
					delete[] temp;
					ite[cnt - 1] = item;
					if (observe != nullptr) {
						observe(*this, item);
					}
				}
			}
			return *this;
		}

		T& operator[](size_t idx) const {
			if (idx >= cnt || idx < 0) {
				string exception = { "Bad index [" + to_string(idx) + "]. " + "Collection has [" + to_string(cnt) + "] items." };
				throw out_of_range(exception);
			}
			else {
				return ite[idx];
			}
		}

		T* operator[](string title) const {
			int index = -1;
			T* retval;
			for (size_t i = 0; i < cnt; i++) {
				if (ite[i].title() == title) {
					index = i;
				}
			}
			if (index == -1) {
				retval = nullptr;
			}
			else {
				retval = &ite[index];
			}
			return retval;
		}
		friend ostream& operator<<(ostream& os, Collection& src) {
			for (size_t i = 0; i < src.size(); ++i) {
				os << src.ite[i];
			}
			return os;
		}
	};
}
