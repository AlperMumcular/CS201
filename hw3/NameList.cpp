/*
 *      Author: Alper Mumcular
 *		ID No: 21902740
 */
#include <iostream>
#include <string>
#include <cstddef>     
#include "NameList.h"     
using namespace std;

NameList::NameList(): size(0), head(NULL){
}

NameList::~NameList(){
   while (!isEmpty())
      remove(1);
} 

bool NameList::isEmpty() const{
   return size == 0;
}  

int NameList::getLength() const{
   return size;
}  

NameList::NameNode *NameList::find(int index) const{
   if ( (index < 1) || (index > getLength()) )
      return NULL;
   
   else{ 
      NameNode *cur = head;
      for (int skip = 1; skip < index; ++skip)
         cur = cur->next;
      return cur;
   }
}  

string NameList::retrieve(int index) const {

   if ((index < 1) || (index > getLength()))
      return "";

   NameNode *cur = find(index);
   return cur->item;
} 

bool NameList::insert(int index, string newItem) {

   int newLength = getLength() + 1;

   if ((index < 1) || (index > newLength))
      return false;

   NameNode *newPtr = new NameNode;
   size = newLength;
   newPtr->item = newItem;

   if (index == 1){
      newPtr->next = head;
      head = newPtr;
   }
   else{
      NameNode *prev = find(index-1);
      newPtr->next = prev->next;
      prev->next = newPtr;
   }
   return true;

}

bool NameList::remove(int index) {

   NameNode *cur;

   if ((index < 1) || (index > getLength()))
      return false;

   --size;
   if (index == 1){
      cur = head;  
      head = head->next;
   }
   else{
      NameNode *prev = find(index-1);
      cur = prev->next;
      prev->next = cur->next;
   }
   cur->next = NULL;
   delete cur;
   cur = NULL;
   
   return true;

} 






