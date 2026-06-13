#include "movement.h"
#include "constants.h"
#include "converter.h"
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

// returns -1 if invalid move
int movePeice(int rowToMoveFrom, char columnToMoveFrom, int rowToMoveTo,
              char columnToMoveTo, bool playerIsWhite) {

  // TODO: if not valid
  struct BoardPosition boardPositionFrom =
      convertToInternalRepresentation(rowToMoveFrom, columnToMoveFrom);

  struct BoardPosition boardPositionTo =
      convertToInternalRepresentation(rowToMoveTo, columnToMoveTo);

  if (boardPositionTo.column < 0 || boardPositionTo.column > 8 ||
      boardPositionTo.row < 0 || boardPositionTo.row > 8) {
    return -1;
  }


  // TODO: Need to check if a peice I can even move

  // struct GamePeice gp = gameBoard[rowIndexToMove][columnIndexToMove];

  // if (playerIsWhite != gp->isWhite) {
  //   printf("Invalid move! The peice at \033[1m%c%d\033is not yours!",
  //          columnToMoveFrom, rowToMoveFrom);
  //   return;
  // }

  // bool test = isValidPeiceToMove(gp, rowToMoveFrom, columnToMoveFrom,
  //                                rowToMoveTo, playerIsWhite);

  gameBoard[boardPositionTo.row][boardPositionTo.column] =
      gameBoard[boardPositionFrom.row][boardPositionFrom.column];

  gameBoard[boardPositionFrom.row][boardPositionFrom.column] = emptyGamePeice;

  return 0;
}
