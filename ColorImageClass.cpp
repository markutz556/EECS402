#include <iostream>
#include <fstream>
using namespace std;

#include "constants.h"
#include "ColorClass.h"
#include "RowColumnClass.h"
#include "ColorImageClass.h"
#include "ensureChoiceValid.h"
#include "ensureInputValid.h"
#include "chooseColor.h"

ColorImageClass::ColorImageClass()
{
 valRow = DEFAULT_IMAGE_ROW;
 valCol = DEFAULT_IMAGE_COLUMN;
 indPix = new ColorClass[valRow * valCol];

 for (int i = 0; i < valRow * valCol; i++)
 {
  indPix[i].setToBlack();
 }
}

bool ColorImageClass::checkRange(
 RowColumnClass &inRowCol
 )
{
 if (inRowCol.getRow() < MIN_RC_VALUE || inRowCol.getCol() < MIN_RC_VALUE)
 {
  return false;
 }
 else if (inRowCol.getRow() > valRow || inRowCol.getCol() > valCol)
 {
  return false;
 }
 else
 {
  return true;
 }
}

void ColorImageClass::initializeTo(
 ColorClass &inColor
 )
{
 for (int i = 0; i < valRow; i++)
 {
  for (int j = 0; j < valCol; j++)
  {
  	oneDindex = i * valCol + j;
   indPix[oneDindex].setTo(inColor);
  }
 }
}

bool ColorImageClass::addImageTo(
 ColorImageClass &rhsImg
 )
{
 ColorClass outColor;
 RowColumnClass inRowCol;
 bool isClip = false;//To check if RGB values is clipped.
 for (int i = 0; i < valRow; i++)
 {
  for (int j = 0; j < valCol; j++)
  {
   inRowCol.setRow(i);
   inRowCol.setCol(j);
   //Pass rhsImg's RGB values to outColor.
   rhsImg.getColorAtLocation(inRowCol, outColor);
   oneDindex = i * valCol + j;
   if (indPix[oneDindex].addColor(outColor))
   {
    isClip = true;
   }
  }
 }
 return isClip;  
}

bool ColorImageClass::addImages(
 int numImgsToAdd,
 ColorImageClass imagesToAdd []
 )
{
 bool isClip = false;//To check if RGB values is clipped.
 ColorClass outColor;
 RowColumnClass inRowCol;
 for (int i = 1; i < numImgsToAdd; i++)
 {
  //Add all images in imagesToAdd to imagesToAdd[0]. 
  if (imagesToAdd[0].addImageTo(imagesToAdd[i]))
  {
   isClip = true;
  }
 }
 for (int j = 0; j < valRow; j++)
 {
  for (int k = 0; k < valCol; k++)
  {
   inRowCol.setRow(j);
   inRowCol.setCol(k);
   oneDindex = j * valCol + k;
   //Pass imagesToAdd's RGB values to inPix[j][k].
   imagesToAdd[0].getColorAtLocation(inRowCol, indPix[oneDindex]);
  }
 }
 return isClip;
}

bool ColorImageClass::setColorAtLocation(
 RowColumnClass &inRowCol,
 ColorClass &inColor
 )
{
 if (checkRange(inRowCol))
 {
 	oneDindex = inRowCol.getRow() * valCol + inRowCol.getCol();
  indPix[oneDindex].setTo(inColor);
  return true;
 }
 else
 {
  return false;
 }
}

bool ColorImageClass::getColorAtLocation(
 RowColumnClass &inRowCol,
 ColorClass &outColor
 )
{
 if (checkRange(inRowCol))
 {
 	oneDindex = inRowCol.getRow() * valCol + inRowCol.getCol();
  outColor.setTo(indPix[oneDindex]);
  return true;
 }
 else
 {
  return false;
 }
}

void ColorImageClass::printImage()
{
 for (int i = 0; i < valRow; i++)
 {
  for (int j = 0; j < valCol; j++)
  {
  	oneDindex = i * valCol + j;
   indPix[oneDindex].printComponentValues();
   if (j < valCol - 1)
   {
    cout << "--";
   }
  }
  cout << endl;
 }
}

