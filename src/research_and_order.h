/**
 * @file research.h
 * @brief Header file per la ricerca e l'ordinamento dei videogame
 * @author Fractesco Pice - Francesco Sblendorio
 * @date 23-06-2025
 * @version 1.0
 * 
 * Questo modulo fornisce funzionalità complete per la ricerca,
 * il filtraggio e l'ordinamento dei videogame, con interfacce
 * differenziate per amministratori e utenti.
 */

#ifndef RESEARCH_H
#define RESEARCH_H

#include "videogame.h"
#include "review.h"

/**
 * @brief Cerca videogame per editore
 * 
 * Filtra i videogame in base al nome dell'editore, supportando
 * ricerca parziale e case-insensitive.
 * 
 * @param keyword Parola chiave per la ricerca dell'editore
 * @param games_count Numero totale di videogame nell'array
 * @param all_games Array contenente tutti i videogame
 * @param temp Array temporaneo per memorizzare i risultati
 * @return int Numero di videogame trovati
 */
int search_editor(char keyword[], int games_count, Videogame all_games[], Videogame temp[]);

/**
 * @brief Cerca videogame per sviluppatore
 * 
 * Filtra i videogame in base al nome dello sviluppatore, supportando
 * ricerca parziale e case-insensitive.
 * 
 * @param keyword Parola chiave per la ricerca dello sviluppatore
 * @param games_count Numero totale di videogame nell'array
 * @param all_games Array contenente tutti i videogame
 * @param temp Array temporaneo per memorizzare i risultati
 * @return int Numero di videogame trovati
 */
int search_developer(char keyword[], int games_count, Videogame all_games[], Videogame temp[]);

/**
 * @brief Cerca videogame per genere
 * 
 * Filtra i videogame in base al genere specificato, supportando
 * ricerca parziale e case-insensitive.
 * 
 * @param keyword Parola chiave per la ricerca del genere
 * @param games_count Numero totale di videogame nell'array
 * @param all_games Array contenente tutti i videogame
 * @param temp Array temporaneo per memorizzare i risultati
 * @return int Numero di videogame trovati
 */
int search_genre(char keyword[], int games_count, Videogame all_games[], Videogame temp[]);

/**
 * @brief Cerca videogame per anno di pubblicazione
 * 
 * Filtra i videogame in base all'anno di pubblicazione specificato.
 * 
 * @param keyword Stringa contenente l'anno di ricerca
 * @param games_count Numero totale di videogame nell'array
 * @param all_games Array contenente tutti i videogame
 * @param temp Array temporaneo per memorizzare i risultati
 * @return int Numero di videogame trovati
 */
int search_year(char keyword[], int games_count, Videogame all_games[], Videogame temp[]);

/**
 * @brief Cerca videogame per titolo
 * 
 * Filtra i videogame in base al titolo, supportando ricerca parziale
 * e case-insensitive per trovare corrispondenze nel nome del gioco.
 * 
 * @param keyword Parola chiave per la ricerca del titolo
 * @param games_count Numero totale di videogame nell'array
 * @param all_games Array contenente tutti i videogame
 * @param temp Array temporaneo per memorizzare i risultati
 * @return int Numero di videogame trovati
 */
int search_title(char keyword[], int games_count, Videogame all_games[], Videogame temp[]);

/**
 * @brief Visualizza videogame per amministratori
 * 
 * Mostra i videogame con interfaccia amministratore, includendo
 * opzioni per modifica, eliminazione e gestione avanzata.
 * 
 * @param all_games Array contenente i videogame da visualizzare
 * @param games_count Numero di videogame nell'array
 */
void show_videogame_admin(Videogame all_games[], int games_count);

/**
 * @brief Visualizza videogame per utenti
 * 
 * Mostra i videogame con interfaccia utente semplificata,
 * focalizzata su visualizzazione e acquisto.
 * 
 * @param all_games Array contenente i videogame da visualizzare
 * @param games_count Numero di videogame nell'array
 */
void show_videogame_user(Videogame all_games[], int games_count);

/**
 * @brief Interfaccia di ricerca videogame per amministratori
 * 
 * Fornisce un'interfaccia completa di ricerca con tutte le opzioni
 * disponibili per gli amministratori del catalogo, incluse funzioni
 * di modifica e gestione avanzata.
 */
void search_videogame_admin();

/**
 * @brief Interfaccia di ricerca videogame per utenti
 * 
 * Fornisce un'interfaccia semplificata di ricerca dedicata agli utenti
 * finali, con opzioni di visualizzazione e acquisto dei videogame.
 */
void search_videogame_user();

/**
 * @brief Visualizza tutti i videogame disponibili
 * 
 * Mostra l'elenco completo di tutti i videogame presenti nel sistema
 * senza alcun filtro o ordinamento particolare.
 */
void show_all_videogames();

/**
 * @brief Ordina videogame per numero di copie vendute (bestseller)
 * 
 * Riordina l'array dei videogame in ordine decrescente basandosi
 * sul numero di copie vendute per identificare i bestseller.
 * 
 * @param all_games Array di videogame da ordinare
 * @param games_count Numero di videogame nell'array
 */
void bestseller_sorter(Videogame all_games[], int games_count);

/**
 * @brief Ordina videogame per valutazione delle recensioni
 * 
 * Riordina l'array dei videogame in ordine decrescente basandosi
 * sulla media delle valutazioni delle recensioni ricevute.
 * 
 * @param all_games Array di videogame da ordinare
 * @param games_count Numero di videogame nell'array
 */
void best_reviewed_sorter(Videogame all_games[], int games_count);

/**
 * @brief Ordina videogame alfabeticamente per titolo
 * 
 * Riordina l'array dei videogame in ordine alfabetico crescente
 * basandosi sul titolo del gioco.
 * 
 * @param all_games Array di videogame da ordinare
 * @param games_count Numero di videogame nell'array
 */
void alfabetical_sorter(Videogame all_games[], int games_count);

/**
 * @brief Visualizza videogame ordinati per vendite (bestseller)
 * 
 * Mostra i videogame ordinati per numero di copie vendute,
 * evidenziando i titoli più commercialmente di successo.
 * 
 * @param all_games Array contenente i videogame da visualizzare
 * @param games_count Numero di videogame nell'array
 */
void bestseller_order(Videogame all_games[], int games_count);

/**
 * @brief Visualizza videogame ordinati per recensioni
 * 
 * Mostra i videogame ordinati per valutazione media delle recensioni,
 * evidenziando i titoli più apprezzati dagli utenti.
 * 
 * @param all_games Array contenente i videogame da visualizzare
 * @param games_count Numero di videogame nell'array
 */
void review_order(Videogame all_games[], int games_count);

/**
 * @brief Visualizza videogame in ordine alfabetico
 * 
 * Mostra i videogame ordinati alfabeticamente per titolo,
 * facilitando la ricerca di giochi specifici.
 * 
 * @param all_games Array contenente i videogame da visualizzare
 * @param games_count Numero di videogame nell'array
 */
void alfabetical_order(Videogame all_games[], int games_count);

/**
 * @brief Visualizza la classifica dei videogame più venduti
 * 
 * Mostra una classifica dedicata dei videogame con il maggior
 * numero di copie vendute.
 */
void top_seller();

/**
 * @brief Visualizza la classifica dei videogame meglio recensiti
 * 
 * Mostra una classifica dedicata dei videogame con le migliori
 * valutazioni medie dalle recensioni.
 */
void top_reviewed();

#endif