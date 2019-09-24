/* Stack.cpp defines the dynamically allocated (array-based ) Stack operations.
 * Joel Adams, for CS 112 at Calvin College.
 * Student Name: Nana Osei Asiedu Yirenkyi
 * Date: 10/30/2018
 */

#include "Stack.h"

/* explicit-value constructor
 * Parameter: capacity, an unsigned value.
 * Precondition: capacity > 0.
 * Postcondition: mySize == 0 && myCapacity == capacity
 *              && myArray contains the address of a dynamic array of 'capacity' entries.
 */
Stack::Stack(unsigned capacity) {
	if (capacity <= 0) {
		throw StackException("Stack(capacity)", "capacity must be positive!");
	}
	mySize = 0;
    myCapacity = capacity;
    myArray = new Item[capacity];
}

/* copy constructor
 * Parameter: original, a Stack (const reference).
 * Postcondition: I am a copy of original.
 */
Stack::Stack(const Stack& original) {
	makeCopyOf(original);
}

/* utility method containing code refactored from
 *  the copy constructor and operator=.
 * Parameter: original, a Stack (const reference).
 * Precondition: original.myCapacity > 0.
 * Postcondition: I am a copy of original.
 */
void Stack::makeCopyOf(const Stack& original) {
	myCapacity = original.myCapacity;
	myArray = new Item[myCapacity];

	for (unsigned i = 0; i < myCapacity; i++) {
		myArray[i] = original.myArray[i];
	}
	mySize = original.mySize;
}

/* destructor
 * Postcondition: myCapacity == 0 && mySize == 0
 *             && myArray has been deallocated.
 */
Stack::~Stack() {
	delete [] myArray;
	myArray = NULL;
	myCapacity = 0;
	mySize = 0;
}

/* assignment operator
 * Parameter: original, a Stack (const reference).
 * Postcondition: I am a copy of original
 *              && I have been returned.
 */
Stack& Stack::operator=(const Stack& original) {
	if (this != &original) {
		delete [] myArray;
		makeCopyOf(original);
	}
	return *this;
}

/* Is Empty method that returns true if the stack is empty
 * Precondition: I am a empty
 */
bool Stack::isEmpty() {
	if (mySize > 0) {return false;}
	return true;
}

/* Is Full method that returns true if the stack is full
 * Precondition: I am a full
 */
bool Stack::isFull() {
	if (mySize == myCapacity) {return true;}
	return false;
}

/*PeekTop method
 * Postcondition: value of the top most item of stack
 */
Item Stack::peekTop() const {
	if ( mySize <= 0 ) {
		throw StackException("peekTop()", "stack is empty");
	}
	return myArray[mySize-1];
   }


/*Push method
 *Parameter: an Item
 *PostCondition: a stack with a new item if there is space
 */
void Stack::push(const Item& it) {
	if ( isFull() ) {
		throw StackException("push()", "stack is full");
	}
	myArray[mySize] = it;
	mySize++;
   }

/*Pop method
 * PostCondition: removes and returns the top item from the Stack.
 */
Item Stack::pop() {
	if ( isEmpty() ) {
		throw StackException("pop()", "stack is empty");
	}
	mySize--; return myArray[mySize];
   }
