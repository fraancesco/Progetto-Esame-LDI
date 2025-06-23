#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#define MAX_STRING_SIZE 100
#define MAX_ARRAY_SIZE 100

// Definiamo la struttura di Videogame con: 
// ID, Anno di pubblicazione, Copie vendute, Titolo, Editore, Sviluppatore, Descrizione e Genere
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

//funzione per aggiungere un nuovo videogame
void add_videogame(); 
//funzione per visualizzare tutti i videogame
int view_all_videogame(Videogame all_games[], int *max_id, int *games_count);
//funzione per modificare un videogame
void edit_videogame();
//funzioni per eliminare un videogame
void delete_videogame();
//funzione per comprare un videogame
void buy_videogame(int videogame_id);




#endif