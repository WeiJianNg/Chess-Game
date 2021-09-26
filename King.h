#ifndef KING_H
#define KING_H 

#include <string>
#include "ChessPiece.h"


class King: public ChessPiece {
	char symbol;
	std::string name; 
	
	public:
		// Constructor 
		King(int color, int row, int col);
		
		// Function to return Piece Name
		std::string getName() const override;
		
		// Function to get Piece symbol to print board for visualisation
		char getSymbol() override;
		
		/* Function to check if there are only spaces between the king and rook.
		 * Helper function to check if castling move is valid */
		bool onlySpaceBtwKingRook(ChessPiece* board[][8], int rook_col) const;
		
		/* Function check if the spaces between the king and rook is under 
		 * threat by the opposing team. Helper function to check if castling 
		 * move is valid */
		bool spacesNotInThreat(ChessPiece* board[][8], 	//
							   ChessPiece* white_pieces[],//
				  			   ChessPiece* black_pieces[],// 
							   int rook_col) const;

		// Function to check if src_piece can be moved to spot with coord 
		// (to_row, to_col). If there is a piece in the destination, dest_piece
		// will be pointing to it. 
		bool canMove(ChessPiece* board[][8], int to_row, int to_col, 	//
					 bool in_check, ChessPiece* white_pieces[], 		//
					 ChessPiece* black_pieces[]) override;		
};

#endif
