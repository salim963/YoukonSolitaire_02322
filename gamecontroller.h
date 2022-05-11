
#include <stdlib.h>

#ifndef YUKONGAME_GAMECONTROLLER_H
#define YUKONGAME_GAMECONTROLLER_H
#endif //YUKONGAME_GAMECONTROLLER_H

/************************************************<Print Message And Last Command>***********************************************/

void PrintMessageAndLastCommand(char Message[10], char LastCommand[50]){
    printf("\n\n");
    printf("Last Command :%s \t\n", LastCommand);
    printf("Message :%s \n\n", Message);

}

void FlipCards(struct Card *cardList) {
    struct Card *card = cardList;
    while (card != NULL) {
        if (card->fliped == false) {
            card->fliped = true;

        }
        card = card->next;
    }

}

/************************************************<Shows All The Cards>***********************************************/
/**
 * this mouthed shows alle the fliped card in the deck
 *
 * */
void ShowsAllTheCards(struct Game *game, char Message[10]) {

    for (int i = 0; i < 7; i++) {
        FlipCards(game->Piles[i].cardList);
    }
    strcpy(Message, "OK");
}

/************************************************<Randomize The Cards>***********************************************/
int Randomize(int minimumVal, int maximumVal) {

    int value = rand() % (maximumVal - minimumVal + 1) + minimumVal;
    return value;

}
/************************************************< Convert Char To Int>***********************************************/
int ConvertCharToInt(char l) {
    int m = l - '0';

    return m;
}
/************************************************< split Char Into 1 Char>***********************************************/
void splitCharInto(char splits[][50], char value[], char *splitChar) {
    int splitsCount = 0;
    char *buffer;
    buffer = strtok(value, splitChar);
    while (buffer != NULL) {
        strcpy(splits[splitsCount], buffer);
        buffer = strtok(NULL, splitChar);

        splitsCount++;
    }

}