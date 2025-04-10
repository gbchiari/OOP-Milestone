/***********************************************************************
// OOP244 Project, Billable Module
//
// Filename: Billable.h
// Version 5.0
// Author: Gustavo Balardin Chiari
// Description: Header file of Billable module (creates the bill) to be used in the project
// Revision History: 5.0
//-----------------------------------------------------------
// Date        Reason
// 2025/04/10  Submiting the MS5-3
//-----------------------------------------------------------
// I have done all the coding by myself
// *
// EXCEPT FOR:
// *
// The read function who I looked up in the teacher's notes from the class, I didn't copy everything, just the structure.
// -----------------------------------------------------------
***********************************************************************/

#ifndef SENECA_BILLABLE_H
#define SENECA_BILLABLE_H
#include <iostream>
#include <fstream>
namespace seneca {
    //The Billable class serves as an abstract base for items that can be added to a customer’s bill.
    class Billable {
    protected:
        char* m_name{};
        double m_price{};
        void name(const char* name);
        void price(double value);
    public:
        //Construction
        Billable();
        //Rule of three
        Billable(const Billable& src);
        Billable& operator=(const Billable& src);
        //"Every single destructor must be virtual" -Fardad
        virtual ~Billable();
        //Only virtual
        virtual double price() const;
        //Pure virtual
        virtual std::ostream& print(std::ostream& os = std::cout) const = 0;
        virtual bool order() = 0;
        virtual bool ordered() const = 0;
        //The read function who I looked up in the teacher's notes from the class, I didn't copy everything, just the structure.
        virtual std::ifstream& read(std::ifstream& file) = 0;
        //*********************************************************************************************************************
        operator const char* () const;
    };
    double operator+(double money, const Billable& B);
    double& operator+=(double& money, const Billable& B);
    std::ostream& operator<<(std::ostream& os, const Billable& B);
}
#endif // !SENECA_BILLABLE_H