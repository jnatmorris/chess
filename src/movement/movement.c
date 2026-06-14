#include "movement.h"
#include "constants.h"
#include "globals.h"
#include <stdbool.h>
#include <stdio.h>


// Pawn may move forward, or sideways to take.


// returns -1 if needs new input for any reason
int movePeice(struct BoardPosition boardPositionFrom,
              struct BoardPosition boardPositionTo, bool playerIsWhite) {


  gameBoard[boardPositionTo.row][boardPositionTo.column] =
      gameBoard[boardPositionFrom.row][boardPositionFrom.column];

  gameBoard[boardPositionFrom.row][boardPositionFrom.column] = emptyGamePeice;

  return 0;
}
