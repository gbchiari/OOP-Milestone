/* Citation and Sources...
Final Project Milestone 3
Module: Drink
Filename: Drink.h
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
        std::ifstream& read(std::ifstream& file);
        double price() const;
    };
    std::ostream& operator<<(std::ostream& os, const Drink& D);
}
#endif // !SENECA_DRINK_H