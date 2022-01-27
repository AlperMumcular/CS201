#include <iostream>
#include <cstddef>   
#include "IntStack.h"       
using namespace std;

IntStack::IntStack() : topPtr(NULL){

}


IntStack::IntStack(const IntStack& aIntStack){

   if (aIntStack.topPtr == NULL)
      topPtr = NULL;  

   else {
     
      topPtr = new IntStackNode;
      topPtr->item = aIntStack.topPtr->item;

     
      IntStackNode *newPtr = topPtr;
      for (IntStackNode *origPtr = aIntStack.topPtr->next;
                      origPtr != NULL;
                      origPtr = origPtr->next){
         newPtr->next = new IntStackNode;
         newPtr = newPtr->next;
         newPtr->item = origPtr->item;
      }
      newPtr->next = NULL;
   }
}


IntStack::~IntStack(){

  
   while (!isEmpty())
      pop();

}

bool IntStack::isEmpty() const {

   return topPtr == NULL;

}

bool IntStack::push(IntStackItemType newItem) {


   IntStackNode *newPtr = new IntStackNode;

 
   newPtr->item = newItem;

   
   newPtr->next = topPtr;
   topPtr = newPtr;

   return true;
}

/*
 *      Author: Alper Mumcular
 *		ID No: 21902740
 */
 
 //taken from slides
bool IntStack::pop() {

   if (isEmpty())
      return false;

  
   else{   
      IntStackNode *temp = topPtr;
      topPtr = topPtr->next;

      
      temp->next = NULL; 
      delete temp;
      return true;
   }
}

bool IntStack::pop(IntStackItemType& IntStackTop) {

   if (isEmpty())
      return false;

   
   else{
      IntStackTop = topPtr->item;
      IntStackNode *temp = topPtr;
      topPtr = topPtr->next;

      
      temp->next = NULL;  
      delete temp;
      return true;
   }
}

bool IntStack::getTop(IntStackItemType& IntStackTop) 
             const {

   if (isEmpty())
      return false;

  
   else {
      IntStackTop = topPtr->item;
      return true;
   }

}


