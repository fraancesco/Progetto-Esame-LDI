#include <stdio.h>
#include <string.h>
#include <math.h>
#include "videogame.h"
#include "file_manager.h"

void add_videogame(){
    Videogame new_game;
    int c;
    int year_error = 0;

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
        if(new_game.year < 1900 || new_game.year > 2050){
            printf("Anno non valido. Riprova.\n");
            year_error = 1;
        }
        if(isnan(new_game.year)){
            printf("Inserire un numero intero. Riprova.\n");
            year_error = 1;
        }
    }while(year_error == 1);
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