#include <stdio.h>
#include <string.h>
#include <math.h>
#include "review.h"
#include "file_manager.h"

void add_review(int videogame_id){
    Review new_review;
    int c, too_long;

    printf("--------Aggiungi recensione--------\n");
    do{ 
        // controlla se la valutazione e valida
        printf("Valore: ");
        scanf("%lf", &new_review.value);
        new_review.value = round(new_review.value * 10.0) / 10.0;
        if(new_review.value < 0.0 || new_review.value > 5.0){
            printf("Valore non valido. Riprova.\n");
        }
    }while(new_review.value < 0 || new_review.value > 5);
    getchar();
    do{
        //controlla se il commento è valido
        too_long = 0;
        printf("Commento: ");
        fgets(new_review.comment, MAX_COMMENT_SIZE, stdin);
        if(strlen(new_review.comment) > 0 && new_review.comment[strlen(new_review.comment) - 1] == '\n'){
            new_review.comment[strlen(new_review.comment) - 1] = '\0'; // rimuove il ritorno a capo preso come carattere nel caso in cui ci sia
        } else{
            while ((c = getchar()) != '\n' && c != EOF); // stringa troppo lunga e quindi ritorno a capo non presente, pulizia del buffer
            too_long = 1;
        }
        if(too_long){
            printf("Descrizione troppo lunga. Riprova.\n");
        }
    }while(too_long);
    
    new_review.videogame_id = videogame_id;
    new_review.id = last_review_id() + 1;

    write_review_file(new_review); //aggiunge la recensione al file

    printf("Recensione aggiunta con successo.\n"); //messaggio di conferma
}

//somma tutte le valutazioni se presenti e fa la media
double average_review(Review reviews[], int reviews_count){
    double average = 0.0;
    
    if(reviews_count == 0){
        return 0.0;
    }

    for (int i = 0; i < reviews_count; i++) {
        average += reviews[i].value;
    }

    if(average == 0.0){
        return 0.0;
    }
    average /= reviews_count;
    return average;
}

// visualizza tutte le recensioni di un videogioco
void view_reviews(int videogame_id){
    int reviews_count;
    double average = 0.0;
    Review reviews[MAX_ARRAY_SIZE];

    // controlla le recensioni del videgame e le mostra, se presenti, con valutazione e commento, altrimenti messaggio di errore
    if(read_reviews(reviews, videogame_id, &reviews_count) == 0){
        if(reviews_count == 0){
            printf("Nessuna recensione trovata.\n");
        } else{
            printf("Media: %.1f\n", average_review(reviews, reviews_count));
            printf("--------Recensioni--------\n");
            for(int i = 0; i < reviews_count; i++){
                printf("Valore: %.1f\n", reviews[i].value);
                printf("Commento: %s\n", reviews[i].comment);
            }
        }
    }
}

// elimina tutte le recensioni di un videogioco
void delete_review(int videogame_id){
    Review all_reviews[MAX_ARRAY_SIZE], reviews_to_keep[MAX_ARRAY_SIZE];
    int total_reviews_count = 0, keep_count = 0;

    if (read_all_reviews(all_reviews, &total_reviews_count) == 0) {

        // Scorro tutte le recensioni e copio solo quelle che NON devono essere eliminate.
        for (int i = 0; i < total_reviews_count; i++) {
            if (all_reviews[i].videogame_id != videogame_id) {
                reviews_to_keep[keep_count] = all_reviews[i];
                keep_count++;
            }
        }

        // Riscrivo il file solo con le recensioni da conservare.
        edit_review_file(reviews_to_keep, keep_count);
    }
}