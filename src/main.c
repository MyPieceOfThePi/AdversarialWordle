#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "wordle.h"
#include "dictionary.h"
#include "game.h"

int main(){
    FILE* La = fopen("dictionaries/wordle-LA.txt", "r");
    FILE* Ta = fopen("dictionaries/wordle-TA.txt", "r");

    load(La, Ta);

    GameState gs;
    for(int i = 0; i < NUM_GUESSES; i++){
        gs.words[i][0] = '\0';
    }

    int guessNum = 0;
    while(true){
        play(&gs, &guessNum);
    }
    freeStack(pool);
    unload();
}