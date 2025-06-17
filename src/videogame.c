#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "videogame.h"
#include "file_manager.h"

void add_videogame(){
    Videogame new_game;
    int c;

    while ((c = getchar()) != '\n' && c != EOF); // svuota il buffer

    printf("--------Aggiungi videogioco--------:\n");
    do{
        printf("Titolo: ");
        fgets(new_game.title, MAX_STRING_SIZE, stdin);
        new_game.title[strlen(new_game.title) - 1] = '\0'; // rimuove il ritorno a capo preso come carattere
        if(strlen(new_game.title) == 0){
            printf("Inserire un titolo. Riprova.\n");
        }
    }while(strlen(new_game.title) == 0);
    do{
        printf("Editore: ");
        fgets(new_game.editor, MAX_STRING_SIZE, stdin);
        new_game.editor[strlen(new_game.editor) - 1] = '\0'; 
        if(strlen(new_game.editor) == 0){
            printf("Inserire un editore. Riprova.\n");
        }
    }while(strlen(new_game.editor) == 0);
    do{
        printf("Sviluppatore: ");
        fgets(new_game.developer, MAX_STRING_SIZE, stdin);
        new_game.developer[strlen(new_game.developer) - 1] = '\0';
        if(strlen(new_game.developer) == 0){
            printf("Inserire un sviluppatore. Riprova.\n");
        }
    }while(strlen(new_game.developer) == 0);
    do{
        printf("Descrizione: ");
        fgets(new_game.description, MAX_STRING_SIZE, stdin);
        new_game.description[strlen(new_game.description) - 1] = '\0';
        if(strlen(new_game.description) == 0){    
            printf("Inserire una descrizione. Riprova.\n");
        }
    }while(strlen(new_game.description) == 0);
    do{
        printf("Anno di pubblicazione: ");
        scanf("%d", &new_game.year);
        if(new_game.year < 1900 || new_game.year > 2026){
            printf("Anno non valido. Riprova.\n");
        }
    }while(new_game.year < 1900 || new_game.year > 2026);
    getchar();
    do{
        printf("Genere: ");
        fgets(new_game.genre, MAX_STRING_SIZE, stdin);
        new_game.genre[strlen(new_game.genre) - 1] = '\0';
        if(strlen(new_game.genre) == 0){
            printf("Inserire un genere. Riprova.\n");
        }
    }while(strlen(new_game.genre) == 0);
    
    new_game.copies_sold = 0;
    new_game.id = last_id() + 1;

    write_file(new_game);

    printf("Videogioco aggiunto con successo.\n");
}

int view_all_videogame(Videogame all_games[], int *max_id, int *games_count){
    if(read_all_videogames(all_games, games_count) == 0){
        if(all_games == NULL){
            printf("Errore nella lettura dei videogiochi.\n");
            return -1;
        }

        printf("--------Ecco tutti i videogiochi--------\n");
        for(int i = 0; i < *games_count; i++){
            printf("%d. \t", all_games[i].id);
            printf("%s\n", all_games[i].title);
            *max_id = i;
        }
        printf("----------------------------------------\n");
    }

    return 0;
}

