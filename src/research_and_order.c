#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "videogame.h"
#include "file_manager.h"
#include "review.h"

void view_videogame(){
    char title[MAX_STRING_SIZE], title_to_confront[MAX_STRING_SIZE], option;
    int c, games_count, too_long, found = 0;
    Videogame all_games[MAX_ARRAY_SIZE];

    while ((c = getchar()) != '\n' && c != EOF); // Pulisce il buffer

    do {
        too_long = 0;
        printf("Inserisci il titolo del videogioco da cercare: ");
        fgets(title, MAX_STRING_SIZE, stdin);
        if(strlen(title) > 0 && title[strlen(title) - 1] == '\n'){
            title[strlen(title) - 1] = '\0';
        } else{
            while ((c = getchar()) != '\n' && c != EOF);
            too_long = 1;
        }
        if (strlen(title) == 0) {
            printf("Inserire un titolo. Riprova.\n");
        }
        if(too_long){
            printf("Titolo troppo lungo. Riprova.\n");
        }
    } while (strlen(title) == 0 || too_long);

    if (read_all_videogames(all_games, &games_count) == 0) {

        for (int i = 0; i < strlen(title); i++){
            title[i] = tolower(title[i]);
        }

        for (int i = 0; i < games_count; i++) {

            memset(title_to_confront, 0, sizeof(title_to_confront)); // svuoto la stringa

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
                printf("Copie vendute: %d\n", all_games[i].copies_sold);
                view_reviews(all_games[i].id);
            }
        }
        if (!found) {
            printf("Videogioco non trovato.\n");
        }
    } else {
        printf("Errore nella lettura dei videogiochi.\n");
    }
}

// TODO: implementare la ricerca per editore, sviluppatore, genere e anno di pubblicazione
void search_videogame(){
    char title[MAX_STRING_SIZE], title_to_confront[MAX_STRING_SIZE], option;
    int c, games_count, too_long, found = 0;
    Videogame all_games[MAX_ARRAY_SIZE];

    while ((c = getchar()) != '\n' && c != EOF); // Pulisce il buffer

    do {
        too_long = 0;
        printf("Inserisci il titolo del videogioco da cercare: ");
        fgets(title, MAX_STRING_SIZE, stdin);
        if(strlen(title) > 0 && title[strlen(title) - 1] == '\n'){
            title[strlen(title) - 1] = '\0';
        } else{
            while ((c = getchar()) != '\n' && c != EOF);
            too_long = 1;
        }
        if (strlen(title) == 0) {
            printf("Inserire un titolo. Riprova.\n");
        }
        if(too_long){
            printf("Titolo troppo lungo. Riprova.\n");
        }
    } while (strlen(title) == 0 || too_long);

    if (read_all_videogames(all_games, &games_count) == 0) {

        for (int i = 0; i < strlen(title); i++){
            title[i] = tolower(title[i]);
        }

        for (int i = 0; i < games_count; i++) {

            memset(title_to_confront, 0, sizeof(title_to_confront)); // svuoto la stringa

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
                printf("Copie vendute: %d\n", all_games[i].copies_sold);
                view_reviews(all_games[i].id);
                printf("-----------------------------------------\n");
                do{
                    printf("Desidere comprare il videogioco (Y/N): ");
                    scanf(" %c", &option);
                    if(option == 'y' || option == 'Y'){
                        buy_videogame(all_games[i].id);
                    }
                    if(option != 'y' && option != 'Y' && option != 'n' && option != 'N'){
                        printf("Opzione non valida. Riprova.\n");
                    }
                }while(option != 'y' && option != 'Y' && option != 'n' && option != 'N');
                printf("-----------------------------------------\n");
                do{
                    printf("Vuoi recensire il videogioco (Y/N): ");
                    scanf(" %c", &option);
                    if(option == 'y' || option == 'Y'){
                        add_review(all_games[i].id);
                    }
                    if(option != 'y' && option != 'Y' && option != 'n' && option != 'N'){
                        printf("Opzione non valida. Riprova.\n");
                    }
                }while(option != 'y' && option != 'Y' && option != 'n' && option != 'N');
            }
        }
        if (!found) {
            printf("Videogioco non trovato.\n");
        }
    } else {
        printf("Errore nella lettura dei videogiochi.\n");
    }
}