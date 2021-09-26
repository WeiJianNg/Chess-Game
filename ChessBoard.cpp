#include "ChessBoard.h"
#include <iostream>

using namespace std;

int ROW_NO = 8; // Number of rows in board
int COL_NO = 8; // Number of cols in board

/* -------------------- Constructor --------------------- */

ChessBoard::ChessBoard()
{
	/* Initialise board */
	this->clearBoard(); // Set all ptrs in board to null
	this->initBoard();	// Initialise board with chess pieces
	cout << "A new chess game is started!" << endl;
}

/* ---------- Game setup / Clean-up functions ----------- */

/* Function to initialise Chess Board - Allocate heap memory for all 
 * chess pieces and place them in the correct positions on the board */
void ChessBoard::initBoard()
{
	// Add Pawns
	for (int i = 0; i < 8; i++)
	{
		// Create Pieces in Heap and Point Board to the pieces
		this->board[1][i] = new Pawn(WHITE, 1, i);
		this->board[6][i] = new Pawn(BLACK, 6, i);

		// Add Pawn pointers to White / Black pieces array
		this->white_pieces[i] = board[1][i];
		this->black_pieces[i] = board[6][i];
	}

	for (int i = 0; i < COL_NO; i++)
	{
		if (i == 0 || i == 7)
		{
			// Add Rook to board
			this->board[0][i] = new Rook(WHITE, 0, i);
			this->board[7][i] = new Rook(BLACK, 7, i);
		}
		else if (i == 1 || i == 6)
		{
			// Add Knight to board
			this->board[0][i] = new Knight(WHITE, 0, i);
			this->board[7][i] = new Knight(BLACK, 7, i);
		}
		else if (i == 2 || i == 5)
		{
			// Add Bishop to board
			this->board[0][i] = new Bishop(WHITE, 0, i);
			this->board[7][i] = new Bishop(BLACK, 7, i);
		}
		else if (i == 3)
		{
			// Add Queen to board
			this->board[0][i] = new Queen(WHITE, 0, i);
			this->board[7][i] = new Queen(BLACK, 7, i);
		}
		else
		{
			// Add King to board
			this->board[0][i] = new King(WHITE, 0, i);
			this->board[7][i] = new King(BLACK, 7, i);
		}
		// Add Other Rank pointers to White / Black pieces array
		this->white_pieces[i + 8] = board[0][i];
		this->black_pieces[i + 8] = board[7][i];
	}
}

// Function to reset all game status to the initial status
void ChessBoard::resetStatus()
{
	this->player_turn = WHITE;
	this->in_check = false;
	this->in_checkmate = false;
	this->in_stalemate = false;
}

/* Function to clear board by setting all board locations to nullptr. Heap 
 * memeory used for the chess pieces are deleted in the 
 * removePieces() function */
void ChessBoard::clearBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			this->board[i][j] = nullptr;
		}
	}
}

/* Function to remove all chess pieces from Chessboard and array. Deallocate 
 * heap memory used. */
void ChessBoard::removePieces()
{
	for (int i = 0; i < 16; i++)
	{
		delete white_pieces[i];
		white_pieces[i] = nullptr;
		delete black_pieces[i];
		black_pieces[i] = nullptr;
	}
}

// Function to reset game state to the initial state
void ChessBoard::resetBoard()
{
	// Delete chess pieces and reset game status
	this->removePieces();
	this->clearBoard();
	this->resetStatus();
	// Initialising a new game
	this->initBoard();
	cout << "A new chess game is started!" << endl;
}

/* ------------- Move Validating Functions -------------- */

// Function to check if input coordinate format is valid
bool ChessBoard::inputIsValid(std::string coord)
{
	int x, y, input_count;

	// Check input length
	input_count = coord.size();
	if (input_count != 2)
	{
		cout << "Invalid move input " << coord << ". "
			 << "The input should be an Alphabet (A - H) followed by "
			 << "a number (1 - 8)" << endl;
		return false;
	}

	x = coord[0];
	y = coord[1];

	// Ensure that x coordinate input is within bound
	if (x < 'A' || x > 'H')
	{
		cout << "Input " << coord << " is out of bound. "
			 << "The input should be an Alphabet (A - H) followed by a number "
			 << "(1 - 8)" << endl;
		return false;
	}

	// Ensure that y coordinate input is within bound
	if (y < '1' || y > '8')
	{
		cout << "Input " << coord << " is out of bound. "
			 << "The input should be an Alphabet (A - H) followed by a number "
			 << "(1 -  8)" << endl;
		return false;
	}
	return true;
}

