/* Matrix.cpp defines Matrix class methods.
 Student Name:Nana Osei Asiedu Yirenkyi
 * Date: Oct 2 2018
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#include "Matrix.h"
#include "MatrixTester.h"


//Default constructor
Matrix::Matrix() {
	myRows = myColumns = 0;
}

//Explicit Constructor
Matrix::Matrix(unsigned rows, unsigned columns) {
	myRows = rows;
	myColumns = columns;
	myVec.setSize(rows);
	for (unsigned i = 0; i < rows; i++) {
		myVec[i].setSize(columns);
	}
}


//Returns the number of Rows in the matrix
unsigned Matrix::getRows() const {
	return myRows;
}


//Returns the number of Rows in the matrix
unsigned Matrix::getColumns() const {
	return myColumns;
}


/* Subscript to retrieve value method for constant
 * 		reference values
 * @index: an unsigned int that must not be out
 * 			of range for myVec
 * Return: myVec[index]
 */
const Vec<Item>& Matrix::operator[](unsigned i) const {
	if (i >= myRows) {
		throw range_error("Bad Subscript");
	}
	return myVec[i];
}
/* Subscript to retrieve value method
 * @index: an unsigned int that must not be out
 * 			of range for myArray
 * Return: myVec[index]
 */
Vec<Item>& Matrix::operator[](unsigned i) {
	if (i >= myRows) {
		throw range_error("Bad Subscript");
	}
	return myVec[i];

}

//Assignment operator tests that left operand and m2 are equal
bool Matrix::operator==(const Matrix& m2) const {
      if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
           return false;
      } else {
           return myVec == m2.myVec;
      }
   }
