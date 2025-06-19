#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#define PATH_VIDEOGAME_FILE "../data/videogiochi.bin"
#define PATH_REVIEW_FILE "../data/recensioni.bin"

int write_videogame_file(Videogame game);
int last_videogame_id();
int read_all_videogames(Videogame all_games[], int *games_count);
void edit_videogame_file(Videogame games[], int games_count);

int last_review_id();
int write_review_file(Review review);


#endif