/* Function to check if <input> player is in-check by checking if the player's
 * King is under threat by pieces from the opposing team except for the 
 * opposing team's king */
bool ChessBoard::isInCheck(int player)
{
	// Get current location of player's King on the chessboard
	int king_row = player == WHITE
					   ? white_pieces[12]->getRow()
					   : black_pieces[12]->getRow();

	int king_col = player == WHITE
					   ? white_pieces[12]->getCol()
					   : black_pieces[12]->getCol();

	// Get chess pieces from the opposing team
	ChessPiece **opp_pieces = player == WHITE ? black_pieces : white_pieces;

	/* Iterate through all chess pieces from the opposing team and check 
	 * if any of them can directly threaten / capture the player's king - chess
	 * piece "can move" to the king's location */
	for (int i = 0; i < 16; i++)
	{
		if (i != 12 && 
			!opp_pieces[i]->isCaptured() && 
			opp_pieces[i]->canMove(board, king_row, king_col, 
									false, white_pieces, black_pieces))
		{
			return true;
		}
	}

	return false;
}

/* Function that checks if a potential move from (src_row, src_col)
 * to (dest_row, dest_col) will expose Player to be in check. The game state 
 * is not modified by this function */
bool ChessBoard::isCheckAfterMove(int player, int src_row, int src_col, 
								  int dest_row, int dest_col)
{
	// Return value
	bool is_check_after_move = false;

	// Pointers to chess pieces at the source and destination location on 
	// the board
	ChessPiece *src_piece = this->board[src_row][src_col];
	ChessPiece *dest_piece = this->board[dest_row][dest_col];

	// Check if this is trial piece first move
	bool is_trial_piece_first_move = src_piece->isFirstMove();

	// Make the potential move
	// Capture piece if destination contains a chess piece
	if (dest_piece != nullptr) 
	{
		dest_piece->capturePiece();
	}

	// Set destination to be the source piece
	this->board[dest_row][dest_col] = src_piece;

	// Update location of the source piece
	this->board[dest_row][dest_col]->setLocation(dest_row, dest_col);

	// Update first move status
	if (is_trial_piece_first_move)
	{
		this->board[dest_row][dest_col]->move();
	}

	/* Remove chess piece at source location by setting board at source 
	 * location to nullptr */
	this->board[src_row][src_col] = nullptr;

	// Check if Player is in check after the potential move
	if (this->isInCheck(player))
	{ 
		is_check_after_move = true;
	}

	/* Undo move by reseting the game state to the initial state
	 * before the potential move was made */
	
	// Moving source piece back to the original position
	this->board[src_row][src_col] = this->board[dest_row][dest_col];

	// Update location of source piece back to the original position
	this->board[src_row][src_col]->setLocation(src_row, src_col);

	// If it was the trial piece's first move, reset is_first_move status
	if (is_trial_piece_first_move) 
	{
		this->board[src_row][src_col]->unMove();
	}
	
	// Set distination location to the piece before being removed
	this->board[dest_row][dest_col] = dest_piece;

	// Upcapture piece if destination contains a chess piece
	if (dest_piece != nullptr) 
	{
		dest_piece->unCapturePiece();
	}

	return is_check_after_move;
}

/* Function that checks if a Player is out of legal moves. The function 
 * checks if there are any moves left for player without being in
 * check after move */
bool ChessBoard::isOutOfMoves(int player, bool in_check)
{
	// Get player's chess pieces
	ChessPiece **chess_pieces = player == WHITE ? white_pieces : black_pieces;

	/* Iterate through all uncaptured chess pieces from the player's team 
	 * and try all possible moves on the board whilst checking if there 
	 * is any moves which will allow player to escape from being in check 
	 * or avoid being in check */
	for (int i = 0; i < 16; i++)
	{
		ChessPiece *trial_piece = chess_pieces[i];
		int trial_row = trial_piece->getRow();
		int trial_col = trial_piece->getCol();

		if (!trial_piece->isCaptured())
		{
			for (int dest_row = 0; dest_row < ROW_NO; dest_row++)
			{
				for (int dest_col = 0; dest_col < COL_NO; dest_col++)
				{
					/* Check if destination location is empty and does not 
					 * contain a chess piece which has the same color as the 
					 * trial piece */
					ChessPiece *dest_piece = board[dest_row][dest_col];
					if (dest_piece == nullptr ||
						dest_piece->getColor() != trial_piece->getColor())
					{
						/* Check if trial piece can move to destination and
						 * check if player is in check after move */
						if (trial_piece->canMove(board, dest_row, dest_col, //
												in_check, white_pieces, 	//
												black_pieces) &&
							!this->isCheckAfterMove(player, trial_row,	//
													trial_col, dest_row,// 
													dest_col))
						{
							return false;
						}
					}
				}
			}
		}
	}
	return true;
}

