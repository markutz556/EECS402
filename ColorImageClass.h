#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_
#endif

#ifndef _COLORIMAGECLASS_H_
#define _COLORIMAGECLASS_H_

#include "ColorClass.h"
#include "RowColumnClass.h"
#include <fstream>
#include <string>

//project3
//Programmer: Shaocheng Wu
//Date: 10/28/2017
//Purpose: This class defines a collection of color pixel values 
//arranged in a rectangle as a color image.

class ColorImageClass
{
 private:
  //2D array of ColorClass objects to form a color image.
  ColorClass *indPix;
  //The one D index value for 2D array.
  int oneDindex;
  //The row value of an input image file.
  int valRow;
  //The column value of an input image file.
  int valCol;

 public:
  //Default constructor build an 2x2 image with black color.
  ColorImageClass(); 

  //To check if row or column value is within range of image
  //if not, then return false.
  bool checkRange(
   RowColumnClass &inRowCol
   );

  //Initialize all image pixels to the color provided via input.
  void initializeTo(
   ColorClass &inColor
   );
 
  //Each pixel in the image has the pixel in the corresponding 
  //location in input image added to it.
  //If pixel additions require RGB value clipping, return true.
  bool addImageTo(
   ColorImageClass &rhsImg
   );
  
  //Set the image's pixel values to the sum of the corresponding
  //pixels in each image in the imagesToAdd input parameter.
  //Return true if the RGB values need clipped.
  bool addImages(
   int numImgsToAdd,
   ColorImageClass imagesToAdd []
   );
  
  //If location in inRowCol is valid, set the pixel at the location 
  //to the color specified via the “inColor” parameter and return true.
  //Else, don't modify and return false. 
  bool setColorAtLocation(
   RowColumnClass &inRowCol,
   ColorClass &inColor
   );
  
  //If location in inRowCol is valid, returns true and the parameter 
  //"outColor" is assigned to the color of image pixel at that location.
  //Else, don't modify and return false. 
  bool getColorAtLocation(
   RowColumnClass &inRowCol,
   ColorClass &outColor
   );
  
  //Print the contents of the image to the screen using the 
  //ColorClass format.
  void printImage();

  //If the color at given image pixel is not the same as the compare
  //color, then set that image pixel to color at corresponding pixel in
  //inserted image.
  bool setImagePixel(
   int inRow, int inCol, ColorClass compareColor,
   ColorImageClass &insertImage
  );

  //Insert a PPM image to another image
  bool insertImage();

  //Reads an image from an input file.
  bool readFromFile(string &inFileName);

  //Write an image to an output file.
  bool writeToFile(string &outFileName);

  //Delete ColorImageClass pointers.
  void deletePointers();

};
#endif