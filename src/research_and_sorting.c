#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "videogame.h"
#include "file_manager.h"
#include "research_and_sorting.h"
#include "review.h"
#include "menu.h"

//scorre tutti i videogame, converte il suo editore in una stringa tutta minuscola e la confronta con quella cercata
//facciamo la stessa cosa per sviluppatore, genere e titolo
int search_editor(char keyword[], int games_count, Videogame all_games[], Videogame temp[]){
    int index = 0;
    char editor[MAX_STRING_SIZE];

    for (int i = 0; i < games_count; i++) {
        memset(editor, 0, sizeof(editor));
        for (int j = 0; j < strlen(all_games[i].editor); j++){
            editor[j] = tolower(all_games[i].editor[j]);
        }
        if(strcmp(editor, keyword) == 0){
            temp[index] = all_games[i];
            index++;
        }
    }
    if(index == 0){
        for (int i = 0; i < games_count; i++) {
            memset(editor, 0, sizeof(editor));
            for (int j = 0; j < strlen(all_games[i].editor); j++){
            editor[j] = tolower(all_games[i].editor[j]);
            }
            if(strstr(editor, keyword) != NULL) {
                temp[index] = all_games[i];
                index++;
            }
        }
    }

    return index;
}
int search_developer(char keyword[], int games_count, Videogame all_games[], Videogame temp[]){
    int index = 0;
    char developer[MAX_STRING_SIZE];

    for (int i = 0; i < games_count; i++) {
        memset(developer, 0, sizeof(developer));
        for (int j = 0; j < strlen(all_games[i].developer); j++){
            developer[j] = tolower(all_games[i].developer[j]);
        }
        if(strcmp(developer, keyword) == 0){
            temp[index] = all_games[i];
            index++;
        }
    }
    if(index == 0){
        for (int i = 0; i < games_count; i++) {
            memset(developer, 0, sizeof(developer));
            for (int j = 0; j < strlen(all_games[i].developer); j++){
            developer[j] = tolower(all_games[i].developer[j]);
            }
            if(strstr(developer, keyword) != NULL) {
                temp[index] = all_games[i];
                index++;
            }
        }
    }

    return index;
}
int search_genre(char keyword[], int games_count, Videogame all_games[], Videogame temp[]){
    int index = 0;
    char genre[MAX_STRING_SIZE];

    for (int i = 0; i < games_count; i++) {
        memset(genre, 0, sizeof(genre));
        for (int j = 0; j < strlen(all_games[i].genre); j++){
            genre[j] = tolower(all_games[i].genre[j]);
        }
        if(strcmp(genre, keyword) == 0){
            temp[index] = all_games[i];
            index++;
        }
    }
    if(index == 0){
        for (int i = 0; i < games_count; i++) {
            memset(genre, 0, sizeof(genre));
            for (int j = 0; j < strlen(all_games[i].genre); j++){
            genre[j] = tolower(all_games[i].genre[j]);
            }
            if(strstr(genre, keyword) != NULL) {
                temp[index] = all_games[i];
                index++;
            }
        }
    }

    return index;
}
//Confronta l'anno inserito con quelli presenti
int search_year(char keyword[], int games_count, Videogame all_games[], Videogame temp[]){
    int index = 0;
    int year = atoi(keyword);

    for (int i = 0; i < games_count; i++) {
        if(year == all_games[i].year){
            temp[index] = all_games[i];
            index++;
        }
    }

    return index;
}

int search_title(char keyword[], int games_count, Videogame all_games[], Videogame temp[]){
    int index = 0;
    char title[MAX_STRING_SIZE];

    for (int i = 0; i < games_count; i++) {
        memset(title, 0, sizeof(title));
        for (int j = 0; j < strlen(all_games[i].title); j++){
            title[j] = tolower(all_games[i].title[j]);
        }
        if(strcmp(title, keyword) == 0){
            temp[index] = all_games[i];
            index++;
        }
    }
    if(index == 0){
        for (int i = 0; i < games_count; i++) {
            memset(title, 0, sizeof(title));
            for (int j = 0; j < strlen(all_games[i].title); j++){
            title[j] = tolower(all_games[i].title[j]);
            }
            if(strstr(title, keyword) != NULL) {
                temp[index] = all_games[i];
                index++;
            }
        }
    }

    return index;
}

