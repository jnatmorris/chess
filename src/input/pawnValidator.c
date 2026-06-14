
#include "constants.h"
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
    if (from->row == startingPosition) {
      return from->row - (1 * operandBasedOnColor) == to->row ||
             from->row - (2 * operandBasedOnColor) == to->row;
    } else {
      return from->row - (1 * operandBasedOnColor) == to->row;
    }
  }

  // if (playerIsWhite) {
  //   // &&
  //   if (from->row == startingPosition) {
  //     return from->row - 1 == to->row || from->row - 2 == to->row;
  //   } else {
  //     return from->row - 1 == to->row;
  //   }

  // } else {
  //   if (from->row == 1) {
  //     return from->row + 1 == to->row || from->row + 2 == to->row;
  //   } else {
  //     return from->row + 1 == to->row;
  //   }
  // }
  //
  return true;
}
