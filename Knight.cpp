#include "Knight.h"
#include <iostream>

Knight::Knight(int color, int row, int col) : ChessPiece(color, row, col)
{
	if (color == 0)
	{
		this->symbol = 'C';
	}
	else
	{
		this->symbol = 'c';
	}
	this->name = "Knight";
};

// Function to return Piece Name
std::string Knight::getName() const
{
	return name;
}

// Function to get Piece symbol to print board for visualisation
char Knight::getSymbol()
{
	return symbol;
}

/* Function to check if src_piece can be moved to spot with coord 
 * (to_row, to_col). */
bool Knight::canMove(ChessPiece *board[][8], int to_row, int to_col, //
					 bool in_check, ChessPiece *white_pieces[],	  	 //
					 ChessPiece *black_pieces[])
{
	// Calculate absolute vertical and horizontal offset distance
	int abs_dist_row = abs(this->getRow() - to_row);
	int abs_dist_col = abs(this->getCol() - to_col);

	// Ensure knight is moving within bound
	if (abs_dist_row > 2 || abs_dist_col > 2)
	{
		return false;
	}

	// Ensure knight cannot make a straight move
	if (abs_dist_row == 0 || abs_dist_col == 0)
	{
		return false;
	}

	// Ensure knight cannot move diagonally
	if (abs_dist_row == abs_dist_col)
	{
		return false;
	}

	return true;
}
