/***********************************************************************
// OOP244 Project, Ordering Module
//
// Filename: Ordering.h
// Version 5.0
// Author: Gustavo Balardin Chiari
// Description: Header file of Ordering module (put all together to create te order (print bill)) to be used in the project
// Revision History: 5.0
//-----------------------------------------------------------
// Date        Reason
// 2025/04/10  Submiting the MS5-3
//-----------------------------------------------------------
// I have done all the coding by myself.
// -----------------------------------------------------------
***********************************************************************/

#ifndef SENECA_ORDERING_H
#define SENECA_ORDERING_H

#include "Billable.h"
#include "Drink.h"
#include "Food.h"
#include "Menu.h"
#include "Utils.h"

namespace seneca {

    class Ordering {
        //Dynamic Arrays
        Drink* m_drinks;
        Food* m_foods;
        Billable* m_orders[MaximumNumberOfBillItems];
        //Counters
        unsigned m_noOfDrinks;
        unsigned m_noOfFoods;
        unsigned m_noOfOrders;
        unsigned m_billNumber;
        //methods
        void billTitlePrint(std::ostream& ostr) const;
        void billFooterPrint(std::ostream& ostr, double total) const;
        size_t countRecords(const char* filename) const;

    public:
        Ordering(const char* drinkFile, const char* foodFile);
        virtual ~Ordering();

        operator bool() const;
        size_t noOfBillItems() const;
        bool hasUnsavedBill() const;
        //methos
        void listFoods() const;
        void listDrinks() const;
        void orderFood();
        void orderDrink();
        void printBill(std::ostream& ostr) const;
        void resetBill();
    };

}

#endif // !SENECA_ORDERING_H