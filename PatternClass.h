#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_
#endif

#ifndef _PATTERNCLASS_H_
#define _PATTERNCLASS_H_

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "ColorClass.h"
#include "RowColumnClass.h"
#include "ColorImageClass.h"

//project3
//Programmer: Shaocheng Wu
//Date: 10/28/2017
//Purpose: This class describes a pattern with an 2D array 
//containing only ones and zeros.

class PatternClass
{
 private:
  //Pointer to an array.
  int *patternAry;
  //The row value of array size.
  int valRow;
  //The column value of array size.
  int valCol;
  //The one D index value for 2D array.
  int oneDindex;

 public:
  //Default constructor builds a 2x2 pattern with only ones.
  PatternClass();

  //Read pattern from input file.
  bool readFromFile(string &inFileName);

  //Print current pattern to the console.
  void printPattern();

  //Set an input image pixel to a chosen color if the pattern 
  //value at that position is 1 or do nothing if the value is 0.
  bool setPatternPixel(
   int inRow, int inCol, ColorClass &setColor,
   ColorImageClass &rhs
  );

  //Place a pattern to the input image.
  bool placePattern(ColorImageClass &rhs);
};
#endif