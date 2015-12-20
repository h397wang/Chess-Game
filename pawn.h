#ifndef PAWN_H
#define PAWN_H

#include "piece.h"


#include <assert.h>
#include <string.h>
#include <iostream>
using namespace std;


#define DEBUG 1


class Pawn : public Piece {
	
	public:
		Pawn(bool, int, int);
		//virtual void moveTo(int, int, Board &b) = 0;	// should be a virtual function
		virtual bool checkMove(int, int, Piece *[8][8]); // should be a virtual function
		virtual void printName();
		void enPassantCapture(int, int, Piece *[8][8]); 
	private:
		bool hasMoved; // may initially move two spaces forward 
		bool promote; // may be promoted to any piece once its on the other side
		
};

#endif


