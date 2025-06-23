#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "videogame.h"
#include "research_and_sorting.h"
#include "review.h"

int get_menu_choice(int min_op, int max_op) {
    char buffer[100];
    char *endptr;
    long choice = -1;

    while (1) { // Cicla finché non otteniamo un input valido
        printf("Scegli una opzione: ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            // Rimuove il carattere di newline (\n) che fgets memorizza
            buffer[strcspn(buffer, "\n")] = 0;

            // Prova a convertire la stringa in un numero
            choice = strtol(buffer, &endptr, 10);

            // Controlla se la conversione è andata a buon fine e se è nell'intervallo giusto
            // 1. endptr == buffer: l'input non iniziava con un numero (es. "abc")
            // 2. *endptr != '\0': c'erano caratteri extra dopo il numero (es. "12xyz")
            // 3. choice < min_op || choice > max_op: il numero è fuori dall'intervallo
            if (endptr == buffer || *endptr != '\0' || choice < min_op || choice > max_op) {
                printf("Opzione non valida. Riprova.\n");
            } else {
                // Input valido, esci dal ciclo
                break;
            }
        } else {
            return max_op; 
        }
    }
    return (int)choice;
}


//Mostra menu degli ordinamenti e fa scegliere come lo si vuole ordinare
void order_menu(Videogame all_games[], int games_count){
    int op;
    do{
        printf("\n--------Ordina Per--------\n");
        printf("1. Recensioni\n");
        printf("2. Bestseller\n");
        printf("3. Alfabetico\n");
        printf("4. Torna al menu precedente\n");
        
        op = get_menu_choice(1, 4);

        if(op == 1){
            review_order(all_games, games_count);
        } else if(op == 2){
            bestseller_order(all_games, games_count);
        } else if(op == 3){
            alfabetical_order(all_games, games_count);
        }
    } while(op != 4);
}

//Mostra il menu e le scelte del visitatore
void user(){
    int op;
    do{
        printf("\n--------Menu visitatore--------\n");
        printf("1. Visualizza videogioco\n");
        printf("2. Visualizza i videogiochi del catalogo\n");
        printf("3. Torna al menu principale\n");
        
        op = get_menu_choice(1, 3);
        
        if(op == 1){
            search_videogame_user();
        } else if(op == 2){
            show_all_videogames();
        }
    } while (op != 3);
}

//Mostra menu delle statistiche e fa scegliere cosa si vuole vedere
void stats(){
    int op;
    do{
        printf("\n--------Gestione statistiche--------\n");
        printf("1. Migliori recensioni \n");
        printf("2. Best seller\n");
        printf("3. Dati singolo videogioco\n");
        printf("4. Torna al menu precedente\n");

        op = get_menu_choice(1, 4);
        
        if(op == 1){
            top_reviewed();
        } else if(op == 2){
            top_seller();
        } else if(op == 3){
            search_videogame_admin();
        }
    } while(op != 4);
}

//Menu per la gestione del videogame
void crud_menu(){
    int op;
    do{
        printf("\n--------Gestione Videogiochi--------\n");
        printf("1. Aggiungi videogioco\n");
        printf("2. Modifica videogioco\n");
        printf("3. Elimina videogioco\n");
        printf("4. Torna al menu admin\n");
        
        op = get_menu_choice(1, 4);

        if(op == 1){
            add_videogame();
        } else if(op == 2){
            edit_videogame();
        } else if(op == 3){
            delete_videogame();
        }
    } while(op != 4);
}

//Mostra il menu e le scelte dell'amministratore
void admin(){
    int op;
    do{
        printf("\n--------Menu amministratore--------\n");
        printf("1. Gestione videogiochi\n");
        printf("2. Visualizza statistiche\n");
        printf("3. Torna al menu principale\n");
        
        op = get_menu_choice(1, 3);

        if(op == 1){
            crud_menu();
        } else if(op == 2){
            stats();
        }
    } while(op != 3);
}

//Mostra il menu iniziale dove scegliere come effettuare l'accesso
void start(){
    int op;
    do{
        printf("\n========Benvenuto nel Catalogo di Videogiochi========\n");
        printf("Seleziona una opzione:\n");
        printf("1. Admin\n");
        printf("2. Utente\n");
        printf("3. Esci\n");

        op = get_menu_choice(1, 3);

        if(op == 1){
            admin();
        } else if(op == 2){
            user();
        }
    } while(op != 3);
}