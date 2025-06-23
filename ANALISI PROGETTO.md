## Informazioni generali:

#### Nome Progetto: 
*Gestione catalogo online di videogiochi*
#### Descrizione del caso di studio: 
*Simulare la gestione di una piattaforma online per conservazione, ordinamento e vendita di videogame.*

> **Nota:**
> *In quanto non esplicitamente richiesto, non è stata gestita l'eventuale eliminazione, modifica, ecc... delle recensioni*
#### Definizione dei campi di un videogame:
+ id (*intero*)
+ year (*intero*)
+ copies_sold (*intero*)
+ title (*stringa*)
+ editor (*stringa*)
+ developer (*stringa*)
+ description (stringa)
+ genre (stringa)

>**Nota:**
>*L'inserimento di una o più recensioni e stata gestita con una struct di tipo Review apposita*
#### Descrizione dei campi di una recensione:
+ id (*intero*)
+ videogame_id (*intero*)
+ value (*double*)
+ comment (stringa)
#### Ruoli presenti nel progetto:

1. **Amministratore:**
   *Funzionalità implementate per un amministratore:*
   1 - Gestione videogiochi:
   * Aggiunta di un videogame;
   * Modifica di un videogame;
   * Eliminazione di un Videogame;
   2 - Visualizzazione delle statistiche:
   * Visualizzazione dei videogame recensiti meglio;
   * Visualizzazione dei videogame più venduti;
   * Visualizzazione dei dati di un videogame cercato;
   3 - Opzione per tornare al menu precedente

2. **Utente:**
   *Funzionalità implementate per un Utente:*
   1 - Visualizzazione videogioco:
   * Opzione per recensione;
   * Opzione per acquistarlo;
   2 - Visualizzazione di tutti i videogiochi del catalogo:
   * Visualizza per Recensioni;
   * Visualizza per Bestseller;
   * Visualizza per Ordine Alfabetico;
   3 - Opzione per tornare al menu precedente

>**Nota:**
>Amministratore:
>- La visualizzazione è stata inserita nella visualizzazione statistiche di un Videogame poiché ritenuta parte delle effettive statistiche.
>- Con la visualizzazione dei videogame per migliori recensioni o per più venduti, vengono visualizzati solo i primi 5 per avere un idea dei videogame più in voga della piattaforma.
>- Con l'inserimento del criterio prima illustrato, vi è presente una terza visualizzazione che mostra tutte le statistiche di un videogame specifico, in questo modo e comunque possibile visionare le statistiche di videogame non presenti nei primi 5.
>Utente:
>- Nell'opzione che ti permette di visualizzare un gioco specifico e inclusa la possibilità di recensirlo e acquistarlo.
>- Nella seconda opzione e inserita anche una visualizzazione di tutti i videogame per ordine alfabetico.
## Funzionalità principali del Progetto:

#### Funzione di Aggiunta Videogame:
Inizialmente viene inizializzata una nuova istanza di tipo *Videogame*, dopo di che andiamo ad inserire i vari dati del videogame: Titolo, Editore, Sviluppatore, Descrizione, Anno di pubblicazione e Genere.
Per ogni *Stringa* che andiamo ad inserire (*Titolo, Editore...*) vengono effettuati due controlli sul loro inserimento:
- Se non viene inserito nessun carattere invia il messaggio di errore: "Inserire un titolo. Riprova"
- Se la stringa inserita è troppo lunga invia il messaggio di errore: "Titolo troppo lungo. Riprova"
I messaggi di errore visti sono solo quelli per il titolo, ovviamente in base al parametro (*Titolo, Editore...*) cambia anche il messaggio di errore.
Per l'*Intero* che andiamo ad inserire (*Anno di pubblicazione*) viene effettuato un singolo controllo sul sul dato inserito e, se minore di 1900 o maggiore di 2026, invia un messaggio di errore: "Anno non valido Riprova".
Dopo aver inserito tutti i dati vi è un ulteriore controllo del Titolo per vedere se il gioco è già stato inserito in precedenze.
Finito l'ultimo controllo il Videogame viene aggiunto al file Videogiochi.bin.
(*Implementata solo per gli amministratori*)

#### Funzione di Modifica Videogame:
Inizialmente viene inizializzata una nuova istanza di tipo Videogame, dopo di che viene effettuato un controllo sul file per verificare se sono presenti dei giochi al suo interno:
- tramite la funzione *view_all_videogame* che richiama la funzione *read_all_videogames* che effettua un controllo, se sono presenti li visualizza tutti i giochi, altrimenti invia un messaggio di errore: "Errore nella lettura dei videogiochi".
Una volta visionati tutti i giochi, viene chiesto di inserire l'id del videogioco che vogliamo modificare, se non valido manda un messaggio di errore.
Una volta scelto il gioco da modificare verranno effettuate le stesse procedure della funzione di aggiunta e avremo la possibilità di visionare allo stesso tempo i parametri del vecchio gioco.
Dopo aver inserito tutti i dati, il file verrà modificato con successo.
(*Implementata solo per gli amministratori*)

