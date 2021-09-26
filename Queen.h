#ifndef QUEEN_H
#define QUEEN_H 

#include <string>
#include "ChessPiece.h"


class Queen: public ChessPiece {
	char symbol;
	std::string name; 
	
	public:
		// Constructor 
		Queen(int color, int row, int col);
		
		// Function to return Piece Name
		std::string getName() const override;
		
		// Function to get Piece symbol to print board for visualisation
		char getSymbol() override;
		
		/* Function to check if src_piece can be moved to spot with coord 
		 * (to_row, to_col). */ 
		bool canMove(ChessPiece* board[][8], int to_row, int to_col,	//
					 bool in_check, ChessPiece* white_pieces[],			//
					 ChessPiece* black_pieces[]) override;		
};

#endif
