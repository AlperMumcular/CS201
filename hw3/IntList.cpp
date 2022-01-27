/*
 *      Author: Alper Mumcular
 *		ID No: 21902740
 */
#include <iostream>
#include <cstddef>    
#include "IntList.h"     
using namespace std;

IntList::IntList(): size(0), head(NULL){
}

IntList::~IntList(){
   while (!isEmpty())
      remove(1);
} 

bool IntList::isEmpty() const{
   return size == 0;
}  

int IntList::getLength() const{
   return size;
}  

IntList::IntNode *IntList::find(int index) const{
   if ( (index < 1) || (index > getLength()) )
      return NULL;
   
   else{ 
      IntNode *cur = head;
      for (int skip = 1; skip < index; ++skip)
         cur = cur->next;
      return cur;
   }
}  

int IntList::retrieve(int index) const {

   if ((index < 1) || (index > getLength()))
      return -1;
   
   IntNode *cur = find(index);
   return cur->item;
} 

bool IntList::insert(int index, int newItem) {

   int newLength = getLength() + 1;

   if ((index < 1) || (index > newLength))
      return false;

   IntNode *newPtr = new IntNode;
   size = newLength;
   newPtr->item = newItem;

   if (index == 1){
      newPtr->next = head;
      head = newPtr;
   }
   else{
      IntNode *prev = find(index-1);
      newPtr->next = prev->next;
      prev->next = newPtr;
   }
   return true;

} 

bool IntList::remove(int index) {

   IntNode *cur;

   if ((index < 1) || (index > getLength()))
      return false;

   --size;
   if (index == 1){
      cur = head;  
      head = head->next;
   }
   else{
      IntNode *prev = find(index-1);
      cur = prev->next;
      prev->next = cur->next;
   }
   cur->next = NULL;
   delete cur;
   cur = NULL;
   
   return true;

}  






