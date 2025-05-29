#include <stdio.h>
#include "videogame.h"
#include "file_manager.h"

void add_videogame(){
    Videogame new_game;
    printf("Aggiungi videogioco:\n");
    printf("Titolo: ");
    scanf("%s", new_game.title);
    printf("Editore: ");
    scanf("%s", new_game.editor);
    printf("Sviluppatore: ");
    scanf("%s", new_game.developer);
    printf("Descrizione: ");
    scanf("%s", new_game.description);
    printf("Anno di pubblicazione: ");
    scanf("%d", &new_game.year);
    printf("Genere: ");
    scanf("%s", new_game.genre);
    printf("Copia venduta: ");
    scanf("%d", &new_game.copies_sold);
    printf("Inserisci un ID per il videogioco: ");
    scanf("%d", &new_game.id);

    write_file(new_game);
}