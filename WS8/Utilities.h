#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
// Workshop 8 - Smart Pointers
// 2019/11 - Cornel
// Name:  Mohammedamaan Shaikh
// Student Number: 157304197
// Email: mishaikh3@myseneca.ca
// Date of completion: 24th July
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me or my prof.

#include "List.h"
#include "Element.h"

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price);
	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price);
}

#endif