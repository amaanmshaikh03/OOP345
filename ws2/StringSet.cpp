/*
Name: Mohammedamaan Shaikh
Student ID: 157304197
OOP345 WS2
*/
#include <iostream>
#include "StringSet.h"
#include <fstream>
using namespace std;
namespace sdds{
	StringSet::StringSet() {
		string_name = nullptr;
		count = 0;
	}
	StringSet::StringSet(const char* file_name) {
		ifstream fin;
		string l;
		string m;
		fin.open(file_name);
		if (fin.is_open()) {
			while (getline(fin, l, ' ')) {
				++count;
			}
			fin.clear();
			fin.seekg(0, ios::beg);
			delete[] string_name;
			string_name = nullptr;
			string_name = new string[count];
			for (size_t i = 0; i < count && fin; i++) {
				getline(fin, m, ' ');
				string_name[i] = m;
			}
		}
		fin.close();
	}
	StringSet::StringSet(StringSet& ss) {
		operator = (ss);
	}
	StringSet& StringSet::operator=(const StringSet& ss) {
		if (this != &ss) {
			count = ss.count;
			delete[] string_name;
			string_name = nullptr;
			string_name = new string[count];
			for (size_t i = 0;i < count;i++) {
				string_name[i] = ss.string_name[i];
			}
		}
		return *this;
	}
	StringSet::StringSet(StringSet&& ss) {
		*this = move(ss);
	}
	StringSet& StringSet::operator=(StringSet&& ss){
		if (this != &ss) {
			count = ss.count;
			ss.count = 0;
			delete[] string_name;
			string_name = ss.string_name;
			ss.string_name = nullptr;
		}
		return *this;
	}
	StringSet::~StringSet() {
		delete[] string_name;
		string_name = nullptr;
	}
	size_t StringSet::size() {
		return count;
	}
	string StringSet::operator[](size_t index) const {
		string l;
		if (string_name != nullptr && index < count) {
			l = string_name[index];
		}
		return l;
	}
}