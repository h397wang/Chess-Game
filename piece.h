
#ifndef PIECE_H
#define PIECE_H

#define BLACK 0
#define WHITE 1


/*
Abstract based class
Values of peices as follows: pawn=1, bishop=knight=3, rook=5, and queen=9 
*/

class Piece{
	friend class Board;
	public:
		Piece(bool, int, int, int); // constructor called at the beginning of the game..
		~Piece(); // destructor for when the peice is captured
		//virtual bool moveTo(int, int, Piece *[4][4]) = 0;	// should be a virtual function
		virtual bool checkMove(int, int, Piece *[8][8]) = 0; // should be a virtual function
		virtual void printName() = 0;
		bool getColour(){ return colour; }
		void setPosition(int, int);
		//void capture(Piece * &)
		int getValue(){ return value;}
		int getEnPassant(){ return enPassant; }
		
	protected:
		bool colour; // 1 for white and 0 for black
		int value; // value of the captured peice
		int row; // also known as rank, ranges from 1 to 8
		int col; // also known as file, ranges from a to h
		char *name; // name of the peice
		static int turnsAlive;
		int enPassant; // this is only applicable for pawns, must be here or else error
};

#endif





