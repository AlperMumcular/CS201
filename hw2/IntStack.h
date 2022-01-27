/*
 *      Author: Alper Mumcular
 *		ID No: 21902740
 */
 
 //taken from slides
typedef double IntStackItemType;

class IntStack{

public:
   IntStack();
   IntStack(const IntStack& aIntStack);
   ~IntStack();

   bool isEmpty() const;
   bool push(IntStackItemType newItem);
   bool pop();
   bool pop(IntStackItemType& IntStackTop);
   bool getTop(IntStackItemType& IntStackTop) const;

private:
   struct IntStackNode {            
      IntStackItemType item;        
      IntStackNode    *next;        
   };

   IntStackNode *topPtr;     
};
