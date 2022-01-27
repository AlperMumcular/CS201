#include "List.h"
#include "Movie.h"
#include <iostream>
#include "MovieBookingSystem.h"
using namespace std;

MovieBookingSystem::MovieBookingSystem(){
	reservationCodes = ReservationList();
	movies = List();
}

void MovieBookingSystem::addMovie(const long movieID, const int audienceRadius){
	if( audienceRadius < 0 || audienceRadius > 7){
		cout << "Invalid Radius." << endl;
		return;
	}
	
	Movie tmp;
	for(int i = 1; i < movies.getLength(); i++){
		if( movies.retrieve(i, tmp) ) {
			if( tmp.getID() == movieID ) {
				cout << "Movie at ";
				tmp.getName();
				cout << " already exists" << endl;
				return;
			}
		}
	}
	
	tmp = Movie(movieID, audienceRadius);
	if(movies.insert( movies.getLength() + 1, tmp ) ) {
		cout << "Movie at ";
		tmp.getName();
		cout << " has been added" << endl;
	}
}

void MovieBookingSystem::cancelMovie(const long movieID){
	Movie tmp;
	for(int i = 1; i < movies.getLength(); i++){
		if( movies.retrieve(i, tmp) ) {
			if( tmp.getID() == movieID ) {
				if(movies.remove(i) ){
					cout << "Movie at ";
					tmp.getName();
					cout << " has been canceled" << endl;
					return;
				}
			}
		}
	}
	tmp = Movie(movieID, 5);
	cout << "Movie at ";
	tmp.getName();
	cout << " does not exist" << endl;
}

void MovieBookingSystem::showAllMovies() const{
	if( movies.isEmpty() ){
		cout << "No movie on show" << endl;
		return;
	}
	else{
		cout << "Movies on show:" << endl;
		
		Movie tmp;
		for(int i = 1; i < movies.getLength(); i++){
			if( movies.retrieve(i, tmp) ){
				cout << "Movie at ";
				tmp.getName();
				cout << " (" << tmp.getAvailableSeats() << " available seats)" << endl;
			}
		}
	}
}
