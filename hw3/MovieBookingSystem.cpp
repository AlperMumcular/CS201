/*
 *      Author: Alper Mumcular
 *		ID No: 21902740
 */
#include "seatList.h"
#include "IntList.h"
#include "ReservationList.h"
#include "NameList.h"
#include "MovieBookingSystem.h"
#include <ctime>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

MovieBookingSystem::MovieBookingSystem(){
	reservationCodes = ReservationList();
	seats = seatList();
	id = IntList();
	NoOfSeats = IntList();
	row = IntList();
	column = IntList();
	radius = IntList();
	names = NameList();
	available = IntList();
	code = 1;
}

MovieBookingSystem::~MovieBookingSystem(){
	reservationCodes.~ReservationList();
	seats.~seatList();
	id.~IntList();
	NoOfSeats.~IntList();
	row.~IntList();
	column.~IntList();
	radius.~IntList();
	names.~NameList();
	available.~IntList();
}

void MovieBookingSystem::addMovie(const long movieID, const int audienceRadius){
	if( audienceRadius < 0 || audienceRadius > 7){
		cout << "Invalid Radius." << endl;
		return;
	}
	
	if(!id.isEmpty()){
		for(int i = 1; i <= id.getLength(); i++){
			if( id.retrieve(i) == movieID ) {
				cout << "Movie at " << names.retrieve(i) << " already exists" << endl;
				return;
			}
		}
	}
	int rowcount, columncount, r, noofseat;
	r = audienceRadius;
	rowcount = 0;
	columncount = 0;
	for(int x = 1; x <= 30; x = x + (r + 1) ){
		rowcount++;
		if(x <= 26){
			columncount++;
		}
	}
	noofseat = (rowcount*columncount);
	 
	id.insert(id.getLength()+1, movieID);
	radius.insert(radius.getLength()+1, audienceRadius);
	row.insert(row.getLength()+1, rowcount);
	column.insert(column.getLength()+1, columncount);
	NoOfSeats.insert(NoOfSeats.getLength()+1, noofseat );
	available.insert(available.getLength()+1, noofseat);
	seats.insert(seats.getLength()+1, noofseat );
	
	// name
	time_t rawtime;
	rawtime = movieID;
	char* p;
	int len;
	p = ctime(&rawtime);		
	len = strlen(p);
	string str; 
	str = "";
	for(int i = 0; i < len - 1; i++){
		str += p[i];
	} 
 	names.insert(names.getLength()+1, str);
 	
	cout << "Movie at " << names.retrieve(names.getLength()) <<" has been added" << endl;
	return;
}

void MovieBookingSystem::cancelMovie(const long movieID){
	for(int i = 1; i < id.getLength(); i++){
			if( id.retrieve(i) == movieID ) {
				id.remove(i);
				radius.remove(i);
				row.remove(i);
				column.remove(i);
				NoOfSeats.remove(i);
				available.remove(i);
				seats.remove(i);
				cout << "Movie at " << names.retrieve(i) << " has been canceled" << endl;
				names.remove(i);
				return;
			}
	}
	// name
	time_t rawtime;
	rawtime = movieID;
	char* p;
	int len;
	p = ctime(&rawtime);		
	len = strlen(p);
	string str; 
	str = "";
	for(int i = 0; i < len - 1; i++){
		str += p[i];
	}	
	cout << "Movie at " << str << " does not exist" << endl;
}


void MovieBookingSystem::showAllMovies() const{
	if( id.isEmpty() ){
		cout << "No movie on show" << endl;
		return;
	}
	else{
		cout << "Movies on show:" << endl;
		
		for(int i = 1; i <= id.getLength(); i++){
			cout << "Movie at " << names.retrieve(i) << " (" << available.retrieve(i) << " available seats)" << endl;
		}
	}
}

