#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "videogame.h"
#include "file_manager.h"
#include "research_and_order.h"
#include "review.h"

void add_videogame(){
    Videogame new_game;
    int c, too_long;

    while ((c = getchar()) != '\n' && c != EOF); // svuota il buffer

    printf("--------Aggiungi videogioco--------\n");
    do{
        too_long = 0;
        printf("Titolo: ");
        fgets(new_game.title, MAX_STRING_SIZE, stdin);
        if (strlen(new_game.title) > 0 && new_game.title[strlen(new_game.title) - 1] == '\n'){
            new_game.title[strlen(new_game.title) - 1] = '\0'; // rimuove il ritorno a capo preso come carattere nel caso in cui ci sia
        } else{
            while ((c = getchar()) != '\n' && c != EOF); // stringa troppo lunga e quindi ritorno a capo non presente, pulizia del buffer
            too_long = 1;
        }
        if(strlen(new_game.title) == 0){
            printf("Inserire un titolo. Riprova.\n");
        }
        if(too_long){
            printf("Titolo troppo lungo. Riprova.\n");
        }
    }while(strlen(new_game.title) == 0 || too_long);
    do{
        too_long = 0;
        printf("Editore: ");
        fgets(new_game.editor, MAX_STRING_SIZE, stdin);
        if(strlen(new_game.editor) > 0 && new_game.editor[strlen(new_game.editor) - 1] == '\n'){
            new_game.editor[strlen(new_game.editor) - 1] = '\0'; 
        } else{
            while ((c = getchar()) != '\n' && c != EOF);
            too_long = 1;
        }
        if(strlen(new_game.editor) == 0){
            printf("Inserire un editore. Riprova.\n");
        }
        if(too_long){
            printf("Nome editore troppo lungo. Riprova.\n");
        }
    }while(strlen(new_game.editor) == 0 || too_long);
    do{
        too_long = 0;
        printf("Sviluppatore: ");
        fgets(new_game.developer, MAX_STRING_SIZE, stdin);
        if(strlen(new_game.developer) > 0 && new_game.developer[strlen(new_game.developer) - 1] == '\n'){
            new_game.developer[strlen(new_game.developer) - 1] = '\0';
        } else{
            while ((c = getchar()) != '\n' && c != EOF);
            too_long = 1;
        }
        if(strlen(new_game.developer) == 0){
            printf("Inserire un sviluppatore. Riprova.\n");
        }
        if(too_long){
            printf("Nome sviluppatore troppo lungo. Riprova.\n");
        }
    }while(strlen(new_game.developer) == 0 || too_long);
    do{
        too_long = 0;
        printf("Descrizione: ");
        fgets(new_game.description, MAX_STRING_SIZE, stdin);
        if(strlen(new_game.description) > 0 && new_game.description[strlen(new_game.description) - 1] == '\n'){
            new_game.description[strlen(new_game.description) - 1] = '\0';
        } else{
            while ((c = getchar()) != '\n' && c != EOF);
            too_long = 1;
        }
        if(strlen(new_game.description) == 0){    
            printf("Inserire una descrizione. Riprova.\n");
        }
        if(too_long){    
            printf("Descrizione troppo lunga. Riprova.\n");
        }
    }while(strlen(new_game.description) == 0 || too_long);
    do{
        printf("Anno di pubblicazione: ");
        scanf("%d", &new_game.year);
        if(new_game.year < 1900 || new_game.year > 2026){
            printf("Anno non valido. Riprova.\n");
        }
    }while(new_game.year < 1900 || new_game.year > 2026);
    getchar();
    do{
        too_long = 0;
        printf("Genere: ");
        fgets(new_game.genre, MAX_STRING_SIZE, stdin);
        if(strlen(new_game.genre) > 0 && new_game.genre[strlen(new_game.genre) - 1] == '\n'){
            new_game.genre[strlen(new_game.genre) - 1] = '\0';
        } else{
            while ((c = getchar()) != '\n' && c != EOF);
            too_long = 1;
        }
        if(strlen(new_game.genre) == 0){
            printf("Inserire un genere. Riprova.\n");
        }
        if(too_long){
            printf("Genere troppo lungo. Riprova.\n");
        }
    }while(strlen(new_game.genre) == 0 || too_long);
    
    new_game.copies_sold = 0;
    new_game.id = last_videogame_id() + 1;

    write_videogame_file(new_game);

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
    Videogame all_games[MAX_ARRAY_SIZE];
    int id, games_count, max_id, i, c, too_long, found = -1;
    
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
            too_long = 0;
            printf("Titolo Vecchio: %s\t Titolo Nuovo: ", all_games[i].title);
            fgets(all_games[i].title, MAX_STRING_SIZE, stdin);
            if(strlen(all_games[i].title) > 0 && all_games[i].title[strlen(all_games[i].title) - 1] == '\n'){
                all_games[i].title[strlen(all_games[i].title) - 1] = '\0';
            } else{
                while ((c = getchar()) != '\n' && c != EOF);
                too_long = 1;
            }
            if(strlen(all_games[i].title) == 0){
                printf("Inserire un titolo. Riprova.\n");
            }
            if(too_long){
            printf("Titolo troppo lungo. Riprova.\n");
        }
        }while(strlen(all_games[i].title) == 0 || too_long);
        do{
            too_long = 0;
            printf("Editore Vecchio: %s\t Editore Nuovo: ", all_games[i].editor);
            fgets(all_games[i].editor, MAX_STRING_SIZE, stdin);
            if(strlen(all_games[i].editor) > 0 && all_games[i].editor[strlen(all_games[i].editor) - 1] == '\n'){
                all_games[i].editor[strlen(all_games[i].editor) - 1] = '\0';
            } else{
                while ((c = getchar()) != '\n' && c != EOF);
                too_long = 1;
            }
            if(strlen(all_games[i].editor) == 0){
                printf("Inserire un editore. Riprova.\n");
            }
            if(too_long){
                printf("Nome editore troppo lungo. Riprova.\n");
            }
        }while(strlen(all_games[i].editor) == 0 || too_long);
        do{
            too_long = 0;
            printf("Sviluppatore Vecchio: %s\t Sviluppatore Nuovo: ", all_games[i].developer);
            fgets(all_games[i].developer, MAX_STRING_SIZE, stdin);
            if(strlen(all_games[i].developer) > 0 && all_games[i].developer[strlen(all_games[i].developer) - 1] == '\n'){
                all_games[i].developer[strlen(all_games[i].developer) - 1] = '\0';    
            } else{
                while ((c = getchar()) != '\n' && c != EOF);
                too_long = 1;
            }
            if(strlen(all_games[i].developer) == 0){
                printf("Inserire un sviluppatore. Riprova.\n");
            }
            if(too_long){
                printf("Nome sviluppatore troppo lungo. Riprova.\n");
            }
        }while(strlen(all_games[i].developer) == 0 || too_long);
        do{
            too_long = 0;
            printf("Descrizione Vecchia: %s\t Descrizione Nuova: ", all_games[i].description);
            fgets(all_games[i].description, MAX_STRING_SIZE, stdin);
            if(strlen(all_games[i].description) > 0 && all_games[i].description[strlen(all_games[i].description) - 1] == '\n'){
                all_games[i].description[strlen(all_games[i].description) - 1] = '\0';
            } else{
                while ((c = getchar()) != '\n' && c != EOF);
                too_long = 1;
            }
            if(strlen(all_games[i].description) == 0){
                printf("Inserire una descrizione. Riprova.\n");
            }
            if(too_long){
                printf("Descrizione troppo lunga. Riprova.\n");
            }
        }while(strlen(all_games[i].description) == 0 || too_long);
        do{
            printf("Anno di pubblicazione Vecchio: %d\t Anno di pubblicazione Nuovo: ", all_games[i].year);
            scanf("%d", &all_games[i].year);
            if(all_games[i].year < 1900 || all_games[i].year > 2050){
                printf("Anno non valido. Riprova.\n");
            }
        }while(all_games[i].year < 1900 || all_games[i].year > 2050);
        getchar();
        do{
            too_long = 0;
            printf("Genere Vecchio: %s\t Genere Nuovo: ", all_games[i].genre);
            fgets(all_games[i].genre, MAX_STRING_SIZE, stdin);
            if(strlen(all_games[i].genre) > 0 && all_games[i].genre[strlen(all_games[i].genre) - 1] == '\n'){
                all_games[i].genre[strlen(all_games[i].genre) - 1] = '\0';
            } else{
                while ((c = getchar()) != '\n' && c != EOF);
                too_long = 1;
            }
            if(strlen(all_games[i].genre) == 0){
                printf("Inserire un genere. Riprova.\n");
            }
            if(too_long){
                printf("Genere troppo lungo. Riprova.\n");
            }
        }while(strlen(all_games[i].genre) == 0 || too_long);
        
        edit_videogame_file(all_games, games_count);
        printf("Videogioco modificato con successo.\n");
    }
}

// TODO: implementare cancellazione delle recensioni
void delete_videogame(){
    Videogame all_games[MAX_ARRAY_SIZE];
    int id, games_count, max_id, found = 0, index_to_delete = -1;;
    
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

            delete_review(all_games[index_to_delete].id);

            // Riscrivi il file con uno in meno
            edit_videogame_file(all_games, games_count - 1);
            printf("Videogioco eliminato con successo.\n");
        } else {
            printf("Errore interno: ID trovato ma indice non identificato.\n");
        }
    }
}

void buy_videogame(int videogame_id){
    int c, games_count;
    Videogame all_games[MAX_ARRAY_SIZE];

    if(read_all_videogames(all_games, &games_count) == 0){
        for(int i = 0; i < games_count; i++){
            if(all_games[i].id == videogame_id){
                all_games[i].copies_sold++;
                printf("Videogioco acquistato con successo.\n");
            }
        }
        edit_videogame_file(all_games, games_count);
    }else{
        printf("Errore nella lettura dei videogiochi.\n");
    }
}