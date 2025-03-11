/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.h
Version 1.0
Author: Gustavo Balardin Chiari
Revision History: v1
-----------------------------------------------------------
Date        Reason
2024/03/10  Submit the MS1
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
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

