#include <stdio.h>
#include <stdlib.h> // For exit()
#include <string.h>
#include <memory.h>
#include <stddef.h>
#include <time.h>
#include <unistd.h>
#include <locale.h>
#include <stdbool.h>
#include "doublylinkedlist.h"
#include "loadandwritefile.h"
#include "gamecontroller.h"
#include "cardsAction.h"
/************************************************<Random Shuffle>***********************************************/
void reset();
__attribute__((unused)) void MoveCardToPile();
void GameMoves();

void RandomShuffle(struct Game *game, char message[]) {
    int RandomPile = Randomize(0, 4);

    int iIndex = 5;
    while (iIndex < 7) {

        int ListCounter = ListCount(game->Piles[iIndex].cardList);
        while (ListCounter > 0) {
            MoveCardToSpecificSite(game, RandomPile, iIndex);
            DisplayPiles(game);
            ListCounter--;


        }
        iIndex++;
    }
    strcpy(message, "OK");
}

/************************************************<Flip Last <One> Card>***********************************************/
void FlipLastCard(struct Game *game, int pileNumber) {

    int listCounter = ListCount(game->Piles[pileNumber].cardList);
    int finalIndex = listCounter - 2;
    if (listCounter > 1) {
        struct Card *card3 = GetCard(game->Piles[pileNumber].cardList, finalIndex);
        if (finalIndex >= 0) {
            card3->fliped = true;
        } else {

        }
    }
}

/************************************************<Listen For Commands>***********************************************/
int ListenForCommands(struct Game *game){

    char COMMAND[256];
    char MESSAGE[10];
    char LASTCOMMAND[50];
    PrintMessageAndLastCommand(MESSAGE,"");

    //Listen for Commands
    while (1) {

        printf("\nINPUT -> \n");
        scanf("%s", &COMMAND);
        strcpy(LASTCOMMAND, COMMAND);

        if(strcmp((const char *) &COMMAND, "LD") == 0) {
            LoadAllTheCards("CardsFolder/CardName.txt", game, MESSAGE);

            if (strcmp(MESSAGE, "OK") == 0) {
                DisplayPiles(game);
                PrintMessageAndLastCommand(MESSAGE,LASTCOMMAND);
            } else{
                PrintMessageAndLastCommand(MESSAGE,LASTCOMMAND);
            }

        }else if (strcmp((const char *) &COMMAND, "SW") == 0) {
            ShowsAllTheCards(game, MESSAGE);
            if (strcmp(MESSAGE, "OK") == 0) {
                DisplayPiles(game);
                PrintMessageAndLastCommand(MESSAGE,LASTCOMMAND);
            }

        }else if (strcmp((const char *) &COMMAND, "SI") == 0) {
            SplitDeck(game, MESSAGE);
            if (strcmp(MESSAGE, "OK") == 0) {
                DisplayPiles(game);
                PrintMessageAndLastCommand(MESSAGE,LASTCOMMAND);
            }
        }else if (strcmp((const char *) &COMMAND, "SR") == 0) {
            RandomShuffle(game, MESSAGE);
            if (strcmp(MESSAGE, "OK") == 0) {
                DisplayPiles(game);
                PrintMessageAndLastCommand(MESSAGE,LASTCOMMAND);
            }
        }else if (strcmp((const char *) &COMMAND, "SD") == 0) {

            if (strcmp(MESSAGE, "OK") == 0) {
                SaveDeckCards(game, COMMAND, MESSAGE,"CardsFolder/Cards.txt");
                PrintMessageAndLastCommand(MESSAGE,LASTCOMMAND);
            }
        }else if (strcmp((const char *) &COMMAND, "QQ") == 0) {
                PrintMessageAndLastCommand(MESSAGE,LASTCOMMAND);
                printf("GOODBYE");
                exit(0);

        }else if (strcmp((const char *) &COMMAND, "P") == 0) {

            LoadAllTheCardsWithP("CardsFolder/CardName.txt", game, MESSAGE);

            if (strcmp(MESSAGE, "OK") == 0) {
                DisplayPiles(game);
                PrintMessageAndLastCommand(MESSAGE,LASTCOMMAND);
            } else{
                PrintMessageAndLastCommand(MESSAGE,LASTCOMMAND);
            }
        }else if (strcmp((const char *) &COMMAND, "Q") == 0) {

            reset(game,MESSAGE);
            if (strcmp(MESSAGE, "OK") == 0) {
                PrintMessageAndLastCommand(MESSAGE,LASTCOMMAND);
            } else{
                PrintMessageAndLastCommand(MESSAGE,LASTCOMMAND);
            }

            printf("the game has been reset ");


        }else if (strstr((const char *) &COMMAND, "->") != 0) {
            GameMoves(game,&COMMAND);
            PrintMessageAndLastCommand(MESSAGE,LASTCOMMAND);
        }

        else {
            printf("\nWRONG INPUT!!! PLEASE WRITE CORRECT COMMAND\n");
        }


    }

}

void GameMoves(struct Game *game, char COMMAND[]) {

    char PlayCommand[2][50];
    char CharToBeSplit[] = "->";
    splitCharInto(PlayCommand, COMMAND, CharToBeSplit);

    int CColNumber = ConvertCharToInt(PlayCommand[0][1]);
    int FColNumber = ConvertCharToInt(PlayCommand[1][1]);
    int currentPileColumn= CColNumber -1;
    int FinalPileColumn = FColNumber -1;

    int listCounter = ListCount(game->Piles[currentPileColumn].cardList);
    int finalIndex = listCounter - 1;
    if (finalIndex >= 0) {
        FlipLastCard(game,currentPileColumn);
        MoveCardToPile(game,currentPileColumn,FinalPileColumn);
        DisplayPiles(game);
    } else {
        printf("There Is No Card In This Pile To Be Move Please Select Other Pile ");
    }
}

/************************************************<Move Card To Pile>***********************************************/

void MoveCardToPile(struct Game *game, int currentPileColumn , int FinalPileColumn) {

    struct Card *card = GetCard3(game->Piles[currentPileColumn].cardList);

    if (game->Piles[currentPileColumn].cardList == NULL) {
        printf("List is Empty can not move the card");

    }
    RemoveLastCard(game, currentPileColumn);
    card->next = NULL;


    if (game->Piles[FinalPileColumn].cardList == NULL) {
        game->Piles[FinalPileColumn].cardList = card;

    } else {
        AddCardToList(game->Piles[FinalPileColumn].cardList, card);

    }

}
/************************************************<Reset The Game>***********************************************/

void reset(struct Game *game, char message[]) {
    for (int i = 0; i < 7; ++i) {

        for (int j = 0; j < 13; ++j) {
            struct Card *card = GetCard3(game->Piles[i].cardList);
            RemoveLastCard(game, i);
            card->next = NULL;
        }

    }
    strcpy(message, "OK");
}

/************************************************<Initialize The 7 Piles>***********************************************/
/**
 * @param Piles
 *
 * */
void InitializePiles(struct Pile Piles[]) {
    for (int i = 0; i < 7; i++) {
        Piles[i].cardList = NULL;
    }


}
/************************************************<Initialize The Game>***********************************************/
void Initialize(struct Game *game) {
    printf("\n Welcome to Yukon Solitaire game Group16 \n\n");
    InitializePiles(game->Piles);
    DisplayPiles(game);


}
/************************************************<Load The Game>***********************************************/

void LoadTheGame() {

    struct Game *_game = (struct Game *) malloc(sizeof(struct Game));
    Initialize(_game);
    ListenForCommands(_game);
}




