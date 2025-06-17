#include <stdio.h>
#include <stdlib.h>
#include "videogame.h"
#include "file_manager.h"

int write_file(Videogame game) {
    FILE *file = fopen(PATH_FILE, "ab");
    
    if (file == NULL) {
        printf("Errore nella scrittura del file.\n");
        return 1;
    }

    fwrite(&game, sizeof(game), 1, file);
    fclose(file);
    return 0;
}

int last_id() {
    Videogame last_record;
    FILE *file = fopen(PATH_FILE, "rb");

    if (file == NULL) {
        printf("Errore nella lettura del file.\n");
        return -1;
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
    FILE *file = fopen(PATH_FILE, "rb");

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

void edit_file(Videogame games[], int games_count) {
    FILE *file = fopen(PATH_FILE, "wb");

    if (file == NULL) {
        printf("Errore nella scrittura del file.\n");
        exit(1);
    }
    
    for(int i = 0; i < games_count; i++){
        fwrite(&games[i], sizeof(Videogame), 1, file);
    }

    fclose(file);
}