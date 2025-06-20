#ifndef RESEARCH_H
#define RESEARCH_H

#include "videogame.h"
#include "review.h"

void search_videogame_admin();
void search_videogame_user();

int search_editor(char keyword[], int games_count, Videogame all_games[], Videogame temp[]);
int search_developer(char keyword[], int games_count, Videogame all_games[], Videogame temp[]);
int search_genre(char keyword[], int games_count, Videogame all_games[], Videogame temp[]);
int search_year(char keyword[], int games_count, Videogame all_games[], Videogame temp[]);
int search_title(char keyword[], int games_count, Videogame all_games[], Videogame temp[]);

void show_all_videogames();
void show_videogame_admin(Videogame all_games[], int games_count);
void show_videogame_user(Videogame all_games[], int games_count);

void bestseller_sorter(Videogame all_games[], int games_count);
void best_reviewed_sorter(Videogame all_games[], int games_count);
void alfabetical_sorter(Videogame all_games[], int games_count);

void bestseller_order(Videogame all_games[], int games_count);
void review_order(Videogame all_games[], int games_count);
void alfabetical_order(Videogame all_games[], int games_count);

void top_seller();
void top_reviewed();

#endif