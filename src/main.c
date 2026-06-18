#include "connection.h"
#include "constants.h"
#include "helpers.h"
#include "intialize.h"
#include "movement.h"
#include <inputValidation.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

int main(int argc, char *argv[]) {
  bool isWhite, isWhitesTurn = true;
  int rowToMoveFrom, rowToMoveTo;
  char columnToMoveFrom, columnToMoveTo;

  int socketFd = connectOrCreateSocket(&isWhite);

  initializeBoard();
  printBoard();

  struct BoardPosition boardPositionFrom, boardPositionTo;

  // game loop
  while (true) {


    bool fromValid = false, toValid = false;
    // input from loop
    while (!fromValid) {
      printf("Row and column of peice \033[1mto move\033[0m (eg, c7): ");
      scanf(" %c%d", &columnToMoveFrom, &rowToMoveFrom);
      fromValid = inputFromValidator(&boardPositionFrom, rowToMoveFrom,
                                     columnToMoveFrom, isWhite);
    }

    // input to loop
    while (!toValid) {
      printf("Row and column of peice \033[1mto move to\033[0m (eg, c6): ");
      scanf(" %c%d", &columnToMoveTo, &rowToMoveTo);
      toValid = inputToValidator(&boardPositionFrom, &boardPositionTo,
                                 rowToMoveTo, columnToMoveTo, isWhite);
    }

    int err = movePeice(boardPositionFrom, boardPositionTo, isWhite);

    printBoard();
  }

  return EXIT_SUCCESS;
}
