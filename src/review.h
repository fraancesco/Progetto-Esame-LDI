#ifndef REVIEW_H
#define REVIEW_H

#define MAX_COMMENT_SIZE 200

// Definiamo la struttura di una Reviw con: 
// ID, ID del videogame, Valutazione e Commento
typedef struct review
{
    int id;
    int videogame_id;
    double value;
    char comment[MAX_COMMENT_SIZE];
} Review;

//funzione per aggiungere una recensione di un videogame
void add_review(int videogame_id);
//funzione per vedere una recensione di un videogame
void view_reviews(int videogame_id);
//funzione per eliminare una recensione di un videogame
void delete_review(int videogame_id);
//funzione per calcolare la media delle recensioni del videogame
double average_review(Review reviews[], int reviews_count);

#endif