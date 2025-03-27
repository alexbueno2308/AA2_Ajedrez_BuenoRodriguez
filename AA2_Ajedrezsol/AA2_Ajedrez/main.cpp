#include "Const.h"
#include "Board.h"
#include "Utils.h"

int main() {

	char chessboard[BOARD_SIZE][BOARD_SIZE];
	bool gameOver = false;
	bool isWhiteTurn = true;
	initchessboard(chessboard);

	do {
		std::string actualTurn = isWhiteTurn ? "BLANCAS" : "NEGRAS";
		std::cout << "Turno de las: " << actualTurn << std::endl;

		viewchessboard(chessboard);

		Position userGetPiece, userSetPiece;

		userGetPiece = getPieceByUser(chessboard, isWhiteTurn);

		isWhiteTurn = !isWhiteTurn;
		system("cls");
	} while (!gameOver);

}