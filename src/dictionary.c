#define _POSIX_C_SOURCE 200809L
#include "dictionary.h"

Element *dictionary[NUM_BUCKETS];

static unsigned int hash(const char *word) {
    unsigned int h = 0;
    while (*word) {
        int c = tolower(*word);
        h = (h << 5) + h + c;
        word++;
    }
    return h % NUM_BUCKETS;
}

bool check(const char *word) {
    for(Element *e = dictionary[hash(word)]; e; e = e->next){
        if(strcmp((char *)(e->value), word) == 0){
            return true;
        }
    }
    return false;
}

bool addWord(char *word){
    return push(&dictionary[hash(word)], word, WORD_LENGTH + 1);
}

void unload(){
    for(int i = 0; i < NUM_BUCKETS; i++){
        freeStack(dictionary[i]);
        dictionary[i] = NULL;
    }
}