/*
 *      Author: Alper Mumcular
 *		ID No: 21902740
 */
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
    int retrieve(int index) const;
	bool insert(int index, int newItem);	
	bool remove(int index);
private:
   struct ReservationNode{      
      int item; 
      ReservationNode *next;    
   };
   int size; 
   ReservationNode *head; 
   ReservationNode *find(int index) const;
};
#endif 