#### Funzione di Eliminazione Videogame:
Inizialmente viene inizializzata una nuova istanza di tipo Videogame, dopo di che viene effettuato un controllo sul file per verificare se sono presenti dei giochi al suo interno:
- tramite la funzione *view_all_videogame* che richiama la funzione *read_all_videogames* che effettua un controllo, se sono presenti li visualizza tutti i giochi, altrimenti invia un messaggio di errore: "Errore nella lettura dei videogiochi".
Una volta visionati tutti i giochi, viene chiesto di inserire l'id del videogioco che vogliamo modificare, se non valido manda un messaggio di errore.
Scelto il gioco da eliminare, quest'ultimo verrà eliminato e dopo di che viene rimosso lo spazio vuoto creato nell'array spostando tutti i videogame successivi di una posizione.
Finito la procedura, il file viene sovrascritto e il gioco eliminato con successo.
(*Implementata solo per gli amministratori*)

#### Funzioni di Visualizzazione Amministratore:
1) *Funzione top_reviewed:*
   Vengono inizializzate un istanza di tipo Reviews e un istanza di tipo Videogame, richiamiamo la funzione *read_all_videogames* e, se sono presenti i giochi, vengono ordinati tramite la funzione *best_reviewed_sorter* e vengono visualizzati i primi 5 videogame meglio recensiti.
2) *Funzione top_seller:*
   Vengono inizializzate un istanza di tipo Reviews e un istanza di tipo Videogame, richiamiamo la funzione *read_all_videogames* e, se sono presenti i giochi, vengono ordinati tramite la funzione *bestseller_sorter* e vengono visualizzati i primi 5 videogame più venduti.
3) *Funzione search_videogame_admin:*
   Dopo aver inizializzato le istanze necessarie per Videogame, andiamo ad inserire la nostra parola chiave per la ricerca del gioco.
   Una volta inserita la parola effettuerà i due controlli sul inserimento effettivo della parola e sulla sua lunghezza.
   Se la parola chiave non riscontra problematiche richiamerà la funzione *read_all_videogames* e se i giochi sono presenti, per ciascuno andremo ad utilizzare, in quest'ordine, le funzioni: *search_title*, *search_editor*, *search_developer*, *search_genre* e *search_year*, in modo tale che, inizialmente cercherà a prescindere per il titolo, se non corrisponde a nessun titolo inizierà a cercare per tutti i criteri, una volta trovato visualizzerà con tutte le sue statistiche, altrimenti dara messaggio di errore: "Videogioco non trovato".

>*Nota:*
>Le funzioni *search_videogame_admin e search_videogame_user* hanno quasi lo stesso funzionamento poiché, con l'utilizzo di funzioni apposite per l'ordinamento e la ricerca, abbiamo potuto riutilizzarle in modo che rispettasse sia le richieste e allo stesso tempo mantenesse ordine e semplicità nel progetto.

#### Funzioni di Visualizzazione Utente:
1) *Funzione search_videogame_user:*
   Dopo aver inizializzato le istanze necessarie per Videogame e Review, andiamo ad inserire la nostra parola chiave per la ricerca del gioco.
   Una volta inserita la parola effettuerà i due controlli sul inserimento effettivo della parola e sulla sua lunghezza.
   Se la parola chiave non riscontra problematiche richiamerà la funzione *read_all_videogames* e se i giochi sono presenti, per ciascuno andremo ad utilizzare, in quest'ordine, le funzioni: *search_title*, *search_editor*, *search_developer*, *search_genre* e *search_year*, in modo tale che, inizialmente cercherà a prescindere per il titolo, se non corrisponde a nessun titolo inizierà a cercare per tutti i criteri, una volta trovato visualizzerà con le statistiche visibili dall'utente, altrimenti dara messaggio di errore: "Videogioco non trovato".
   Dopo aver trovato e visualizzato il/i gioco/giochi abbiamo la possibilità di scegliere due opzioni:
   + *Opzione 1:*
     Da la possibilità di scegliere se comprare il gioco o meno, dopo aver eseguito i controlli per vedere se la risposta inserita sia corretta, in caso positivo aumenterà il contatore delle vendite di quel determinato videogame e uscirà il messaggio di "videogioco acquistato con successo".
   + *Opzione 2:*
     Da la possibilità di scegliere se inserire una recensione al gioco, dopo aver eseguito i controlli per vedere se la risposta inserita sia corretta, in caso positivo permette di aggiungere una nuova recensione con controllo sulla valutazione e sul commento inserito per farlo inserire in modo corretto.
2) *Funzione show_all_videogames*:
   Dopo aver inizializzato le istanze necessarie per Videogame e Review, vengono mostrati tutti i videogiochi, de presenti, del catalogo e viene posta la scelta di ordinamento, in caso positivo l'utente, tramite un altro menu ha 3 possibilità di scelta:
   * *Giochi ordinati per il numero di vendite:*
     La funzione *bestseller_order* ci permette di ordinare tutti i videogame dal più venduto al meno venduto.
   * *Giochi ordinati per media recensioni:*
     La funzione *review_order* ci permette di ordinare tutti i videogame dal videogame con migliori recensioni fino a quello con le peggiori recensioni.
   * *Giochi ordinati in ordine alfabetico:*
     La funzione *alfabetical_order* ci permette di ordinare tutti i videogame in ordine alfabetico.

>*Nota:*
> - I giochi ordinati secondo le recensioni danno la possibilità di vederne la media ma non le singole recensioni.
> - Molte funzioni utilizzano, come già indicato nella nota precedente, altre funzioni più generalizzate, per non creare un analisi ridondante è stato ritenuto opportuno non citare una stessa funzione, qual ora venga utilizzata, molteplici volte.
   
## Test Unity:
