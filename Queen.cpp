#include "Queen.h"

Queen::Queen(int color, int row, int col) : ChessPiece(color, row, col)
{
	if (color == 0)
	{
		this->symbol = 'Q';
	}
	else
	{
		this->symbol = 'q';
	}
	this->name = "Queen";
};

// Function to return Piece Name
std::string Queen::getName() const
{
	return name;
}

// Function to get Piece symbol to print board for visualisation
char Queen::getSymbol()
{
	return symbol;
}

/* Function to check if src_piece can be moved to spot with coord 
 * (to_row, to_col). If there is a piece in the destination, dest_piece
 * will be pointing to it. */
bool Queen::canMove(ChessPiece *board[][8], int to_row, int to_col, //
					bool in_check, ChessPiece *white_pieces[],		//
					ChessPiece *black_pieces[])
{
	// Calculate absolute vertical and horizontal offset distances
	int abs_dist_row = abs(this->getRow() - to_row);
	int abs_dist_col = abs(this->getCol() - to_col);

	// Ensure Queen can only move Horizontally, Vertically and Diagonally
	if (abs_dist_row != 0 && abs_dist_col != 0)
	{
		if (abs_dist_col != abs_dist_row)
		{
			return false;
		}
	}

	// Check if there are any chess pieces blocking if Queen is to move:
	// 1. Vertically
	if (abs_dist_col == 0 && abs_dist_row > 0)
	{
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
	}

	// 2. Horizontally
	if (abs_dist_row == 0 && abs_dist_col > 0)
	{
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
	}

	// 3. Diagonally
	if (abs_dist_row == abs_dist_col)
	{
		if (to_row < this->getRow())
		{
			// Check for diagonal 1
			if (to_col < this->getCol())
			{
				for (int i = 1; i < abs_dist_row; i++)
				{
					if (board[this->getRow() - i][this->getCol() - i]!=nullptr)
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
					if (board[this->getRow() - i][this->getCol() + i]!=nullptr)
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
					if (board[this->getRow() + i][this->getCol() - i]!=nullptr)
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
					if (board[this->getRow() + i][this->getCol() + i]!=nullptr)
					{
						return false;
					}
				}
			}
		}
	}

	return true;
}
