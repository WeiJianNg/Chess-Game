#include "ChessPiece.h"

/* --- Constructor --- */
ChessPiece::ChessPiece(int color, int row, int col)
{
	this->color = color;
	this->row = row;
	this->col = col;
}

/* --- Getter Functions --- */

// Function to get coordinates
int ChessPiece::getCol() const
{
	return this->col;
}

int ChessPiece::getRow() const
{
	return this->row;
}

// Function to get Piece color
int ChessPiece::getColor() const
{
	return this->color;
}

// Function to get captured status of chess piece
bool ChessPiece::isCaptured() const
{
	return this->captured;
}

// Function to return if Piece has moved
bool ChessPiece::isFirstMove() const
{
	return this->is_first_move;
}

/* --- Setter Functions --- */

// Function to update location
void ChessPiece::setLocation(int row, int col)
{
	this->row = row;
	this->col = col;
}

// Function to change chess piece status to captured
void ChessPiece::capturePiece()
{
	this->captured = true;
}

// Function to set Piece to moved
void ChessPiece::move()
{
	this->is_first_move = false;
}

// Function set first move back to true
void ChessPiece::unMove()
{
	this->is_first_move = true;
}

// Function to uncapture a chess piece
void ChessPiece::unCapturePiece()
{
	this->captured = false;
}
