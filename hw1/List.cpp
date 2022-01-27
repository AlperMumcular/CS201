/*
 *      Author: Alper Mumcular
 *		ID No: 21902740
 */
#include <iostream>
#include <cstddef>     // for NULL
#include "List.h"     // header file
using namespace std;

List::List(): size(0), head(NULL){

}

List::~List(){

   while (!isEmpty())
      remove(1);

} // end destructor

bool List::isEmpty() const{

   return size == 0;

}  // end isEmpty

int List::getLength() const{

   return size;

}  // end getLength

List::MovieNode *List::find(int index) const{
// Locates a specified node in a linked list.
// Precondition: index is the number of the
// desired node.
// Postcondition: Returns a pointer to the 
// desired node. If index < 1 or index > the 
// number of nodes in the list, returns NULL.

   if ( (index < 1) || (index > getLength()) )
      return NULL;
   
   else{ // count from the beginning of the list
      MovieNode *cur = head;
      for (int skip = 1; skip < index; ++skip)
         cur = cur->next;
      return cur;
   }
}  // end find

bool List::retrieve(int index,
           Movie& dataItem) const {

   if ((index < 1) || (index > getLength()))
      return false;
   
   // get pointer to node, then data in node
   MovieNode *cur = find(index);
   dataItem = cur->item;

   return true;

} // end retrieve

bool List::insert(int index, Movie newItem) {

   int newLength = getLength() + 1;

   if ((index < 1) || (index > newLength))
      return false;

   MovieNode *newPtr = new MovieNode;
   size = newLength;
   newPtr->item = newItem;

   if (index == 1){
      newPtr->next = head;
      head = newPtr;
   }
   else{
      MovieNode *prev = find(index-1);
      newPtr->next = prev->next;
      prev->next = newPtr;
   }
   return true;

} // end insert

bool List::remove(int index) {

   MovieNode *cur;

   if ((index < 1) || (index > getLength()))
      return false;

   --size;
   if (index == 1){
      cur = head;  
      head = head->next;
   }
   else{
      MovieNode *prev = find(index-1);
      cur = prev->next;
      prev->next = cur->next;
   }
   cur->next = NULL;
   delete cur;
   cur = NULL;
   
   return true;

}  // end remove


