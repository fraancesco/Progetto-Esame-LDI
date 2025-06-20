#ifndef MENU_H
#define MENU_H
#include "review.h"
#include "videogame.h"

void stats();
void admin();
void crud_menu();
void user();
void start();
void order_menu(Videogame all_games[], int games_count, Review reviews[], int reviews_count);

#endif