#include <stdio.h>
#include <stdbool.h>

#include "game.h"
#include <string.h>



_Noreturn void go();

int main() {
    printf("Welcome to Yukon Solitaire game\nGroup16 \n\n");

    go();

    return 0;
}


void go() {
    char playCommand[2];
    int newGame = 0;
    while (true){
            printf("INPUT >");
            scanf("%s",playCommand);

        Node * cardsDeckHead;
/// if we start a new game than we should create a new deck
        if (newGame == 0) {
            cardsDeckHead = CreateDeck();
        }else{
            cardsDeckHead =MixDeck(CreateDeck());
        }

        if(strcmp(playCommand,"SW") != 0){
            printDeck(cardsDeckHead);
            printf("\n");
            printf("LAST command:SW \n");

        }else if(strcmp(playCommand,"SR") != 0){
            newGame = 1;
            printf("LAST command:SR \n");

        }else if (strcmp(playCommand, "QQ") != 0){
            printf("LAST command:QQ \n");
            break;

        }

/*
        if(!strcmp(playCommand,"SW")){
            printf("Last message: \n",playCommand);
        }*/
    }
}









