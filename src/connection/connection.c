#include "constants.h"
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int connectToServer() {
  int fd = socket(AF_UNIX, SOCK_STREAM, 0);
  if (fd == -1) {
    return -1;
  }

  if (connect(fd, (struct sockaddr *)&sockAdr, sizeof(sockAdr)) == 0) {
    return fd;
  }

  close(fd);
  return -1;
}

int createSocketServer() {
  int fd;

  if ((fd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
    return -1;
  }

  unlink(sockAdr.sun_path);

  if (bind(fd, (struct sockaddr *)&sockAdr, sizeof(sockAdr)) == -1) {
    printf("Failed to bind the socket!\n");
    return EXIT_FAILURE;
  }

  if (listen(fd, 1) == -1) {
    printf("Failed to listen on socket\n!");
    return EXIT_FAILURE;
  }

  printf("Created socket server!\n");

  return fd;
}

// try connecting to socket
// if: connection succeedes, this means another play has started the game
// already and become client
// else: user becomes server and awaits for other to connect
int connectOrCreateSocket(bool *isWhite) {
  int fd = connectToServer();

  if (fd != -1) {
    *isWhite = false;
    return fd;
  }

  *isWhite = true;

  return createSocketServer();
}
