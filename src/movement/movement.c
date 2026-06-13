#include "movement.h"
#include "constants.h"
#include "globals.h"
#include <stdbool.h>
#include <stdio.h>

bool isForward1Free(struct BoardPosition boardPositionFrom,
                    struct BoardPosition boardPositionTo) {

  return true;
}

// Pawn may move forward, or sideways to take.
bool isValidPositionForPawn(struct BoardPosition boardPositionFrom,
                            struct BoardPosition boardPositionTo,
                            bool playerIsWhite) {
  if (playerIsWhite) {
    return gameBoard[boardPositionTo.row - 1][boardPositionTo.column]
               .PeiceType == Empty;
  } else {
    return gameBoard[boardPositionTo.row + 1][boardPositionTo.column]
               .PeiceType == Empty;
  }
}

// returns -1 if needs new input for any reason
int movePeice(struct BoardPosition boardPositionFrom,
              struct BoardPosition boardPositionTo, bool playerIsWhite) {


  gameBoard[boardPositionTo.row][boardPositionTo.column] =
      gameBoard[boardPositionFrom.row][boardPositionFrom.column];

  gameBoard[boardPositionFrom.row][boardPositionFrom.column] = emptyGamePeice;

  return 0;
}
