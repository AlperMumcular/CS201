/*
 *      Author: Alper Mumcular
 *		ID No: 21902740
 */
#include <iostream>
#include <cstddef>     
#include "ReservationList.h"     
using namespace std;

ReservationList::ReservationList(): size(0), head(NULL){
}

ReservationList::~ReservationList(){
   while (!isEmpty())
      remove(0);
} 

bool ReservationList::isEmpty() const{
   return size == 0;
} 

int ReservationList::getLength() const{
   return size;
}  

ReservationList::ReservationNode *ReservationList::find(int index) const{
   if ( (index < 1) || (index > getLength()) )
      return NULL;
   
   else{ 
      ReservationNode *cur = head;
      for (int skip = 1; skip < index; ++skip)
         cur = cur->next;
      return cur;
   }
}  

int ReservationList::retrieve(int index) const {

   if ((index < 1) || (index > getLength()))
      return -1;
   
   ReservationNode *cur = find(index);
   return cur->item;
} 

bool ReservationList::insert(int index, int newItem) {
	int newindex = index + 1;

   int newLength = getLength() + 1;

   if ((newindex < 1) || (newindex > newLength))
      return false;

   ReservationNode *newPtr = new ReservationNode;
   size = newLength;
   newPtr->item = newItem;

   if (newindex == 1){
      newPtr->next = head;
      head = newPtr;
   }
   else{
      ReservationNode *prev = find(newindex-1);
      newPtr->next = prev->next;
      prev->next = newPtr;
   }
   return true;

} 

bool ReservationList::remove(int index) {
	int newindex = index + 1;
   ReservationNode *cur;

   if ((newindex < 1) || (newindex > getLength()))
      return false;

   --size;
   if (newindex == 1){
      cur = head;  
      head = head->next;
   }
   else{
      ReservationNode *prev = find(newindex-1);
      cur = prev->next;
      prev->next = cur->next;
   }
   /*
   cur->next = NULL;
   delete cur;
   cur = NULL;
   */
   return true;

} 






