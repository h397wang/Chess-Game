
// derived from class Peice

#ifndef ROOK_H
#define ROOK_H

#include "piece.h"


#include <assert.h>
#include <string.h>
#include <iostream>
using namespace std;


#define DEBUG 1


// needs castling option


class Rook : public Piece {
	//friend Board;
	public:
		Rook();
		Rook(bool, int, int); 
		//virtual bool moveTo(int, int, Piece *[4][4]);	// should be a virtual function
		virtual bool checkMove(int, int, Piece *[8][8]); // should be a virtual function
		virtual void printName();
	private:
		//static int numbers;
		
};

#endif

