/*
 *      Author: Alper Mumcular
 *		ID No: 21902740
 */
#include <iostream>
#include <cstddef>    
#include "seatList.h"    
using namespace std;

seatList::seatList(): size(0), head(NULL){
}

seatList::~seatList(){
   while (!isEmpty()) {
	  remove(1); 
	}
} 

bool seatList::isEmpty() const{
   return size == 0;
}  

int seatList::getLength() const{
   return size;
}  

seatList::seatNode *seatList::find(int index) const{
   if ( (index < 1) || (index > getLength()) )
      return NULL;
   
   else{
      seatNode *cur = head;
      for (int skip = 1; skip < index; ++skip)
         cur = cur->next;
      return cur;
   }
}  

int seatList::retrieve(int index, int seatindex) const {

   if ((index < 1) || (index > getLength()))
      return -1;
   
   seatNode *cur = find(index);
   return (cur->seats).retrieve(seatindex);
} 

bool seatList::insert(int index, int newItem) {

   int newLength = getLength() + 1;

   if ((index < 1) || (index > newLength))
      return false;

   seatNode *newPtr = new seatNode;
   size = newLength;
   newPtr->item = newItem;
   //+++
	newPtr->seats = IntList();
	for(int i = 1; i <= newItem; i++){
		(newPtr->seats).insert(i, 0);
	}
	
   if (index == 1){
      newPtr->next = head;
      head = newPtr;
   }
   else{
      seatNode *prev = find(index-1);
      newPtr->next = prev->next;
      prev->next = newPtr;
   }
   return true;

} 

// reservation
bool seatList::insert(int index, int seatindex, int newItem) {
	
	int newLength = getLength() + 1;

   if ((index < 1) || (index > newLength))
      return false;

   seatNode *newPtr = find(index);
   //+++
    (newPtr->seats).remove(seatindex);
	(newPtr->seats).insert(seatindex, newItem);
	
   return true;
}	

bool seatList::remove(int index) {

   seatNode *cur;

   if ((index < 1) || (index > getLength()))
      return false;

   --size;
   if (index == 1){
      cur = head;  
      head = head->next;
   }
   else{
      seatNode *prev = find(index-1);
      cur = prev->next;
      prev->next = cur->next;
   }
   (cur->seats).~IntList();
   cur->next = NULL;
   delete cur;
   cur = NULL;
   
   return true;

} 






