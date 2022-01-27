/*
 *      Author: Alper Mumcular
 *		ID No: 21902740
 */
#include <iostream>
using namespace std;
#ifndef INTLIST_H_
#define INTLIST_H_

class IntList {
public:
    IntList();
    ~IntList();
    bool isEmpty() const;
    int getLength() const;
    int retrieve(int index) const;
	bool insert(int index, int newItem);	
	bool remove(int index);
private:
   struct IntNode{      
      int item; 
      IntNode *next;    
   };
   int size;  
   IntNode *head;  
   IntNode *find(int index) const;
};
#endif 




