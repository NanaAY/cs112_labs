/* LinkedQueue.cpp defines the methods for class LinkedQueue.
 * Joel Adams, for CS 112 at Calvin College.
 * Student name:Nana Osei Asiedu Yirenkyi
 * Date: 11/13/2018
 */

#include "LinkedQueue.h"


//LinkedQueue::LinkedQueue(const LinkedQueue& original) {
//	makeCopyOf(original);
//}
//
//void LinkedQueue::makeCopyOf(const LinkedQueue& original) {
//	mySize = original.mySize;
//	if ( mySize == 0 ) {
//		myFirstPtr = myLastPtr = NULL;
//	} else {
//		myFirstPtr = new Node(original.getFirst(), NULL);
//		Node * temp0 = original.myFirstPtr->myNextPtr;
//		Node * temp1 = myFirstPtr;
//		while (temp0 != NULL) {
//			temp1->myNextPtr = new Node(temp0->myItem, NULL);
//			temp1 = temp1->myNextPtr;
//			temp0 = temp0->myNextPtr;
//		}
//		myLastPtr = temp1;
//	}
//}
//
//LinkedQueue::~LinkedQueue() {
//	delete myFirstPtr;
//	myFirstPtr = myLastPtr = NULL;
//	mySize = 0;
//}
//
//LinkedQueue& LinkedQueue::operator=(const LinkedQueue& aQueue) {
//	if (this != &aQueue) {
//		delete myFirstPtr;    // invokes recursive ~Node()
//		makeCopyOf(aQueue);
//	}
//	return *this;
//}
//
//
//
//bool LinkedQueue::isFull() const {
//	return false;
//}