//Stampa tutte le informazioni del/i videgame per l'amministratore
void show_videogame_admin(Videogame all_games[], int games_count){
    if (games_count == 1) {
        printf("--------Videogioco Trovato--------\n");
    } else{
        printf("--------Videogiochi Trovati--------\n");
    }

    for (int i = 0; i < games_count; i++) {
        printf("Titolo: %s\n", all_games[i].title);
        printf("Editore: %s\n", all_games[i].editor);
        printf("Sviluppatore: %s\n", all_games[i].developer);
        printf("Descrizione: %s\n", all_games[i].description);
        printf("Anno di pubblicazione: %d\n", all_games[i].year);
        printf("Genere: %s\n", all_games[i].genre);
        printf("Copie vendute: %d\n", all_games[i].copies_sold);
        view_reviews(all_games[i].id);
        if (games_count != 1) {
            printf("-----------------------------------------\n");
        }
    }
}

//Stampa le informazioni del titolo,sviluppatore, genere e media recensioni
//Poi fa scegliere se acquistarlo controllando che abbiano scritto correttamente, altrimenti da errore
void show_videogame_user(Videogame all_games[], int games_count){
    Review reviews[MAX_ARRAY_SIZE];
    int reviews_count;
    char option;

    if (games_count == 1) {
        printf("--------Videogioco Trovato--------\n");
    } else{
        printf("--------Videogiochi Trovati--------\n");
    }

    for (int i = 0; i < games_count; i++) {
        printf("Titolo: %s\n", all_games[i].title);
        printf("Sviluppatore: %s\n", all_games[i].developer);
        printf("Genere: %s\n", all_games[i].genre);
        if(read_reviews(reviews, all_games[i].id, &reviews_count) == 0){
            printf("Media: %.1f\n", average_review(reviews, reviews_count));
        }
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
        if(games_count != 1){
            printf("-----------------------------------------\n");
        }
    }
}

//Ricerca nella parte dell'amministratore, tramite una parola chiave,
// il titolo del gioco e se non corrisponde ad un titolo prova per anche gli altri criteri
void search_videogame_admin(){
    char keyword[MAX_STRING_SIZE], option;
    int c, games_count, too_long, found = 0;
    Videogame all_games[MAX_ARRAY_SIZE], temp [MAX_ARRAY_SIZE];

    while ((c = getchar()) != '\n' && c != EOF); // Pulisce il buffer

    do {
        too_long = 0;
        printf("Inserisci parola chiave: ");
        fgets(keyword, MAX_STRING_SIZE, stdin);
        if(strlen(keyword) > 0 && keyword[strlen(keyword) - 1] == '\n'){
            keyword[strlen(keyword) - 1] = '\0';
        } else{
            while ((c = getchar()) != '\n' && c != EOF);
            too_long = 1;
        }
        if (strlen(keyword) == 0) {
            printf("Inserire una parola chiave. Riprova.\n");
        }
        if(too_long){
            printf("Parola troppo lunga. Riprova.\n");
        }
    } while (strlen(keyword) == 0 || too_long);

    for(int i = 0; i < strlen(keyword); i++){
        keyword[i] = tolower(keyword[i]);
    }

    if (read_all_videogames(all_games, &games_count) == 0) {
        if ((found = search_title(keyword, games_count, all_games, temp)) > 0) {
            show_videogame_admin(temp, found);
        } else if((found = search_editor(keyword, games_count, all_games, temp)) > 0){
            show_videogame_admin(temp, found);
        } else if((found = search_developer(keyword, games_count, all_games, temp)) > 0){
            show_videogame_admin(temp, found);
        } else if((found = search_genre(keyword, games_count, all_games, temp)) > 0){
            show_videogame_admin(temp, found);
        } else if((found = search_year(keyword, games_count, all_games, temp)) > 0){
            show_videogame_admin(temp, found);
        } else{
            printf("Videogioco non trovato.\n");
        }
    } else {
        printf("Errore nella lettura dei videogiochi.\n");
    }
}

//stesso identico criterio utilizzato per l'admin
void search_videogame_user(){
    char keyword[MAX_STRING_SIZE], option;
    int c, games_count, too_long, reviews_count, found = 0;
    Videogame all_games[MAX_ARRAY_SIZE], temp [MAX_ARRAY_SIZE];
    Review reviews[MAX_ARRAY_SIZE];

    while ((c = getchar()) != '\n' && c != EOF); // Pulisce il buffer

    do {
        too_long = 0;
        printf("Inserisci parola chiave: ");
        fgets(keyword, MAX_STRING_SIZE, stdin);
        if(strlen(keyword) > 0 && keyword[strlen(keyword) - 1] == '\n'){
            keyword[strlen(keyword) - 1] = '\0';
        } else{
            while ((c = getchar()) != '\n' && c != EOF);
            too_long = 1;
        }
        if (strlen(keyword) == 0) {
            printf("Inserire un titolo. Riprova.\n");
        }
        if(too_long){
            printf("Titolo troppo lungo. Riprova.\n");
        }
    } while (strlen(keyword) == 0 || too_long);

    for(int i = 0; i < strlen(keyword); i++){
        keyword[i] = tolower(keyword[i]);
    }

    if (read_all_videogames(all_games, &games_count) == 0) {
        if ((found = search_title(keyword, games_count, all_games, temp)) > 0) {
            show_videogame_user(temp, found);
        } else if((found = search_editor(keyword, games_count, all_games, temp)) > 0){
            show_videogame_user(temp, found);
        } else if((found = search_developer(keyword, games_count, all_games, temp)) > 0){
            show_videogame_user(temp, found);
        } else if((found = search_genre(keyword, games_count, all_games, temp)) > 0){
            show_videogame_user(temp, found);
        } else if((found = search_year(keyword, games_count, all_games, temp)) > 0){
            show_videogame_user(temp, found);
        } else{
            printf("Videogioco non trovato.\n");
        }
    } else {
        printf("Errore nella lettura dei videogiochi.\n");
    }
}

