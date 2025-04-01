/* Citation and Sources...
Final Project Milestone 3
Module: Billable
Filename: Billable.cpp
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
#include "Billable.h"
#include "Utils.h"
#include <cstring>
namespace seneca {
    /////////////////////////////////MS3////////////////////////////////////////
    //Construtor (Billable Class)
    Billable::Billable() {}
    //Copy constructor
    Billable::Billable(const Billable& src) {
        m_name = ut.alocpy(src.m_name);
        m_price = src.m_price;
    }
    //Overload operator =
    Billable& Billable::operator=(const Billable& src) {
        if (this != &src) {
            ut.alocpy(m_name, src.m_name);
            m_price = src.m_price;
        }
        return *this;
    }
    //Destructor
    Billable::~Billable() {
        delete[] m_name;
    }
    //All the functions for the Billable Class below**
    void Billable::name(const char* name) {
        ut.alocpy(m_name, name);
    }
    void Billable::price(double value) {
        m_price = value;
    }
    double Billable::price() const {
        return m_price;
    }
    Billable::operator const char* () const {
        return m_name;
    }
    double operator+(double money, const Billable& B) {
        if (B.ordered()) {
            money += B.price();
        }
        return money;
    }
    double& operator+=(double& money, const Billable& B) {
        if (B.ordered()) {
            money += B.price();
        }
        return money;
    }
    std::ostream& operator<<(std::ostream& os, const Billable& B) {
        return B.print(os);
    }
}