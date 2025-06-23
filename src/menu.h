/**
 * @file menu.h
 * @brief Header file per la gestione dei menu dell'applicazione
 * @author Francesco Pice - Francesco Sblendorio
 * @date 23-06-2025
 * @version 1.0
 * 
 * Questo modulo contiene tutte le funzioni per la gestione
 * dell'interfaccia utente e dei menu di navigazione del sistema
 * di gestione videogame, con interfacce differenziate per
 * amministratori e utenti.
 */

#ifndef MENU_H
#define MENU_H

#include "review.h"
#include "videogame.h"

/**
 * @brief Menu per le opzioni di ordinamento e visualizzazione
 * 
 * Presenta le diverse modalità di ordinamento e visualizzazione
 * dei videogame: per vendite (bestseller), per recensioni,
 * alfabetico, e altre opzioni di filtraggio e presentazione.
 * 
 * @param all_games Array contenente tutti i videogame da ordinare/visualizzare
 * @param games_count Numero totale di videogame nell'array
 */
void order_menu(Videogame all_games[], int games_count);

/**
 * @brief Menu principale per le funzioni utente
 * 
 * Presenta il menu principale dedicato agli utenti finali con
 * opzioni per la ricerca, visualizzazione, acquisto di videogame
 * e gestione delle recensioni personali.
 */
void user();

/**
 * @brief Visualizza le statistiche del sistema
 * 
 * Mostra statistiche generali sui videogame presenti nel sistema,
 * come numero totale di giochi, generi più popolari, media vendite,
 * e altre informazioni aggregate utili per analisi e reportistica.
 */
void stats();

/**
 * @brief Menu per le operazioni CRUD sui videogame
 * 
 * Visualizza il menu dedicato alle operazioni di gestione dei videogame:
 * Create (aggiungi), Read (visualizza), Update (modifica), Delete (elimina).
 * Questo menu è tipicamente accessibile solo agli amministratori.
 */
void crud_menu();

/**
 * @brief Menu principale per le funzioni di amministrazione
 * 
 * Presenta il menu principale dedicato agli amministratori con
 * tutte le opzioni di gestione avanzata del sistema, incluse
 * funzioni CRUD, statistiche e configurazioni amministrative.
 */
void admin();

/**
 * @brief Menu di avvio per la selezione del ruolo
 * 
 * Primo menu mostrato all'avvio dell'applicazione che permette
 * di selezionare il tipo di accesso: amministratore o utente normale.
 * Determina quale set di funzionalità sarà disponibile nella sessione.
 */
void start();

#endif