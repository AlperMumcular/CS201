/*
 *      Author: Alper Mumcular
 *		ID No: 21902740
 */
 
 //taken from slides
typedef char StackItemType;

class Stack{

public:
   Stack();
   Stack(const Stack& aStack);
   ~Stack();

   bool isEmpty() const;
   bool push(StackItemType newItem);
   bool pop();
   bool pop(StackItemType& stackTop);
   bool getTop(StackItemType& stackTop) const;

private:
   struct StackNode {           
      StackItemType item;        
      StackNode    *next;        
   };

   StackNode *topPtr;     
};


