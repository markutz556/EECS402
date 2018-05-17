#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_
#endif

#ifndef _ROWCOLUMNCLASS_H_
#define _ROWCOLUMNCLASS_H_

//project3
//Programmer: Shaocheng Wu
//Date: 10/28/2017
//Purpose: This class identifies a pixel within an image 
//with index values.

class RowColumnClass
{
 private:
  int valRow; //the value of row index
  int valCol; //the value of column index

 public:
  //Default ctor set the row and column value to default value.
  RowColumnClass();
  
  //Value ctor set row and column values to the provided values.
  RowColumnClass(
   int inRow,
   int inCol
   );
  
  //Set row and column values to the values provided.
  void setRowCol(
   int inRow,
   int inCol
   );
  
  //Set the row value to the value provided.
  void setRow(
   int inRow
   );
  
  //Set the column value to the value provided.
  void setCol(
   int inCol
   );
  
  //Return the row value to the caller.
  int getRow();
  
  //Return the column value to the caller.
  int getCol();
  
  //Add row and column values in the input parameter 
  //to those of the object the function is called on.
  void addRowColTo(
   RowColumnClass &inRowCol
   );
  
  //Print this object's attributes in special format.
  void printRowCol();
};
#endif