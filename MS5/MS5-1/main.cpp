/***********************************************************************
// OOP244 Project, MAIN 
//
// Filename: main.cpp
// Version 1.0
// Author: Gustavo Balardin Chiari
// Description: .cpp file of project (brain of project) to be used in the project
// Revision History: 1.0
//-----------------------------------------------------------
// Date        Reason
// 2025/04/10  Submiting the MS5-1
//-----------------------------------------------------------
// I have done all the coding by myself in this file.
// -----------------------------------------------------------
***********************************************************************/

#include <iostream>
#include "Ordering.h"
#include "Menu.h"
#include "Utils.h"
using namespace std;
using namespace seneca;
int main() {
    Ordering ordering("drinks.csv", "foods.csv");

    if (!ordering) {
        cout << "Failed to open data files or the data files are corrupted!" << endl;
        return 1;
    }

    Menu mainMenu("Seneca Restaurant ", "End Program");
    mainMenu << "Order" << "Print Bill" << "Start a New Bill" << "List Foods" << "List Drinks";

    bool done = false;
    while (!done) {
        size_t selection = mainMenu.select();
        switch (selection) {
        case 4:
            ordering.listFoods();
            break;
        case 5:
            ordering.listDrinks();
            break;
        case 0:
            done = true;
            break;
        default:
            break;
        }
    }
}