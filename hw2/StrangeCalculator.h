/*
 *      Author: Alper Mumcular
 *		ID No: 21902740
 */
#include <iostream>
#include <string>
using namespace std;
#ifndef STRANGECALCULATOR_H_
#define STRANGECALCULATOR_H_
	string infix2prefix( const string exp );
	double evaluatePrefix( const string exp );
	bool isBalancedInfix( const string exp );
	void evaluateInputPrefixExpression( );
	int precedence( char c );
#endif

