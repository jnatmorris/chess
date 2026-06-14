#include "constants.h"
#include "globals.h"
#include "pawnValidator.h"
#include <converter.h>
#include <stdbool.h>
#include <stdio.h>

// 1. check if empty square
// 2. check if proper color
// 3. check if the peice can even move
bool inputFromValidator(struct BoardPosition *out, int row, char column,
                        bool playerIsWhite) {
  *out = convertToInternalRepresentation(row, column);

  // empty
  if (gameBoard[out->row][out->column].PeiceType == Empty) {
    printf("\033[1m%c%d\033[0m is an empty position!\n", column, row);
    return false;
  }

  // not correct color
  if (gameBoard[out->row][out->column].isWhite != playerIsWhite) {
    printf("The peice at \033[1m%c%d\033[0m is not yours!\n", column, row);
    return false;
  }

  return true;
}

// 1. check if the desired location is off the board
// 2. check if the location is valid for the peice
// 		2.1 dependent on the peice type, need to check
// 3. don't allow to not move
bool inputToValidator(struct BoardPosition *from, struct BoardPosition *out,
                      int row, char column, bool playerIsWhite) {
  *out = convertToInternalRepresentation(row, column);

  // general check if desired location goes off the board
  if (out->column < 0 || out->column > GAME_BOARD_SIZE || out->row < 0 ||
      out->row > GAME_BOARD_SIZE) {
    printf("Position \033[1m%c%d\033[0m is off the board!\n", column, row);
    return false;
  }

  // don't allow to choose same position as from and to
  if (from->row == out->row && from->column == out->column) {
    printf("\033[1mFrom and to\033[0m position may not be the same!\n");
    return false;
  }

  switch (gameBoard[from->row][from->column].PeiceType) {
  case Pawn:
    // if first row
    return isValidPositionForPawn(from, out, playerIsWhite);
  case Rook:
    break;
  case Knight:
    break;
  case Bishop:
    break;
  case Queen:
    break;
  case King:
    break;
  default:
    printf("Position \033[1m%c%d\033[0m is empty!\n", column, row);
    return false;
  }

  return true;
}
