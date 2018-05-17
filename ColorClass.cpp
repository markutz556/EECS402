#include <iostream>
#include <fstream>
using namespace std;

#include "ColorClass.h"
#include "constants.h"

bool ColorClass::checkVal(int &valColor)
{
 if (valColor > MAX_VALUE)
 {
  valColor = MAX_VALUE;
  return true;
 } 
 else if (valColor < MIN_VALUE)
 {
  valColor = MIN_VALUE;
  return true;
 }
 else
 {
  return false;
 }
}

ColorClass::ColorClass()
{
 valRed = MAX_VALUE;
 valGreen = MAX_VALUE;
 valBlue = MAX_VALUE;
}

ColorClass::ColorClass(
 int inRed,
 int inGreen,
 int inBlue
 )
{
 setTo(inRed, inGreen, inBlue);
}

void ColorClass::setToBlack()
{
 valRed = MIN_VALUE;
 valGreen = MIN_VALUE;
 valBlue = MIN_VALUE;
}
void ColorClass::setToRed() 
{
 valRed = MAX_VALUE;
 valBlue = MIN_VALUE;
 valGreen = MIN_VALUE;
}
void ColorClass::setToGreen()
{
 valRed = MIN_VALUE;
 valBlue = MIN_VALUE;
 valGreen = MAX_VALUE;
}
void ColorClass::setToBlue()
{
 valRed = MIN_VALUE;
 valBlue = MAX_VALUE;
 valGreen = MIN_VALUE;
}
void ColorClass::setToWhite()
{
 valRed = MAX_VALUE;
 valBlue = MAX_VALUE;
 valGreen = MAX_VALUE;
}

bool ColorClass::setTo(
 int inRed,
 int inGreen,
 int inBlue
 )
{
 valRed = inRed;
 checkVal(valRed);
 valGreen = inGreen;
 checkVal(valGreen);
 valBlue = inBlue;
 checkVal(valBlue);
 return checkVal(valRed) || checkVal(valGreen) || checkVal(valBlue);
}

bool ColorClass::setTo(
 ColorClass &inColor
 )
{
 valRed = inColor.valRed;
 checkVal(valRed);
 valGreen = inColor.valGreen;
 checkVal(valGreen);
 valBlue = inColor.valBlue;
 checkVal(valBlue);
 return checkVal(valRed) || checkVal(valGreen) || checkVal(valBlue);
}

bool ColorClass::addColor(
 ColorClass &rhs
 )
{
 valRed = valRed + rhs.valRed;
 checkVal(valRed);
 valGreen = valGreen + rhs.valGreen;
 checkVal(valGreen);
 valBlue = valBlue + rhs.valBlue;
 checkVal(valBlue);
 return checkVal(valRed) || checkVal(valGreen) || checkVal(valBlue);
}

bool ColorClass::substractColor(
 ColorClass &rhs
 )
{
 valRed = valRed - rhs.valRed;
 checkVal(valRed);
 valGreen = valGreen - rhs.valGreen;
 checkVal(valGreen);
 valBlue = valBlue - rhs.valBlue;
 checkVal(valBlue);
 return checkVal(valRed) || checkVal(valGreen) || checkVal(valBlue);
}

bool ColorClass::adjustBrightness(
 double adjFactor
 )
{
 valRed = int(valRed * adjFactor);
 valGreen = int(valGreen * adjFactor);
 valBlue = int(valBlue * adjFactor);
 return setTo(valRed, valGreen, valBlue);
}

bool ColorClass::compareColor(ColorClass outColor)
{
 if (valRed == outColor.valRed &&
  valGreen == outColor.valGreen &&
  valBlue == outColor.valBlue
  )
 {
  return true;
 }
 return false;
}

bool ColorClass::readFromStream(ifstream &inFile)
{
	bool success = true;
 bool isInRange = true;
 int inRed;
 int inGreen;
 int inBlue;

 inFile >> inRed >> inGreen >> inBlue;
 //Error checking.
 if (inFile.fail()) 
 {
  cout << "ERROR: Invalid RGB values." << endl;
  success = false;
 }
 else if (checkVal(inRed) || checkVal(inGreen) || checkVal(inBlue))
 {
  cout << "RGB value out of range." << endl;
  isInRange = false;
 }
 else
 {
  valRed = inRed;
  valGreen = inGreen;
  valBlue = inBlue;
 }
 return success && isInRange;
}

void ColorClass::writeToStream(ofstream &outFile)
{
 outFile << valRed << " " << valGreen << " " << valBlue << " ";
}

void ColorClass::printComponentValues()
{
 cout << "R: " << valRed << " G: " << valGreen << " B: " << valBlue << " ";
}
