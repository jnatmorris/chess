#ifndef CONNECTION_H
#define CONNECTION_H

#include <stdbool.h>

int connectToServer();
int createSocketServer();
int connectOrCreateSocket(bool* isWhite);

#endif
