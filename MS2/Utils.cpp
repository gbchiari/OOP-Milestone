/***********************************************************************
// OOP244 Project, Utils Module
//
// File	Utils.h
// Version 0.1
// started by Fardad
// Description
// utility function to be used in the project
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Gustavo B Chiari  03/23/2025      MS2
/////////////////////////////////////////////////////////////////
Date        Reason
2025/23/23  Submit the MS2
-----------------------------------------------------------
The Utils.h and Utils.cpp the Professor Fardad Soleimanloo gave the students.
-----------------------------------------------------------
***********************************************************************/
#include <iostream>
#include "Utils.h"
using namespace std;
namespace seneca {
   Utils ut;

   char* Utils::alocpy(const char* src) const{
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

   bool Utils::isspace(const char* cstring) const{
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
 }