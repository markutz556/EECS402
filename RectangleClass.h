#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_
#endif

#ifndef _RECTANGLECLASS_H_
#define _RECTANGLECLASS_H_

#include <iostream>
using namespace std;

#include "ColorClass.h"
#include "RowColumnClass.h"
#include "ColorImageClass.h"

//project3
//Programmer: Shaocheng Wu
//Date: 10/28/2017
//Purpose: This class describes a rectangle with height and width
//and with specific color filled, which can be inserted to specific
//position in an image.

class RectangleClass
{
 private:
  //Width of a rectangle.
  int width;
  //Height of a rectangle.
  int height;
  //Upper left row value of image position to be inserted a rectangle.
  int upperLeftRow;
  //Upper left column value of image position to be inserted a rectangle. 
  int upperLeftCol;
  //Specific color for the rectangle.
  ColorClass inColor;

 public:
  //Default constructor builds a rectangle with 1 height and 1 width and 
  //with white color. The default position to insert in image is row 0 
  //column 0.
  RectangleClass();

  //Convert upper-left and lower-right location to width and height.
  void convertUpLeftLowRight();

  //Standard input is case that user inputs the upper left position for 
  //insertion and width and height parameters for rectangle.
  void standardInput();

  //Convert center location, half-width and half-height to width, height and upper-left location.
  void convertCenterLoc();

  //According to the fill option, place a rectangle with a specific color to a
  //specific location in the image.
  bool fillRectangle(
   int fillOption, int colorChoice, 
   ColorImageClass &rhs, RowColumnClass &inRowCol
  );
};
#endif