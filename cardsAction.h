

#ifndef YUKONGAME_CARDSACTION_H
#define YUKONGAME_CARDSACTION_H

#endif //YUKONGAME_CARDSACTION_H

/************************************************< List Count>***********************************************/
int ListCount(struct Card *List1) {

    int listCounter = 0;
    if ((List1 != NULL)) {
        struct Card *card = List1;
//  if(card!=NULL)    listCounter+1;
        while (card != NULL) {
            card = card->next;
            listCounter++;
        }

    }

    return listCounter;

}


void AddDisplayPile(struct Pile pile, char PileGrid[][7][3], int column) {
    if (pile.cardList != NULL) {

        struct Card *card = pile.cardList;
        int counter = 0;
        while (card != NULL) {
            if (card->fliped == true) {

                strcpy(PileGrid[counter][column], card->value);
            } else {
                char tmp[3] = "[]";
                tmp[2] = '\0';

                strcpy(PileGrid[counter][column], tmp);

            }

            card = card->next;
            counter++;
        }
    }

}
void DisplayPiles(struct Game *game) {

    int PileCounts[7];

    for (int i = 0; i < 7; i++) {
        PileCounts[i] = ListCount(game->Piles[i].cardList);

    }
        int highestRow = 0;

        for (int j = 0; j < 7; j++) {
            if (PileCounts[j] > highestRow) {
                highestRow = PileCounts[j];
            }

        }

    char DisplayGrid[highestRow][7][3];
    for (int i = 0; i < highestRow; i++) {
        for (int j = 0; j < 7; j++) {
            char tmp[2] = "";
            strcpy(DisplayGrid[i][j], tmp);
        }

    }

    for (int i = 0; i < 7; i++) {

        AddDisplayPile(game->Piles[i], DisplayGrid, i);
    }
    printf("\n");
    for (int i = 0; i < 7; i++) {
        printf("C%d\t", i + 1);

    }

    printf("\n\n");

    for (int i = 0; i < highestRow; i++) {
        for (int j = 0; j < 7; j++) {
            printf("%s\t", DisplayGrid[i][j]);

        }
        printf("\n");
    }


}



struct Card *GetCard3(struct Card *List) {

    struct Card *card = List;

    struct Card *card1;
    while (card != NULL) {
        if (card != NULL) {
            card1 = card;

        }
        card = card->next;

    }


    return card1;
}


void AddCardToList(struct Card *cardList, struct Card *CardToAdd) {

    if (cardList != NULL) {
        struct Card *card = NULL;

        card = GetCard3(cardList);

        if (card != NULL) {
            card->next = CardToAdd;
        }
    } else {
        cardList = CardToAdd;
    }

}



void AddCardsToPile(struct Pile Piles[], char data[53][4], int PileColumn, int startIndex, int endIndex, int flipCount) {
    int FlipCounter = 0;

    for (int i = startIndex; i <= endIndex; i++) {

        if (i == startIndex) {
            Piles[PileColumn].cardList = (struct Card *) malloc(sizeof(struct Card));
            Piles[PileColumn].cardList->next = NULL;
            char lo[3];
            lo[0] = data[i][0];
            lo[1] = data[i][1];
            lo[2] = '\0';

            strcpy(Piles[PileColumn].cardList->value, lo);
            Piles[PileColumn].cardList->color = Piles[PileColumn].cardList->value[1];
            if (PileColumn != 0) {
                Piles[PileColumn].cardList->fliped = false;
            } else {
                Piles[PileColumn].cardList->fliped = true;
            }

        } else {
            struct Card *card = (struct Card *) malloc(sizeof(struct Card));
            card->next = NULL;

            char lo[3];
            lo[0] = data[i][0];
            lo[1] = data[i][1];
            lo[2] = '\0';
            strcpy(card->value, lo);
            card->color = card->value[1];


            if ((FlipCounter + 1) < flipCount) {
                card->fliped = false;
                FlipCounter++;
            } else {
                card->fliped = true;
            }
            AddCardToList(Piles[PileColumn].cardList, card);
        }

    }


}


struct Card *GetCard(struct Card *List, int Index) {
    struct Card *card = List;


    int listCounter = 0;


    while (listCounter != Index) {
        card = card->next;
        listCounter++;

    }

    return card;
}


/*Delete the first node of a linked list.*/
void RemoveFirstCard(struct Game *game, int pileNumber) {

}

void RemoveLastCard(struct Game *game, int pileNumber) {

    int listCounter = ListCount(game->Piles[pileNumber].cardList);
    int finalIndex = listCounter - 2;
    if (listCounter > 1) {
        struct Card *card3 = GetCard(game->Piles[pileNumber].cardList, finalIndex);
        if (finalIndex >= 0) {

            card3->next = NULL;
        } else {
            card3 = NULL;
        }
    } else {
        game->Piles[pileNumber].cardList = NULL;
    }
}
void MoveCardToSpecificSite(struct Game *game, int FinalPileColumn, int currentPileColumn) {

    struct Card *card = GetCard3(game->Piles[currentPileColumn].cardList);
    RemoveLastCard(game, currentPileColumn);
    card->next = NULL;
    AddCardToList(game->Piles[FinalPileColumn].cardList, card);

}
void SplitDeck(struct Game *game, char message[]) {
    int nSplitNumber = 40;
    int iIndex = 0;

    while (nSplitNumber > 0) {

        int ListCounter =ListCount(game->Piles[iIndex].cardList);
        while (ListCounter > 0) {
            MoveCardToSpecificSite(game, 6, iIndex);
            ListCounter--;

            nSplitNumber--;
            if (nSplitNumber < 1) {
                ListCounter = -1;
            }


        }
        if (iIndex < 7) {
            iIndex++;
        }

        DisplayPiles(game);

    }


    strcpy(message, "OK");
}

