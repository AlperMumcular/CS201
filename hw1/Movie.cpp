/*
 *      Author: Alper Mumcular
 *		ID No: 21902740
 */
#include <iostream>
#include "Movie.h"
#include <ctime>
#include <string.h>
using namespace std;
Movie::Movie(){
	
}

Movie::Movie(const int id, const int radius){
	row = 0;
	column = 0;
	for(int x = 1; x <= 30; x = x + (radius + 1) ){
		row++;
		if(x <= 26){
			column++;
		}
	} 
	movieID = id;
	NoOfSeats = row * column;
	r = radius;
	seats = new int [NoOfSeats];
	for(int i = 0; i < NoOfSeats; i++){
		*(seats + i) = 0;
	}
}

Movie::~Movie(){
	if(seats != NULL) {
		delete [] seats;
	}
}

int Movie::getID(){
	return movieID;
}

int Movie::getNoOfSeats(){
	return NoOfSeats;
}

int* Movie::getSeats(){
	return seats;
}

int Movie::getRow(){
	return row;
}

int Movie::getColumn(){
	return column;
}
int Movie::getRadius(){
	return r; 
}
int Movie::getAvailableSeats(){
	int count = 0;
	for(int i = 0; i < NoOfSeats; i++){
		if(seats[i] == 0){
			count++;
		}
	}
	return count;
}
void Movie::getSeatPlan(){
	cout << "Movie at ";
	this->getName();
	cout << " has " << this->getAvailableSeats() << " available seats" << endl;
	
	cout << "    ";
	for(char i = 'A'; i <= 'Z'; i = i + this->getRadius() + 1 ) {
		cout << i << " ";
	}
	cout << endl;
	int count = 0;
	for(int n = 1; n <= 30; n = n + this->getRadius() + 1  ) {
		if(n < 10){
			cout << " " << n << "  ";
		}
		else {
			cout << n << "  ";
		} 
		for(int x = count * this->getColumn(); x < (count + 1) * this->getColumn(); x++){
			if( *( this->getSeats() + x ) == 0 ) {
				cout << "o ";
			}
			else{
				cout << "x ";
			}	
		}
		count++;
		cout << endl;
	}
	cout << endl;	
}
void Movie::getName(){
	time_t rawtime;
	rawtime = this->getID();
	char* p;
	int len;
	p = ctime(&rawtime);		
	len = strlen(p);
	string str;
	str = "";
	for(int i = 0; i < len - 1; i++){
		str += p[i];
	}
	cout << str;
}

