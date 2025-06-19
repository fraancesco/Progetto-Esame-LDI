#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#define MAX_STRING_SIZE 100
#define MAX_ARRAY_SIZE 100

typedef struct {
    int id;
    int year;
    int copies_sold;
    char title[MAX_STRING_SIZE];
    char editor[MAX_STRING_SIZE];
    char developer[MAX_STRING_SIZE];
    char description[MAX_STRING_SIZE];
    char genre[MAX_STRING_SIZE];
} Videogame;

void add_videogame();
int view_all_videogame(Videogame all_games[], int *max_id, int *games_count);
void edit_videogame();
void delete_videogame();
void search_videogame();

void buy_videogame(int videogame_id);

void view_videogame();


#endif