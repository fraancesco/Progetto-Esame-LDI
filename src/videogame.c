#include <stdio.h>
#include <string.h>
#include "videogame.h"
#include "file_manager.h"

void add_videogame(){
    Videogame new_game;
    int c;

    while ((c = getchar()) != '\n' && c != EOF); // svuota il buffer

    printf("Aggiungi videogioco:\n");
    printf("Titolo: ");
    fgets(new_game.title, MAX_STRING_SIZE, stdin);
    new_game.title[strlen(new_game.title) - 1] = '\0';
    printf("Editore: ");
    fgets(new_game.editor, MAX_STRING_SIZE, stdin);
    new_game.editor[strlen(new_game.editor) - 1] = '\0';
    printf("Sviluppatore: ");
    fgets(new_game.developer, MAX_STRING_SIZE, stdin);
    new_game.developer[strlen(new_game.developer) - 1] = '\0';
    printf("Descrizione: ");
    fgets(new_game.description, MAX_STRING_SIZE, stdin);
    new_game.description[strlen(new_game.description) - 1] = '\0';
    printf("Anno di pubblicazione: ");
    scanf("%d", &new_game.year);
    getchar();
    printf("Genere: ");
    fgets(new_game.genre, MAX_STRING_SIZE, stdin);
    new_game.genre[strlen(new_game.genre) - 1] = '\0';
    printf("Copia venduta: ");
    scanf("%d", &new_game.copies_sold);
    printf("Inserisci un ID per il videogioco: ");
    scanf("%d", &new_game.id);

    write_file(new_game);

    printf("Videogioco aggiunto con successo.\n");
}