#include <stdio.h>
#include "videogame.h"
#include "file_manager.h"
#include "review.h"

// scrive un videogioco nel file binario
int write_videogame_file(Videogame game) {
    FILE *file = fopen(PATH_VIDEOGAME_FILE, "ab");
    
    // controlla se il file è stato aperto correttamente
    if (file == NULL) {
        printf("Errore nella scrittura del file.\n");
        return -1;
    }

    // scrive il videogioco nel file
    fwrite(&game, sizeof(game), 1, file);
    fclose(file);
    return 0;
}

// legge l'ultimo ID videogioco presente nel file
int last_videogame_id() {
    Videogame last_record;
    FILE *file = fopen(PATH_VIDEOGAME_FILE, "rb");

    // controlla se il file è stato aperto correttamente
    if (file == NULL) {
        return -1;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    if (size == 0) {
        fclose(file);
        return 0; // se il file è vuoto, ritorna 0
    }
    
    // legge l'ultimo record presente nel file
    fseek(file, -sizeof(Videogame), SEEK_END);
    fread(&last_record, sizeof(Videogame), 1, file);
    fclose(file);
    
    // ritorna l'ID del record letto
    return last_record.id;
}

// legge tutti i videogiochi dal file binario
int read_all_videogames(Videogame all_games[], int *games_count) {
    FILE *file = fopen(PATH_VIDEOGAME_FILE, "rb");

    // controlla se il file è stato aperto correttamente
    if (file == NULL) {
        printf("Errore nella lettura del file.\n");
        return -1;
    }

    // calcola il numero di record nel file, partendo dalla sua dimensione
    fseek(file, 0, SEEK_END);
    *games_count = ftell(file) / sizeof(Videogame);

    if (games_count == 0) {
        fclose(file);
        return 0;
    }

    // legge tutti i record nel file
    fseek(file, 0, SEEK_SET);
    for(int i = 0; i < *games_count; i++){
        fread(&all_games[i], sizeof(Videogame), 1, file);
    }

    return 0;
}

// aggiorna il file dei videogiochi con modifiche
int edit_videogame_file(Videogame games[], int games_count) {
    FILE *file = fopen(PATH_VIDEOGAME_FILE, "wb");

    // controlla se il file è stato aperto correttamente
    if (file == NULL) {
        printf("Errore nella scrittura del file.\n");
        return -1;
    }
    
    // scrive tutti i videogiochi presenti nell'array modificato nel file
    for(int i = 0; i < games_count; i++){
        fwrite(&games[i], sizeof(Videogame), 1, file);
    }

    fclose(file);

    return 0;
}

// legge l'ultimo ID recensione presente nel file
int last_review_id() {
    Review last_record;
    FILE *file = fopen(PATH_REVIEW_FILE, "rb");

    // controlla se il file è stato aperto correttamente
    if (file == NULL) {
        return -1;
    }

    // calcola la dimensione del file, partendo dalla sua dimensione
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    if (size == 0) {
        fclose(file);
        return 0; // se il file è vuoto, ritorna 0
    }
    
    // legge l'ultimo record presente nel file
    fseek(file, -sizeof(Review), SEEK_END);
    fread(&last_record, sizeof(Review), 1, file);
    fclose(file);
    
    // ritorna l'ID del record letto
    return last_record.id;
}

// scrive una recensione nel file binario
int write_review_file(Review review) {
    FILE *file = fopen(PATH_REVIEW_FILE, "ab");
    
    // controlla se il file è stato aperto correttamente
    if (file == NULL) {
        printf("Errore nella scrittura del file.\n");
        return -1;
    }

    // scrive la recensione nel file
    fwrite(&review, sizeof(review), 1, file);
    fclose(file);
    return 0;
}

// aggiorna il file delle recensioni con modifiche
int edit_review_file(Review reviews[], int reviews_count) {
    FILE *file = fopen(PATH_VIDEOGAME_FILE, "wb");

    // controlla se il file è stato aperto correttamente
    if (file == NULL) {
        printf("Errore nella scrittura del file.\n");
        return -1;
    }
    
    // scrive tutte le recensioni presenti nell'array modificato nel file
    for(int i = 0; i < reviews_count; i++){
        fwrite(&reviews[i], sizeof(Videogame), 1, file);
    }

    fclose(file);

    return 0;
}

// legge tutte le recensioni dal file binario
int read_all_reviews(Review reviews[], int videogame_id, int *reviews_count) {
    FILE *file = fopen(PATH_REVIEW_FILE, "rb");

    if (file == NULL) {
        printf("Errore nella lettura del file.\n");
        return -1;
    }

    // calcola il numero di record nel file, partendo dalla sua dimensione
    fseek(file, 0, SEEK_END);
    *reviews_count = ftell(file) / sizeof(Review);

    // se il file è vuoto, ritorna 0
    if (*reviews_count == 0) {
        fclose(file);
        return 0;
    }

    // legge tutte le recensioni nel file
    *reviews_count = 0;
    fseek(file, 0, SEEK_SET);
    for(int i = 0; i < *reviews_count; i++){
        fread(&reviews[i], sizeof(Review), 1, file);
    }

    return 0;
}

// legge tutte le recensioni relative ad un videogioco dal file binario
int read_reviews(Review reviews[], int videogame_id, int *reviews_count) {
    Review temp;
    int all_reviews_number;
    FILE *file = fopen(PATH_REVIEW_FILE, "rb");

    // controlla se il file è stato aperto correttamente
    if (file == NULL) {
        printf("Errore nella lettura del file.\n");
        return -1;
    }

    // calcola il numero di record nel file, partendo dalla sua dimensione
    fseek(file, 0, SEEK_END);
    all_reviews_number = ftell(file) / sizeof(Review);


    if (all_reviews_number == 0) {
        fclose(file);
        return 0;
    }

    // legge le recensioni presenti nel file, filtrandole secondo l'ID del videogioco
    *reviews_count = 0;
    fseek(file, 0, SEEK_SET);
    for(int i = 0; i < all_reviews_number; i++){
        fread(&temp, sizeof(Review), 1, file);
        if(temp.videogame_id == videogame_id){
            reviews[(*reviews_count)++] = temp;
        }
    }

    return 0;
}