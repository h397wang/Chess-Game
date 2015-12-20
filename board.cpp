

#include "board.h"
#include "piece.h"
#include "rook.h"

#include <iostream>

using namespace std;


int Piece::turnsAlive;

Board::Board(){
	
	cout << "Starting a new game" << endl;
	
	score = 0;
	turns = 0;
	
	// let the player be white, and he faces forward
	
	// create the black army, remember the queen is always on the corresponding colored spot
	
	// create the empty spaces
	
	for (int row = 0; row < 8; row ++){
		for (int col = 0; col < 8; col++){
			theBoard[row][col] = NULL;
		}
	}
	cout << "All positions have been set to NULL" << endl;
	
	
	for (int col = 0; col < 8; col++){
		theBoard[1][col] = new Pawn(0, 1, col);
		theBoard[6][col] = new Pawn(1, 6, col);
	}
	
	
	

}

Board::~Board(){
	
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			delete theBoard[i][j];
		}
	}
	
}

void Board::printBoard(){
	

	for (int i = 0; i < 8; i++){ // for each row	
		for (int j = 0; j < 12; j++){ // 
			cout << "--";
		}
		cout << endl;
		for (int k = 0; k < 8; k++){ // for each col
			cout << "|";
			if (theBoard[i][k] == NULL){
				cout << "  ";
			}else{
				cout << theBoard[i][k]->name; // this is not working for some reason
				//theBoard[i][k]->printName();
			}
		}
		cout << "|";
		cout << endl;
	}
	for (int i = 0; i < 12; i++){
		cout << "--";
	}
	cout << endl;
	
}


int Board::getScore(){
	return 0;
}

bool Board::movePiece(int ri, int ci, int r, int c){
	
	// check if its a blank spot
	if (theBoard[ri][ci] == NULL){
		cout << "An empty spot was selected " << endl;
		return false;
	}
	
	// check that its your own piece, and not the opponents
	
	if (consider(ri, ci, r, c)){
		// then do the switcharoo
	
		// check whether or not that a piece was captured
		if (theBoard[r][c] != NULL){ // if it wasnt empty space
			Piece *temp = theBoard[r][c]; // piece to be captured and deleted
			theBoard[r][c]->printName(); 
			cout << " has been captured by ";
			theBoard[ri][ci]->printName();
			cout << endl;
			delete temp;
		}
		
		Piece *copy = theBoard[ri][ci];
		theBoard[ri][ci] = NULL;
		theBoard[r][c] = copy;
		
	// remember to change the coordinates of the piece itself...
		theBoard[r][c]->setPosition(r,c);
		
		theBoard[r][c]->printName();
		cout << " has been moved from (" << ri << "," << ci << ") to " << r << "," << c << ")" << endl;
		turns++;
		theBoard[r][c]->turnsAlive++; // this is for the enpassant to work
		return true;
	}else{
		cout << " move from (" << ri << "," << ci << ") to " << r << "," << c << "), FAILED " << endl;
		return false;
	}
}


bool Board::consider(int ri, int ci, int r, int c){
	
	bool output = theBoard[ri][ci]->checkMove(r, c, theBoard);
	return output;
}



