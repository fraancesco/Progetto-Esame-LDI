#ifndef REVIEW_H
#define REVIEW_H

#define MAX_COMMENT_SIZE 200

typedef struct review
{
    int id;
    int videogame_id;
    double value;
    char comment[MAX_COMMENT_SIZE];
} Review;


void add_review(int videogame_id);
void view_reviews(int videogame_id);
void delete_review(int videogame_id);

#endif