/*
 *      Author: Alper Mumcular
 *		ID No: 21902740
 */
#include <string.h>
#ifndef MOVIE_H_
#define MOVIE_H_
class Movie {
public:
	Movie();
	Movie( const int id, const int radius );
	~Movie();
	int getID();
	int getNoOfSeats();
	int getRow();
	int getColumn();
	int getRadius();
	int* getSeats();
	int getAvailableSeats();
	void getSeatPlan();
	void getName();
private:
	int movieID, NoOfSeats, row, column, r;
	int* seats;
}; //end of class



#endif /* MOVIE_H_ */

