/* Citation and Sources...
Final Project Milestone 3
Module: Drink
Filename: Drink.cpp
Version 1.0
Author: Gustavo Balardin Chiari
Revision History: v1
-----------------------------------------------------------
Date        Reason
2025/04/01  Submit the MS3
-----------------------------------------------------------
I have done all the coding by myself
*
EXCEPT FOR:
*
The read function who I looked up in the teacher's notes from the class, I didn't copy everything, just the structure.
-----------------------------------------------------------
*/
#include "Drink.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>
#include <cstring>
namespace seneca {
    /////////////////////////////////MS3////////////////////////////////////////
    //Inheritance Drink class with Billable class
    Drink::Drink() : Billable() { m_size = '\0'; }
    std::ostream& Drink::print(std::ostream& os) const {
        if (!ordered()) {
            if (m_price == 0 || m_size == '\0') {
                os << (m_name ? m_name : "");
            }
            else {
                os << std::left << std::setw(28) << std::setfill('.') << (m_name ? m_name : "")
                    << std::right << std::setfill(' ')
                    << "....."
                    << std::setw(7) << std::fixed << std::setprecision(2) << m_price;
            }
        }
        else {
            os << std::left << std::setw(28) << std::setfill('.') << (m_name ? m_name : "")
                << std::right << std::setfill(' ');
            if (m_size == 'S') os << "SML..";
            else if (m_size == 'M') os << "MID..";
            else if (m_size == 'L') os << "LRG..";
            else if (m_size == 'X') os << "XLR..";
            else os << ".....";
            os << std::setw(7) << std::fixed << std::setprecision(2) << price();
        }
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
    //Structure who I looked up in the teacher's notes from the class.
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
    //Price const because doesn't change
    double Drink::price() const {
        if (!ordered() || m_size == 'L') return m_price;
        if (m_size == 'S') return m_price * 0.5;
        if (m_size == 'M') return m_price * 0.75;
        if (m_size == 'X') return m_price * 1.5;
        return m_price;
    }
    //Overload operator <<
    std::ostream& operator<<(std::ostream& os, const Drink& D) {
        return D.print(os);
    }
}