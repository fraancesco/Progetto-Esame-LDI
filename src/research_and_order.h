#ifndef RESEARCH_H
#define RESEARCH_H

#include "videogame.h"
#include "review.h"

void search_videogame_admin();
void search_videogame_user();

void show_all_videogames();

void bestseller_sorter(Videogame all_games[], int games_count);
void best_reviewed_sorter(Videogame all_games[], int games_count);
void alfabetical_sorter(Videogame all_games[], int games_count);

void bestseller_order(Videogame all_games[], int games_count);
void review_order(Videogame all_games[], int games_count);
void alfabetical_order(Videogame all_games[], int games_count);

void top_seller();
void top_reviewed();

#endif