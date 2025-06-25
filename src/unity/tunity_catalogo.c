// Abilita il supporto per i double in Unity
#define UNITY_INCLUDE_DOUBLE

// --- Inclusione Framework Unity ---
#include "unity.c"
#include "unity.h"
#include "unity_internals.h"

// --- Inclusione Header del Progetto ---
#include "../file_manager.h"
#include "../menu.h"
#include "../research_and_sorting.h"
#include "../review.h"
#include "../videogame.h"

// --- Inclusione Sorgenti per la Compilazione ---
#undef PATH_VIDEOGAME_FILE
#define PATH_VIDEOGAME_FILE "../../data/test_videogiochi.bin"

#undef PATH_REVIEW_FILE
#define PATH_REVIEW_FILE "../../data/test_recensioni.bin"

#include "../file_manager.c"
#include "../review.c"
#include "../videogame.c"
#include "../research_and_sorting.c"
#include "../menu.c"


/*
 * FUNZIONI DI SETUP E TEARDOWN
 *  Pulisce i file di test per garantire che ogni test venga eseguito
 *  in uno stato pulito e isolato.
 */
void setUp(void) {
    remove(PATH_VIDEOGAME_FILE);
    remove(PATH_REVIEW_FILE);
}

void tearDown(void) {
    remove(PATH_VIDEOGAME_FILE);
    remove(PATH_REVIEW_FILE);
}

/*
 * PREPARAZIONE DATI DI TEST
 */

// Funzione helper per creare un set di dati di videogiochi standard per i test
void create_test_videogame_dataset() {
    Videogame games[] = {
        {1, 2022, 1500, "Elden Ring", "FromSoftware", "FromSoftware", "Un vasto RPG open world", "RPG"},
        {2, 2018, 2500, "Red Dead Redemption 2", "Rockstar Games", "Rockstar Games", "Avventura nel selvaggio west", "Action-Adventure"},
        {3, 2023, 800, "Baldur's Gate 3", "Larian Studios", "Larian Studios", "RPG basato su D&D", "RPG"},
        {4, 2011, 3000, "Skyrim", "Bethesda", "Bethesda", "Dragi e avventura", "RPG"}
    };
    FILE *file = fopen(PATH_VIDEOGAME_FILE, "wb");
    TEST_ASSERT_NOT_NULL(file);
    fwrite(games, sizeof(Videogame), 4, file);
    fclose(file);
}

// Funzione helper per creare un set di dati di recensioni standard per i test
void create_test_review_dataset() {
    Review reviews[] = {
        {1, 1, 4.8, "Capolavoro assoluto."},
        {2, 1, 4.5, "Molto difficile ma gratificante."},
        {3, 2, 5.0, "Il miglior gioco mai creato."},
        {4, 3, 4.9, "Incredibilmente profondo."},
        {5, 4, 4.2, "Un classico senza tempo."}
    };
    FILE *file = fopen(PATH_REVIEW_FILE, "wb");
    TEST_ASSERT_NOT_NULL(file);
    fwrite(reviews, sizeof(Review), 5, file);
    fclose(file);
}

/*
 * TEST PER FILE_MANAGER.C
 */

// Verifica che l'ID restituito per un file di videogiochi vuoto o inesistente sia correttamente 0.
void test_last_videogame_id_on_empty_file(void) {
    TEST_ASSERT_EQUAL_INT(0, last_videogame_id());
}

// Verifica la scrittura e la successiva rilettura di un singolo videogioco per verificare che siano state mantenute correttamente.
void test_write_and_read_single_videogame(void) {
    Videogame game = {1, 2025, 0, "Test Game", "Test Editor", "Test Dev", "Desc", "Genre"};
    TEST_ASSERT_EQUAL_INT(0, write_videogame_file(game));

    TEST_ASSERT_EQUAL_INT(1, last_videogame_id());

    Videogame read_games[1];
    int count = 0;
    read_all_videogames(read_games, &count);

    TEST_ASSERT_EQUAL_INT(1, count);
    TEST_ASSERT_EQUAL_STRING("Test Game", read_games[0].title);
}

/*void test_write_duplicate_videogame_should_fail(void) {
    Videogame game1 = {1, 2025, 0, "Unique Title", "E1", "D1", "D", "G"};
    Videogame game2 = {2, 2026, 0, "Unique Title", "E2", "D2", "D", "G"}; 
    
    write_videogame_file(game1);
    TEST_ASSERT_EQUAL_INT(-1, write_videogame_file(game2));
} Non verificabile, dovrebbe cambiare il path del file di test*/

