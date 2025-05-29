#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "videogame.h"

int read_file(char *filename, void *buffer, int size);
int write_file(Videogame game);

#endif