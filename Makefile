all: chess

chess: ChessMain.o ChessBoard.o ChessPiece.o Pawn.o Rook.o Knight.o Bishop.o Queen.o King.o
	g++ -Wall -g ChessMain.o ChessBoard.o ChessPiece.o Pawn.o Rook.o Knight.o Bishop.o Queen.o King.o -o chess

ChessMain.o: ChessMain.cpp ChessBoard.h
	g++ -Wall -c ChessMain.cpp 

ChessBoard.o: ChessBoard.cpp ChessBoard.h
	g++ -Wall -c ChessBoard.cpp

ChessPiece.o: ChessPiece.cpp ChessPiece.h
	g++ -Wall -c ChessPiece.cpp

Pawn.o: Pawn.cpp Pawn.h
	g++ -Wall -c Pawn.cpp

Rook.o: Rook.cpp Rook.h
	g++ -Wall -c Rook.cpp

Knight.o: Knight.cpp Knight.h
	g++ -Wall -c Knight.cpp

Bishop.o: Bishop.cpp Bishop.h
	g++ -Wall -c Bishop.cpp

Queen.o: Queen.cpp Queen.h
	g++ -Wall -c Queen.cpp

King.o: King.cpp King.h
	g++ -Wall -c King.cpp

clean:
	rm -f *.o

