#include "List.h"
#include "ReservationList.h"
#ifndef MOVIEBOOKINGSYSTEM_H_
#define MOVIEBOOKINGSYSTEM_H_
class MovieBookingSystem{
public:
	const static int numOfRow = 30;
	const static int numOfColumn = 26;
	MovieBookingSystem();
	~MovieBookingSystem();
	void addMovie( const long movieID, const int audienceRadius );
	void cancelMovie( const long movieID);
	void showAllMovies() const;
	void showMovie( const long movieID) const;
	int makeReservation( const long movieID, const int row, const char col);
	void cancelReservations( ReservationList resCode);
	void showReservation( const int resCode) const;
private:
	ReservationList reservationCodes;
	List movies;	
};
#endif 
