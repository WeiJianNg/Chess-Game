#include "Bishop.h"

Bishop::Bishop(int color, int row, int col) : ChessPiece(color, row, col)
{
	if (color == 0)
	{
		this->symbol = 'B';
	}
	else
	{
		this->symbol = 'b';
	}
	this->name = "Bishop";
};

// Function to return Piece Name
std::string Bishop::getName() const
{
	return name;
}

// Function to get Piece symbol to print board for visualisation
char Bishop::getSymbol()
{
	return symbol;
}

/* Function to check if src_piece can be moved to spot with coord 
 * (to_row, to_col). */
bool Bishop::canMove(ChessPiece *board[][8], int to_row, int to_col, //
					 bool in_check, ChessPiece *white_pieces[],		 //
					 ChessPiece *black_pieces[])
{
	// Calculate absolute vertical and horizontal offset distances
	int abs_dist_row = abs(this->getRow() - to_row);
	int abs_dist_col = abs(this->getCol() - to_col);

	// Check if Bishop is making a diagonal move
	if (abs_dist_row != abs_dist_col)
	{
		return false;
	}

	/* Check if there are any chess piece between the source and 
	 * destination location 
	 * 	D1 || D2
	 * 	========
	 * 	D3 || D4 */

	if (to_row < this->getRow())
	{
		// Check for diagonal 1
		if (to_col < this->getCol())
		{
			for (int i = 1; i < abs_dist_row; i++)
			{
				if (board[this->getRow() - i][this->getCol() - i] != nullptr)
				{
					return false;
				}
			}
		}

		// Check for diagonal 2
		if (to_col > this->getCol())
		{
			for (int i = 1; i < abs_dist_row; i++)
			{
				if (board[this->getRow() - i][this->getCol() + i] != nullptr)
				{
					return false;
				}
			}
		}
	}

	if (to_row > this->getRow())
	{
		// Check for diagonal 3
		if (to_col < this->getCol())
		{
			for (int i = 1; i < abs_dist_row; i++)
			{
				if (board[this->getRow() + i][this->getCol() - i] != nullptr)
				{
					return false;
				}
			}
		}

		// Check for diagonal 4
		if (to_col > this->getCol())
		{
			for (int i = 1; i < abs_dist_row; i++)
			{
				if (board[this->getRow() + i][this->getCol() + i] != nullptr)
				{
					return false;
				}
			}
		}
	}

	return true;
}
