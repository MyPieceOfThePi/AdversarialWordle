#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "wordle.h"

#define NUM_BUCKETS 10657 

extern Element *dictionary[NUM_BUCKETS];

bool check(const char *word);
bool addWord(char *word);
void unload();

#endif