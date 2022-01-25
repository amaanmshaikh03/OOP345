// Workshop 9 - Multi-Threading
// SecureData.h
#ifndef W9_SECUREDATA_H
#define W9_SECUREDATA_H
// Name: Mohammedamaan Shaikh
// Seneca Student ID: 157304197
// Seneca email: mishaikh3@myseneca.ca
// Date of completion: 31th July
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me or my prof.
#include <iostream>

namespace w9
{
	class Cryptor {
	public:
		char operator()(char in, char key) const { return in ^ key; }
	};
	void converter(char*, char, int, const Cryptor&);

	class SecureData {
		char* text;
		std::ostream* ofs;
		int nbytes;
		bool encoded;
		void code(char);
	public:
		SecureData(const char*, char, std::ostream*);
		SecureData(const SecureData&) = delete;
		SecureData& operator=(const SecureData&) = delete;
		~SecureData();
		void display(std::ostream&) const;
		void backup(const char*);
		void restore(const char*, char);
	};
	std::ostream& operator<<(std::ostream&, const SecureData&);
}
#endif