#include "helpers.h"
#include "intialize.h"
#include "movement.h"
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

  bool isMyTurn = color == 'w';

  int rowToMoveFrom, rowToMoveTo;
  char columnToMoveFrom, columnToMoveTo;

  initializeBoard();
  printBoard();

  while (true) {

    printf("Row and column of peice \033[1mto move\033[0m (eg, c7): ");
    scanf(" %c%d", &columnToMoveFrom, &rowToMoveFrom);

    printf("Row and column of peice \033[1mto move to\033[0m (eg, c6): ");
    scanf(" %c%d", &columnToMoveTo, &rowToMoveTo);

    int err = movePeice(rowToMoveFrom, columnToMoveFrom, rowToMoveTo,
                        columnToMoveTo, color == 'w');

    if (err == -1) {
      printf("Invalid move!\n");
    } else {
      printBoard();
    }
  }

  return EXIT_SUCCESS;
}