void MovieBookingSystem::showMovie(const long movieID) const {
	for(int i = 1; i <= id.getLength(); i++){
		if( id.retrieve(i) == movieID ) {
			cout << "Movie at " << names.retrieve(i) << " has " << available.retrieve(i) << " available seats" << endl;
			cout << "    ";
			for(char c = 'A'; c <= 'Z'; c = c + radius.retrieve(i) + 1 ) {
				cout << c << " ";
			}
			cout << endl;
			int count = 0;
			for(int n = 1; n <= 30; n = n + radius.retrieve(i) + 1  ) {
				if(n < 10){
					cout << " " << n << "  ";
				}
				else {
					cout << n << "  ";
				} 
				for(int x = count * column.retrieve(i) + 1; x < (count + 1) * column.retrieve(i) + 1; x++){
					if( seats.retrieve(i, x) == 0 ) {
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
	}
} 

int MovieBookingSystem::makeReservation(const long movieID, const int roww, const char col){
	int i = 1;
	for(; i <= id.getLength(); i++){
		if( id.retrieve(i) == movieID ) {
			break;
		}
	}
	if(i == id.getLength() + 1 ) {
		cout << "This movie ID does not exist" << endl;
		return -1;
	}
	else{
		int rows = 0;
		int cols = 0;
		for(int x = 1; x <= 30; x = x + radius.retrieve(i) + 1 ){
			if(x == roww) {
				for(char c = 'A'; c <= 'Z'; c = c + radius.retrieve(i) + 1 ){
					if(c == col){
						if( seats.retrieve(i, ( column.retrieve(i) * rows ) + cols + 1 ) == 0 ) {
							seats.insert(i, ( column.retrieve(i) * rows ) + cols + 1 , code);
							available.insert(i, available.retrieve(i) - 1);
							available.remove(i+1);
							cout << "Reservation done for " << col << roww << " in Movie at " << names.retrieve(i) << endl;
							code++;
							return code - 1;
						}
						else {
							cout << "Seat " << col << roww << " is not available in Movie at " << names.retrieve(i) << endl;
							return -1;
						}
					}
					cols++;
				}
			}
			rows++;
		}
		cout << "Seat " << col << roww << " is not occupiable in Movie at " << names.retrieve(i) << endl;
		return -1;
	}
}


void MovieBookingSystem::cancelReservations(ReservationList resCode){
	int codes;
	int count = 0;
	for( int i = 1; i <= resCode.getLength(); i++ ) {
		codes = resCode.retrieve(i);
		for(int n = 1; n <= id.getLength(); n++){
			for(int x = 1; x <= NoOfSeats.retrieve(n); x++){
				if( seats.retrieve(n, x) == codes ) {
					count++;
					n = id.getLength() + 1;
					x = NoOfSeats.retrieve(n);
				}
			}
		}
	}
	if( count != resCode.getLength() ){
		cout << "Some reservation codes do not exist. Cancelation is failed" << endl;
		return;
	}
	else {
		int rowcount;
		char colcount;
		for( int i = 1; i <= resCode.getLength(); i++ ) {
			codes = resCode.retrieve(i);
			for(int n = 1; n <= id.getLength(); n++){
				for(int x = 0; x < NoOfSeats.retrieve(n); x++){
					if( seats.retrieve(n, x) == codes ) {
						seats.insert(n, x, 0);
						rowcount = 1 + ( ( x / column.retrieve(n) ) * ( radius.retrieve(n) + 1 )  ); 
						colcount = 'A';
						colcount = colcount + ( (x % column.retrieve(n) - 1 ) * ( radius.retrieve(n) + 1 )  );
						available.insert(n, available.retrieve(n) + 1);
						available.remove(n+1);
						cout << "Reservation on Code " << codes << " is canceled: Seat " << colcount << rowcount << " in Movie at " << names.retrieve(n) << endl;
						break;
					}
				}
			}
		}
	}
} 

void MovieBookingSystem::showReservation(const int resCode) const {
	int rowcount;
	char colcount;
	
	for(int i = 1; i <= id.getLength(); i++ ){
		for(int n = 1; n <= NoOfSeats.retrieve(i); n++){
			if( seats.retrieve(i, n) == resCode ) {
				rowcount = 1 + ( ( n / column.retrieve(i) ) * ( radius.retrieve(i) + 1 ) ); 
				colcount = 'A';
				colcount = colcount + ( (n % column.retrieve(i) - 1) * ( radius.retrieve(i) + 1 )  );
				cout << "Reservation with Code " << resCode << ": Seat " << colcount << rowcount << " in Movie at " << names.retrieve(i) << endl;
				return;
			}
		}
	}
	cout << "No reservation with Code " << resCode << endl;
}




