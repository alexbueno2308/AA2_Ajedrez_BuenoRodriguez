#include "Const.h"
#include "Utils.h"

void initchessboard(char chessboard[BOARD_SIZE][BOARD_SIZE]) {
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++) {
			//set PAWNS
			if (j == BOARD_SIZE - 2) chessboard[j][i] = WHITE_PAWN;
			else if (j == 1) chessboard[j][i] = BLACK_PAWN;
			else chessboard[j][i] = EMPTY; //set empty
		}
	}



	const short rookYPosL = 0;
	const short rookYPosR = BOARD_SIZE - 1;
	const short knightYPosL = 1;
	const short knightYPosR = BOARD_SIZE - 2;
	const short bishopYPosL = 2;
	const short bishopYPosR = BOARD_SIZE - 3;

	const short whiteKingYPosL = 3;
	const short WhiteQueenYPosR = BOARD_SIZE - 4;
	const short blackKingYPosR = BOARD_SIZE - 4;
	const short blackQueenYPosL = 3;

	//set black chess pieces
	chessboard[0][rookYPosL] = BLACK_ROOK;
	chessboard[0][rookYPosR] = BLACK_ROOK;
	chessboard[0][knightYPosL] = BLACK_KNIGHT;
	chessboard[0][knightYPosR] = BLACK_KNIGHT;
	chessboard[0][bishopYPosL] = BLACK_BISHOP;
	chessboard[0][bishopYPosR] = BLACK_BISHOP;
	chessboard[0][blackKingYPosR] = BLACK_KING;
	chessboard[0][blackQueenYPosL] = BLACK_QUEEN;

	//set white chess pieces
	chessboard[BOARD_SIZE-1][rookYPosL] = WHITE_ROOK;
	chessboard[BOARD_SIZE-1][rookYPosR] = WHITE_ROOK;
	chessboard[BOARD_SIZE-1][knightYPosL] = WHITE_KNIGHT;
	chessboard[BOARD_SIZE-1][knightYPosR] = WHITE_KNIGHT;
	chessboard[BOARD_SIZE-1][bishopYPosL] = WHITE_BISHOP;
	chessboard[BOARD_SIZE-1][bishopYPosR] = WHITE_BISHOP;
	chessboard[BOARD_SIZE-1][whiteKingYPosL] = WHITE_KING;
	chessboard[BOARD_SIZE-1][WhiteQueenYPosR] = WHITE_QUEEN;

	std::cout << "hola";
}

void viewchessboard(char chessboard[BOARD_SIZE][BOARD_SIZE]) {

	std::cout << ' ' << ' ';
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		std::cout << i + 1 << ' ';
	}
	std::cout << std::endl;

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		std::cout << BOARD_SIZE - i << ' ';
		for (int j = 0; j < BOARD_SIZE; j++) {
			std::cout << chessboard[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

Position getPieceByUser(char chessboard[BOARD_SIZE][BOARD_SIZE], bool isWhiteTurn) {

	Position userGetPiece;
	bool isGettingAPiece = true;
	do {

		isGettingAPiece = true;
		
			std::cout << "-----------------" << std::endl;
			std::cout << "Elige una pieza:" << std::endl;
			std::cout << "X: ";
			std::cin >> userGetPiece.x;
			std::cout << "Y: ";
			std::cin >> userGetPiece.y;

			userGetPiece.x--;

			userGetPiece.y--;
			userGetPiece.y = BOARD_SIZE - userGetPiece.y;

			if (userGetPiece.x <0 || userGetPiece.x >BOARD_SIZE-1 ||	userGetPiece.y <0 || userGetPiece.y >BOARD_SIZE-1) {
				std::cout << "INPUT INVALIDO: Te pasas de los limites" << std::endl;
				isGettingAPiece = false;
			}
			else if (chessboard[userGetPiece.x][userGetPiece.y] == EMPTY)
			{
				std::cout << "INPUT INVALIDO: Aqui no hay ninguna pieza" << std::endl;
				isGettingAPiece = false;
			}


	} while (!isGettingAPiece);
}