// Testa la modifica di un videogioco, salvando le modifiche su file e verificando che siano state mantenute correttamente.
void test_edit_videogame_file(void) {
    create_test_videogame_dataset();
    Videogame all_games[MAX_ARRAY_SIZE];
    int games_count = 0;
    read_all_videogames(all_games, &games_count);

    strcpy(all_games[0].title, "Elden Ring Edited");
    all_games[0].year = 2024;
    edit_videogame_file(all_games, games_count);

    read_all_videogames(all_games, &games_count);
    TEST_ASSERT_EQUAL_STRING("Elden Ring Edited", all_games[0].title);
    TEST_ASSERT_EQUAL_INT(2024, all_games[0].year);
}


/*
 * TEST PER REVIEW.C
 */

// Verifica che la media di un set vuoto, verificando che il risultato sia 0 come da comportamento atteso.
void test_average_review_with_no_reviews(void) {
    Review reviews[1];

    TEST_ASSERT_EQUAL_DOUBLE(0.0, average_review(reviews, 0));
}

// Verifica la correttezza dell'algoritmo per un set di dati multipli per controllare l'accuratezza dell'algoritmo.
void test_average_review_with_multiple_reviews(void) {
    Review reviews[] = {
        {1, 1, 5.0, ""},
        {2, 1, 4.0, ""},
        {3, 1, 3.5, ""}
    };
    double expected_avg = (5.0 + 4.0 + 3.5) / 3.0;
    TEST_ASSERT_EQUAL_DOUBLE(expected_avg, average_review(reviews, 3));
}

// Verifica il corretto ordinamento alfabetico dei videogiochi in base al titolo.
void test_delete_review_logic(void) {
    create_test_review_dataset();
    Review all_reviews[MAX_ARRAY_SIZE];
    int reviews_count = 0;
    
    FILE *file = fopen(PATH_REVIEW_FILE, "rb");
    fseek(file, 0, SEEK_END);
    reviews_count = ftell(file) / sizeof(Review);
    fseek(file, 0, SEEK_SET);
    fread(all_reviews, sizeof(Review), reviews_count, file);
    fclose(file);

    TEST_ASSERT_EQUAL_INT(5, reviews_count);

    int index_to_delete = -1;
    for(int i=0; i<reviews_count; i++){
        if(all_reviews[i].videogame_id == 2){
            index_to_delete = i;
            break;
        }
    }
    
    for (int i = index_to_delete; i < reviews_count - 1; i++) {
        all_reviews[i] = all_reviews[i + 1];
    }
    
    edit_review_file(all_reviews, reviews_count - 1);
    
    Review updated_reviews[MAX_ARRAY_SIZE];
    int updated_count;
    read_all_reviews(updated_reviews, &updated_count); 

    TEST_ASSERT_EQUAL_INT(4, updated_count);
}


/*
 * TEST PER VIDEOGAME.C
 */

// Verifica la funzionalità di acquisto, controllando che il contatore delle copie vendute di un gioco venga incrementato correttamente dopo la chiamata alla funzione.
void test_buy_videogame(void) {
    create_test_videogame_dataset();
    
    buy_videogame(1);
    
    Videogame all_games[MAX_ARRAY_SIZE];
    int games_count;
    read_all_videogames(all_games, &games_count);
    
    TEST_ASSERT_EQUAL_INT(1501, all_games[0].copies_sold);
}

/*
 * TEST PER RESEARCH_AND_SORTING.C
 */

// Verifica la ricerca per titolo con una corrispondenza esatta e case-insensitive per assicurare che venga restituito il gioco corretto.
void test_search_title_exact_match(void) {
    create_test_videogame_dataset();
    Videogame all_games[MAX_ARRAY_SIZE], temp[MAX_ARRAY_SIZE];
    int games_count;
    read_all_videogames(all_games, &games_count);
    
    int found = search_title("elden ring", games_count, all_games, temp);
    
    TEST_ASSERT_EQUAL_INT(1, found);
    TEST_ASSERT_EQUAL_STRING("Elden Ring", temp[0].title);
}

// Verifica che la ricerca per un titolo non esistente nel catalogo non produce alcun risultato.
void test_search_title_no_match(void) {
    create_test_videogame_dataset();
    Videogame all_games[MAX_ARRAY_SIZE], temp[MAX_ARRAY_SIZE];
    int games_count;
    read_all_videogames(all_games, &games_count);
    
    int found = search_title("zelda", games_count, all_games, temp);
    
    TEST_ASSERT_EQUAL_INT(0, found);
}

