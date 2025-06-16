#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#define PATH_FILE "../data/videogiochi.bin"

int write_file(Videogame game);
int last_id();
int read_all_videogames(Videogame all_games[]);
void edit_file(Videogame games[]);

#endif