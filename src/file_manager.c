#include <stdio.h>
#include "videogame.h"
#include "file_manager.h"

int write_file(Videogame game) {
    FILE *file = fopen("data/videogiochi.bin", "wb");
    
    if (file == NULL) {
        printf("Errore nella scrittura del file.\n");
        return 1;
    }

    fwrite(&game, sizeof(game), 1, file);
    fclose(file);
    return 0;
}