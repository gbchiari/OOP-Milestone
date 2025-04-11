/***********************************************************************
// OOP244 Project, Menu Module
//
// Filename: Menu.h
// Version 5.0
// Author: Gustavo Balardin Chiari
// Description: .cpp file of Menu module (brain) to be used in the project
// Revision History: 5.0
//-----------------------------------------------------------
// Date        Reason
// 2025/04/10  Submiting the MS5-4
//-----------------------------------------------------------
// I have done all the coding by myself in this file.
// -----------------------------------------------------------
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include "Utils.h"
#include <iostream>
#include <iomanip> //To setw() work good

namespace seneca {
	/////////////////////////////////MS2////////////////////////////////////////

	//Construtor (Menu Class)
	Menu::Menu(const char* title, const char* exitOption, unsigned int indentNumber, unsigned int indentSize) :
		m_numberOfItem(0),
		m_indentNumber(indentNumber),
		m_indentSize(indentSize),
		m_title(title, indentNumber, indentSize, -1),
		m_exitOption(exitOption, indentNumber, indentSize, 0),
		m_promptSelection("> ", indentNumber, indentSize, -1) {
		//Initialize the array as nullptr
		for (unsigned int i = 0; i < MaximumNumberOfMenuItems; i++) {
			m_items[i] = nullptr;
		}
	}
	//Destrutor (Menu Class)
	Menu::~Menu() {
		for (unsigned int i = 0; i < m_numberOfItem; i++) {
			delete m_items[i];
		}
	}
	//Operator `<<` to add Menu Items
	Menu& Menu::operator<<(const char* menuItem) {
		if (m_numberOfItem < MaximumNumberOfMenuItems) {
			m_items[m_numberOfItem] = new MenuItem(menuItem, m_indentNumber, m_indentSize, m_numberOfItem + 1);
			m_numberOfItem++;
		}
		return *this;
	}
	//Display (ms2) (Menu Class)
	std::ostream& Menu::display(std::ostream& ostr) const {
		if (m_title) {
			m_title.display(ostr);
			ostr << std::endl;
		}
		for (unsigned int i = 0; i < m_numberOfItem; i++) {
			(*m_items[i]).display(ostr);
			ostr << std::endl;
		}
		m_exitOption.display(ostr);
		return ostr;
	}
	//Select method (Menu Class)
	size_t Menu::select() const {
		display();
		std::cout << std::endl;
		m_promptSelection.display();
		return ut.getInt(0, m_numberOfItem);
	}
	//Operator `<<` to show Menu no couit
	size_t operator<<(std::ostream& ostr, const Menu& menu) {
		if (&ostr == &std::cout) {
			return menu.select();
		}
		return 0;
	}

	/////////////////////////////////MS1////////////////////////////////////////


	MenuItem::MenuItem(const char* content, unsigned int indentNumber, unsigned int indentSize, int rowNumber) {
		/*
		Validations:
		(The content is nullptr, empty, or consists only of whitespace characters)
		(Any of the indentation or indentation size values exceed 4)
		(The row value is greater than MaximumNumberOfMenuItems)
		*/
		if (!content || content[0] == '\0' || indentNumber > 4 || indentSize > 4 || (rowNumber >= 0 && (unsigned int)rowNumber > MaximumNumberOfMenuItems)) {
			//Safe empty state
			m_content = nullptr;
			m_indentNumber = 0;
			m_indentSize = 0;
			m_rowNumber = -1; //Not print if it is invalid
		}
		else {
			m_content = new char[ut.strlen(content) + 1]; //+1 for the '\0'
			ut.strcpy(m_content, content); //Copy m_content into content
			m_indentNumber = indentNumber;
			m_indentSize = indentSize;
			m_rowNumber = rowNumber;
		}
	}

	MenuItem::~MenuItem() {
		delete[] m_content; //Kills the memory
		m_content = nullptr;
	}

	MenuItem::operator bool() const {
		//If a MenuItem is cast to a bool, it should return false if it is in a safe empty state and true if it is a valid MenuItem.
		return m_content != nullptr;
	}

	//Display (ms1) (MenuItem Class)
	std::ostream& MenuItem::display(std::ostream& ostr) const {
		if (m_content) { //If MenuItem is valid
			//Display the content with proper indentation based on the indentation number and the indentation size.
			for (unsigned int i = 0; i < m_indentNumber * m_indentSize; i++) {
				ostr << ' ';
			}
			//Include the row number formatted as a two-character-wide value followed by "- " if row is non-negative.
			if (m_rowNumber >= 0) {
				//Using setw(2) to help format as a two-character-wide
				ostr << std::setw(2) << m_rowNumber << "- ";
			}

			//Creating a helper pointer that advances while ut.isspace() is true
			//The helper pointer was referenced from OpenAI's ChatGPT (2024).
			const char* ptr = m_content;
			while (*ptr && ut.isspace(*ptr)) {
				ptr++;
			}

			ostr << ptr; //Display the helper pointer (string inside) without spaces

		}
		else { //If MenuItem is not valid
			ostr << "??????????";
		}

		return ostr;
	}
};