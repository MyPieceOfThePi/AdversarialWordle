#include "game.h"

void printGame(GameState g){
    printf("\033[2J\033[1;1H");
    for(int i = 0; i < NUM_GUESSES; i++){
        if(g.words[i][0] == '\0') return;

        for(int j = 0; j < WORD_LENGTH; j++){
            switch (g.feedback[i][j]){
                case GREEN:
                    printf("\x1b[42m");
                    break;
                case YELLOW:
                    printf("\x1b[43m");
                    break;
                case GREY:
                    printf("\x1b[100m");
                    break;
            }
            printf("%c\x1b[0m", g.words[i][j]);
        }
        printf("\n");
    }
}

bool getInput(char *word){
    char str[100];

    if(scanf("%99s",str) != 1) return false;

    if(strlen(str) != 5){
        printf("Please enter five characters (enter)\n");
        return false;
    }

    for(int i = 0; i < 5; i++){
        if(!isalpha(str[i])){
            printf("Please only enter alphabetic characters (enter)\n");
            return false;
        }
        str[i] = tolower(str[i]);
    }

    if(!check(str)){
        printf("Please enter a valid word (enter)\n");
        return false;
    }

    strcpy(word, str);
    return true;
}

void load(FILE* La, FILE* Ta){
    char buff[WORD_LENGTH + 1];
    while (fscanf(La, "%s", buff) == 1) {
        push(&pool, buff, WORD_LENGTH + 1);
        addWord(buff);
    }
    while (fscanf(Ta, "%s", buff) == 1) {
        addWord(buff);
    }
}


void play(GameState *gs, int *guessNum){
    char str[WORD_LENGTH + 1];
    while(!getInput(str)){
        char c;
        scanf("%c", &c);
        printGame(*gs);
    }

    Feedback fdbk[5];
    processGuess(str, fdbk);

    for(int i = 0; i < WORD_LENGTH; i++){
        gs->feedback[*guessNum][i] = fdbk[i];
        gs->words[*guessNum][i] = str[i];
    }

    printGame(*gs);
    (*guessNum)++;
}