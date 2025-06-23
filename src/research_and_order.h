#ifndef RESEARCH_H
#define RESEARCH_H

#include "videogame.h"
#include "review.h"

//Funzione per la ricerca dei videogame da parte dell'amministratore
void search_videogame_admin();
//Funzione per la ricerca dei videogame da parte dell'utente
void search_videogame_user();

//Funzioni per la ricerca per specifico campo: editore, sviluppatore, genere, anno, titolo.
int search_editor(char keyword[], int games_count, Videogame all_games[], Videogame temp[]);
int search_developer(char keyword[], int games_count, Videogame all_games[], Videogame temp[]);
int search_genre(char keyword[], int games_count, Videogame all_games[], Videogame temp[]);
int search_year(char keyword[], int games_count, Videogame all_games[], Videogame temp[]);
int search_title(char keyword[], int games_count, Videogame all_games[], Videogame temp[]);

//Mostra tutti i videogame
void show_all_videogames();
//Mostra i videogame per l'amministratore
void show_videogame_admin(Videogame all_games[], int games_count);
//Mostra i videogame per l'utente
void show_videogame_user(Videogame all_games[], int games_count);

//Funzioni per ordinare i videogame in base a vari criteri
void bestseller_sorter(Videogame all_games[], int games_count); //Vendite (Bestseller)
void best_reviewed_sorter(Videogame all_games[], int games_count); //Recensioni migliori
void alfabetical_sorter(Videogame all_games[], int games_count); //Alfabeticamente

//Funzioni per visuallizzare i videogame ordinati in base alle: Vendite, Recensioni migliori e Alfabeticamente.
void bestseller_order(Videogame all_games[], int games_count);
void review_order(Videogame all_games[], int games_count);
void alfabetical_order(Videogame all_games[], int games_count);

//Mostra i videogame più venduti
void top_seller();
//Mostra i videogame meglio recensiti
void top_reviewed();

#endif