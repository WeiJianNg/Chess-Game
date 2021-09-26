#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <string>
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

class ChessBoard {
		ChessPiece* board[8][8]; // Board that contains Chess pieces
		
		/* Array that points to all pieces on Board. Pointer to Pawns (left to
		 * right) are stored in the first 8 positions. Other Ranks are stored 
		 * in the following 8 positions. The position is allocated based on the 
		 * initial position of the board (left to right). Example Rook (left) 
		 * is at index 8, King is at index 12, and Knight (right) is at index 
		 * 14.*/
		ChessPiece* black_pieces[16]; 
		ChessPiece* white_pieces[16]; 		
		
		// Game State
		int player_turn = WHITE;	
		bool in_check = false;
		bool in_checkmate = false;
		bool in_stalemate = false;

		/* ----- Game setup / clean up functions ----- */

		/* Function to initialise Chess Board - Allocate heap memory for all 
		 * chess Pieces and place them in the correct positions on the board */
		void initBoard();
		
		/* Function to remove all chess pieces from Chessboard and deallocate 
		 * heap memory used. */
		void removePieces();

		// Function to clear board 
		void clearBoard();		
			
		// Function to reset all game status
		void resetStatus();

		/* ----- Move validating functions ----- */

		// Function to check if input format is valid
		bool inputIsValid(std::string coord);
		
		/* Function which returns true if the Player's King (White or Black) is 
		 * in check */
		bool isInCheck(int player);

 		/* Function which returns true if a potential move from 
		 * (src_row, src_col) to (dest_row, dest_col) will expose Player to 
		 * be in check. The game state is not modified by the function */
		bool isCheckAfterMove(int player, int src_row, int src_col, //
							  int dest_row, int dest_col);
		
		/* Function check if player can still make any moves without exposing
		 * the king to be in check */
		bool isOutOfMoves(int player, bool in_check);
		
		/* ----- Game State Setter functions ----- */

		/* Function which updates the game state (i.e. Location of the Chess 
		 * Pieces on board, Player's turn, check status and etc) and print the 
		 * relevant successful move output messages */
		void makeMove(std::string src_square, std::string dest_square);	
		
		/* ------ Helper functions ------ */

		/* Function to print Name of Chess Piece in the formate 
		 * <color>'s <piece_name> */
		std::string printName(ChessPiece const* piece);
		
		public:
			// Constructor for ChessBoard
			ChessBoard();
			
			// Function to print Board for debugging
			void printBoard();
			
			// Function submit move
			void submitMove(std::string src_square, std::string dest_square);
			
			// Function to reset the Board
			void resetBoard();	
				
			// Destructor for ChessBoard
			~ChessBoard();
};

#endif
