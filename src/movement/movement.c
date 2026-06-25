#include "movement.h"
#include "globals.h"

void movePeice(struct BoardPosition boardPositionFrom,
               struct BoardPosition boardPositionTo) {

  gameBoard[boardPositionTo.row][boardPositionTo.column] =
      gameBoard[boardPositionFrom.row][boardPositionFrom.column];

  gameBoard[boardPositionFrom.row][boardPositionFrom.column] = emptyGamePeice;
}
