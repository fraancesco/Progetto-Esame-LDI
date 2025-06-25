/**
 * @file file_manager.h
 * @brief Header file per la gestione dei file binari del sistema
 * @author Francesco Pice - Francesco Sblendorio
 * @date 23-06-2025
 * @version 1.0
 * 
 * Questo modulo fornisce funzionalità complete per la gestione
 * della persistenza dei dati attraverso file binari, gestendo
 * sia i videogame che le recensioni con operazioni di lettura,
 * scrittura e modifica.
 */

#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "videogame.h"
#include "review.h"

/** @brief Percorso del file binario contenente i dati dei videogame */
#define PATH_VIDEOGAME_FILE "../data/videogiochi.bin"

/** @brief Percorso del file binario contenente i dati delle recensioni */
#define PATH_REVIEW_FILE "../data/recensioni.bin"

/**
 * @brief Scrive un videogame nel file binario
 * 
 * Aggiunge un nuovo videogame al file binario di persistenza,
 * gestendo automaticamente l'apertura, scrittura e chiusura del file.
 * 
 * @param game variabile di tipo Videogame da scrivere nel file
 * @return int Codice di ritorno (0 se successo, -1 se errore)
 */
int write_videogame_file(Videogame game);

/**
 * @brief Ottiene l'ultimo ID videogame presente nel file
 * 
 * Legge il file dei videogame per determinare l'ID più alto
 * attualmente utilizzato, per assegnare nuovi ID univoci.
 * 
 * @return ultimo ID videogame presente nel file
 */
int last_videogame_id();

/**
 * @brief Legge tutti i videogame dal file binario
 * 
 * Legge tutti i videogame presenti nel file binario,
 * popolando l'array fornito e aggiornando il contatore.
 * 
 * @param all_games Array di destinazione per i videogame letti
 * @param games_count Puntatore al contatore dei videogame caricati
 * @return int Numero di videogame letti (-1 se errore)
 */
int read_all_videogames(Videogame all_games[], int *games_count);

/**
 * @brief Aggiorna il file dei videogame con modifiche
 * 
 * Riscrive completamente il file binario dei videogame con i dati
 * aggiornati dall'array in memoria, utilizzato dopo modifiche o eliminazioni.
 * 
 * @param games Array contenente i videogame da salvare
 * @param games_count Numero di videogame nell'array
 * @return int Codice di ritorno (0 se successo, -1 se errore)
 */
int edit_videogame_file(Videogame games[], int games_count);

/**
 * @brief Ottiene l'ultimo ID recensione presente nel file
 * 
 * Legge il file delle recensioni per determinare l'ID più alto
 * attualmente utilizzato, per assegnare nuovi ID univoci.
 * 
 * @return int Ultimo ID utilizzato (0 se file vuoto, -1 se errore)
 */
int last_review_id();

/**
 * @brief Scrive una recensione nel file binario
 * 
 * Aggiunge una nuova recensione al file binario di persistenza,
 * gestendo automaticamente l'apertura, scrittura e chiusura del file.
 * 
 * @param review Struttura Review da scrivere nel file
 * @return int Codice di ritorno (0 se successo, -1 se errore)
 */
int write_review_file(Review review);

/**
 * @brief Aggiorna il file delle recensioni con modifiche
 * 
 * Riscrive completamente il file binario delle recensioni con i dati
 * aggiornati dall'array in memoria, utilizzato dopo modifiche o eliminazioni.
 * 
 * @param reviews Array contenente le recensioni da salvare
 * @param reviews_count Numero di recensioni nell'array
 * @return int Codice di ritorno (0 se successo, -1 se errore)
 */
int edit_review_file(Review reviews[], int reviews_count);

/**
 * @brief Legge tutte le recensioni dal file binario
 * 
 * Legge tutte le recensioni presenti nel file binario,
 * indipendentemente dal videogame di appartenenza.
 * 
 * @param reviews Array di destinazione per le recensioni lette
 * @param reviews_count Puntatore al contatore delle recensioni caricate
 * @return int Numero di recensioni lette (-1 se errore)
 */
int read_all_reviews(Review reviews[], int *reviews_count);

/**
 * @brief Legge le recensioni di un videogame specifico
 * 
 * Legge tutte le recensioni associate a un determinato
 * videogame, filtrando per videogame_id.
 * 
 * @param reviews Array di destinazione per le recensioni lette
 * @param videogame_id ID del videogame di cui leggere le recensioni
 * @param reviews_count Puntatore al contatore delle recensioni caricate
 * @return int Codice di ritorno (0 se successo, -1 se errore)
 */
int read_reviews(Review reviews[], int videogame_id, int *reviews_count);

#endif