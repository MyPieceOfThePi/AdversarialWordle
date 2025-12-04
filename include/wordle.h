#ifndef WORDLE_H
#define WORDLE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

#define WORD_LENGTH 5

extern Element *pool;

typedef enum FeedbackColour{
    GREY,
    YELLOW,
    GREEN
} Feedback;

void processGuess(char *guess, Feedback out[WORD_LENGTH]);

#endif