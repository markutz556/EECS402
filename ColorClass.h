#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_
#endif

#ifndef _COLORCLASS_H_
#define _COLORCLASS_H_

#include <fstream>

//project3
//Programmer: Shaocheng Wu
//Date: 10/28/2017
//Purpose: This class describes a color with the information 
//of RGB values, which are within range 0-255.

class ColorClass
{
 private:
  int valRed; //the value of red color
  int valGreen; //the value of green color
  int valBlue; //the value of blue color
  
  //To check if a RGB value needs to be clipped and 
  //if so, then clip the value and return true. Else return false.
  bool checkVal(int &valColor);

 public:
  //Default ctor sets RGB value to full white.
  ColorClass();

  //Value ctor sets the initial RGB values to values provided.
  ColorClass(
   int inRed,
   int inGreen,
   int inBlue
   );

  //Set color values to full black, red, green, blue or white.
  void setToBlack();
  void setToRed(); 
  void setToGreen();
  void setToBlue();
  void setToWhite();

  //Set the color's RGB values to the provided values.
  //If clipped, return true. Else return false.
  bool setTo(
   int inRed,
   int inGreen,
   int inBlue
   );
  
  //Set the color's RGB values the same as in the "inColor".
  //If clipped, return true. Else return false.
  bool setTo(
   ColorClass &inColor
   );
 
  //Add RGB values and those in the input parameter color.
  //If clipped, return true. Else return false.
  bool addColor(
   ColorClass &rhs
   );
  
  //Subtract the RGB value from the input from each RGB value.
  //If clipped, return true. Else return false.
  bool substractColor(
   ColorClass &rhs
   );
  
  //Multiplie RGB values by provided factor to make adjustment.
  //If clipped, return true. Else return false.
  bool adjustBrightness(
   double adjFactor
   );

  //Compare two ColorClass to see if they have same RGB values.
  //If same, return true and else return false.
  bool compareColor(
   ColorClass outColor
   );

  //Read color from an input file.
  bool readFromStream(ifstream &inFile);

  //Write color to an output file.
  void writeToStream(ofstream &outFile);

  //Print the component color values to the console.
  void printComponentValues();
};
#endif