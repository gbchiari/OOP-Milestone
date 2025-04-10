/***********************************************************************
// OOP244 Project, Billable Module
//
// Filename: Billable.cpp
// Version 4.0
// Author: Gustavo Balardin Chiari
// Description: .cpp file of Billable module (creates the bill) to be used in the project
// Revision History: 4.0
//-----------------------------------------------------------
// Date        Reason
// 2025/04/10  Submiting the MS4
//-----------------------------------------------------------
// I have done all the coding by myself.
// -----------------------------------------------------------
//***********************************************************************/

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