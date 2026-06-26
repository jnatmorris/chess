
#include "constants.h"
#include "globals.h"
#include "stdbool.h"

bool isPositionEmpty(struct BoardPosition *position) {
  return gameBoard[position->row][position->column].PeiceType == Empty;
}

bool isLocationSameColor(struct BoardPosition *position, bool isWhite) {
  return gameBoard[position->row][position->column].isWhite != isWhite;
}
