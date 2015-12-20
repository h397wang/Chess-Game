
#include "Piece.h"


#include <assert.h>
#include <string.h>
#include <iostream>
using namespace std;



Knight::Knight(bool col, int r, int c) : Piece(col, r, c, 3){
	name = new char[3];
	assert(name != NULL);
	strcpy(name, (col? "WN" : "BN"));	
}

bool Knight::checkMove(int r, int c, Piece *b[8][8]){

	cout << "checkMove for Knight called" << endl;
	
	// Check if coordinate is within board
	cout << "Check if the coordinates are within bound" << endl;
	if (r > 8 || r < 0 || c > 7 || c < 0){
		cout << "That coordinate is not even on the board" << endl;
		return false;
	}	
	
	// check if it's a valid knight move
	if (!((abs(r-row) == 1 && abs(c-col) == 2) ^ (abs(r-row) == 2) && abs(c-col) == 1))){
		return false;
	}
	
	// check if the piece is a friendly unit
	if (b[r][c]->getColour == colour){
		return false;
	}
	
	return true;
	
}

void Knight::printName(){
	//cout << "I am a " << name << endl;
	cout << name;
}

