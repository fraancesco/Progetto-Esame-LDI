#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "videogame.h"
#include "file_manager.h"

int games_count = 0;

void add_videogame(){
    Videogame new_game;
    int c;

    while ((c = getchar()) != '\n' && c != EOF); // svuota il buffer

    printf("Aggiungi videogioco:\n");
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
    games_count++;

    printf("Videogioco aggiunto con successo.\n");
}

void edit_videogame(){
    Videogame all_games[games_count];
    int id, max_id, i, c, found = 0;
    
    if(read_all_videogames(all_games) == 0){
       

        if(all_games == NULL){
            printf("Errore nella lettura dei videogiochi.\n");
            return;
        }

        printf("Ecco tutti i videogiochi:\n");
        for(i = 0; i < games_count; i++){
            printf("%d. \t", all_games[i].id);
            printf("%s\n", all_games[i].title);
            max_id = i;
        }

        do{
            printf("Seleziona l'id del videogioco da modificare:\n");
            scanf("%d", &id);
            if((id < 1 || id > max_id) || isnan(id) || id == NULL){
                printf("Id non valido. Riprova.\n");
            }
        }while((id < 1 || id > max_id) || isnan(id) || id == NULL);

        i = 0;

        do{
            if (all_games[i].id == id) {
                found = 1;

                while ((c = getchar()) != '\n' && c != EOF); // svuota il buffer

                printf("Modifica videogioco:\n");
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
                    if(isnan(all_games[i].year)){
                        printf("Inserire un numero intero. Riprova.\n");
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
                
                edit_file(all_games);

                printf("Videogioco modificato con successo.\n");
            }
            i++;
        }while(i < games_count && found == 0);
    }
}