#include "globals.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void printBoard(bool isWhite) {
  system("clear");

  if (isWhite) {
    printf("You are \033[97mwhite\033[0m!\n");
  } else {
    printf("You are \033[30mblack\033[0m!\n");
  }

  printf("\n");
  for (int row = 0; row < GAME_BOARD_WITH_EDGES_SIZE; row++) {

    // border top
    if (row == 0) {
      for (int column = 0; column < GAME_BOARD_WITH_EDGES_SIZE; column++) {
        printf("\033[4m %c \033[0m", borderTop[column]);
      }
    } else {
      // border side
      printf("%c| ", borderLeft[row - 1]);
    }

    if (row != 0) {
      for (int column = 0; column < GAME_BOARD_SIZE; column++) {
        struct GamePeice gp = gameBoard[row - 1][column];
        // is empty space
        if (gp.PeiceType == 0) {
          printf("   ");
        } else {
          // is a game peice
          int isLastRow = row == GAME_BOARD_SIZE;

          if (gp.isWhite) {
            printf("\033[%s97m %c \033[0m", isLastRow ? "4;" : "",
                   gp.PeiceType);
          } else {
            printf("\033[%s30m %c \033[0m", isLastRow ? "4;" : "",
                   gp.PeiceType);
          }
        }
      }
    }

    printf("|\n");
  }
  printf("\n");
}
