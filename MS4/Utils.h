/***********************************************************************
// OOP244 Project, Utils Module
//
// Filename: Utils.h
// Version 4.0
// Author: Gustavo Balardin Chiari
// Description: Header file of Utils module (helper functions) to be used in the project
// Revision History: 4.0
//-----------------------------------------------------------
// Date        Reason
// 2025/04/10  Submiting the MS4
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

#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H
namespace seneca {
    class Utils {
    public:
        char* alocpy(const char* src)const;
        char* alocpy(char*& des, const char* src)const;
        char* strcpy(char* des, const char* src)const;
        int strlen(const char* str)const;
        bool isspace(char ch)const;
        bool isspace(const char* cstring)const;

        //2 new functions to help in MS3
        //The charsplit function who I asked from OpenAI's ChatGPT (2024) to help me build the function.
        void charsplit(const char* line, char* left, char* right, char separator = ',') const;
        double todouble(const char* str) const;

        //foolprof MS2
        int getInt();
        unsigned int getInt(unsigned int min, unsigned int max);
        char* makeBillFileName(char* filename, size_t billNo)const;
    };
    extern Utils ut;   // makes the ut object available where Utils.h is included
    // to call a Utils function call it as follows
    // ut.strcpy(des, src);
}

#endif // !SENECA_UTILS_H
