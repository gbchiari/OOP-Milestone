/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
Version 1.0
Author: Gustavo Balardin Chiari
Revision History: v1
-----------------------------------------------------------
Date        Reason
2025/03/11  Added helper pointer to skip leading spaces
-----------------------------------------------------------
I have done all the coding by myself
*
EXCEPT FOR:
*
The idea of using a helper pointer to traverse and skip leading spaces
was referenced from OpenAI's ChatGPT (2024).
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include "Utils.h"
#include <cstring>
#include <iostream>
#include <iomanip> //To setw(2) work properly

namespace seneca {

	MenuItem::MenuItem(const char* content, unsigned int indentNumber, unsigned int indentSize, int rowNumber) {
		/*
		Validations:
		(The content is nullptr, empty, or consists only of whitespace characters)
		(Any of the indentation or indentation size values exceed 4)
		(The row value is greater than MaximumNumberOfMenuItems)
		*/
		if (!content || content[0] == '\0' || indentNumber > 4 || indentSize > 4 || (rowNumber >= 0 && (unsigned int)rowNumber > MaximumNumberOfMenuItems)){
			//Safe empty state
			m_content = nullptr;
			m_indentNumber = 0;
			m_indentSize = 0;
			m_rowNumber = -1; //Not print if it is invalid
		}
		else {
			m_content = new char[strlen(content) +1]; //+1 for the '\0'
			strcpy(m_content, content); //Copy m_content into content
			m_indentNumber = indentNumber;
			m_indentSize = indentSize;
			m_rowNumber = rowNumber;
		}
	}

	MenuItem::~MenuItem() {
		delete[] m_content; //Kills the memory
		m_content = nullptr;
	}

	MenuItem::operator bool() const{
		//If a MenuItem is cast to a bool, it should return false if it is in a safe empty state and true if it is a valid MenuItem.
		return m_content != nullptr;
	}

	std::ostream& MenuItem::display(std::ostream& ostr) const{
		if(m_content){ //If MenuItem is valid
			//Display the content with proper indentation based on the indentation number and the indentation size.
			for (unsigned int i = 0; i < m_indentNumber * m_indentSize; i++) {
					ostr << ' ';
			}
			//Include the row number formatted as a two-character-wide value followed by "- " if row is non-negative.
			if(m_rowNumber >= 0){
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

		}else { //If MenuItem is not valid
			ostr << "??????????";
		}

		return ostr;
	}
};