/**
 * @file videogame.h
 * @brief Header file per la gestione dei videogiochi
 * @author Francesco Pice - Francesco Sblendorio
 * @date 23-06-2025
 * @version 1.0
 */

#ifndef VIDEOGAME_H
#define VIDEOGAME_H

/** @brief Dimensione massima per le stringhe */
#define MAX_STRING_SIZE 100

/** @brief Dimensione massima per gli array */
#define MAX_ARRAY_SIZE 100

/**
 * @brief Struttura che rappresenta un videogame
 * 
 * Questa struttura contiene tutte le informazioni necessarie
 * per descrivere un videogioco all'interno del catalogo.
 */
typedef struct {
    int id;                                    /**< ID univoco del videogame */
    int year;                                  /**< Anno di pubblicazione */
    int copies_sold;                           /**< Numero di copie vendute */
    char title[MAX_STRING_SIZE];               /**< Titolo del videogame */
    char editor[MAX_STRING_SIZE];              /**< Casa editrice */
    char developer[MAX_STRING_SIZE];           /**< Sviluppatore */
    char description[MAX_STRING_SIZE];         /**< Descrizione del gioco */
    char genre[MAX_STRING_SIZE];               /**< Genere del videogame */
} Videogame;

/**
 * @brief Aggiunge un nuovo videogame al catalogo
 * 
 * Questa funzione permette di inserire un nuovo videogame
 * nella collezione, richiedendo all'utente di inserire
 * tutte le informazioni necessarie.
 */
void add_videogame();

/**
 * @brief Visualizza tutti i videogame presenti nel sistema
 * 
 * Questa funzione mostra l'elenco completo di tutti i videogame
 * memorizzati nel sistema ai fini di sceglierne l'id per eventuali operazioni.
 * 
 * @param all_games Array contenente tutti i videogame
 * @param max_id Indirizzo del massimo ID
 * @param games_count Indirizzo del numero di videogame
 * @return int Codice di ritorno (0 se successo, -1 se errore)
 */
int view_all_videogame(Videogame all_games[], int *max_id, int *games_count);

/**
 * @brief Modifica le informazioni di un videogame esistente
 * 
 * Questa funzione permette di modificare i dati di un videogame
 * già presente nel catalogo, identificandolo tramite il suo ID.
 */
void edit_videogame();

/**
 * @brief Elimina un videogame dal catalogo
 * 
 * Questa funzione rimuove definitivamente un videogame
 * dal catalogo, identificandolo tramite il suo ID, eliminandone relative recensionni  .
 */
void delete_videogame();

/**
 * @brief Simula l'acquisto di un videogame
 * 
 * Questa funzione gestisce la logica per l'acquisto di un videogame,
 * aggiornando il contatore delle copie vendute.
 * 
 * @param videogame_id ID del videogame da acquistare
 */
void buy_videogame(int videogame_id);

#endif