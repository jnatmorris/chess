#include "constants.h"

const char borderLeft[] = {'8', '7', '6', '5', '4', '3', '2', '1'};
const char borderTop[9] = {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

const struct GamePeice emptyGamePeice = {.PeiceType = Empty, .isWhite = 0};

const struct sockaddr_un sockAdr = {.sun_family = AF_UNIX,
                                    .sun_path = "/tmp/chess_socket"};
