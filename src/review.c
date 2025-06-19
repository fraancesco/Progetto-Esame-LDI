#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "review.h"
#include "file_manager.h"

void add_review(int videogame_id){
    Review new_review;
    int c, too_long;

    while ((c = getchar()) != '\n' && c != EOF); // svuota il buffer

    printf("--------Aggiungi recensione--------\n");
    do{
        printf("Valore: ");
        scanf("%d", &new_review.value);
        if(new_review.value < 0 || new_review.value > 5){
            printf("Valore non valido. Riprova.\n");
        }
    }while(new_review.value < 0 || new_review.value > 5);
    do{
        too_long = 0;
        printf("Commento: ");
        fgets(new_review.comment, MAX_COMMENT_SIZE, stdin);
        if(strlen(new_review.comment) > 0 && new_review.comment[strlen(new_review.comment) - 1] == '\n'){
            new_review.comment[strlen(new_review.comment) - 1] = '\0'; // rimuove il ritorno a capo preso come carattere nel caso in cui ci sia
        } else{
            while ((c = getchar()) != '\n' && c != EOF); // stringa troppo lunga e quindi ritorno a capo non presente, pulizia del buffer
            too_long = 1;
        }
        if(strlen(new_review.comment) == 0){
            printf("Inserire una descrizione. Riprova.\n");
        }
        if(too_long){
            printf("Descrizione troppo lunga. Riprova.\n");
        }
    }while(strlen(new_review.comment) == 0 || too_long);
    
    new_review.videogame_id = videogame_id;
    new_review.id = last_review_id() + 1;

    write_review_file(new_review);

    printf("Recensione aggiunta con successo.\n");
}