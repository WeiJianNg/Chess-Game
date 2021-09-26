#include "King.h"

King::King(int color, int row, int col) : ChessPiece(color, row, col)
{
	if (color == 0)
	{
		this->symbol = 'K';
	}
	else
	{
		this->symbol = 'k';
	}
	this->name = "King";
};

// Function to return Piece Name
std::string King::getName() const
{
	return name;
}

// Function to get Piece symbol to print board for visualisation
char King::getSymbol()
{
	return symbol;
}

/* Function to check if there are only empty spaces between the king and the 
 * rook for castling move */
bool King::onlySpaceBtwKingRook(ChessPiece *board[][8], int rook_col) const
{
	if (this->getCol() > rook_col)
	{
		for (int i = rook_col + 1; i < this->getCol(); i++)
		{
			if (board[this->getRow()][i] != nullptr)
			{
				return false;
			}
		}
	}
	else
	{
		for (int i = this->getCol() + 1; i < rook_col; i++)
		{
			if (board[this->getRow()][i] != nullptr)
			{
				return false;
			}
		}
	}
	return true;
}

/* Function to check if the empty spaces between the rook and king is under
 * threat by any of the opponent's chess pieces for castling move */
bool King::spacesNotInThreat(ChessPiece *board[][8],	   //
							 ChessPiece *white_pieces[], //
							 ChessPiece *black_pieces[], //
							 int rook_col) const
{
	auto **opp_pieces = this->getColor() == WHITE ? black_pieces : white_pieces;

	for (int i = 0; i < 16; i++)
	{
		if (this->getCol() > rook_col)
		{
			for (int j = rook_col + 1; j < this->getCol(); j++)
			{
				if (opp_pieces[i]->canMove(board, this->getRow(), j, false,
										   white_pieces, black_pieces))
				{
					return false;
				}
			}
		}
		else
		{
			for (int j = this->getCol() + 1; j < rook_col; j++)
			{
				if (opp_pieces[i]->canMove(board, this->getRow(), j, false,
										   white_pieces, black_pieces))
				{
					return false;
				}
			}
		}
	}

	return true;
}

/* Function to check if src_piece can be moved to spot with coord 
 * (to_row, to_col). If there is a piece in the destination, dest_piece
 * will be pointing to it. */
bool King::canMove(ChessPiece *board[][8], int to_row, int to_col, //
				   bool in_check, ChessPiece *white_pieces[],		//
				   ChessPiece *black_pieces[])
{
	// Calculate absolute vertical and horizontal offset distances
	int abs_dist_row = abs(this->getRow() - to_row);
	int abs_dist_col = abs(this->getCol() - to_col);

	if (!in_check && this->isFirstMove() && abs_dist_col == 2)
	{
		// Check if Castling Move is to the right or left

		// Get ChessPiece at Rook location
		int rook_col = this->getCol() > to_col ? 0 : 7;
		auto *rook = board[this->getRow()][rook_col];

		/* Check if there is a chess piece at the rook location, if there is 
		 * one,Check if the piece is a rook and Check that it hasn't been moved. 
		 * After that, Check if there are only spaces between the king and 
		 * rook. Finally, check that all the empty spaces are not under threat
		 */
		if (rook != nullptr && rook->getName() == "Rook" &&
			rook->isFirstMove() &&
			onlySpaceBtwKingRook(board, rook_col) &&
			spacesNotInThreat(board, white_pieces, black_pieces, rook_col))
		{
			return true;
		}
	}

	if (abs_dist_row > 1 || abs_dist_col > 1)
	{
		return false;
	}

	return true;
}
