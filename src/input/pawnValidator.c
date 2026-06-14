
#include "constants.h"
#include "globals.h"
#include <stdbool.h>
#include <stdio.h>

// on starting line, move 1 or two positions
// can take, move diagonal
// gets to end
bool isValidPositionForPawn(struct BoardPosition *from,
                            struct BoardPosition *to, bool playerIsWhite) {

  int startingPosition = playerIsWhite ? 6 : 1;
  int operandBasedOnColor = playerIsWhite ? 1 : -1;

  // check if user wants to move forward in column (not taking)
  if (from->column == to->column) {
    // if pawn is on starting line allow pawn to move 2 spaces
    if (from->row == startingPosition) {
      return from->row - (1 * operandBasedOnColor) == to->row ||
             from->row - (2 * operandBasedOnColor) == to->row;
    } else {
      return from->row - (1 * operandBasedOnColor) == to->row;
    }
  }

  // if moving forward and right or left to take. check if space is also filled
  // with something to take (peice + color)
  if ((from->column + 1 == to->column || from->column - 1 == to->column) &&
      from->column + operandBasedOnColor == to->row &&     // one row over
      gameBoard[to->row][to->column].PeiceType != Empty && // must be a peice
      gameBoard[to->row][to->column].isWhite !=
          playerIsWhite) // not the same color
  {
    return true;
  }

  // TODO: Implement En Passant

  return false;
}
