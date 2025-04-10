/***********************************************************************
// OOP244 Project, Menu Module
//
// Filename: Menu.h
// Version 5.0
// Author: Gustavo Balardin Chiari
// Description: Header file of Menu module (brain) to be used in the project
// Revision History: 5.0
//-----------------------------------------------------------
// Date        Reason
// 2025/04/10  Submiting the MS5-1
//-----------------------------------------------------------
// I have done all the coding by myself in this file.
// -----------------------------------------------------------
***********************************************************************/

#ifndef SENECA_MENU_H
#define SENECA_MENU_H
#include "constants.h"
#include <iostream>

namespace seneca {
	class Menu;
	class MenuItem {
		char* m_content;
		unsigned int m_indentNumber;
		unsigned int m_indentSize;
		int m_rowNumber;
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

		friend class Menu; //Using friend because class Menu is the owner of MenuItem
	};

	class Menu {
		unsigned int m_numberOfItem;
		unsigned int m_indentNumber;
		unsigned int m_indentSize;
		MenuItem m_title;
		MenuItem m_exitOption;
		MenuItem m_promptSelection;
		MenuItem* m_items[MaximumNumberOfMenuItems];
	public:
		Menu(const char* title, const char* exitOption = "Exit", unsigned int indentNumber = 0, unsigned int indentSize = 3);
		~Menu();
		//Rule of three
		Menu(const Menu&) = delete; //Not copyable
		Menu& operator=(const Menu&) = delete;  //Not assignable
		//Operator << Overload to add Menu Items
		Menu& operator<<(const char* menuItem);
		std::ostream& display(std::ostream& ostr = std::cout) const;
		//Select method
		size_t select() const;
	};

	//Operator << Overload for Menu (Dont modify the Menu)
	size_t operator<<(std::ostream& ostr, const Menu& menu);
};

#endif // !SENECA_MENU_H

