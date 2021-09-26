#include"ChessBoard.h"

#include<iostream>

using std::cout;
using std::endl;

int main() {

	cout << "========================\n";
	cout << "Testing the Chess Engine\n";
	cout << "========================\n\n";

	ChessBoard cb;
	cout << '\n';
	
	cb.submitMove("D7", "D6");
	cout << '\n';
	
	cb.submitMove("D4", "H6");
	cout << '\n';

	cb.submitMove("D2", "D4");
	cout << '\n';

	cb.submitMove("F8", "B4");
	cout << '\n';
	
	cout << "=========================\n";
	cout << "Alekhine vs. Vasic (1931)\n";
	cout << "=========================\n\n";

	cb.resetBoard();
	cout << '\n';

	cb.submitMove("E2", "E4");
	cb.submitMove("E7", "E6");
	cout << '\n';

	cb.submitMove("D2", "D4");
	cb.submitMove("D7", "D5");
	cout << '\n';
	

	cb.submitMove("B1", "C3");
/*	
	cout << "\n============================= Test Cases (Pawn) ==============================\n";
	cout << "Pawn (black)::Test - Leap Over Opponent\n";
	cb.submitMove("D5", "D3");
	cout << "------------------------------------------------------------------------------\n";
	cout << "Pawn (black)::Test - Capture Enemy in front\n";
	cb.submitMove("D5", "D4");
	cout << "------------------------------------------------------------------------------\n";
	cout << "Pawn (black)::Test - Moving diagonal (right) without capture\n";
	cb.submitMove("E6", "F5");
	cout << "------------------------------------------------------------------------------\n";
	cout << "Pawn (black)::Test - Moving diagonal (left) without capture\n";
	cb.submitMove("D5", "C4");
	cout << "------------------------------------------------------------------------------\n";
	cout << "Pawn (black)::Test - Moving Backwards\n";
	cb.submitMove("E6", "E7");
	cout << "------------------------------------------------------------------------------\n";
	cout << "Pawn (black)::Test - Moving Backwards diagonal\n";
	cb.submitMove("D5", "D6");
	cout << "------------------------------------------------------------------------------\n";
	cout << "Pawn (black)::Test - Capture own piece\n";
	cb.submitMove("E6", "D5");
	cout << "==================================== End =======================================\n\n";
*/	
	cb.submitMove("F8", "B4");
	cout << '\n';
/*	
	cout << "\n============================= Test Cases (Pawn) ==============================\n";
	cout << "Pawn (white)::Test - Leap Over Opponent\n";
	cb.submitMove("D4", "D6");
	cout << "------------------------------------------------------------------------------\n";
	cout << "Pawn (white)::Test - Capture Enemy in front\n";
	cb.submitMove("D4", "D5");
	cout << "------------------------------------------------------------------------------\n";
	cout << "Pawn (white)::Test - Moving diagonal (right) without capture\n";
	cb.submitMove("D4", "E5");
	cout << "------------------------------------------------------------------------------\n";
	cout << "Pawn (white)::Test - Moving diagonal (left) without capture\n";
	cb.submitMove("D4", "C5");
	cout << "------------------------------------------------------------------------------\n";
	cout << "Pawn (white)::Test - Moving Backwards\n";
	cb.submitMove("E4", "E3");
	cout << "------------------------------------------------------------------------------\n";
	cout << "Pawn (white)::Test - Moving Backwards diagonal\n";
	cb.submitMove("E4", "F3");
	cout << "------------------------------------------------------------------------------\n";
	cout << "Pawn (white)::Test - Capture Own Piece\n";
	cb.submitMove("B2", "C3");	
	cout << "==================================== End =======================================\n\n";
	
	cout << "\n============================ Test Cases (Bishop) =============================\n";
	cout << "Bishop (White)::Test - Leap Over Chess Piece\n";
	cb.submitMove("C1", "A3");	
	cout << "------------------------------------------------------------------------------\n";
	cout << "Bishop (White)::Test - Leap Over Chess Piece\n";
	cb.submitMove("F1", "H3");
	cout << "------------------------------------------------------------------------------\n";
	cout << "Bishop (White)::Test - Move horizontally without capture\n";
	cb.submitMove("C1", "B1");
	cout << "------------------------------------------------------------------------------\n";
	cout << "Bishop (White)::Test - Capture own piece\n";
	cb.submitMove("C1", "B2");
	cout << "==================================== End =======================================\n\n";
	
	cout << "\n============================ Test Cases (Board) ==============================\n";
	cout << "Board::Test - Expose King to being Capture / Check\n";
	cb.submitMove("C3", "A4");	
	cout << "==================================== End =======================================\n\n";
*/	
	cb.submitMove("F1", "D3");
/*	
	cout << "\n============================ Test Cases (Bishop) =============================\n";
	cout << "Bishop (black)::Test - Leap Over Opponent\n";
	cb.submitMove("B4", "D2");
	cout << "--------------------------------------------------------------------------------\n";
	cout << "Bishop (black)::Test - Move vertically and Capture Enemy\n";
	cb.submitMove("B4", "B2");
	cout << "--------------------------------------------------------------------------------\n";
	cout << "Bishop (black)::Test - Moving vertically without capture\n";
	cb.submitMove("B4", "B6");
	cout << "--------------------------------------------------------------------------------\n";
	cout << "Bishop (black)::Test - Moving horizontally without capture\n";
	cb.submitMove("B4", "C4");
	cout << "--------------------------------------------------------------------------------\n";
	cout << "Bishop (black)::Test - Capture own piece\n";
	cb.submitMove("C8", "B7");
	cout << "==================================== End =======================================\n\n";
*/	
	cb.submitMove("B4", "C3");
	cout << '\n';
/*	
	cout << "\n============================ Test Cases (Board) =============================\n";
	// White King is now being checked try moves where Check will continue
	cout << "Board::Test - Expose King to being Capture / Check\n";
	cb.submitMove("B2", "B4");		
	cout << "--------------------------------------------------------------------------------\n";
	cout << "Board::Test - Expose King to being Capture / Check\n";
	cb.submitMove("G1", "F3");
	cout << "==================================== End =======================================\n\n";
*/	
	cb.submitMove("B2", "C3");
	cb.submitMove("H7", "H6");
	cout << '\n';
/*	
	cout << "\n============================ Test Cases (Pawn) ===============================\n";
	cout << "Pawn (White)::Test - Double Move after first Move\n";
	cb.submitMove("C3", "C5");	
	cout << "==================================== End =======================================\n\n";
*/	
	cb.submitMove("C1", "A3");
/*	
	cout << "\n============================ Test Cases (Pawn) ===============================\n";
	cout << "Pawn (Black)::Test - Double Move after first Move\n";
	cb.submitMove("H6", "H4");	
	cout << "==================================== End =======================================\n\n";
*/	
	cb.submitMove("B8", "D7");
	cout << '\n';

	cb.submitMove("D1", "E2");
	cb.submitMove("D5", "E4");
	cout << '\n';

	cb.submitMove("D3", "E4");
	cb.submitMove("G8", "F6");
	cout << '\n';
/*	
	cout << "\n=========================== Test Cases (Queen) ===============================\n";
	cout << "Queen (White)::Test - Taking own piece\n";
	cb.submitMove("E2", "C2");		
	cout << "--------------------------------------------------------------------------------\n";
	cout << "Queen (White)::Test - Horizontal moving over other piece\n";
	cb.submitMove("E2", "B2");
	cout << "--------------------------------------------------------------------------------\n";
	cout << "Queen (White)::Test - Vertical moving over other piece\n";
	cb.submitMove("E2", "E7");
	cout << "--------------------------------------------------------------------------------\n";
	cout << "Queen (White)::Test - Illegal Pathing\n";
	cb.submitMove("E2", "F4");
	cout << "--------------------------------------------------------------------------------\n";
	cout << "Queen (White)::Test - Illegal Pathing\n";
	cb.submitMove("E2", "D5");
	cout << "==================================== End =======================================\n\n";
*/	
	cb.submitMove("E4", "D3");
/*	
	cout << "\n=========================== Test Cases (Knight) ==============================\n";
	cout << "Knight (Black)::Test - Capture own piece\n";
	cb.submitMove("F6", "D7");
	cout << "--------------------------------------------------------------------------------\n";
	cout << "Knight (Black)::Test - Move Horizontal - 1\n";
	cb.submitMove("F6", "G6");	
	cout << "--------------------------------------------------------------------------------\n";
	cout << "Knight (Black)::Test - Move Horizontal - 2\n";
	cb.submitMove("F6", "D6");	
	cout << "--------------------------------------------------------------------------------\n";
	cout << "Knight (Black)::Test - Move Vertical - 1\n";
	cb.submitMove("D7", "D6");	
	cout << "--------------------------------------------------------------------------------\n";
	cout << "Knight (Black)::Test - Move Vertical - 2\n";
	cb.submitMove("D7", "D5");
	cout << "--------------------------------------------------------------------------------\n";
	cout << "Knight (Black)::Test - Move Diagonal - 1\n";
	cb.submitMove("F6", "E5");	
	cout << "--------------------------------------------------------------------------------\n";
	cout << "Knight (Black)::Test - Move Diagonal - 2\n";
	cb.submitMove("D7", "D5");	
	cout << "==================================== End =======================================\n\n";
*/	
	cb.submitMove("B7", "B6");
	cout << '\n';

	cb.submitMove("E2", "E6");
	cb.submitMove("F7", "E6");
	cout << '\n';
/*	
	cout << "\n============================ Test Cases (Rook) ===============================\n";
	cout << "Rook (White)::Test - Capture own piece\n";
	cb.submitMove("A1", "A2");	
	cout << "--------------------------------------------------------------------------------\n";
	cout << "Rook (White)::Test - Move Diagonally\n";
	cb.submitMove("A1", "B2");	
	cout << "--------------------------------------------------------------------------------\n";
	cout << "Rook (White)::Test - Jump over pieces\n";
	cb.submitMove("A1", "A4");
	cout << "--------------------------------------------------------------------------------\n";
	cout << "Rook (White)::Test - Jump over pieces\n";
	cb.submitMove("H1", "F1");
	cout << "==================================== End =======================================\n\n";
*/	
	cb.submitMove("D3", "G6");
	cout << '\n';
	cb.printBoard();

	cout << "=========================\n";
	cout << "Scholar's Mate \n";
	cout << "=========================\n\n";

	cb.resetBoard();
	cout << '\n';

	cb.submitMove("E2", "E4");
	cb.submitMove("E7", "E5");
	cout << '\n';

	cb.submitMove("F1", "C4");
	cb.submitMove("B8", "C6");
	cout << '\n';

	cb.submitMove("D1", "H5");
	cb.submitMove("G8", "F6");
	cout << '\n';
	
	cb.submitMove("H5", "F7");
	cout << '\n';
	cb.printBoard();
	
	cout << "\n=========================\n";
	cout << "Fool's Mate \n";
	cout << "=========================\n\n";

	cb.resetBoard();
	cout << '\n';

	cb.submitMove("F2", "F3");
	cb.submitMove("E7", "E5");
	cout << '\n';

	cb.submitMove("G2", "G4");
	cb.submitMove("D8", "H4");
	cout << '\n';
	cb.printBoard();

	cout << "=============================\n";
	cout << "The Immortal Game\n";
	cout << "Anderssen - Kieseritzky (1851)\n";
	cout << "==============================\n\n";
	
	cb.resetBoard();
	cout << '\n';

	cb.submitMove("E2", "E4");
	cb.submitMove("E7", "E5");
	cout << '\n';

	cb.submitMove("F2", "F4");
	cb.submitMove("E5", "F4");
	cout << '\n';

	cb.submitMove("F1", "C4");
	cb.submitMove("D8", "H4");
	cout << '\n';

	cb.submitMove("E1", "F1");
	cb.submitMove("B7", "B5");
	cout << '\n';

	cb.submitMove("C4", "B5");
	cb.submitMove("G8", "F6");
	cout << '\n';

	cb.submitMove("G1", "F3");
	cb.submitMove("H4", "H6");
	cout << '\n';

	cb.submitMove("D2", "D3");
	cb.submitMove("F6", "H5");
	cout << '\n';

	cb.submitMove("F3", "H4");
	cb.submitMove("H6", "G5");
	cout << '\n';

	cb.submitMove("H4", "F5");
	cb.submitMove("C7", "C6");
	cout << '\n';

	cb.submitMove("G2", "G4");
	cb.submitMove("H5", "F6");
	cout << '\n';

	cb.submitMove("H1", "G1");
	cb.submitMove("C6", "B5");
	cout << '\n';

	cb.submitMove("H2", "H4");
	cb.submitMove("G5", "G6");
	cout << '\n';

	cb.submitMove("H4", "H5");
	cb.submitMove("G6", "G5");
	cout << '\n';

	cb.submitMove("D1", "F3");
	cb.submitMove("F6", "G8");
	cout << '\n';

	cb.submitMove("C1", "F4");
	cb.submitMove("G5", "F6");
	cout << '\n';

	cb.submitMove("B1", "C3");
	cb.submitMove("F8", "C5");
	cout << '\n';

	cb.submitMove("C3", "D5");
	cb.submitMove("F6", "B2");
	cout << '\n';

	cb.submitMove("F4", "D6");
	cb.submitMove("C5", "G1");
	cout << '\n';

	cb.submitMove("E4", "E5");
	cb.submitMove("B2", "A1");
	cout << '\n';

	cb.submitMove("F1", "E2");
	cb.submitMove("B8", "A6");
	cout << '\n';

	cb.submitMove("F5", "G7");
	cb.submitMove("E8", "D8");
	cout << '\n';

	cb.submitMove("F3", "F6");
	cb.submitMove("G8", "F6");
	cout << '\n';

	cb.submitMove("D6", "E7");
	cout << '\n';
	cb.printBoard();

	cout << "===========================\n";
	cout << "Hohmeister vs. Frank (1993)\n";
	cout << "===========================\n\n";
	
	cb.resetBoard();
	cout << '\n';

	cb.submitMove("D2", "D4");
	cb.submitMove("E7", "E5");
	cout << '\n';

	cb.submitMove("D1", "D2");
	cb.submitMove("E5", "E4");
	cout << '\n';

	cb.submitMove("D2", "F4");
	cb.submitMove("F7", "F5");
	cout << '\n';

	cb.submitMove("H2", "H3");
	cb.submitMove("F8", "B4");
	cout << '\n';

	cb.submitMove("B1", "D2");
	cb.submitMove("D7", "D6");
	cout << '\n';

	cb.submitMove("F4", "H2");
	cb.submitMove("C8", "E6");
	cout << '\n';

	cb.submitMove("A2", "A4");
	cb.submitMove("D8", "H4");
	cout << '\n';

	cb.submitMove("A1", "A3");
	cb.submitMove("C7", "C5");
	cout << '\n';

	cb.submitMove("A3", "G3");
	cb.submitMove("F5", "F4");
	cout << '\n';

	cb.submitMove("F2", "F3");
	cb.submitMove("E6", "B3");
	cout << '\n';

	cb.submitMove("D4", "D5");
	cb.submitMove("B4", "A5");
	cout << '\n';

	cb.submitMove("C2", "C4");
	cb.submitMove("E4", "E3");
	cout << '\n';
	cb.printBoard();

	cout << "===========================\n";
	cout << "Alekhine vs. Feldt (1916)\n";
	cout << "===========================\n\n";
	
	cb.resetBoard();
	cout << '\n';
	
	cb.submitMove("E2", "E4");
	cb.submitMove("E7", "E6");
	cout << '\n';

	cb.submitMove("D2", "D4");
	cb.submitMove("D7", "D5");
	cout << '\n';

	cb.submitMove("B1", "C3");
	cb.submitMove("G8", "F6");
	cout << '\n';

	cb.submitMove("E4", "D5");
	cb.submitMove("F6", "D5");
	cout << '\n';

	cb.submitMove("C3", "E4");
	cb.submitMove("F7", "F5");
	cout << '\n';

	cb.submitMove("E4", "G5");
	cb.submitMove("F8", "E7");
	cout << '\n';

	cb.submitMove("G5", "F3");
	cb.submitMove("C7", "C6");
	cout << '\n';

	cb.submitMove("F3", "E5");
	cb.submitMove("E8", "G8");
	cout << '\n';

	cb.submitMove("G1", "F3");
	cb.submitMove("B7", "B6");
	cout << '\n';

	cb.submitMove("F1", "D3");
	cb.submitMove("C8", "B7");
	cout << '\n';

	cb.submitMove("E1", "G1");
	cb.submitMove("F8", "E8");
	cout << '\n';

	cb.submitMove("C2", "C4");
	cb.submitMove("D5", "F6");
	cout << '\n';
/*	
	cout << "\n============================ Test Cases (Pawn) ===============================\n";
	cout << "Pawn (White)::Test - Diagonal Move two spot to capture\n";
	cb.submitMove("C4", "E6");		
	cout << "--------------------------------------------------------------------------------\n";
	cout << "Pawn (White)::Test - Forward Move two spot to capture \n";
	cb.submitMove("C4", "C6");
	cout << "--------------------------------------------------------------------------------\n";
	cout << "Pawn (White)::Test - Backward Move two spot \n";
	cb.submitMove("C4", "C2");
	cout << "--------------------------------------------------------------------------------\n";
	cout << "Pawn (White)::Test - Double forward move\n";
	cb.submitMove("D4", "D6");
	cout << "--------------------------------------------------------------------------------\n";
	cout << "Pawn (White)::Test - Triple forward move\n";
	cb.submitMove("D4", "D7");
	cout << "==================================== End =======================================\n\n";
*/	
	cb.submitMove("C1", "F4");
	cb.submitMove("B8", "D7");
	cout << '\n';

	cb.submitMove("D1", "E2");
	cb.submitMove("C6", "C5");
	cout << '\n';

	cb.submitMove("E5", "F7");
	cb.submitMove("G8", "F7");
	cout << '\n';

	cb.submitMove("E2", "E6");
	cb.submitMove("F7", "G6");
	cout << '\n';

	cb.submitMove("G2", "G4");
	cb.submitMove("B7", "E4");
	cout << '\n';

	cb.submitMove("F3", "H4");
	cout << '\n';
	cb.printBoard();

	return 0;
}
