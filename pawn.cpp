

#include "piece.h"
#include "pawn.h"

#include <assert.h>
#include <string.h>
#include <iostream>
using namespace std;


Pawn::Pawn(bool col, int r, int c) : Piece(col, r, c, 1){
	hasMoved = false; 
	promote = false;
	name = new char[3];
	assert(name != NULL);
	strcpy(name, (col? "WP" : "BP"));	
}

/*
bool Pawn::moveTo(int r, int c){
	
	return true;
}
*/

bool Pawn::checkMove(int r, int c, Piece *b[8][8]){
	
	
	//first checks if coordinates are within board, then it should check if it's within range,
	//then it should check if its occupied/nlocked
	cout << "checkMove for Pawn called" << endl;
	
	// Check if coordinate is within board
	cout << "Check if the coordinates are within bound" << endl;
	if (r > 8 || r < 0 || c > 7 || c < 0){
		cout << "That coordinate is not even on the board" << endl;
		return false;
	}
	
	// determine what colour it is and whether or not it has moved
	if (colour == 0){ // if its black
		if (hasMoved){
			if (r-row != 1){
				cout << "The Pawn can only move one unit forward, as it has been mobilized" << endl;
				return false;
			}
			if (abs(c-col) > 1){
				cout << "The Pawn can only move up to one unit on either side" << endl;
				return false;
			}
			
			// check that the move forward isnt already occupied by a unit as it cant capture directly
			if (col == c && b[r][col] != NULL){
				cout << "The Pawn cannot move forward as it is obstructed by another piece" << endl;
				return false;
			}else if (col == c && b[r][col] == NULL){
				cout << "Free space, pawn advances" << endl;
				return true;
			}
			
			//
			// check that diagnoal moves are occupied by enemies
			
			// but check for enpassant first
			if (row == 4 && b[row][c]->getValue() == 1 && b[row][c]->getColour() == 1) {
				// enpassant can only be played the turn after
			 	if (b[row][c]->getEnPassant() == (this->turnsAlive - 1)){
			 		// then the enpassant move is valid, make the appropriate modifications to the board
			 		enPassantCapture(r, c, b);
			 		return true; //
			 	}
			}
		
			// only for diagnal moves
			if (b[r][c] == NULL){ // then there's nothing to capture
				cout << "This space is empty, there's no enemy to capture" << endl;
				return false;
			}
			
			if (b[r][c]->getColour() == colour){
				cout << "This space is occupied by a friendly piece" << endl;
				return false;
			}
			
		}else{
			hasMoved = true;
			if (r-row > 2 && r > row){
				cout << "The Pawn can only move up to two units forward, as it first mobilizes" << endl;
				return false;
			}
			if (abs(c-col) > 1){
				cout << "The Pawn can only move up to one unit on either side" << endl;
				return false;
			}
			
			// check that diagnoal moves are occupied by enemies
			if (c != col){
				if (row == 3){
					cout << "Not a Knight" << endl;
					return false;
				}
				if (b[r][c] == NULL){ // then there's nothing to capture
					cout << "This space is empty, there's no enemy to capture" << endl;
					return false;
				}
				if (b[r][c]->getColour() == colour){
					cout << "This space is occupied by a friendly piece" << endl;
					return false;
				}
				return true;
			}
			
			// check forward move first
			if (b[row+1][c] != NULL){
				cout << "The Pawn is obstructed" << endl;
				return false;
			}
			if (b[r][c] != NULL){
				cout << "The Pawn is obstructed" << endl;
			}
		}
	}else{ // white pawn, add the enpassant move
		if (hasMoved){
			if (row -r != 1){
				cout << "The Pawn can only move one unit forward, as it has been mobilized" << endl;
				return false;
			}
			if (abs(c-col) > 1){
				cout << "The Pawn can only move up to one unit on either side" << endl;
				return false;
			}
			// check that the move forward isnt already occupied by a unit as it cant capture directly
			if (col == c && b[r][col] != NULL){
				cout << "The Pawn cannot move forward as it is obstructed by another piece" << endl;
				return false;
			}else if (col == c && b[r][col] == NULL){
				cout << "Free space, pawn advances" << endl;
				return true;
			}
			
			// check that diagnoal moves are occupied by enemies
			// check for enpassant first
			cout << "check for enpassant" << endl;
			cout << "row == 3? " << (row == 3) << endl;
			cout << "b[row][c]->getValue() == 1? " << (b[row][c]->getValue() == 1) << endl;
			cout << "b[row][c]->getColour() == 0? " << (b[row][c]->getColour() == 0) << endl;
			
			if (row == 3 && b[row][c]->getValue() == 1 && b[row][c]->getColour() == 0) {
				// enpassant can only be played the turn after
				cout << "b[row][c]->getEnPassant() " << b[row][c]->getEnPassant() << endl;
				cout << "turnsAlive " << turnsAlive << endl;
			 	if (b[row][c]->getEnPassant() == turnsAlive - 1){
			 		// then the enpassant move is valid, make the appropriate modifications to the board
			 		enPassantCapture(r, c, b);
			 		return true; 
			 	}
			}
			
			if (b[r][c] == NULL){ // then there's nothing to capture
				cout << "This space is empty, there's no enemy to capture" << endl;
				return false;
			}
			if (b[r][c]->getColour() == colour){
				cout << "This space is occupied by a friendly piece" << endl;
				return false;
			}
			
		}else{
			
			if (row - r > 2 && row > r){
				cout << "The Pawn can only move up to two units forward, as it first mobilizes" << endl;
				return false;
			}
			if (abs(c-col) > 1){
				cout << "The Pawn can only move up to one unit on either side" << endl;
				return false;
			}
			
			// check that diagnoal moves are occupied by enemies
			if (c != col){
				if (row == 4){
					cout << "Not a Knight" << endl;
					return false;
				}
				if (b[r][c] == NULL){ // then there's nothing to capture
					cout << "This space is empty, there's no enemy to capture" << endl;
					return false;
				}
				if (b[r][c]->getColour() == colour){
					cout << "This space is occupied by a friendly piece" << endl;
					return false;
				}
			}
			
			// check forward move first
			if (b[row-1][c] != NULL){
				cout << "The Pawn is obstructed" << endl;
				return false;
			}
			if (b[r][c] != NULL){
				cout << "The Pawn is obstructed" << endl;
			}
		}
	}
	
	if (abs(r-row) == 2){
		// enable enpassant
		enPassant = turnsAlive;
	}
	
	hasMoved = true;
	return true;
}

void Pawn::printName(){
	//cout << "I am a " << name << endl;
	cout << name;
}

void Pawn::enPassantCapture(int r, int c, Piece *b[8][8]){
	// takes in the board and destination of the pawn
	// deletes the pawn that was captured,
	// this function is called before the generic move function, will take care of the rest
	// 
	// output the message
	b[row][c]->printName(); 
	cout << " has been captured via enPassant by ";
	printName();
	cout << endl;
	
	Piece *temp = b[row][c]; // location of the captured piece
	
	b[row][c] = NULL; // set its location to null
	delete temp; // delete the piece
	
	cout << "deleted" << endl;
	

}

