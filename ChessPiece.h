#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <string>

#define WHITE 0
#define BLACK 1

class ChessPiece {
	int color;
	int row;
	int col;
	bool is_first_move = true;
	bool captured = false;

	public:
		/* --- Constructor --- */
		ChessPiece(int color, int row, int col);

		/* --- Getter Functions --- */
		int getCol() const;
		int getRow() const;
		int getColor() const;
		bool isFirstMove() const;
		bool isCaptured() const;	

		/* --- Setter Functions --- */
		
		// Function to update chess piece location
		void setLocation(int row, int col);

		// Function to set ChessPiece capture status
		void capturePiece(); 

		// Function to reset ChessPiece capture status
		void unCapturePiece(); 

		// Function to set ChessPiece is_first_move to false
		void move(); 

		// Function to set ChessPiece is_first_move back to true
		void unMove(); 
		
		/* -------- Function to be overwritten by derived class ---------- */
		
		/* Function to check if src_piece can be moved to spot with coord 
		 * (to_row, to_col). 
		 * <Inputs>
		 * board - Reference to the game board array
		 * to_row, to_col - row and column of the destination
		 * in_check - Check status of the game
		 * white_pieces - Pointer to the array which points to all the chess
		 * 				  white pieces on the board
		 * black_pieces - same as white_pieces but for black pieces */
		virtual bool canMove(ChessPiece* board[][8], int to_row, int to_col,//
							 bool in_check, ChessPiece* white_pieces[], 	//
							 ChessPiece* black_pieces[]) = 0;
		
		// Function which returns the symbol for the ChessPiece
		virtual char getSymbol() = 0;

		// Function which returns the name of the ChessPiece
		virtual std::string getName() const = 0;

		/* ------ Destructor ------ */
		virtual ~ChessPiece() {};
};

#endif
