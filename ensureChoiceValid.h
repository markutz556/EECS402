#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_
#endif

#ifndef _ENSURECHOICEVALID_H_
#define _ENSURECHOICEVALID_H_
#endif

#include <iostream>
#include <string>
using namespace std;

//project3
//Programmer: Shaocheng Wu
//Date: 10/28/2017
//Purpose: This function implements error checking for input
//menu choice value. It ends when user inputs the valid value.

void ensureChoiceValid(const int menuSize, int &userChoice);