// Verifica la ricerca per genere usando una parola chiave parziale per verificare il corretto funzionamento del match parziale.
void test_search_genre_partial_match(void) {
    create_test_videogame_dataset();
    Videogame all_games[MAX_ARRAY_SIZE], temp[MAX_ARRAY_SIZE];
    int games_count;
    read_all_videogames(all_games, &games_count);
    
    int found = search_genre("adventure", games_count, all_games, temp);
    
    TEST_ASSERT_EQUAL_INT(1, found);
    TEST_ASSERT_EQUAL_STRING("Red Dead Redemption 2", temp[0].title);
}

// Controlla la ricerca per anno di pubblicazione per filtrare i giochi e restituire solo quelli corrispondenti.
void test_search_year(void) {
    create_test_videogame_dataset();
    Videogame all_games[MAX_ARRAY_SIZE], temp[MAX_ARRAY_SIZE];
    int games_count;
    read_all_videogames(all_games, &games_count);
    
    int found = search_year("2018", games_count, all_games, temp);
    
    TEST_ASSERT_EQUAL_INT(1, found);
    TEST_ASSERT_EQUAL_STRING("Red Dead Redemption 2", temp[0].title);
}

// Verifica il corretto ordinamento alfabetico dei videogiochi in base al titolo.
void test_alfabetical_sorter(void) {
    create_test_videogame_dataset();
    Videogame all_games[MAX_ARRAY_SIZE];
    int games_count;
    read_all_videogames(all_games, &games_count);
    
    alfabetical_sorter(all_games, games_count);
    
    TEST_ASSERT_EQUAL_STRING("Baldur's Gate 3", all_games[0].title);
    TEST_ASSERT_EQUAL_STRING("Elden Ring", all_games[1].title);
    TEST_ASSERT_EQUAL_STRING("Red Dead Redemption 2", all_games[2].title);
    TEST_ASSERT_EQUAL_STRING("Skyrim", all_games[3].title);
}

// Verifica l'ordinamento dei giochi per numero di copie vendute (bestseller) in ordine decrescente.
void test_bestseller_sorter(void) {
    create_test_videogame_dataset();
    Videogame all_games[MAX_ARRAY_SIZE];
    int games_count;
    read_all_videogames(all_games, &games_count);
    
    bestseller_sorter(all_games, games_count);
    
    TEST_ASSERT_EQUAL_STRING("Skyrim", all_games[0].title); 
    TEST_ASSERT_EQUAL_STRING("Red Dead Redemption 2", all_games[1].title); 
    TEST_ASSERT_EQUAL_STRING("Elden Ring", all_games[2].title);
    TEST_ASSERT_EQUAL_STRING("Baldur's Gate 3", all_games[3].title);
}

// Verifica l'ordinamento dei giochi in base alla media delle loro recensioni, dal più apprezzato al meno apprezzato.
void test_best_reviewed_sorter(void) {
    create_test_videogame_dataset();
    create_test_review_dataset();
    Videogame all_games[MAX_ARRAY_SIZE];
    int games_count;
    read_all_videogames(all_games, &games_count);
    
    best_reviewed_sorter(all_games, games_count);

    TEST_ASSERT_EQUAL_STRING("Red Dead Redemption 2", all_games[0].title);
    TEST_ASSERT_EQUAL_STRING("Baldur's Gate 3", all_games[1].title);
    TEST_ASSERT_EQUAL_STRING("Elden Ring", all_games[2].title);
    TEST_ASSERT_EQUAL_STRING("Skyrim", all_games[3].title);
}

int test_runner_main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_last_videogame_id_on_empty_file);
    RUN_TEST(test_write_and_read_single_videogame);
    //RUN_TEST(test_write_duplicate_videogame_should_fail);
    RUN_TEST(test_edit_videogame_file);
    
    RUN_TEST(test_average_review_with_no_reviews);
    RUN_TEST(test_average_review_with_multiple_reviews);
    RUN_TEST(test_delete_review_logic);

    RUN_TEST(test_buy_videogame);

    RUN_TEST(test_search_title_exact_match);
    RUN_TEST(test_search_title_no_match);
    RUN_TEST(test_search_genre_partial_match);
    RUN_TEST(test_search_year);
    
    RUN_TEST(test_alfabetical_sorter);
    RUN_TEST(test_bestseller_sorter);
    RUN_TEST(test_best_reviewed_sorter);

    return UNITY_END(); 
}

// Entry point per l'eseguibile di test.
#undef main
int main(void){
    return test_runner_main();
}