/* ------------ Game State Setter functions ------------- */

/* Function which updates the game state (i.e. Location of the Chess 
 * Pieces on board, Player's turn, check status and etc) and prints out the 
 * relevant output messages */
void ChessBoard::makeMove(std::string src_square, std::string dest_square)
{
	/* Convert source and destination square coordinates to integer for ease
	 * of referencing using the board array */
	int src_row = src_square[1] - '1';
	int src_col = src_square[0] - 'A';
	int dest_row = dest_square[1] - '1';
	int dest_col = dest_square[0] - 'A';
	bool isCastlingMove = false;

	/* Check if it is a castling move - a castling move must involve the King
	 * moving 2 spot */
	if (board[src_row][src_col]->getName() == "King" &&
		abs(dest_col - src_col) == 2)
	{
		isCastlingMove = true;
	}

	// Printing make move messages
	if (isCastlingMove)
	{
		cout << "Castling Move: " << printName(board[src_row][src_col]) 
			 << " has " << (dest_col > src_col ? "King-side" : "Queen-side")
			 << " castled" << endl;
	}
	else if (board[dest_row][dest_col] != nullptr)
	{
		cout << printName(board[src_row][src_col]) << " moves from "
			 << src_square << " to " << dest_square
			 << " taking " << printName(board[dest_row][dest_col]) << endl;
	}
	else
	{
		cout << printName(board[src_row][src_col]) << " moves from "
			 << src_square << " to " << dest_square << endl;
	}

	// Capture piece if destination square contains a chesspiece
	if (board[dest_row][dest_col] != nullptr)
	{
		board[dest_row][dest_col]->capturePiece();
	}

	// Set board at destination to point to Chess Piece at source location
	this->board[dest_row][dest_col] = this->board[src_row][src_col];

	// Set Board at source to null
	this->board[src_row][src_col] = nullptr;

	// Update coordinates of the chess piece
	this->board[dest_row][dest_col]->setLocation(dest_row, dest_col);

	// Update is_first_move status of chess piece
	this->board[dest_row][dest_col]->move();

	if (isCastlingMove)
	{
		// Move Rook
		int rook_col = dest_col > src_col ? 7 : 0;
		int new_rook_col = dest_col > src_col ? 5 : 3;

		this->board[dest_row][new_rook_col] = this->board[dest_row][rook_col];

		this->board[dest_row][rook_col] = nullptr;

		this->board[dest_row][new_rook_col]->setLocation(dest_row, new_rook_col);

		this->board[dest_row][new_rook_col]->move();
	}

	// Check if opponent is in-check 
	if (this->isInCheck(player_turn == WHITE ? BLACK : WHITE))
	{
		// Opponent is in-check
		if (this->isOutOfMoves(player_turn == WHITE ? BLACK : WHITE, true))
		/* If opponent is in-check and is out of moves, then opponent is 
		 * in checkmate */
		{
			cout << (player_turn == WHITE ? "Black" : "White")
				 << " is in checkmate" << endl;
			in_checkmate = true;
		}
		else
		/* If opponent is in-check and still have moves available then 
		 * opponent is in-check only */
		{
			cout << (player_turn == WHITE ? "Black" : "White")
				 << " is in check" << endl;
			in_check = true;
		}
	}
	else
	{
		// Opponent is not in-check
		if (this->isOutOfMoves(player_turn == WHITE ? BLACK : WHITE, false))
		/* If opponent is not in-check but is out of moves then game is in
		 * stalemate */
		{
			cout << (this->player_turn == WHITE ? "Black" : "White")
				 << " is in stalemate" << endl;
			this->in_stalemate = true;
		}
		
		this->in_check = false;
	}

	// Update Player's turn
	this->player_turn = this->player_turn == WHITE ? BLACK : WHITE;
}

