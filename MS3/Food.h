/* Citation and Sources...
Final Project Milestone 3
Module: Food
Filename: Food.h
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
#ifndef SENECA_FOOD_H
#define SENECA_FOOD_H
#include "Billable.h"
namespace seneca {
    //The Food class, derived from Billable, represents a food item and includes functionality for customization and portion type.
    class Food : public Billable {
        bool m_ordered{};
        bool m_child{};
        char* m_customize{};
    public:
        //Construction
        Food();
        //Rule of three
        Food(const Food&);
        Food& operator=(const Food&);
        //"Every single destructor must be virtual" -Fardad
        virtual ~Food();
        //Methofs
        std::ostream& print(std::ostream& os = std::cout) const;
        bool order();
        bool ordered() const;
        std::ifstream& read(std::ifstream& file);
        double price() const;
    };
    std::ostream& operator<<(std::ostream& os, const Food& F);
}
#endif // !SENECA_FOOD_H