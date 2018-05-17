#include <iostream>
#include <string>
using namespace std;

#include "constants.h"
#include "ColorClass.h"
#include "RowColumnClass.h"
#include "ColorImageClass.h"
#include "RectangleClass.h"
#include "PatternClass.h"
#include "ensureChoiceValid.h"
#include "ensureInputValid.h"
#include "chooseColor.h"

int main()
{
 string fname; 
 string outFileName;
 ColorImageClass inImage;
 RectangleClass inRectangle;
 PatternClass inPattern;
 RowColumnClass inRowCol;
 bool isSuccess;
 int userChoice = 0;
 int colorChoice;
 int fillOption;

 cout << "Enter string for PPM image file name to load: ";
 cin >> fname;
 
 isSuccess = inImage.readFromFile(fname);

 if (isSuccess)
 {
  while (userChoice != EXIT_OPTION)
  {
   cout << "1. Annotate image with rectangle" << endl;
   cout << "2. Annotate image with pattern from file" << endl;
   cout << "3. Insert another image" << endl;
   cout << "4. Write out current image" << endl;
   cout << "5. Exit the program" << endl;
  
   cout << "Enter int for main menu choice: ";
   cin >> userChoice;
   ensureChoiceValid(MAIN_MENU_SIZE, userChoice);

   if (userChoice == RECT_ANNOTATION_OPTION)
   {
    cout << "1. Specify upper left and lower right corners of rectangle" << endl;
    cout << "2. Specify upper left corner and dimensions of rectangle" << endl;
    cout << "3. Specify extent from center of rectangle" << endl;
   
    cout << "Enter int for rectangle specification method: ";
    cin >> userChoice;
    ensureChoiceValid(RECT_ANNOTATION_MENU_SIZE, userChoice);

    if (userChoice == UPPER_LEFT_LOWER_RIGHT_METHOD)
    {
     inRectangle.convertUpLeftLowRight();
     chooseColor("Enter int for rectangle color: ", colorChoice);

     cout << "1. NO" << endl;
     cout << "2. YES" << endl;
     cout << "Enter int for rectangle fill option: ";
     cin >> fillOption;
     ensureChoiceValid(RECT_FILL_MENU_SIZE, fillOption);

     isSuccess = inRectangle.fillRectangle(
      fillOption, colorChoice,
      inImage, inRowCol);
    }

    if (userChoice == UPPER_LEFT_DIMENSION_METHOD)
    {
     inRectangle.standardInput();
     chooseColor("Enter int for rectangle color: ", colorChoice);

     cout << "1. NO" << endl;
     cout << "2. YES" << endl;
     cout << "Enter int for rectangle fill option: ";
     cin >> fillOption;
     ensureChoiceValid(RECT_FILL_MENU_SIZE, fillOption);
   
     isSuccess = inRectangle.fillRectangle(
      fillOption, colorChoice,
      inImage, inRowCol);
    }

    if (userChoice == CENTER_METHOD)
    {
     inRectangle.convertCenterLoc();
     chooseColor("Enter int for rectangle color: ", colorChoice);

     cout << "1. NO" << endl;
     cout << "2. YES" << endl;
     cout << "Enter int for rectangle fill option: ";
     cin >> fillOption;
     ensureChoiceValid(RECT_FILL_MENU_SIZE, fillOption);

     isSuccess = inRectangle.fillRectangle(
      fillOption, colorChoice,
      inImage, inRowCol);
    }

    if (!isSuccess)
    {
     cout << "ERROR: Rectangle size out of range!" << endl;
    }
   }

   else if (userChoice == PATTERN_ANNOTATION_OPTION)
   {
    cout << "Enter string for file name containing pattern: ";
    cin >> fname;
  
    isSuccess = inPattern.readFromFile(fname);

    if (isSuccess)
    {
     inPattern.placePattern(inImage);
    }
   }

   else if (userChoice == IMAGE_INSERT_OPTION)
   {
    inImage.insertImage();
   }
   
   else if (userChoice == WRITE_OUT_OPTION)
   {
    cout << "Enter string for PPM file name to output: ";
    cin >> outFileName;

    inImage.writeToFile(outFileName);
   }

  }
  cout << "Thank you for using this program" << endl;
 }
  
 inImage.deletePointers();

 return 0;

}