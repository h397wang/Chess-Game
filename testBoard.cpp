
#include <iostream>
#include <iomanip>


#include "board.h"
#include "piece.h"
#include "rook.h"

using namespace std;

//bool DEBUG = 1;

int main(){
	
	//Board game();
	Board *brdPtr = new Board();
	
	brdPtr->printBoard();
	
	brdPtr->movePiece(1,0,3,0);
	brdPtr->movePiece(6,1,4,1);
	brdPtr->movePiece(3,0,4,0);
	brdPtr->movePiece(4,1,3,1);
	brdPtr->movePiece(1,2,3,2);
	brdPtr->printBoard();
	brdPtr->movePiece(3,1,2,2);
	brdPtr->movePiece(1,3,2,2);
	brdPtr->movePiece(4,0,3,0);
	brdPtr->printBoard();
	
	
	/*
	char *name = "BR";
	
	for (int j = 0; j < 8; j++){
		
	for (int i = 0; i<12; i++){
		cout << "--";
	}
	cout << endl;
	for (int i = 0; i<8; i++){
		cout << "|" << name;
	}
	cout << "|";
	cout << endl;
	
	}
	for (int i = 0; i<12; i++){
		cout << "--";
	}
	
	cout << setw(5) << "|R";
	cout << setw(5) <<"|K";
	cout << setw(5) <<"|B";
	cout << setw(5) <<"|Q";
	cout << setw(5) <<"|" << endl;
	
	for (int i = 0; i<12; i++){
		cout << " ";
	}
	cout << endl;
	
	
	for (int i = 0; i<12; i++){
		cout << "P";
	}
	*/
	
	
}

	