void edit_videogame(){
    Videogame all_games[MAX];
    int id, games_count, max_id, i, c, found = -1;
    
    if(view_all_videogame(all_games, &max_id, &games_count) != -1){

        do {
            printf("Seleziona l'id del videogioco da modificare: ");
            scanf("%d", &id);

            for (i = 0; i < games_count; i++) {
                if (all_games[i].id == id) {
                    found = i;
                    break;
                }
            }

            if (found == -1) {
                printf("Id non valido. Riprova.\n");
            }

        } while (found == -1);

        i = found;

        while ((c = getchar()) != '\n' && c != EOF)
        printf("--------Modifica videogioco--------\n");
        do{
            printf("Titolo Vecchio: %s\t Titolo Nuovo: ", all_games[i].title);
            fgets(all_games[i].title, MAX_STRING_SIZE, stdin);
            all_games[i].title[strlen(all_games[i].title) - 1] = '\0';
            if(strlen(all_games[i].title) == 0){
                printf("Inserire un titolo. Riprova.\n");
            }
        }while(strlen(all_games[i].title) == 0);
        do{
            printf("Editore Vecchio: %s\t Editore Nuovo: ", all_games[i].editor);
            fgets(all_games[i].editor, MAX_STRING_SIZE, stdin);
            all_games[i].editor[strlen(all_games[i].editor) - 1] = '\0';
            if(strlen(all_games[i].editor) == 0){
                printf("Inserire un editore. Riprova.\n");
            }
        }while(strlen(all_games[i].editor) == 0);
        do{
            printf("Sviluppatore Vecchio: %s\t Sviluppatore Nuovo: ", all_games[i].developer);
            fgets(all_games[i].developer, MAX_STRING_SIZE, stdin);
            all_games[i].developer[strlen(all_games[i].developer) - 1] = '\0';
            if(strlen(all_games[i].developer) == 0){
                printf("Inserire un sviluppatore. Riprova.\n");
            }
        }while(strlen(all_games[i].developer) == 0);
        do{
            printf("Descrizione Vecchia: %s\t Descrizione Nuova: ", all_games[i].description);
            fgets(all_games[i].description, MAX_STRING_SIZE, stdin);
            all_games[i].description[strlen(all_games[i].description) - 1] = '\0';
            if(strlen(all_games[i].description) == 0){
                printf("Inserire una descrizione. Riprova.\n");
            }
        }while(strlen(all_games[i].description) == 0);
        do{
            printf("Anno di pubblicazione Vecchio: %d\t Anno di pubblicazione Nuovo: ", all_games[i].year);
            scanf("%d", &all_games[i].year);
            if(all_games[i].year < 1900 || all_games[i].year > 2050){
                printf("Anno non valido. Riprova.\n");
            }
        }while(all_games[i].year < 1900 || all_games[i].year > 2050);
        getchar();
        do{
            printf("Genere Vecchio: %s\t Genere Nuovo: ", all_games[i].genre);
            fgets(all_games[i].genre, MAX_STRING_SIZE, stdin);
            all_games[i].genre[strlen(all_games[i].genre) - 1] = '\0';
            if(strlen(all_games[i].genre) == 0){
                printf("Inserire un genere. Riprova.\n");
            }
        }while(strlen(all_games[i].genre) == 0);
        
        edit_file(all_games, games_count);
        printf("Videogioco modificato con successo.\n");
    }
}

void delete_videogame(){
    Videogame all_games[MAX];
    int id, games_count, max_id, found = 0;
    
    if(view_all_videogame(all_games, &max_id, &games_count) != -1){
       
        do {
            printf("Seleziona l'id del videogioco da eliminare: ");
            scanf("%d", &id);

            // Verifica se esiste un videogioco con quell'id
            for(int i = 0; i < games_count; i++) {
                if(all_games[i].id == id) {
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Id non valido. Riprova.\n");
                id = -1;
            }

        } while(id == -1);

        // Trova l’indice da eliminare
        int index_to_delete = -1;
        for (int i = 0; i < games_count; i++) {
            if (all_games[i].id == id) {
                index_to_delete = i;
                break;
            }
        }

        if (index_to_delete != -1) {
            // Elimina il record spostando gli altri
            for (int i = index_to_delete; i < games_count - 1; i++) {
                all_games[i] = all_games[i + 1];
            }

            // Riscrivi il file con uno in meno
            edit_file(all_games, games_count - 1);
            printf("Videogioco eliminato con successo.\n");
        } else {
            printf("Errore interno: ID trovato ma indice non identificato.\n");
        }
    }
}

void search_videogame(){
    char title[MAX_STRING_SIZE], title_to_confront[MAX_STRING_SIZE];
    int c, games_count, found = 0;
    Videogame all_games[MAX];

    while ((c = getchar()) != '\n' && c != EOF); // Pulisce il buffer

    do {
        printf("Inserisci il titolo del videogioco da cercare: ");
        fgets(title, MAX_STRING_SIZE, stdin);
        title[strlen(title) - 1] = '\0';
        if (strlen(title) == 0) {
            printf("Inserire un titolo. Riprova.\n");
        }
    } while (strlen(title) == 0);

    if (read_all_videogames(all_games, &games_count) == 0) {

        for (int i = 0; i < strlen(title); i++){
            title[i] = tolower(title[i]);
        }

        for (int i = 0; i < games_count; i++) {

            memset(title_to_confront, 0, sizeof(title_to_confront));

            for (int j = 0; j < strlen(all_games[i].title); j++){
            title_to_confront[j] = tolower(all_games[i].title[j]);
            }
            if (strstr(title_to_confront, title) != NULL) {
                if (found == 0){
                    printf("--------Videogiochi trovati--------\n");
                    found = 1;
                }
                printf("Titolo: %s\n", all_games[i].title);
                printf("Editore: %s\n", all_games[i].editor);
                printf("Sviluppatore: %s\n", all_games[i].developer);
                printf("Descrizione: %s\n", all_games[i].description);
                printf("Anno di pubblicazione: %d\n", all_games[i].year);
                printf("Genere: %s\n", all_games[i].genre);
            }
        }
        if (!found) {
            printf("Videogioco non trovato.\n");
        }
    } else {
        printf("Errore nella lettura dei videogiochi.\n");
    }
}