#include <iostream>
using namespace std;

#include "constants.h"
#include "ColorClass.h"
#include "RowColumnClass.h"
#include "ColorImageClass.h"
#include "RectangleClass.h"
#include "ensureInputValid.h"

RectangleClass::RectangleClass()
{
 width = DEFAULT_REC_WIDTH;
 height = DEFAULT_REC_HEIGHT;
 upperLeftRow = DEFAULT_REC_ROW;
 upperLeftCol = DEFAULT_REC_COLUMN;
 inColor.setToWhite();
}

void RectangleClass::convertUpLeftLowRight()
{
 int inUpLeftRow;
 int inUpLeftCol;
 int inLowRightRow; 
 int inLowRightCol;
 
 cout << "Enter upper left corner row and column: ";
 cin >> inUpLeftRow >> inUpLeftCol;
 ensureInputValid(inUpLeftRow, inUpLeftCol);

 cout << "Enter lower right corner row and column: ";
 cin >> inLowRightRow >> inLowRightCol;
 ensureInputValid(inLowRightRow, inLowRightCol);

 height = inLowRightRow - inUpLeftRow;
 width = inLowRightCol - inUpLeftCol;
 upperLeftRow = inUpLeftRow;
 upperLeftCol = inUpLeftCol;
}

void RectangleClass::standardInput()
{
 int inUpLeftRow;
 int inUpLeftCol;
 int inHeight;
 int inWidth;

 cout << "Enter upper left corner row and column: ";
 cin >> inUpLeftRow >> inUpLeftCol;
 ensureInputValid(inUpLeftRow, inUpLeftCol);

 cout << "Enter int for number of rows: ";
 cin >> inHeight;
 cout << "Enter int for number of columns: ";
 cin >> inWidth;
 ensureInputValid(inHeight, inWidth);

 height = inHeight;
 width = inWidth;
 upperLeftRow = inUpLeftRow;
 upperLeftCol = inUpLeftCol;
}

void RectangleClass::convertCenterLoc()
{
 int centerRow;
 int centerCol;
 int halfHeight; 
 int halfWidth;

 cout << "Enter rectangle center row and column: ";
 cin >> centerRow >> centerCol;
 ensureInputValid(centerRow, centerCol);

 cout << "Enter int for half number of rows: ";
 cin >> halfHeight;
 cout << "Enter int for half number of columns: ";
 cin >> halfWidth;
 ensureInputValid(halfHeight, halfWidth);

 height = halfHeight * 2;
 width = halfWidth * 2;
 upperLeftRow = centerRow - halfHeight;
 upperLeftCol = centerCol - halfWidth;
}

bool RectangleClass::fillRectangle(
 int fillOption, int colorChoice, 
 ColorImageClass &rhs, RowColumnClass &inRowCol
 )
{
 bool isSuccess = true;

 if (colorChoice == RED_OPTION) 
 {
  inColor.setToRed();
 }
 else if (colorChoice == GREEN_OPTION)
 {
  inColor.setToGreen();
 }
 else if (colorChoice == BLUE_OPTION)
 {
  inColor.setToBlue();
 }
 else if (colorChoice == BLACK_OPTION)
 {
  inColor.setToBlack();
 }
 else if (colorChoice == WHITE_OPTION)
 {
  inColor.setToWhite();
 }

 if (fillOption == FILL_ALL)
 {
  for (int i = upperLeftRow; i <= upperLeftRow + height; i++)
  {
   for (int j = upperLeftCol; j <= upperLeftCol + width; j++)
   {
	   inRowCol.setRowCol(i, j);
	   isSuccess = rhs.setColorAtLocation(inRowCol, inColor);

	   if (!isSuccess)
	   {
	    cout << "Invalid image location." << endl;
	    return false;
	   }
   }
  }
 }
 else if (fillOption == FILL_SIDE)
 {
  for (int i = upperLeftRow; i <= upperLeftRow + height; i++)
  {
   inRowCol.setRowCol(i, upperLeftCol);
   isSuccess = rhs.setColorAtLocation(inRowCol, inColor);

   inRowCol.setRowCol(i, upperLeftCol + width);
   isSuccess = rhs.setColorAtLocation(inRowCol, inColor);
  }

  for (int j = upperLeftCol; j <= upperLeftCol + width; j++)
  {
   inRowCol.setRowCol(upperLeftRow, j);
   isSuccess = rhs.setColorAtLocation(inRowCol, inColor);

   inRowCol.setRowCol(upperLeftRow + height, j);
   isSuccess = rhs.setColorAtLocation(inRowCol, inColor);
  }
 }
 return isSuccess;
}
