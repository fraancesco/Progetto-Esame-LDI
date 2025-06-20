#include <stdio.h>
#include "menu.h"
#include "videogame.h"
#include "research_and_order.h"
#include "review.h"

void stats(){
    int op;
    do{
        printf("--------Gestione statistiche--------\n");
        printf("1. Migliori recensioni \n");
        printf("2. Best seller\n");
        printf("3. Dati singolo videogioco\n");
        printf("4. Torna al menu principale\n");
        printf("Scegli una opzione: ");
        do {
            scanf("%d", &op);
            if (op < 1 || op > 4) {
                printf("Opzione non valida. Riprova.\n");
            }
        }while (op < 1 || op > 4);
        if(op == 1){
            top_reviewed();
        } else if(op == 2){
            top_seller();
        } else if(op == 3){
            search_videogame_admin();
        }
    }while(op != 4);
}

void order_menu(Videogame all_games[], int games_count){
    int op;
    do{
        printf("--------Ordina Per--------\n");
        printf("1. Recensioni\n");
        printf("2. Bestseller\n");
        printf("3. Alfabetico\n");
        printf("4. Torna al menu principale\n");
        printf("Scegli una opzione: ");
        do {
            scanf("%d", &op);
            if (op < 1 || op > 4) {
                printf("Opzione non valida. Riprova.\n");
            }
        }while (op < 1 || op > 4);
        if(op == 1){
            review_order(all_games, games_count);
        } else if(op == 2){
            bestseller_order(all_games, games_count);
        } else if(op == 3){
            alfabetical_order(all_games, games_count);
        }
    }while(op != 4);
}

void admin(){
    int op;
    do{
        printf("--------Menu amministratore--------\n");
        printf("1. Gestione videogiochi\n");
        printf("2. Visualizza statistiche\n");
        printf("3. Torna al menu principale\n");
        printf("Scegli una opzione: ");
        do {
            scanf("%d", &op);
            if (op < 1 || op > 3) {
                printf("Opzione non valida. Riprova.\n");
            }
        }while (op < 1 || op > 3);
        if(op == 1){
            crud_menu();
        } else if(op == 2){
            stats();
        }
    }while(op != 3);
}

void crud_menu(){
    int op;
    do{
        printf("--------Opzioni--------\n");
        printf("1. Aggiungi videogioco\n");
        printf("2. Modifica videogioco\n");
        printf("3. Elimina videogioco\n");
        printf("4. Torna al menu admin\n");
        printf("Scegli una opzione: ");
        do {
            scanf("%d", &op);
            if (op < 1 || op > 4) {
                printf("Opzione non valida. Riprova.\n");
            }
        }while (op < 1 || op > 4);
        if(op == 1){
            add_videogame();
        } else if(op == 2){
            edit_videogame();
        } else if(op == 3){
            delete_videogame();
        }
    }while(op != 4);
}

void user(){
    int op;
    do{
        printf("--------Menu visitatore--------\n");
        printf("1. Visualizza videogioco\n");
        printf("2. Visualizza i videogiochi del catalogo\n");
        printf("3. Torna al menu principale\n");
        printf("Scegli una opzione: ");
        do {
            scanf("%d", &op);
            if (op < 1 || op > 3) {
                printf("Opzione non valida. Riprova.\n");
            }
        }while (op < 1 || op > 3);
        if(op == 1){
            search_videogame_user();
        } else if(op == 2){
            show_all_videogames();
        }
    }while (op != 3);
}

void start(){
    int op;
    do{
        printf("========Benvenuto nel Catalogo di Videogiochi========\n");
        printf("Seleziona una opzione:\n");
        printf("1. Admin\n");
        printf("2. Utente\n");
        printf("3. Esci\n");
        printf("Scegli una opzione: ");
        do {
            scanf("%d", &op);
            if (op < 1 || op > 3) {
                printf("Opzione non valida. Riprova.\n");
            }
        }while (op < 1 || op > 3);
        if(op == 1){
            admin();
        } else if(op == 2){
            user();
        }
    }while(op != 3);
}