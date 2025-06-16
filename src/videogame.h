#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#define MAX_STRING_SIZE 100

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
void view_videogame(int id);
void edit_videogame();
void delete_videogame(int id);

void sell_videogame(int id);

#endif