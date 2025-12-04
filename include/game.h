#ifndef GAME_H
#define GAME_H
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include "wordle.h"
#include "stack.h"
#include "dictionary.h"

#define NUM_GUESSES 15

typedef struct {
    char words[NUM_GUESSES][WORD_LENGTH + 1];
    Feedback feedback[NUM_GUESSES][WORD_LENGTH];
} GameState;

void printGame(GameState gs);
void clear();
void play(GameState *gs, int *guessNum);
bool getInput(char *word);
void load(FILE* La, FILE* Ta);
#endif