
#ifndef KNIGHT_H
#define KNIGHT_H

class Knight : public Piece {
	
	public:
		Knight(bool, int, int);
		//virtual void moveTo(int, int, Board &b) = 0;	// should be a virtual function
		virtual bool checkMove(int, int, Piece *[8][8]); // should be a virtual function
		virtual void printName();
	private:
		
};


#endif
