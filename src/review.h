#ifndef REVIEW_H
#define REVIEW_H

#define MAX_COMMENT_SIZE 200

typedef struct review
{
    int id;
    int videogame_id;
    int value;
    char comment[MAX_COMMENT_SIZE];
} Review;


void add_review(int videogame_id);
void view_review();

#endif