/* Citation and Sources...
Final Project Milestone 3
Module: Billable
Filename: Billable.h
Version 1.0
Author: Gustavo Balardin Chiari
Revision History: v1
-----------------------------------------------------------
Date        Reason
2025/04/01  Submit the MS3
-----------------------------------------------------------
I have done all the coding by myself
-----------------------------------------------------------
*/
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
        virtual std::ifstream& read(std::ifstream& file) = 0;
        operator const char* () const;
    };
    double operator+(double money, const Billable& B);
    double& operator+=(double& money, const Billable& B);
    std::ostream& operator<<(std::ostream& os, const Billable& B);
}
#endif // !SENECA_BILLABLE_H