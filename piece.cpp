
#include "piece.h"

#define DEBUG 1

Piece::Piece(bool colr, int r, int c, int v){
	// it doesnt really do anything...
	colour = colr;
	row = r; 
	col = c;
	value = v;
	turnsAlive = 0;
}

Piece::~Piece(){
	delete [] name;
}

void Piece::setPosition(int r, int c){ 
	// sets the position of the piece to row = r, col = c. called by the movePiece function afer validating move
	row = r;
	col = c;
}

	
