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
  int rowToMoveFrom, rowToMoveTo;
  char columnToMoveFrom, columnToMoveTo;

  int socketFd = connectOrCreateSocket(&isWhite);

  initializeBoard();
  printBoard(isWhite);
  isMyTurn = isWhite;

  struct BoardPosition boardPositionFrom, boardPositionTo;

  // game loop
  while (true) {

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

      int err = movePeice(boardPositionFrom, boardPositionTo, isWhite);

      struct UserMoveBoardPositions myMove = {0};
      myMove.from = boardPositionFrom;
      myMove.to = boardPositionTo;
      send(socketFd, &myMove, sizeof(myMove), 0);

      printBoard(isWhite);
      isMyTurn = false;
    } else {
      printf("Awaiting move from other player...\n");

      struct UserMoveBoardPositions opponentsMove = {0};
      int res = recv(socketFd, &opponentsMove, sizeof(opponentsMove), 0);

      movePeice(opponentsMove.from, opponentsMove.to, isWhite);
      printBoard(isWhite);

      isMyTurn = true;
    }
  }

  return EXIT_SUCCESS;
}
