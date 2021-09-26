#include "Rook.h"

Rook::Rook(int color, int row, int col) : ChessPiece(color, row, col)
{
	if (color == WHITE)
	{
		this->symbol = 'R';
	}
	else
	{
		this->symbol = 'r';
	}
	this->name = "Rook";
};

// Function to return Piece Name
std::string Rook::getName() const
{
	return this->name;
}

// Function to get Piece symbol to print board for visualisation
char Rook::getSymbol()
{
	return this->symbol;
}

/* Function to check if src_piece can be moved to spot with coord 
 * (to_row, to_col). */
bool Rook::canMove(ChessPiece *board[][8], int to_row, int to_col, //
				   bool in_check, ChessPiece *white_pieces[],		//
				   ChessPiece *black_pieces[])
{
	// Calculate absolute vertical and horizontal offset distances
	int abs_dist_row = abs(this->getRow() - to_row);
	int abs_vert_row = abs(this->getCol() - to_col);

	// Check if rook making an illegal diagonal move
	if (abs_dist_row != 0 && abs_vert_row != 0)
	{
		return false;
	}

	// Check if there are any piece blocking the rook movement
	// 1. Vertically
	if (this->getRow() < to_row)
	{
		for (int i = this->getRow() + 1; i < to_row; i++)
		{
			if (board[i][this->getCol()] != nullptr)
			{
				return false;
			}
		}
	}
	else
	{
		for (int i = this->getRow() - 1; i > to_row; i--)
		{
			if (board[i][this->getCol()] != nullptr)
			{
				return false;
			}
		}
	}

	// 2. Horizontally
	if (this->getCol() < to_col)
	{
		for (int i = this->getCol() + 1; i < to_col; i++)
		{
			if (board[this->getRow()][i] != nullptr)
			{
				return false;
			}
		}
	}
	else
	{
		for (int i = this->getCol() - 1; i > to_col; i--)
		{
			if (board[this->getRow()][i] != nullptr)
			{
				return false;
			}
		}
	}
	return true;
}
