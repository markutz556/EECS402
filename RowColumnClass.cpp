#include <iostream>
using namespace std;

#include "RowColumnClass.h"
#include "constants.h"

RowColumnClass::RowColumnClass()
{
 valRow = DEFAULT_VALUE;
 valCol = DEFAULT_VALUE;
}

RowColumnClass::RowColumnClass(
 int inRow,
 int inCol
 )
{
 valRow = inRow;
 valCol = inCol;
}

void RowColumnClass::setRowCol(
 int inRow,
 int inCol
 )
{
 valRow = inRow;
 valCol = inCol;
}

void RowColumnClass::setRow(
 int inRow
 )
{
 valRow = inRow;
}

void RowColumnClass::setCol(
 int inCol
 )
{
 valCol = inCol;
}

int RowColumnClass::getRow()
{
 return valRow;
}

int RowColumnClass::getCol()
{
 return valCol;
}

void RowColumnClass::addRowColTo(
 RowColumnClass &inRowCol
 )
{
 valRow = valRow + inRowCol.valRow;
 valCol = valCol + inRowCol.valCol;
}

void RowColumnClass::printRowCol(
 )
{
 cout << "[" << valRow << "," << valCol << "]";
}