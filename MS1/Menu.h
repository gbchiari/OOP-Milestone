/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: constants.h
Version 1.0
Author: Gustavo Balardin Chiari
Revision History: v2
-----------------------------------------------------------
Date        Reason
2025/23/23  Updating the Citation and Sources
-----------------------------------------------------------
I have done all the coding by myself
*
EXCEPT FOR:
*
The Utils.h and Utils.cpp because the Professor Fardad Soleimanloo gave the students.
-----------------------------------------------------------
*/
#ifndef SENECA_MENU_H
#define SENECA_MENU_H
#include "constants.h"
#include <iostream>

namespace seneca {
	class MenuItem {
		char* m_content;
		unsigned int m_indentNumber;
		unsigned int m_indentSize;
		int m_rowNumber;
	public:
		//Construction
		MenuItem(const char* content, unsigned int indentNumber, unsigned int indentSize, int rowNumber);
		//Destructor
		~MenuItem();
		//Rule of three
		MenuItem(const MenuItem&) = delete; //Not copyable
		MenuItem& operator=(const MenuItem&) = delete; //Not assignable
		//Bool Type Conversion Overload
		operator bool() const;
		//Display with standard value
		std::ostream& display(std::ostream& ostr = std::cout) const;
	};
}
#endif // !SENECA_MENU_H

