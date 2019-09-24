/* List.cpp
 * Name: Nana Osei Asiedu Yirenkyi
 * Date: Oct 9 2018
 * Lab05
 */

#include "List.h"
#include <iostream>;
#include <stdexcept>
using namespace std;

//Default List Constructor
List::List() {
	mySize = 0;
	myFirst = myLast = NULL;
}


//Explicit List Constructor
List::Node::Node() {
	myItem = 0;
	myNext = NULL;
  }


//Default Node Constructor
List::Node::Node(Item it, Node* next){
	myItem = it;
	myNext = next;
}


//Adds an item to the end of the list
void List::append(Item it){
	Node* nodePtr = new Node(it, NULL);
	if (mySize == 0) {
		myFirst = nodePtr;
	}
	else { myLast -> myNext = nodePtr;

	}
	myLast = nodePtr;
	mySize ++;
}


//Acceses and returns the size of the list
unsigned List::getSize() const {
	return mySize;
}


//Acceses and returns the first Item in the first node
Item List::getFirst() const{
	if (mySize < 0 || myFirst == NULL) {
		throw underflow_error("Size of list is too small.");
	}
	return myFirst -> myItem;
}


//Acceses and returns the last Item in the last node
Item List::getLast() const {
	if (mySize < 0 || myFirst == NULL) {
		throw underflow_error("Size of list is too small.");
	}
	return myLast -> myItem;
}


//List Destructor
List::~List() {
     delete myFirst;          // delete first node, invoking ~Node() (does nothing if myFirst == NULL)
     myFirst = myLast = NULL; // clear myFirst and myLast (optional)
     mySize = 0;              // clear mySize (optional)
}


//Node Destructor
List::Node::~Node() {
//	cout << "~Node() is deallocating the node containing item "
//			<< myItem << endl;
	delete myNext;       // delete the next node, invoking ~Node() in it
                           // (does nothing if myNext == NULL)
   }


//Copy Method that makes a copy of a List
void List::makeCopyOf(const List& original) {
	myFirst = myLast = NULL; //  set pointers
	mySize = 0; //   and size to 'empty' values
	Node* oPtr = original.myFirst; //  start at the first node
	while (oPtr != NULL) {
		//  while there are nodes to copy:
		append(oPtr->myItem); //   append the item in that node
		oPtr = oPtr->myNext; //   advance to next node
	}
}


//List copy constructor that makes use of copy method
List::List(const List& original) {
	makeCopyOf(original);
   }


// Assignment operator assigns the left hand side of  operand to the right hand side
List& List::operator=(const List& original) {
	if (this != &original) {
		delete myFirst;
		makeCopyOf(original);
	}
	return *this;
   }
