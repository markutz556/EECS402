#include <iostream>
#include <string>
using namespace std;

#include "constants.h"
#include "chooseColor.h"

void chooseColor(const string &label, int &colorChoice)
{
 bool validInputFound = false;

 cout << "1. Red" << endl;
 cout << "2. Green" << endl;
 cout << "3. Blue" << endl;
 cout << "4. Black" << endl;
 cout << "5. White" << endl;
 cout << label;

 cin >> colorChoice;

 while (!validInputFound)
 {
  if (cin.fail() || colorChoice < MIN_MENU_CHOICE 
  	|| colorChoice > COLOR_MENU_SIZE)
  {
   cin.clear();
   cin.ignore(200, '\n');
   cout << "Invalid entry - try again!" << endl;
   cout << "Enter valid int for color choice: ";
   cin >> colorChoice;
  }
  else
  {
   validInputFound = true;
  }
 }
}