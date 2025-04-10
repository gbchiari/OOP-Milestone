/***********************************************************************
// OOP244 Project, MAIN 
//
// Filename: main.cpp
// Version 2.0
// Author: Gustavo Balardin Chiari
// Description: .cpp file of project (brain of project) to be used in the project
// Revision History: 2.0
//-----------------------------------------------------------
// Date        Reason
// 2025/04/10  Submiting the MS5-2
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

    Menu orderMenu("Order Menu", "Back to main menu", 1, 3);
    orderMenu << "Food" << "Drink";

    bool done = false;
    while (!done) {
        size_t selection = mainMenu.select();
        switch (selection) {
        case 1: { //Order
            bool orderingDone = false;
            while (!orderingDone) {
                size_t orderSelection = orderMenu.select();
                switch (orderSelection) {
                case 1: //Food (NEXT MILESTONE (MS53))
                    //FINISH
                    break;
                case 2: //Drink
                    ordering.orderDrink();
                    break;
                case 0: //Back
                    orderingDone = true;
                    break;
                }
            }
            break;
        }
        case 4: //List Foods
            ordering.listFoods();
            break;
        case 5: //List Drinks
            ordering.listDrinks();
            break;
        case 0: { // End Program
            if (ordering.hasUnsavedBill()) {
                Menu confirmExit("You have bills that are not saved. Are you sure you want to exit?", "No");
                confirmExit << "Yes";
                if (confirmExit.select() == 1) {
                    done = true;
                }
            }
            else {
                done = true;
            }
            break;
        }
        default:
            break;
        }
    }

}