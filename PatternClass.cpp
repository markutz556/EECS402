#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "constants.h"
#include "ColorClass.h"
#include "RowColumnClass.h"
#include "ColorImageClass.h"
#include "PatternClass.h"
#include "ensureInputValid.h"
#include "chooseColor.h"

PatternClass::PatternClass()
{
 valRow = DEFAULT_PATTERN_ROW;
 valCol = DEFAULT_PATTERN_COLUMN;
 patternAry = new int[valRow * valCol];
 
 for (int i = 0; i < valRow * valCol; i++)
 {
  patternAry[i] = 1;
 }
}

bool PatternClass::readFromFile(string &inFileName)
{
 ifstream inFile;
 int inRow;
 int inCol;

 inFile.open(inFileName.c_str());

 if (inFile.fail())
 {
  cout << "Unable to open input pattern file!" << endl;
  return false;
 }

 while (!inFile.eof()) 
 {
  inFile >> inCol >> inRow;
  
  if (inFile.fail()) 
  {
   cout << "ERROR: Invalid row and column values." << endl;
   return false;
  }
  else if (inRow <= MIN_RC_VALUE || inCol <= MIN_RC_VALUE) 
  {
   cout << "Row or column values of image are wrong." << endl;
   return false;
  }
  
  patternAry = new int[inRow * inCol];
  valRow = inRow;
  valCol = inCol;

  for (int i = 0; i < inRow; i++) 
  {
   for (int j = 0; j < inCol; j++)
   {
    oneDindex = i * inCol + j;
    inFile >> patternAry[oneDindex];
    
    if (inFile.fail()) 
    {
     cout << "ERROR: Invalid pattern values." << endl;
     return false;
    }
    else if (patternAry[oneDindex] != NO_MODIFIED 
     && patternAry[oneDindex] != IS_MODIFIED)
    {
     cout << "ERROR: Invalid values at Row: " << i 
     << " and column: " << j <<endl;
     return false;
    }
   }
  }
  inFile >> inCol >> inRow;
 }
 inFile.close();
 return true;
}

void PatternClass::printPattern()
{
 for (int i = 0; i < valRow; i++)
 {
  cout << '\n' << endl;
  for (int j = 0; j < valCol; j++)
  {
   oneDindex = i * valCol + j;
   cout << patternAry[oneDindex] << " ";
  }
 }
}

bool PatternClass::setPatternPixel(
 int inRow, int inCol, ColorClass &setColor,
 ColorImageClass &rhs
 )
{
 RowColumnClass inRowCol;
 bool isSuccess;
   
 for (int i = inRow; i < inRow + valRow; i++)
 {
  for (int j = inCol; j < inCol + valCol; j++)
  {
   inRowCol.setRowCol(i, j);
   oneDindex = (i - inRow) * valCol + j - inCol;
   if (patternAry[oneDindex])
   {
    isSuccess = rhs.setColorAtLocation(inRowCol, setColor);

    if (!isSuccess)
    {
     cout << "Pattern size out of range at row: " 
     << i << " and column: " << j << "." << endl;
     return false;
    }
   }
  }
 }
 return true;
}

bool PatternClass::placePattern(
 ColorImageClass &insertImage
 )
{
 int inRow;
 int inCol;
 int colorChoice = 0;
 ColorClass setColor;
 bool isSuccess;

 cout << "Enter upper left corner of pattern row and column: ";
 cin >> inRow >> inCol;
 ensureInputValid(inRow, inCol);

 chooseColor("Enter int for pattern color: ", colorChoice);

 if (colorChoice == RED_OPTION)
 {
  setColor.setToRed();
  isSuccess = setPatternPixel(inRow, inCol, setColor, insertImage);
 }
 if (colorChoice == GREEN_OPTION)
 {
  setColor.setToGreen();
  isSuccess = setPatternPixel(inRow, inCol, setColor, insertImage);
 }
 if (colorChoice == BLUE_OPTION)
 {
  setColor.setToBlue();
  isSuccess = setPatternPixel(inRow, inCol, setColor, insertImage);
 }
 if (colorChoice == BLACK_OPTION)
 {
  setColor.setToBlack();
  isSuccess = setPatternPixel(inRow, inCol, setColor, insertImage);
 }
 if (colorChoice == WHITE_OPTION)
 {
  setColor.setToWhite();
  isSuccess = setPatternPixel(inRow, inCol, setColor, insertImage);
 }

 delete [] patternAry;

 return isSuccess;
}
