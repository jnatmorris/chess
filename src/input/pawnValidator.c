
#include "constants.h"
#include "globals.h"
#include <stdbool.h>
#include <stdio.h>

/*
 * 1. May move 1 or 2 positions (starting line)
 * 2. may move diagonal to take
 * 3. TODO: may En Passant
 * 4. TODO: may choose a peice when at end
 */
bool isValidPositionForPawn(struct BoardPosition *from,
                            struct BoardPosition *to, bool playerIsWhite) {

  int startingPosition = playerIsWhite ? 6 : 1;
  int operandBasedOnColor = playerIsWhite ? 1 : -1;

  // check if user wants to move forward in column (not taking)
  if (from->column == to->column) {

    if (gameBoard[to->row][to->column].PeiceType != Empty) {
      return false;
    }

    // if pawn is on starting line allow pawn to move 2 spaces
    if (from->row == startingPosition) {
      return from->row - (1 * operandBasedOnColor) == to->row ||
             from->row - (2 * operandBasedOnColor) == to->row;
    } else {
      return from->row - (1 * operandBasedOnColor) == to->row;
    }
  }

  if ((from->column + 1 == to->column || from->column - 1 == to->column) &&
      from->row + (-1 * operandBasedOnColor) ==
          to->row && // one forward/backwars (-1 as 0 is top)
      gameBoard[to->row][to->column].PeiceType != Empty && // must be a peice
      gameBoard[to->row][to->column].isWhite !=
          playerIsWhite) // not the same color
  {
    return true;
  }

  return false;
}
