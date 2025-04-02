/* Citation and Sources...
Final Project Milestone 3
Module: Food
Filename: Food.cpp
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
#include "Food.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>
#include <cstring>
namespace seneca {
    /////////////////////////////////MS3////////////////////////////////////////
    //Inheritance Food class with Billable class
    Food::Food() : Billable() {}
    Food::Food(const Food& src) : Billable(src) {
        m_customize = ut.alocpy(src.m_customize);
        m_child = src.m_child;
        m_ordered = src.m_ordered;
    }
    //Overload operator =
    Food& Food::operator=(const Food& src) {
        if (this != &src) {
            Billable::operator=(src);
            ut.alocpy(m_customize, src.m_customize);
            m_child = src.m_child;
            m_ordered = src.m_ordered;
        }
        return *this;
    }
    //Destructor
    Food::~Food() {
        delete[] m_customize;
    }
    //Pritn method
    std::ostream& Food::print(std::ostream& os) const {
        if (!m_name || m_price == 0.0) {
            os << (m_name ? m_name : "");
        }
        else if (!m_ordered) {
            //If not ordered =
            os << std::left << std::setw(33) << std::setfill('.') << m_name
                << std::right << std::setfill(' ')
                << std::setw(7) << std::fixed << std::setprecision(2) << m_price;
        }
        else {
            //Ordered =
            os << std::left << std::setw(28) << std::setfill('.') << m_name
                << std::right << std::setfill(' ')
                << (m_child ? "Child" : "Adult")
                << std::setw(7) << std::fixed << std::setprecision(2) << price();
            if (m_customize && &os == &std::cout) {
                os << " >> ";
                for (int i = 0; i < 30 && m_customize[i]; ++i)
                    os << m_customize[i];
            }
        }
        return os;
    }
    //Order method
    bool Food::order() {
        std::cout << "         Food Size Selection\n"
            "          1- Adult\n"
            "          2- Child\n"
            "          0- Back\n"
            "         > ";
        int sel = ut.getInt(0, 2);
        switch (sel) {
        case 1: m_child = false; m_ordered = true; break;
        case 2: m_child = true; m_ordered = true; break;
        case 0: m_ordered = false; delete[] m_customize; m_customize = nullptr; return false;
        }
        std::cout << "Special instructions\n> ";
        char input[256]{};
        std::cin.getline(input, 256);
        if (input[0] == '\0') {
            delete[] m_customize;
            m_customize = nullptr;
        }
        else {
            ut.alocpy(m_customize, input);
        }
        return true;
    }
    bool Food::ordered() const {
        return m_ordered;
    }
    //Read method
    //Structure who I looked up in the teacher's notes from the class.
    std::ifstream& Food::read(std::ifstream& file) {
        char line[256]{};
        if (file.getline(line, 256)) {
            char namePart[200]{}, pricePart[50]{};
            ut.charsplit(line, namePart, pricePart);
            name(namePart);
            Billable::price(ut.todouble(pricePart));
            m_child = false;
            m_ordered = false;
            delete[] m_customize;
            m_customize = nullptr;
        }
        return file;
    }
    double Food::price() const {
        return (m_ordered && m_child) ? m_price * 0.5 : m_price;
    }
    std::ostream& operator<<(std::ostream& os, const Food& F) {
        if (!F.ordered()) {
            os << (const char*)F;
        }
        else {
            F.print(os);
        }
        return os;
    }
}
