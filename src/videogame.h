#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#define MAX_STRING_SIZE 100
#define MAX 100

typedef struct {
    int id;
    int year;
    int copies_sold;
    char title[100];
    char editor[100];
    char developer[100];
    char description[100];
    char genre[100];
} Videogame;

void add_videogame();
void search_videogame();
int view_all_videogame(Videogame all_games[], int *max_id, int *games_count);
void edit_videogame();
void delete_videogame();

void sell_videogame(int id);

#endif