bool ColorImageClass::setImagePixel(
 int inRow, int inCol, ColorClass compareColor,
 ColorImageClass &insertImage
 )
{
 ColorClass outColor;
 RowColumnClass inRowCol;
 bool isSuccess;

 for (int i = inRow; i < inRow + insertImage.valRow; i++)
 {
  for (int j = inCol; j < inCol + insertImage.valCol; j++)
  {
   inRowCol.setRowCol(i - inRow, j - inCol); //Position of inserted image
   isSuccess = insertImage.getColorAtLocation(inRowCol, outColor);

   if (!isSuccess)
   {
    cout << "Inserted image size out of range at Row: " 
    << i << " and Column: " << j << "." << endl;
    return false;
   }

   if (!outColor.compareColor(compareColor))
   {
    oneDindex = i * valCol + j;
    indPix[oneDindex].setTo(outColor);
   }
  }
 }
 return true; 
}

bool ColorImageClass::insertImage()
{
 ColorImageClass insertImage;
 ColorClass compareColor;
 RowColumnClass inRowCol;
 string insertFileName;
 int transparentColor;
 bool isSuccess;
 int insertRow;
 int insertCol;

 cout << "Enter string for file name of PPM image to insert: ";
 cin >> insertFileName;
 isSuccess = insertImage.readFromFile(insertFileName);

 if (isSuccess)
 {
  cout << "Enter upper left corner to insert image row and column: ";
  cin >> insertRow >> insertCol;
  ensureInputValid(insertRow, insertCol);

  chooseColor("Enter int for transparency color: ", transparentColor);

  if (transparentColor == RED_OPTION)
  {
   compareColor.setToRed();
   isSuccess = setImagePixel(
    insertRow, insertCol, compareColor, insertImage
    );   
  }
  if (transparentColor == GREEN_OPTION)
  {
   compareColor.setToGreen();
   isSuccess = setImagePixel(
    insertRow, insertCol, compareColor, insertImage
    );
  }
  if (transparentColor == BLUE_OPTION)
  {
   compareColor.setToBlue();
   isSuccess = setImagePixel(
    insertRow, insertCol, compareColor, insertImage
    );
  }
  if (transparentColor == BLACK_OPTION)
  {
   compareColor.setToBlack();
   isSuccess = setImagePixel(
    insertRow, insertCol, compareColor, insertImage
    );
  }
  if (transparentColor == WHITE_OPTION)
  {
   compareColor.setToWhite();
   isSuccess = setImagePixel(
    insertRow, insertCol, compareColor, insertImage
    );
  }
 }
 return isSuccess;
}

bool ColorImageClass::readFromFile(string &inFileName)
{
	ifstream inFile;
 string header = " ";
 bool isSuccess;
 int maxColor;
 int inRow;
 int inCol;

	inFile.open(inFileName.c_str());

 if (inFile.fail())
 {
  cout << "Unable to open input file!" << endl;
  return false;
 }

 while (!inFile.eof()) 
 {
  inFile >> header;
  if (header == "P3") 
  {
   inFile >> inCol >> inRow;
   if (inRow <= MIN_RC_VALUE || inCol <= MIN_RC_VALUE) 
   {
   	cout << "Row or column values of image are wrong." << endl;
   	return false;
   }
   inFile >> maxColor;

   if (maxColor != MAX_VALUE)
   {
    cout << "Invalid color range in this image." << endl;
    return false;
   }
   indPix = new ColorClass[inRow * inCol];
   valRow = inRow;
   valCol = inCol;

   for (int i = 0; i < inRow; i++) 
   {
   	for (int j = 0; j < inCol; j++)
   	{
   		oneDindex = i * inCol + j;
     isSuccess = indPix[oneDindex].readFromStream(inFile);
     if (!isSuccess)
     {
      cout << "ERROR at Row: " << i << " and column: " << j <<endl;
      return false;
     }
   	}
   }
  }
  else
  {
  	cout << "Error found when trying to read magic number - \
   expected P3 but found " << header << "." << endl;
  	return false;
  }
  inFile >> header; 
 }
 inFile.close();
 return true;
}

bool ColorImageClass::writeToFile(string &outFileName)
{
 ofstream outFile;
 string header = " ";
 int oneDindex;

 outFile.open(outFileName.c_str());

 if (outFile.fail())
 {
  cout << "Unable to create output file!" << endl;
  return false;
 }
 outFile << "P3" << endl;
 outFile << valCol << " " << valRow << endl;
 outFile << "255" << endl;
 for (int i = 0; i < valRow; i++)
 {
  for (int j = 0; j < valCol; j++)
  {
   oneDindex = i * valCol + j;
   indPix[oneDindex].writeToStream(outFile);
  }
  outFile << endl;
 }
 outFile.close();
 return true;
}

void ColorImageClass::deletePointers()
{
 delete [] indPix; 
}
