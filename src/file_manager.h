#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "videogame.h"
#include "review.h"

#define PATH_VIDEOGAME_FILE "../data/videogiochi.bin"
#define PATH_REVIEW_FILE "../data/recensioni.bin"

int write_videogame_file(Videogame game);
int last_videogame_id();
int read_all_videogames(Videogame all_games[], int *games_count);
void edit_videogame_file(Videogame games[], int games_count);

int last_review_id();
int write_review_file(Review review);
int read_reviews(Review reviews[], int videogame_id, int *reviews_count);
int read_all_reviews(Review reviews[], int videogame_id, int *reviews_count);
void edit_review_file(Review reviews[], int reviews_count);

#endif