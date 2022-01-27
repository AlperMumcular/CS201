/*
 *      Author: Alper Mumcular
 *		ID No: 21902740
 */
#include "Movie.h"
#include <iostream>
using namespace std;
#ifndef LIST_H_
#define LIST_H_

class List {
public:
    List();
    ~List();
    bool isEmpty() const;
    int getLength() const;
    bool retrieve(int index, Movie& dataItem) const;
	bool insert(int index, Movie newItem);	
	bool remove(int index);
private:

   struct MovieNode{      // a node on the list
      Movie item; // a data item on the list
      MovieNode *next;    // pointer to next node
   };


   int       size;  // number of items in list
   MovieNode *head;  // pointer to linked list 
				    // of items


   MovieNode *find(int index) const;
   // Returns a pointer to the index-th node
   // in the linked list
};
#endif 

