/*
 *      Author: Alper Mumcular
 *		ID No: 21902740
 */
#include <iostream>
#include <string>
using namespace std;
#ifndef NameLIST_H_
#define NameLIST_H_

class NameList {
public:
    NameList();
    ~NameList();
    bool isEmpty() const;
    int getLength() const;
    string retrieve(int index) const;
	bool insert(int index, string newItem);	
	bool remove(int index);
private:

   struct NameNode{   
      string item; 
      NameNode *next;   
   };
   int size;  
   NameNode *head;  
   NameNode *find(int index) const;
};
#endif 




