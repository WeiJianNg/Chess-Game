#include "Pawn.h"

// Constructor
Pawn::Pawn(int color, int row, int col) : ChessPiece(color, row, col)
{
	if (color == 0)
	{
		this->symbol = 'P';
	}
	else
	{
		this->symbol = 'p';
	}
};

// Function to return Piece Name
std::string Pawn::getName() const
{
	return this->name;
}

// Function to get Piece symbol to print board for visualisation
char Pawn::getSymbol()
{
	return this->symbol;
}

// Function to check if Pawn can move to (to_row, to_col)
bool Pawn::canMove(ChessPiece *board[][8], int to_row, int to_col, //
				   bool in_check, ChessPiece *white_pieces[],		//
				   ChessPiece *black_pieces[])
{
	// Vertical and horizontal distance between destination and source location
	int dist_x = this->getCol() - to_col;
	int dist_y = this->getRow() - to_row;

	// Absolute vertical and horizontal distance
	int dist_y_abs = abs(dist_y);
	int dist_x_abs = abs(dist_x);

	// Check if Pawn is moving towards the opponent
	if (this->getColor() == WHITE)
	{
		if (dist_y > 0) 
		{
			return false;
		}
	}
	else
	{
		if (dist_y < 0) 
		{
			return false;
		}
	}

	// Check for Non-capturing move
	// Pawn can only move forward for a non capturing move
	if (board[to_row][to_col] == nullptr)
	{
		// Pawn can only move forward, if it is a non capturing move
		if (dist_x_abs != 0)
		{
			return false;
		}

		// Check if move is within bounds (maximum 2 spot)
		if (dist_y_abs > 2)
		{
			return false;
		}

		// Additional checks when Pawn tries to move forward two spot
		if (dist_y_abs == 2)
		{
			// Pawn can only make a double move if it is first move
			if (!this->isFirstMove()) 
			{	
				return false;
			}

			/* For moving two spots, check if there is any chesspiece between
			 * the source and destination location */
			int row_btw = (this->getRow() + to_row) / 2;
			int col_btw = (this->getCol() + to_col) / 2;
			
			// Must not contain any chess piece between
			if (board[row_btw][col_btw] != nullptr)
			{
				return false; 
			}
		}
	}

	// Check for Capturing move
	// Pawn can only move diagonally by one spot for a capturing move
	if (board[to_row][to_col] != nullptr)
	{
		/* Pawn can only move diagonally by one spot, if it is a 
		 * capturing move */
		if (!(dist_x_abs == 1 && dist_y_abs == 1))
		{
			return false;
		}
	}

	return true;
}
