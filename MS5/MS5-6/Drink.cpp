/***********************************************************************
// OOP244 Project, Drink Module
//
// Filename: Drink.cpp
// Version 5.0
// Author: Gustavo Balardin Chiari
// Description: .cpp file of Drink module (available drinks on the menu) to be used in the project
// Revision History: 5.0
//-----------------------------------------------------------
// Date        Reason
// 2025/04/10  Submiting the MS5-6
//-----------------------------------------------------------
// I have done all the coding by myself
// *
// EXCEPT FOR:
// *
// The read function who I looked up in the teacher's notes from the class, I didn't copy everything, just the structure.
// -----------------------------------------------------------
***********************************************************************/

#include "Drink.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>
#include <cstring>
namespace seneca {
    /////////////////////////////////MS3////////////////////////////////////////
    //Inheritance Drink class with Billable class
    Drink::Drink() : Billable() { m_size = '\0'; }
    Drink::Drink(const Drink& src) : Billable(src) {
        m_size = src.m_size;
    }
    Drink& Drink::operator=(const Drink& src) {
        if (this != &src) {
            Billable::operator=(src);
            m_size = src.m_size;
        }
        return *this;
    }
    std::ostream& Drink::print(std::ostream& os) const {
        os << std::left << std::setw(28) << std::setfill('.') << (m_name ? m_name : "")
            << std::right << std::setfill(' ');

        if (m_size == 'S') os << "SML..";
        else if (m_size == 'M') os << "MID..";
        else if (m_size == 'L') os << "LRG..";
        else if (m_size == 'X') os << "XLR..";
        else os << ".....";

        os << std::setw(7) << std::fixed << std::setprecision(2) << price();
        return os;
    }
    //Order method
    bool Drink::order() {
        std::cout << "         Drink Size Selection\n"
            "          1- Small\n"
            "          2- Medium\n"
            "          3- Larg\n"
            "          4- Extra Large\n"
            "          0- Back\n"
            "         > ";
        int sel = ut.getInt(0, 4);
        switch (sel) {
        case 1: m_size = 'S'; return true;
        case 2: m_size = 'M'; return true;
        case 3: m_size = 'L'; return true;
        case 4: m_size = 'X'; return true;
        case 0: m_size = '\0'; return false;
        }
        return false;
    }
    bool Drink::ordered() const {
        return m_size != '\0';
    }
    //Read method
    //The read function who I looked up in the teacher's notes from the class, I didn't copy everything, just the structure.
    std::ifstream& Drink::read(std::ifstream& file) {
        char line[256]{};
        if (file.getline(line, 256)) {
            char namePart[200]{}, pricePart[50]{};
            ut.charsplit(line, namePart, pricePart);
            name(namePart);
            Billable::price(ut.todouble(pricePart));
            m_size = '\0';
        }
        return file;
    }
    //*********************************************************************************************************************
    double Drink::price() const {
        if (!ordered() || m_size == 'L') return m_price;
        if (m_size == 'S') return m_price * 0.5;
        if (m_size == 'M') return m_price * 0.75;
        if (m_size == 'X') return m_price * 1.5;
        return m_price;
    }
    //Overload operator <<
    std::ostream& operator<<(std::ostream& os, const Drink& D) {
        if (!D.ordered()) {
            os << (const char*)D;
        }
        else {
            D.print(os);
        }
        return os;
    }
}