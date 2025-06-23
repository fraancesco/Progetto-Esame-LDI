/**
 * @file review.h
 * @brief Header file per la gestione delle recensioni dei videogame
 * @author Francesco Pice - Francesco Sblendorio
 * @date 23-06-2025
 * @version 1.0
 */

#ifndef REVIEW_H
#define REVIEW_H

/** @brief Dimensione massima per i commenti delle recensioni */
#define MAX_COMMENT_SIZE 200

/**
 * @brief Struttura che rappresenta una recensione di un videogame
 * 
 * Questa struttura contiene tutte le informazioni necessarie
 * per memorizzare una recensione associata a un videogame specifico.
 */
typedef struct review
{
    int id;                                    /**< ID univoco della recensione */
    int videogame_id;                          /**< ID del videogame recensito */
    double value;                              /**< Valutazione numerica (es. 1.0-5.0) */
    char comment[MAX_COMMENT_SIZE];            /**< Commento testuale della recensione */
} Review;

/**
 * @brief Aggiunge una nuova recensione per un videogame
 * 
 * Questa funzione permette di inserire una nuova recensione
 * per un videogame specifico, richiedendo all'utente di inserire
 * la valutazione e il commento.
 * 
 * @param videogame_id ID del videogame da recensire
 */
void add_review(int videogame_id);

/**
 * @brief Calcola la media delle valutazioni per un videogame
 * 
 * Questa funzione elabora tutte le recensioni fornite e calcola
 * la valutazione media, utile per ottenere un punteggio complessivo.
 * 
 * @param reviews Array contenente le recensioni da elaborare
 * @param reviews_count Numero di recensioni nell'array
 * @return double Valore medio delle valutazioni (0.0 se nessuna recensione)
 */
double average_review(Review reviews[], int reviews_count);

/**
 * @brief Visualizza tutte le recensioni di un videogame
 * 
 * Questa funzione mostra l'elenco completo delle recensioni
 * associate al videogame specificato, inclusi valutazioni e commenti.
 * 
 * @param videogame_id ID del videogame di cui visualizzare le recensioni
 */
void view_reviews(int videogame_id);

/**
 * @brief Elimina una recensione di un videogame
 * 
 * Questa funzione rimuove una recensione specifica associata
 * al videogame indicato, identificandola tramite selezione dell'utente.
 * 
 * @param videogame_id ID del videogame da cui eliminare la recensione
 */
void delete_review(int videogame_id);

#endif