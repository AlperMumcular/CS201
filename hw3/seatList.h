/*
 *      Author: Alper Mumcular
 *		ID No: 21902740
 */
#include <iostream>
#include "IntList.h"
using namespace std;
#ifndef SEATLIST_H_
#define SEATLIST_H_

class seatList {
public:
    seatList();
    ~seatList();
    bool isEmpty() const;
    int getLength() const;
    int retrieve(int index, int seatindex) const;
	bool insert(int index, int newItem);
	bool insert(int index, int seatindex, int newItem);	
	bool remove(int index);
private:
   struct seatNode{     
      int item; 
      seatNode *next;    
      IntList seats;
   };
   int size;  
   seatNode *head;  
   seatNode *find(int index) const;
};
#endif 




