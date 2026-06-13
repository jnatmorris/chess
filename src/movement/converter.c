#include "constants.h"
#include <stdio.h>

int convertColumnToInternalRepresentation(char column) {
  for (int i = 0; i < 9; i++) {
    if (borderTop[i] == column) {
      return i - 1;
    }
  }
  return -1;
}

int convertRowToInternalRepresentation(int row) { return 8 - row; }

// convert user entered values to internal 2d matrix representation
struct BoardPosition convertToInternalRepresentation(int row, char column) {

  struct BoardPosition boardPosition;
  boardPosition.row = convertRowToInternalRepresentation(row);
  boardPosition.column = convertColumnToInternalRepresentation(column);

  return boardPosition;
}
