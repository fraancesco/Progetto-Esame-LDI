#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "videogame.h"
#include "file_manager.h"
#include "review.h"
#include "menu.h"

// TODO: implementare la ricerca per editore, sviluppatore, genere e anno di pubblicazione
void search_videogame_admin(){
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
void search_videogame_user(){
    char title[MAX_STRING_SIZE], title_to_confront[MAX_STRING_SIZE], option;
    int c, games_count, too_long, reviews_count, found = 0;
    Videogame all_games[MAX_ARRAY_SIZE];
    Review reviews[MAX_ARRAY_SIZE];

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
                printf("Sviluppatore: %s\n", all_games[i].developer);
                printf("Genere: %s\n", all_games[i].genre);
                if(read_reviews(reviews, all_games[i].id, &reviews_count) == 0){
                    printf("Media: %.1f\n", average_review(reviews, reviews_count));
                }
                printf("-----------------------------------------\n");
                do{
                    printf("Desideri comprare il videogioco (Y/N): ");
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

void show_all_videogames(){
    int games_count, reviews_count;
    Videogame all_games[MAX_ARRAY_SIZE];
    Review reviews[MAX_ARRAY_SIZE];
    char option;

    printf("--------Videogiochi--------\n");
    if (read_all_videogames(all_games, &games_count) == 0) {
        for (int i = 0; i < games_count; i++) {
            printf("Titolo: %s\n", all_games[i].title);
            printf("Sviluppatore: %s\n", all_games[i].developer);
            printf("Genere: %s\n", all_games[i].genre);
            if(read_reviews(reviews, all_games[i].id, &reviews_count) == 0){
                printf("Media: %.1f\n", average_review(reviews, reviews_count));
            }
            printf("-----------------------------------------\n");
        }
    }
    do{
        printf("Desideri ordinare i videogiochi (Y/N): ");
        scanf(" %c", &option);
        if(option == 'y' || option == 'Y'){
            order_menu(all_games, games_count, reviews, reviews_count);
        }
        if(option != 'y' && option != 'Y' && option != 'n' && option != 'N'){
            printf("Opzione non valida. Riprova.\n");
        }
    }while(option != 'y' && option != 'Y' && option != 'n' && option != 'N');
}

void bestseller_sorter(Videogame all_games[], int games_count){
    int i, j;
    Videogame temp;
    for(i = 0; i < games_count; i++){
        for(j = i + 1; j < games_count; j++){
            if(all_games[i].copies_sold < all_games[j].copies_sold){
                temp = all_games[i];
                all_games[i] = all_games[j];
                all_games[j] = temp;
            }
        }
    }
}
// AGGIUSTARE QUESTA FUNZIONE PER AVERE LA MEDIA DELLE RECENSIONI
void best_reviewed_sorter(Videogame all_games[], int games_count){
    double average = 0.0;
    int i, j, reviews_count_temp, reviews_count_temp_2;
    Videogame temp;
    Review temp_1[MAX_ARRAY_SIZE], temp_2 [MAX_ARRAY_SIZE];
    for(i = 0; i < games_count; i++){
        if(read_reviews(temp_1, all_games[i].id,&reviews_count_temp) == 0){
            for(j = i + 1; j < games_count; j++){
                if(read_reviews(temp_2, all_games[j].id,&reviews_count_temp_2) == 0){
                    if(average_review(temp_1, reviews_count_temp) < average_review(temp_2, reviews_count_temp_2)){
                        temp = all_games[i];
                        all_games[i] = all_games[j];
                        all_games[j] = temp;
                    }
                }
            }
        }
    }
}

void alfabetical_sorter(Videogame all_games[], int games_count){
    int i, j;
    Videogame temp;
    for(i = 0; i < games_count; i++){
        for(j = i + 1; j < games_count; j++){
            if(strcmp(all_games[i].title, all_games[j].title) > 0){
                temp = all_games[i];
                all_games[i] = all_games[j];
                all_games[j] = temp;
            }
        }
    }
}

void bestseller_order(Videogame all_games[], int games_count){
    bestseller_sorter(all_games, games_count);

    printf("--------Videogiochi in ordine di vendita--------\n");
    for(int i = 0; i < games_count; i++){
        printf("Titolo: %s\t Copies venduti: %d\n", all_games[i].title, all_games[i].copies_sold);
    }
}

void review_order(Videogame all_games[], int games_count){
    best_reviewed_sorter(all_games, games_count);
    Review reviews[MAX_ARRAY_SIZE];
    int reviews_count;

    printf("--------Videogiochi in ordine di recensione--------\n");
    for(int i = 0; i < games_count; i++){
        if(read_reviews(reviews, all_games[i].id, &reviews_count) == 0){
            printf("Titolo: %s\t Media Recensioni: %1.1lf\n", all_games[i].title, average_review(reviews, reviews_count));
        }
    }
}

void alfabetical_order(Videogame all_games[], int games_count){
    alfabetical_sorter(all_games, games_count);

    printf("--------Videogiochi in ordine alfabetico--------\n");
    for(int i = 0; i < games_count; i++){
        printf("Titolo: %s\n", all_games[i].title);
    }
}

void top_seller(Videogame all_games[], int games_count){
//....
}

void top_reviewed(Videogame all_games[], int games_count, Review reviews[], int reviews_count){
//....
}