#include "constants.h"
#include "helpers.h"
#include "intialize.h"
#include "movement.h"
#include <inputValidation.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int opt;
  char color;

  while ((opt = getopt(argc, argv, "c:")) != -1) {
    switch (opt) {
    case 'c':
      color = optarg[0];
      if (color != 'w' && color != 'b') {
        printf("Unknown color provided to argument c! Requires 'b' or 'w'!\n");
        return EXIT_FAILURE;
      }
      break;

    case ':':
    case '?':
      return EXIT_FAILURE;

    default:
      printf("Invalid input\n");
      return EXIT_FAILURE;
    }
  }

  int rowToMoveFrom, rowToMoveTo;
  char columnToMoveFrom, columnToMoveTo;

  initializeBoard();
  printBoard();

  struct BoardPosition boardPositionFrom, boardPositionTo;
  bool isWhite = color == 'w';

  // game loop
  while (true) {

    bool fromValid = false;
    // input from loop
    while (!fromValid) {
      printf("Row and column of peice \033[1mto move\033[0m (eg, c7): ");
      scanf(" %c%d", &columnToMoveFrom, &rowToMoveFrom);
      fromValid = inputFromValidator(&boardPositionFrom, rowToMoveFrom,
                                     columnToMoveFrom, isWhite);
    }

    bool toValid = false;
    // input from loop
    while (!toValid) {
      printf("Row and column of peice \033[1mto move to\033[0m (eg, c6): ");
      scanf(" %c%d", &columnToMoveTo, &rowToMoveTo);
      toValid = inputToValidator(&boardPositionFrom, &boardPositionTo,
                                 rowToMoveTo, columnToMoveTo,isWhite);
    }

    int err = movePeice(boardPositionFrom, boardPositionTo, isWhite);

    printBoard();
  }

  return EXIT_SUCCESS;
}
