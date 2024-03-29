/* Experiment1.cpp defines the methods that measure the time required
 *  to append an item to a vector or list.
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 * Student name:
 * Date:
 */
 
 #include "Experiment1.h"

#include <vector>
#include <list>
#include <list>
#include <iomanip>     // setw()
using namespace std;

void Experiment1::run() {
	cout << "\n1a. Timing vector append operations using the average over " << REPS << " repetitions:"
	     << endl;
	     
	timeAppendToVectorOfSize(10);
	timeAppendToVectorOfSize(100);
	timeAppendToVectorOfSize(1000);
	timeAppendToVectorOfSize(10000);
	timeAppendToVectorOfSize(100000);
	timeAppendToVectorOfSize(1000000);

	timeRepeatedAppendUntilVectorIsSize(1000000);

	cout << "\n1b. Timing List append operations using the average over " << REPS << " repetitions:"
		 << endl;

	timeAppendToListOfSize(10);
	timeAppendToListOfSize(100);
	timeAppendToListOfSize(1000);
	timeAppendToListOfSize(10000);
	timeAppendToListOfSize(100000);
	timeAppendToListOfSize(1000000);

	timeRepeatedAppendUntilListIsSize(1000000);

	cout << "\nExperiment 1 complete." << endl;
}

void Experiment1::timeAppendToVectorOfSize(unsigned size) {
	cout << " -- time to append to a full vector of size "
	     << setw(8)
	     << size << ":\t" << flush;
	myTimer.reset();
	for (int i = 0; i < REPS; i++) {               // repeatedly...
		vector<int> v(size);                       // construct new size-n vector
		myTimer.start();                           // start timer
		v.push_back(i);                            // append an Item
		myTimer.stop();                            // stop timer
	}
	cout << fixed << showpoint << setprecision(9)  // compute average
	     << myTimer.getTotalTime() / REPS << " secs"
	     << endl;
}


void Experiment1::timeRepeatedAppendUntilVectorIsSize(unsigned maxSize) {
	cout << "\n ** average time to append "
	     << maxSize << " items to an initially empty vector: " << flush;
	myTimer.reset();
	vector<unsigned> v;                            // construct empty vector
	for (unsigned i = 0; i < maxSize; i++) {       // repeatedly ...
		myTimer.start();                           // start timer
		v.push_back(i);                            // append an Item
		myTimer.stop();                            // stop timer
	}
	cout << fixed << showpoint << setprecision(9)  // compute average
		 << myTimer.getTotalTime() / maxSize  << " secs"
	     << endl;
}

void Experiment1::timeAppendToListOfSize(unsigned size) {
	cout << " -- time to append to a full List of size "
		 << setw(8)
		 << size << ":\t" << flush;
	myTimer.reset();
	for (int i = 0; i < REPS; i++) {
		list<int> list1(size);
		myTimer.start();
		list1.push_back(i);
		myTimer.stop();
	}
	cout << fixed << showpoint << setprecision(9)  // compute average
		 << myTimer.getTotalTime() / REPS << " secs"
		 << endl;

}


void Experiment1::timeRepeatedAppendUntilListIsSize(unsigned maxSize) {
	cout << "\n ** average time to append "
		 << maxSize << " items to an initially empty List: " << flush;
	myTimer.reset();
	list<unsigned> list1;                            // construct empty list
	for (unsigned i = 0; i < maxSize; i++) {       // repeatedly ...
		myTimer.start();                           // start timer
		list1.push_back(i);                            // append an Item
		myTimer.stop();                            // stop timer
		}
	cout << fixed << showpoint << setprecision(9)  // compute average
		 << myTimer.getTotalTime() / maxSize  << " secs"
		 << endl;}


