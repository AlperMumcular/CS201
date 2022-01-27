/*
 *      Author: Alper Mumcular
 *		ID No: 21902740
 */
#include <iostream>
#include <cstddef>     // for NULL
#include "ReservationList.h"     // header file
using namespace std;

ReservationList::ReservationList(): size(0), head(NULL){

}

ReservationList::~ReservationList(){

   while (!isEmpty())
      remove(1);

} // end destructor

bool ReservationList::isEmpty() const{

   return size == 0;

}  // end isEmpty

int ReservationList::getLength() const{

   return size;

}  // end getLength

ReservationList::ReservationNode *ReservationList::find(int index) const{
// Locates a specified node in a linked list.
// Precondition: index is the number of the
// desired node.
// Postcondition: Returns a pointer to the 
// desired node. If index < 1 or index > the 
// number of nodes in the list, returns NULL.

   if ( (index < 1) || (index > getLength()) )
      return NULL;
   
   else{ // count from the beginning of the list
      ReservationNode *cur = head;
      for (int skip = 1; skip < index; ++skip)
         cur = cur->next;
      return cur;
   }
}  // end find

bool ReservationList::retrieve(int index,
           int& dataItem) const {

   if ((index < 1) || (index > getLength()))
      return false;
   
   // get pointer to node, then data in node
   ReservationNode *cur = find(index);
   dataItem = cur->item;

   return true;

} // end retrieve

bool ReservationList::insert(int index, int newItem) {

   int newLength = getLength() + 1;

   if ((index < 1) || (index > newLength))
      return false;

   ReservationNode *newPtr = new ReservationNode;
   size = newLength;
   newPtr->item = newItem;

   if (index == 1){
      newPtr->next = head;
      head = newPtr;
   }
   else{
      ReservationNode *prev = find(index-1);
      newPtr->next = prev->next;
      prev->next = newPtr;
   }
   return true;

} // end insert

bool ReservationList::remove(int index) {

   ReservationNode *cur;

   if ((index < 1) || (index > getLength()))
      return false;

   --size;
   if (index == 1){
      cur = head;  
      head = head->next;
   }
   else{
      ReservationNode *prev = find(index-1);
      cur = prev->next;
      prev->next = cur->next;
   }
   cur->next = NULL;
   delete cur;
   cur = NULL;
   
   return true;

}  // end remove


