#include <iostream>
#include <string>
using namespace std;

#include "constants.h"
#include "ensureChoiceValid.h"
//error checking

void ensureChoiceValid(const int menuSize, int &userChoice)
{
 bool validInputFound = false;

 while (!validInputFound)
 {
    if (cin.fail() || userChoice < MIN_MENU_CHOICE || userChoice > menuSize)
  {
   cin.clear();
   cin.ignore(200, '\n');
   cout << "Invalid entry - try again!" << endl;
   cout << "Enter valid int for menu choice: ";
   cin >> userChoice;
  }
  else
  {
   validInputFound = true;
  }
 }
}