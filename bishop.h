
#ifndef BISHOP_H
#define BISHOP_H


#include "Piece.h"

#include <assert.h>
#include <string.h>
#include <iostream>
using namespace std;


class Bishop : public Piece {
	
	public:
		Bishop(int, int, Piece *[8][8]);
		virtual bool checkMove(int, int, Piece *[8][8]); // should be a virtual function
		virtual void printName();
	private:
	
	
};

#endif