//mostra tutti i videogame e fa scegliere secondo quale ordine li vuole vedere
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
            order_menu(all_games, games_count);
        }
        if(option != 'y' && option != 'Y' && option != 'n' && option != 'N'){
            printf("Opzione non valida. Riprova.\n");
        }
    }while(option != 'y' && option != 'Y' && option != 'n' && option != 'N');
}



//funzioni di ordinamento dei vari criteri
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

//funzione di visualizzazione dei criteri ordinati
void bestseller_order(Videogame all_games[], int games_count){
    bestseller_sorter(all_games, games_count);

    printf("--------Videogiochi in ordine di vendita--------\n");
    for(int i = 0; i < games_count; i++){
        printf("Titolo: %s\t COPIE VENDUTE: %d\n", all_games[i].title, all_games[i].copies_sold);
        printf("-----------------------------------------\n");
    }
}

void review_order(Videogame all_games[], int games_count){
    best_reviewed_sorter(all_games, games_count);
    Review reviews[MAX_ARRAY_SIZE];
    int reviews_count;

    printf("--------Videogiochi in ordine di recensione--------\n");
    for(int i = 0; i < games_count; i++){
        if(read_reviews(reviews, all_games[i].id, &reviews_count) == 0){
            printf("Titolo: %s\t MEDIA RECENSIONI: %1.1lf\n", all_games[i].title, average_review(reviews, reviews_count));
            printf("-----------------------------------------\n");
        }
    }
}

void alfabetical_order(Videogame all_games[], int games_count){
    alfabetical_sorter(all_games, games_count);

    printf("--------Videogiochi in ordine alfabetico--------\n");
    for(int i = 0; i < games_count; i++){
        printf("Titolo: %s\n", all_games[i].title);
        printf("Descrizione: %s\n", all_games[i].description);
        printf("Genere: %s\n", all_games[i].genre);
        printf("-----------------------------------------\n");
    }
}

//Mostra i videogame più venduti
void top_seller(){
    Review reviews[MAX_ARRAY_SIZE];
    Videogame all_games[MAX_ARRAY_SIZE] = {0};
    int reviews_count, games_count;

    if(read_all_videogames(all_games, &games_count) == 0){
        bestseller_sorter(all_games, games_count);
        
        printf("--------Videogiochi in ordine di Vendita--------\n");
        for(int i = 0; i < 5; i++){
            if(strcmp(all_games[i].title, "") != 0){
                if(read_reviews(reviews, all_games[i].id, &reviews_count) == 0){
                    printf("Titolo: %s\n", all_games[i].title);
                    printf("Descrizione: %s\n", all_games[i].description);
                    printf("Genere: %s\n", all_games[i].genre);
                    printf("Media Recensioni: %1.1lf\n", average_review(reviews, reviews_count));
                    printf("COPIE VENDUTE: %d\n", all_games[i].copies_sold);
                    printf("\n");
                }
            }
        }
    }
}

//Mostra i videogame meglio recensiti
void top_reviewed(){
    Review reviews[MAX_ARRAY_SIZE];
    Videogame all_games[MAX_ARRAY_SIZE] = {0};
    int reviews_count, games_count;

    if(read_all_videogames(all_games, &games_count) == 0){
        best_reviewed_sorter(all_games, games_count);
        
        printf("--------Videogiochi in ordine di Recensioni--------\n");
        for(int i = 0; i < 5; i++){
            if(strcmp(all_games[i].title, "") != 0){
                if(read_reviews(reviews, all_games[i].id, &reviews_count) == 0){
                    printf("Titolo: %s\n", all_games[i].title);
                    printf("Descrizione: %s\n", all_games[i].description);
                    printf("Genere: %s\n", all_games[i].genre);
                    printf("Copie Vendute: %d\n", all_games[i].copies_sold);
                    printf("MEDIA RECENSIONI: %1.1lf\n", average_review(reviews, reviews_count));
                    printf("\n");
                }
            }
        }
    }
}