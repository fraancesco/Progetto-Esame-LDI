#include <stdio.h>
#include "videogame.h"
#include "file_manager.h"

int write_file(Videogame game) {
    FILE *file = fopen("../data/videogiochi.bin", "ab");
    
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
    FILE *file = fopen("../data/videogiochi.bin", "rb");

    if (file == NULL) {
        printf("Errore nella lettura del file.\n");
        return 1;
    }

    fseek(file, -sizeof(Videogame), SEEK_END);
    fread(&last_record, sizeof(Videogame), 1, file);
    fclose(file);
    
    return last_record.id;
}