/* Function to submit move to chess board */
void ChessBoard::submitMove(std::string src_square, std::string dest_square)
{
	/* Convert source and destination square coordinates to integer for ease
	 * of referencing the 2D board array */
	int src_row = src_square[1] - '1';
	int src_col = src_square[0] - 'A';
	int dest_row = dest_square[1] - '1';
	int dest_col = dest_square[0] - 'A';

	ChessPiece *src_piece;	// Pointer to chess piece at source location
	ChessPiece *dest_piece; // Pointer to chess piece at destination location

	// Check if game has already ended
	if (this->in_checkmate)
	{
		cout << "Game has already ended. "
			 << (this->player_turn == WHITE ? "Black" : "White")
			 << " has Won the game!" << endl;
		return;
	}

	// Check if game is in stalemate
	if (this->in_stalemate)
	{
		cout << "Game has already ended in stalemate." << endl;
		return;
	}

	/* Check src input and dest input are valid i.e. within bounds and numeric
	 * character only */
	if (!this->inputIsValid(src_square) || !this->inputIsValid(dest_square))
	{
		cout << "Unable to move piece from " << src_square << " to "
			 << dest_square << " as input is not valid." << endl;
		return;
	}

	// Check if source location has a chess piece
	if (this->board[src_row][src_col] == nullptr)
	{
		cout << "There is no piece at position " << src_square 
			 << "!" << endl;
		return;
	}

	// Check if source and destination location is the same - not moving
	if (src_row == dest_row && src_col == dest_col)
	{
		cout << "Unable to move chess piece from " 
			 << src_square << " to " << dest_square
			 << " .Source and destination location is the same." << endl;
		return;
	}

	// Check if it is player's turn to move
	src_piece = this->board[src_row][src_col];
	if (src_piece->getColor() != this->player_turn)
	{
		cout << "It is not " 
			 << (this->player_turn == WHITE ? "Black" : "White")
			 << "'s turn to move!" << endl;
		return;
	}

	/* If there is a chess piece at the destination location, check if color 
	 * of the chess pieces at source and destination is the same, */
	if (this->board[dest_row][dest_col] != nullptr)
	{
		dest_piece = this->board[dest_row][dest_col];
		if (src_piece->getColor() == dest_piece->getColor())
		{
			cout << "Unable to move " << this->printName(src_piece) << " from "
				 << src_square << " to " << dest_square << ". "
				 << "As " << dest_square
				 << " is currently occupied by " << this->printName(dest_piece)
				 << endl;
			return;
		}
	}

	/* At this point, check move logic for chess piece. Check if it is legal
	 * to move from source to destination location. The canMove function 
	 * only checks the logic of the move but it does not check if the move
	 * will expose the chess piece to be in-check. */
	if (src_piece->canMove(this->board, dest_row, dest_col, this->in_check, //
						   this->white_pieces, this->black_pieces))
	{
		// Check if move will expose king to be in-check. 
		if (this->isCheckAfterMove(player_turn, src_row, src_col, dest_row, //
								   dest_col))
		{
			// player's king is in-check after move
			cout << this->printName(src_piece) << " cannot move from "
				 << src_square << " to " << dest_square << "!";
			
			if (this->in_check)
			{
			// King already in-check before move is made
				cout << " As "
					 << (this->player_turn == WHITE ? "White" : "Black")
					 << "'s King is currently being checked." << endl;
			}
			else
			{
			// King will be in check after move
				cout << " As this will expose "
					 << (this->player_turn == WHITE ? "White" : "Black")
					 << "'s King to being checked." << endl;
			}
		}
		else
		{
			/* Player's king is not in-check after move and move is valid. 
			 * Therefore, make move */
			this->makeMove(src_square, dest_square);
		}
	}
	else
	{
		cout << this->printName(src_piece) << " cannot move " 
			 << "to " << dest_square << "!" 
			 << endl;
	}
	return;
}

/* --------------- Board Helper Functions --------------- */

// Function to print chessboard for debugging
void ChessBoard::printBoard()
{
	cout << "    A   B   C   D   E   F   G   H  " << endl;
	cout << "  + - + - + - + - + - + - + - + - +" << endl;
	for (int i = 7; i >= 0; i--)
	{
		cout << i + 1 << " |";
		for (int j = 0; j < 8; j++)
		{
			if (this->board[i][j] == nullptr)
			{
				cout << " "
					 << " "
					 << " |";
			}
			else
			{
				cout << " " << this->board[i][j]->getSymbol() << " |";
			}
		}
		cout << " " << i + 1 << endl;
		cout << "  + - + - + - + - + - + - + - + - +" << endl;
	}
	cout << "    A   B   C   D   E   F   G   H  " << endl;
}

// Function to print name of Chess Piece in the following format
// <color>'s <piece_name>
std::string ChessBoard::printName(ChessPiece const *piece)
{
	std::string color = piece->getColor() == WHITE ? "White" : "Black";
	std::string pieceName = piece->getName();
	return color + "'s " + pieceName;
}

/* ------------------- Deconstructor -------------------- */
ChessBoard::~ChessBoard()
{
	// Deallocate heap memory used to store chess pieces
	this->removePieces();
}
