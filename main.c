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
    char playCommand[90];
    int newGame = 0;
    while (true) {
        printf("INPUT >");
        scanf("%s", &playCommand);


        Node *cardsDeckHead;


///the 7 suit columns

        static Node *c1;
        static Node *c2;
        static Node *c3;
        static Node *c4;
        static Node *c5;
        static Node *c6;
        static Node *c7;

        static Node * sC;
        static Node * sD;
        static Node * sH;
        static Node * sS;


/// if we start a new game than we should create a new deck
        if (newGame == 0) {
            cardsDeckHead = CreateDeck();
        }

        if (strcmp(&playCommand, "SW") == 0) {
            printDeck(cardsDeckHead);
            printf("\n");
            printf("LAST command:SW \n");

        }

        if (strcmp(&playCommand, "SR") == 0) {
            newGame = 1;
            cardsDeckHead = MixDeck(CreateDeck());
            printDeck(cardsDeckHead);
            printf("\n");
            printf("LAST command:SR \n");

        } else if (strcmp(&playCommand, "QQ") == 0) {
            printf("LAST command:QQ \n");
            break;

        }if (strcmp(&playCommand, "P") == 0) {

            printf("LAST command:p \n");

            setTheGame(cardsDeckHead,&c1,&c2,&c3,&c4,&c5,&c6,&c7,&sC,&sD,&sH,&sS);

            printf("HELLO nr 1\n");

            while (true) {
                printf("HELLO \n");
                theBoard(c1, c2, c3, c4, c5, c6, c7, sC, sD, sH, sS);
            }

/*
        if(!strcmp(playCommand,"SW")){
            printf("Last message: \n",playCommand);
        }*/
        }
    }


}









