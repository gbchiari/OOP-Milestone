/***********************************************************************
// OOP244 Project, Utils Module
//
// Filename: Utils.cpp
// Version 5.0
// Author: Gustavo Balardin Chiari
// Description: .cpp file of Utils module (helper functions) to be used in the project
// Revision History: 5.0
//-----------------------------------------------------------
// Date        Reason
// 2025/04/10  Submiting the MS5-3
//-----------------------------------------------------------
// The Utils.h and Utils.cpp the Professor Fardad Soleimanloo gave the students.
// *
// EXCEPT FOR:
// *
// These 3 functions double todouble(const char* str) const; || int getInt(); || unsigned int getInt(unsigned int min, unsigned int max); || I did my myself.
// ---
// The charsplit function who I asked from OpenAI's ChatGPT (2024) to help me build the function.
// -----------------------------------------------------------
***********************************************************************/

#include <iostream>
#include "Utils.h"
using namespace std;
namespace seneca {
    Utils ut;

    char* Utils::alocpy(const char* src) const {
        char* des{};
        return alocpy(des, src);
    }

    char* Utils::alocpy(char*& des, const char* src)const {
        delete[] des;
        des = nullptr;
        if (src) {
            des = new char[strlen(src) + 1];
            strcpy(des, src);
        }
        return des;
    }
    char* Utils::strcpy(char* des, const char* src)const {
        int i;
        for (i = 0; src[i]; i++) des[i] = src[i];
        des[i] = char(0);
        return des;
    }
    int Utils::strlen(const char* str)const {
        int len;
        for (len = 0; str[len]; len++);
        return len;
    }

    bool Utils::isspace(char ch)const {
        return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r';
    }

    bool Utils::isspace(const char* cstring) const {
        while (cstring && isspace(*cstring)) {
            cstring++;
        }
        return cstring && *cstring == 0;
    }


    //FOOLPROF

    int Utils::getInt()
    {
        int value;
        bool valid;
        do {
            valid = true;
            if (std::cin.peek() == '\n') {
                std::cin.ignore(10000, '\n');
                std::cout << "You must enter a value: ";
                valid = false;
            }
            else {
                std::cin >> value;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n'); //Ignore the invalid input
                    std::cout << "Invalid integer: ";
                    valid = false;
                }
                else if (std::cin.peek() != '\n') { //See if we have extras caracteres
                    std::cout << "Only an integer please: ";
                    valid = false;
                    std::cin.ignore(10000, '\n'); //Ignore all the next 10000 extra caracteres 
                }
            }
        } while (!valid);
        std::cin.ignore(10000, '\n');
        return value;
    }


    unsigned int Utils::getInt(unsigned int min, unsigned int max) {
        unsigned int value;
        do {
            value = getInt();
            if (value < min || value > max) { //Check tghe min e max values
                std::cout << "Invalid value [" << min << " <= value <= " << max << "], try again: ";
            }
        } while (value < min || value > max);
        return value;
    }

    //2 new functions to help in MS3
    //*************************************************************************************************** 
    //The charsplit function who I asked from OpenAI's ChatGPT (2024) to help me build the function.
    void Utils::charsplit(const char* line, char* left, char* right, char separator) const {
        int i = 0, j = 0;
        while (line[i] != '\0' && line[i] != separator) {
            left[i] = line[i];
            i++;
        }
        left[i] = '\0';
        if (line[i] == separator) i++;
        while (line[i] != '\0') {
            right[j++] = line[i++];
        }
        right[j] = '\0';
    }
    //OpenAI's ChatGPT (2024)
    //***************************************************************************************************

    double Utils::todouble(const char* str) const {
        double val = 0.0;
        int intPart = 0, fracPart = 0, fracDiv = 1;
        bool isFraction = false;

        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] == '.') {
                isFraction = true;
            }
            else if (str[i] >= '0' && str[i] <= '9') {
                if (!isFraction) {
                    intPart = intPart * 10 + (str[i] - '0');
                }
                else {
                    fracPart = fracPart * 10 + (str[i] - '0');
                    fracDiv *= 10;
                }
            }
        }

        val = intPart + (fracPart / (double)fracDiv);
        return val;
    }
    //MS4 - MAKE BILL FILE NAME -
    char* Utils::makeBillFileName(char* filename, size_t billNo)const {
        char billFileName[21] = "bill_";
        size_t temp = billNo;
        int cnt = 5;
        int length;
        // Calculate the number of digits
        do {
            cnt++;
            temp /= 10;
        } while (temp > 0);
        length = cnt;
        // Convert each digit to character from the end
        while (billNo > 0) {
            billFileName[--cnt] = (billNo % 10) + '0';
            billNo /= 10;
        }
        // Handle the case when billNo is 0
        if (billFileName[cnt - 1] == '\0') {
            billFileName[--cnt] = '0';
        }
        // Attach .txt to the end of the file name
        for (int i = 0; ".txt"[i]; i++) {
            billFileName[length++] = ".txt"[i];
        }
        billFileName[length] = '\0';
        strcpy(filename, billFileName);
        return filename;
    }
}