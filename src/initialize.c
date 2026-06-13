#include "constants.h"
#include "globals.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initializePeices(int row, int column) {
  gameBoard[row][column].isWhite = row == 6 || row == 7;

  switch (row) {
  case 0:
  case 7:
    gameBoard[row][column].PeiceType = SquareOrder[column];
    break;
  case 1:
  case 6:
    gameBoard[row][column].PeiceType = Pawn;
    break;
  default:
    gameBoard[row][column].PeiceType = Empty;
    break;
  }
}

void initializeBoard() {
  for (int row = 0; row < GAME_BOARD_SIZE; row++) {
    for (int column = 0; column < GAME_BOARD_SIZE; column++) {
      initializePeices(row, column);
    }
  }
}
