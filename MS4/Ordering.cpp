/***********************************************************************
// OOP244 Project, Ordering Module
//
// Filename: Ordering.cpp
// Version 4.0
// Author: Gustavo Balardin Chiari
// Description: .cpp of Ordering module (put all together to create te order (print bill)) to be used in the project
// Revision History: 4.0
//-----------------------------------------------------------
// Date        Reason
// 2025/04/10  Submiting the MS4
//-----------------------------------------------------------
// I have done all the coding by myself.
// -----------------------------------------------------------
//***********************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Ordering.h"
#include "constants.h"
using namespace std;
namespace seneca {
    //MS4 - Ordering Class
    size_t Ordering::countRecords(const char* filename) const {
        size_t count = 0;
        ifstream file(filename);
        char c;
        while (file.get(c)) {
            if (c == '\n') count++;
        }
        return count;
    }
    Ordering::Ordering(const char* drinkFile, const char* foodFile)
        : m_drinks(nullptr), m_foods(nullptr), m_noOfDrinks(0), m_noOfFoods(0),
        m_noOfOrders(0), m_billNumber(1) {

        size_t drinkCount = countRecords(drinkFile);
        size_t foodCount = countRecords(foodFile);

        m_drinks = new Drink[drinkCount];
        m_foods = new Food[foodCount];

        //Drink INput File
        //Food INput File
        ifstream din(drinkFile);
        ifstream fin(foodFile);

        if (!din.is_open() || !fin.is_open()) {
            delete[] m_drinks;
            delete[] m_foods;
            m_drinks = nullptr;
            m_foods = nullptr;
            return;
        }

        size_t d = 0, f = 0;
        while (d < drinkCount && m_drinks[d].read(din)) d++;
        while (f < foodCount && m_foods[f].read(fin)) f++;

        if (d != drinkCount || f != foodCount) {
            delete[] m_drinks;
            delete[] m_foods;
            m_drinks = nullptr;
            m_foods = nullptr;
        }
        else {
            m_noOfDrinks = d;
            m_noOfFoods = f;
        }
    }
    Ordering::~Ordering() {
        delete[] m_drinks;
        delete[] m_foods;
        for (unsigned i = 0; i < m_noOfOrders; i++) {
            delete m_orders[i];
        }
    }
    Ordering::operator bool() const {
        return m_drinks != nullptr && m_foods != nullptr;
    }
    size_t Ordering::noOfBillItems() const {
        return m_noOfOrders;
    }
    bool Ordering::hasUnsavedBill() const {
        return m_noOfOrders > 0;
    }
    void Ordering::listFoods() const {
        cout << "List Of Avaiable Meals\n========================================\n";
        for (unsigned i = 0; i < m_noOfFoods; i++) {
            m_foods[i].print(cout) << endl;
        }
        cout << "========================================" << endl;
    }
    void Ordering::listDrinks() const {
        cout << "List Of Avaiable Drinks\n========================================\n";
        for (unsigned i = 0; i < m_noOfDrinks; i++) {
            m_drinks[i].print(cout) << endl;
        }
        cout << "========================================" << endl;
    }
    void Ordering::orderFood() {
        Menu menu("Food Menu", "Back to Order", 2);
        for (unsigned i = 0; i < m_noOfFoods; i++) {
            menu << (const char*)m_foods[i];
        }

        size_t choice = menu.select();
        if (choice) {
            Food* food = new Food(m_foods[choice - 1]);
            if (food->order()) {
                m_orders[m_noOfOrders++] = food;
            }
            else {
                delete food;
            }
        }
    }
    void Ordering::orderDrink() {
        Menu menu("Drink Menu", "Back to Order", 2);
        for (unsigned i = 0; i < m_noOfDrinks; i++) {
            menu << (const char*)m_drinks[i];
        }

        size_t choice = menu.select();
        if (choice) {
            Drink* drink = new Drink(m_drinks[choice - 1]);
            if (drink->order()) {
                m_orders[m_noOfOrders++] = drink;
            }
            else {
                delete drink;
            }
        }
    }
    void Ordering::billTitlePrint(ostream& ostr) const {
        ostr << "Bill # ";
        ostr.width(3);
        ostr.fill('0');
        ostr << m_billNumber << " =============================" << endl;
    }
    void Ordering::billFooterPrint(ostream& ostr, double total) const {
        double tax = total * Tax;
        double totalWithTax = total + tax;
        ostr << fixed << setprecision(2);
        ostr << "                     Total:      " << setw(7) << total << endl;
        ostr << "                     Tax:        " << setw(7) << tax << endl;
        ostr << "                     Total+Tax:  " << setw(7) << totalWithTax << endl;
        ostr << "========================================" << endl;
    }
    void Ordering::printBill(ostream& ostr) const {
        double total = 0;
        billTitlePrint(ostr);
        for (unsigned i = 0; i < m_noOfOrders; i++) {
            m_orders[i]->print(ostr) << endl;
            total += *m_orders[i];
        }
        billFooterPrint(ostr, total);
    }
    void Ordering::resetBill() {
        char filename[128];
        Utils().makeBillFileName(filename, m_billNumber);
        ofstream fout(filename);
        if (fout) {
            printBill(fout);
            cout << "Saved bill number " << m_billNumber << endl;
            cout << "Starting bill number " << (m_billNumber + 1) << endl;
        }

        for (unsigned i = 0; i < m_noOfOrders; i++) {
            delete m_orders[i];
            m_orders[i] = nullptr;
        }

        m_noOfOrders = 0;
        m_billNumber++;
    }
}