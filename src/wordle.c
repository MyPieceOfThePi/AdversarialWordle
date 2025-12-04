#include "wordle.h"
#include <stdio.h>
Element *stack[243];
Element *pool = NULL;

static int hash(Feedback feedback[WORD_LENGTH]){
    int h = 0;
    for(int i = 0; i < WORD_LENGTH; i++){
        h = h*3 + feedback[i];
    }
    return h;
}

void score(char *guess, char *answer, Feedback out[WORD_LENGTH]){
    int dict[26] = {0};
    for(int i = 0; i < WORD_LENGTH; i++) out[i] = GREY;
    for(int i = 0; i < WORD_LENGTH; i++){
        if(guess[i] == answer[i]) out[i] = GREEN;
        else dict[answer[i] - 'a']++;
    }
    for(int i = 0; i < WORD_LENGTH; i++){
        if(dict[guess[i] - 'a'] && out[i] != GREEN){
            dict[guess[i] -'a']--; 
            out[i] = YELLOW;
        }
    }
}

void processGuess(char *guess, Feedback out[WORD_LENGTH]){
    for(Element *e = pool; e; e = e->next){
        Feedback fdbk[WORD_LENGTH] = {0};
        score(guess, (char*) (e->value), fdbk);
        push(&(stack[hash(fdbk)]), e->value, WORD_LENGTH + 1);
    }

    Element *max = NULL;
    for(int i = 0; i < 243; i++){
        if(stack[i] == NULL) continue;
        if(!max || stack[i]->len > max->len) max = stack[i];
    }

    freeStack(pool);
    pool = max;
    for(int i = 0; i < 243; i++){
        if(stack[i] != pool){
            freeStack(stack[i]);
        }
        stack[i] = NULL;
    }

    score(guess, (char*) (pool->value), out);
}