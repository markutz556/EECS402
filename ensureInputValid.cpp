#include <iostream>
#include <string>
using namespace std;

#include "constants.h"
#include "ensureInputValid.h"

void ensureInputValid(int &inRow, int &inCol)
{
 bool validInputFound = false;

 while (!validInputFound)
 {
  if (cin.fail() || inRow < MIN_RC_VALUE || inCol < MIN_RC_VALUE)
  {
   cin.clear();
   cin.ignore(200, '\n');
   cout << "Invalid entry - try again!" << endl;
   cout << "Enter int for row and/or column: ";
   cin >> inRow >> inCol;
  }
  else
  {
   validInputFound = true;
  }
 }
}