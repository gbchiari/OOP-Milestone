/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: constants.h
Version 1.0
Author: Gustavo Balardin Chiari
Revision History: v2
-----------------------------------------------------------
Date        Reason
2025/23/23  Updating the Citation and Sources
-----------------------------------------------------------
I have done all the coding by myself
*
EXCEPT FOR:
*
The Utils.h and Utils.cpp because the Professor Fardad Soleimanloo gave the students.
-----------------------------------------------------------
*/
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
   };
   extern Utils ut;   // makes the ut object available where Utils.h is included
                     // to call a Utils function call it as follows
                     // ut.strcpy(des, src);
}

#endif // !SENECA_UTILS_H
