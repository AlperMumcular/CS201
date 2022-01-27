/*
 *      Author: Alper Mumcular
 *		ID No: 21902740
 */
#include "Stack.h"
#include "IntStack.h"
#include "StrangeCalculator.h"
#include <string>
#include <iostream>   
using namespace std;

string infix2prefix( const string exp ){
	Stack myStack;
	string tmp = "";
	string reverseResult = "";
	string result = "";
	char chr;
	char popped;
	for(int n = exp.length()-1; n >= 0; n--){
		if( exp.at(n) == '(' || exp.at(n) == ')' ) {
			if( exp.at(n) == '(' )
				tmp = tmp + ")";
			else
				tmp = tmp + "(";
		}
		else 
			tmp = tmp + exp.at(n);
	}
	
	for(int i=0; i<tmp.length();i++){
		if(tmp.at(i)>= '1' && tmp.at(i) <= '9'){
			reverseResult = reverseResult + tmp.at(i);
		}
		else if(tmp.at(i)=='('){
			myStack.push(tmp.at(i));
		}
		else if(tmp.at(i)==')'){ 
			myStack.pop(popped);
			while( !myStack.isEmpty() && popped != '('){
				reverseResult = reverseResult + popped;
				myStack.pop(popped);
			}
		}
		else if(tmp.at(i)=='+'||tmp.at(i)=='-'||tmp.at(i)=='*'||tmp.at(i)=='/'){ 
			if(myStack.isEmpty()){ 
				myStack.push(tmp.at(i));
			}
			else if( !myStack.isEmpty() ){ 
				myStack.getTop(chr);
				if(precedence(tmp.at(i)) > precedence(chr) ){
					myStack.push(tmp.at(i));
				}
				else if(precedence(tmp.at(i)) == precedence(chr)){
					myStack.push(tmp.at(i));
				}
				else{
					while(!myStack.isEmpty() && precedence(tmp.at(i)) <= precedence(chr)){
						myStack.pop(popped);
						reverseResult = reverseResult + popped;
					}
					myStack.push(tmp.at(i));
				}
			}
		}
	}
	
	for(; !myStack.isEmpty(); ) {
		myStack.pop(chr);
		if( chr != '(' )
			reverseResult = reverseResult + chr;
	}
	
	for(int a = reverseResult.length()-1; a >= 0; a--){
		result = result + reverseResult.at(a);
	} 
	return result;
}

double evaluatePrefix( const string exp ){
	IntStack stack;
	double p1, p2;
	double n;
	for(int i = exp.length()-1; i >=0; i--){
		if(exp.at(i)>= '1' && exp.at(i) <= '9'){
			if(exp.at(i)== '0'){
				stack.push(0);
			}
			else if(exp.at(i)== '1'){
				stack.push(1);
			}
			else if(exp.at(i)== '2'){
				stack.push(2);
			}
			else if(exp.at(i)== '3'){
				stack.push(3);
			}
			else if(exp.at(i)== '4'){
				stack.push(4);
			}
			else if(exp.at(i)== '5'){
				stack.push(5);
			}
			else if(exp.at(i)== '6'){
				stack.push(6);
			}
			else if(exp.at(i)== '7'){
				stack.push(7);
			}
			else if(exp.at(i)== '8'){
				stack.push(8);
			}
			else if(exp.at(i)== '9'){
				stack.push(9);
			}
		}
		else{
			if(exp.at(i)=='+'){
				stack.pop(p1);
				stack.pop(p2);
				n=p1+p2;
				stack.push( n );
			}
			else if(exp.at(i)=='-'){
				stack.pop(p1);
				stack.pop(p2);
				n=p1-p2;
				stack.push( n );
			}
			else if(exp.at(i)=='/'){
				stack.pop(p1);
				stack.pop(p2);
				n=p1/p2;
				stack.push( n );
			}
			else if(exp.at(i)=='*'){
				stack.pop(p1);
				stack.pop(p2);
				n=p1*p2;
				stack.push( n );
			}
		}
	}
	double result;
	stack.pop(result);
	return result;
}

bool isBalancedInfix( const string exp ){
	Stack myStack;
	bool balanced = true;
	int i = 0;
	char c;
	while(balanced && i < exp.length()){
		c = exp.at(i);
		i++;
		if(c == '(')
			myStack.push('(');
		else if(c == ')'){
			if(!myStack.isEmpty())
				myStack.pop();
			else
				balanced = false;
		}
	}
	if(balanced && myStack.isEmpty())
		return true;
	else 
		return false;	
}

void evaluateInputPrefixExpression(){
	string input, nospace;
	cout << "infix input:";
	getline( cin, input);
	for(int i = 0; i<input.length(); i++){
		if( input.at(i) == ' ' ){
		}
		else{
			nospace = nospace + input.at(i);
		}
	}
	if(isBalancedInfix(nospace)){		
		cout << "result of: " << nospace << " is: " << evaluatePrefix(infix2prefix(nospace));				
	}
	else{
		cout << "This input has unbalanced parantheses.";
	}
	
}

int precedence( char c ){
	if( c == '-' || c == '+' ) {
		return 1;
	}
	if( c == '/' || c == '*' ){
		return 2;
	}
	return 0;
}

