
#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include "rook.h"
#include "pawn.h"

#include <iostream>
using namespace std;

class Piece;

class Board{
	/*
	friend class Piece;
	friend class Rook;
	friend class Pawn;
	*/
	
	public:
		Board(); // constructor for a new game
		~Board();
		int getScore();
		void printBoard();
		bool movePiece(int, int, int, int);
		bool consider(int, int, int, int);
		
	private:
		// maintains an array of pointers to peices to keep track of shit...
		Piece *theBoard[8][8];
		
		int turns; // indicates the number of moves that have been played
		int score; // indicates the score of the board, with respect to some player...
};

#endif


