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

int main(int argc, char *argv[]) {
  bool isWhite, isMyTurn;
  int rowToMoveFrom, rowToMoveTo, opponentFd;
  char columnToMoveFrom, columnToMoveTo;

  if ((opponentFd = connectOrCreateSocket(&isWhite)) == -1) {
    return EXIT_FAILURE;
  }

  initializeBoard();
  printBoard(isWhite);
  isMyTurn = isWhite;

  struct BoardPosition boardPositionFrom, boardPositionTo;

  // game loop
  while (true) {
    struct UserMoveBoardPositions playerMove = {0};
    // if is white
    // white goes
    // await move from black
    // else black
    //

    if (isMyTurn) {
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

      movePeice(boardPositionFrom, boardPositionTo);

      playerMove.from = boardPositionFrom;
      playerMove.to = boardPositionTo;

      if (send(opponentFd, &playerMove, sizeof(playerMove), 0) == -1) {
        printf("Failed sending move to opponent!\n");
        return EXIT_FAILURE;
      }

      printBoard(isWhite);
      isMyTurn = false;
    } else {
      printf("Awaiting move from other player...\n");

      if (recv(opponentFd, &playerMove, sizeof(playerMove), 0) == -1) {
        printf("Failed in receiving opponents move!\n");
        return EXIT_FAILURE;
      }

      movePeice(playerMove.from, playerMove.to);
      printBoard(isWhite);

      isMyTurn = true;
    }
  }

  return EXIT_SUCCESS;
}
