/***********************************************************************
// OOP244 Project, Drink Module
//
// Filename: Drink.h
// Version 4.0
// Author: Gustavo Balardin Chiari
// Description: Header file of Drink module (available drinks on the menu) to be used in the project
// Revision History: 4.0
//-----------------------------------------------------------
// Date        Reason
// 2025/04/10  Submiting the MS4
//-----------------------------------------------------------
// I have done all the coding by myself
// *
// EXCEPT FOR:
// *
// The read function who I looked up in the teacher's notes from the class, I didn't copy everything, just the structure.
// -----------------------------------------------------------
***********************************************************************/

#ifndef SENECA_DRINK_H
#define SENECA_DRINK_H
#include "Billable.h"
namespace seneca {
    //The Drink class inherits from Billable and represents a drink item. 
    class Drink : public Billable {
        char m_size{};
    public:
        //Construction
        Drink();
        //Rule of three
        Drink(const Drink& src);
        Drink& operator=(const Drink& src);
        //Public methofds
        std::ostream& print(std::ostream& os = std::cout) const;
        bool order();
        bool ordered() const;
        //The read function who I looked up in the teacher's notes from the class, I didn't copy everything, just the structure.
        std::ifstream& read(std::ifstream& file);
        //*********************************************************************************************************************
        double price() const;
    };
    std::ostream& operator<<(std::ostream& os, const Drink& D);
}
#endif // !SENECA_DRINK_H