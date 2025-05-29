#include <stdio.h>
#include "menu.h"

void admin(){
    int op;
    do{
        printf("Menu amministratore:\n");
        printf("1. Gestione videogiochi\n");
        printf("2. Gestione recensioni\n");
        printf("3. Visualizza videogiochi\n");
        printf("4. Torna al menu principale\n");
        do {
            scanf("%d", &op);
            if (op < 1 || op > 4) {
                printf("Opzione non valida. Riprova.\n");
            }
        }while (op < 1 || op > 4);
        if(op == 1){
            //admin_videogame();
        } else if(op == 2){
            //admin_review();
        } else if(op == 3){
            //view_videogame();
        }
    }while(op != 4);
}

void user(){
    int op;
    do{
        printf("Menu visitatore:\n");
        printf("1. Visualizza videogioco\n");
        printf("2. Aggiungi recensione\n");
        printf("3. Acquista videogioco\n");
        printf("4. Torna al menu principale\n");
        do {
            scanf("%d", &op);
            if (op < 1 || op > 4) {
                printf("Opzione non valida. Riprova.\n");
            }
        }while (op < 1 || op > 4);
        if(op == 1){
            //view_videogame();
        } else if(op == 2){
            //add_review();
        } else if(op == 3){
            //buy_videogame();
        }
    }while (op != 4);
}

void start(){
    int op;
    do{
        printf("Benvenuto nel Catalogo di Videogiochi!\n");
        printf("Seleziona una opzione:\n");
        printf("1. Admin\n");
        printf("2. Utente\n");
        printf("3. Esci\n");
        do {
            scanf("%d", &op);
            if (op < 1 || op > 3) {
                printf("Opzione non valida. Riprova.\n");
            }
        }while (op < 1 || op > 3);
        if(op == 1){
            admin();
        } else {
            user();
        }
    }while(op != 3);
}