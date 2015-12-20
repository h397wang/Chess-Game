#include "bishop.h"




Bishop::Bishop(bool col, int r, int c) : Piece(col, r, c, 3){
	name = new char[3];
	assert(name != NULL);
	strcpy(name, (col? "WB" : "BB"));	
}

bool Bisohp::checkMove(int r, int c, Piece *b[8][8]){

	cout << "checkMove for " << name << " called" << endl;
	
	// Check if coordinate is within board
	cout << "Check if the coordinates are within bound" << endl;
	if (r > 8 || r < 0 || c > 7 || c < 0){
		cout << "That coordinate is not even on the board" << endl;
		return false;
	}	
	
	// check if it's a valid bishop move
	// bishops only move diagnal... so delta x == delta y
	if (r-row != c-col){
		return false;
	}
	
	// check for obstruction
	for (int i = row; i != r; i+= (r-row > 0? 1:-1)){
		for (int i = col; i != c; i+= (c-col > 0? 1:-1)){
			if (b[i][j] != NULL){
				return false;
			}
		}
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
