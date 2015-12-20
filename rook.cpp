
#include "piece.h"
#include "rook.h"


#define DEBUG 0

Rook::Rook() : Piece(0, 0, 0, 5){

}

Rook::Rook(bool colr, int r, int c) : Piece(colr, r, c, 5) {
	name = new char[3];
	assert(name != NULL);
	strcpy(name, (colr? "WR" : "BR"));
	cout << name << endl;
	cout << (colr == 1? "White":"Black") << "Rook has been created at position (" << r << "," << c << ")" << endl;
}


bool Rook::checkMove(int r, int c, Piece *theBoard[8][8]){

	//takes in the proposed row and col of the new position
	//o/utputs true is valid and false if invalid
	
	
	//first checks if coordinates are within board, then it should check if it's within range,
	//then it should check if its occupied/nlocked
	cout << "checkMove for Rook called" << endl;
	
	// Check if coordinate is within board
	cout << "Check if the coordinates are within bound" << endl;
	if (r > 8 || r < 0 || c > 7 || c < 0){
		cout << "That coordinate is not even on the board" << endl;
		return false;
	}
	
	// rooks can only move down the col and row of its pos
	// one of r or c must equal to row or col
	
	cout << "Check the rows and cols" << endl;
	if (!(r == row ^ c == col)){
		cout << "The rook can only move along columns and rows" << endl;
		return false;
	}
	
	// to move to any position, that position must not be occupied by a peice of its own colour
	cout << "Check if occupied by own piece" << endl;
	
	
	if(theBoard[r][c] == NULL){
		;
	}else if (theBoard[r][c]->getColour() == colour){ // if its null, or empty, then you cant call getColour
		cout << "That position is occupied by your a piece on your team" << endl;
		return false;
	}
	
	// by passing all the earlier tests, this new position is "inline" and must blank, or occupied by an enemy
	// check that nothing is obstructing its path
	cout << "Check for obstructions" << endl;
	if (r == row){ // then check the cols in between
		for (int i = col + (c-col > 0? 1:-1); i != c; i+= (c-col > 0? 1:-1)){
			if (theBoard[row][i] != NULL){
				cout << "There is a piece obstructing the path of the rook" << endl;
				return false;
			}
		}
	}else if (c == col){ // check the rows in between
		for (int i = row + (r-row > 0? 1:-1); i != r; i+=(r-row > 0? 1:-1)){
			if (theBoard[i][col] != NULL){
				cout << "There is a piece obstructing the path of the rook" << endl;
				return false;
			}
		}
	}
	
	// check if it's moving there or capturing a piece
	cout << "Move is valid\n" << endl;
	return true;
	
	
}

void Rook::printName(){
	//cout << "I am a " << name << endl;
	cout << (colour == 1? "W":"B") << "R";
}

	 	
	
	
