#include <stdio.h>
#include <stdlib.h>
#include "videogame.h"
#include "file_manager.h"
#include "review.h"

int write_videogame_file(Videogame game) {
    FILE *file = fopen(PATH_VIDEOGAME_FILE, "ab");
    
    if (file == NULL) {
        printf("Errore nella scrittura del file.\n");
        return 1;
    }

    fwrite(&game, sizeof(game), 1, file);
    fclose(file);
    return 0;
}

int last_videogame_id() {
    Videogame last_record;
    FILE *file = fopen(PATH_VIDEOGAME_FILE, "rb");

    if (file == NULL) {
        return 0;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    if (size == 0) {
        fclose(file);
        return 0;
    }
    
    fseek(file, -sizeof(Videogame), SEEK_END);
    fread(&last_record, sizeof(Videogame), 1, file);
    fclose(file);
    
    return last_record.id;
}

int read_all_videogames(Videogame all_games[], int *games_count) {
    FILE *file = fopen(PATH_VIDEOGAME_FILE, "rb");

    if (file == NULL) {
        printf("Errore nella lettura del file.\n");
        return -1;
    }

    fseek(file, 0, SEEK_END);
    *games_count = ftell(file) / sizeof(Videogame);

    if (games_count == 0) {
        fclose(file);
        return 0;
    }

    fseek(file, 0, SEEK_SET);
    for(int i = 0; i < *games_count; i++){
        fread(&all_games[i], sizeof(Videogame), 1, file);
    }

    return 0;
}

void edit_videogame_file(Videogame games[], int games_count) {
    FILE *file = fopen(PATH_VIDEOGAME_FILE, "wb");

    if (file == NULL) {
        printf("Errore nella scrittura del file.\n");
        exit(1);
    }
    
    for(int i = 0; i < games_count; i++){
        fwrite(&games[i], sizeof(Videogame), 1, file);
    }

    fclose(file);
}

int last_review_id() {
    Review last_record;
    FILE *file = fopen(PATH_REVIEW_FILE, "rb");

    if (file == NULL) {
        return 0;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    if (size == 0) {
        fclose(file);
        return 0;
    }
    
    fseek(file, -sizeof(Review), SEEK_END);
    fread(&last_record, sizeof(Review), 1, file);
    fclose(file);
    
    return last_record.id;
}

int write_review_file(Review review) {
    FILE *file = fopen(PATH_REVIEW_FILE, "ab");
    
    if (file == NULL) {
        printf("Errore nella scrittura del file.\n");
        return 1;
    }

    fwrite(&review, sizeof(review), 1, file);
    fclose(file);
    return 0;
}

int read_all_reviews(Review reviews[], int videogame_id, int *reviews_count) {
    FILE *file = fopen(PATH_REVIEW_FILE, "rb");

    if (file == NULL) {
        printf("Errore nella lettura del file.\n");
        return -1;
    }

    fseek(file, 0, SEEK_END);
    *reviews_count = ftell(file) / sizeof(Review);


    if (*reviews_count == 0) {
        fclose(file);
        return 0;
    }

    *reviews_count = 0;
    fseek(file, 0, SEEK_SET);
    for(int i = 0; i < *reviews_count; i++){
        fread(&reviews[i], sizeof(Review), 1, file);
    }

    return 0;
}

void edit_review_file(Review reviews[], int reviews_count) {
    FILE *file = fopen(PATH_VIDEOGAME_FILE, "wb");

    if (file == NULL) {
        printf("Errore nella scrittura del file.\n");
        exit(1);
    }
    
    for(int i = 0; i < reviews_count; i++){
        fwrite(&reviews[i], sizeof(Videogame), 1, file);
    }

    fclose(file);
}

int read_reviews(Review reviews[], int videogame_id, int *reviews_count) {
    Review temp;
    int all_reviews_number;
    FILE *file = fopen(PATH_REVIEW_FILE, "rb");

    if (file == NULL) {
        printf("Errore nella lettura del file.\n");
        return -1;
    }

    fseek(file, 0, SEEK_END);
    all_reviews_number = ftell(file) / sizeof(Review);


    if (all_reviews_number == 0) {
        fclose(file);
        return 0;
    }

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