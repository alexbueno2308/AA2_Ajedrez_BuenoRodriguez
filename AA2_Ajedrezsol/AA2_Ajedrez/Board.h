#pragma once
#include "Const.h"
#include "Utils.h"

void initchessboard(char chessboard[BOARD_SIZE][BOARD_SIZE]);
void viewchessboard(char chessboard[BOARD_SIZE][BOARD_SIZE]);

Position getPieceByUser(char chessboard[BOARD_SIZE][BOARD_SIZE], bool isWhiteTurn);
void serPieceByUser();