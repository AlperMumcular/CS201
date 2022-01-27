/*
 *      Author: Alper Mumcular
 *		ID No: 21902740
 */
#include "Movie.h"
#include <iostream>
using namespace std;
#ifndef RESERVATIONLIST_H_
#define RESERVATIONLIST_H_

class ReservationList {
public:
    ReservationList();
    ~ReservationList();
    bool isEmpty() const;
    int getLength() const;
    bool retrieve(int index, int& dataItem) const;
	bool insert(int index, int newItem);	
	bool remove(int index);
private:

   struct ReservationNode{      // a node on the list
      int item; // a data item on the list
      ReservationNode *next;    // pointer to next node
   };


   int       size;  // number of items in list
   ReservationNode *head;  // pointer to linked list 
				    // of items


   ReservationNode *find(int index) const;
   // Returns a pointer to the index-th node
   // in the linked list
};
#endif 
