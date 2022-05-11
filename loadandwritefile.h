

#ifndef YUKONGAME_LOADANDWRITEFILE_H
#define YUKONGAME_LOADANDWRITEFILE_H
#endif //YUKONGAME_LOADANDWRITEFILE_H

struct Card *GetCard();
int ListCount();
void AddCardsToPile();
void AddCardToList();

/************************************************< read From File>***********************************************/
void readFromFile(char filename[], char fileMode[2], char fields[][4], char Message[10]) {
    FILE *stream;
    char buffer[4];
    int readCount = 0;
    stream = fopen(filename, fileMode);

    if (stream != NULL) {

        while (fread(buffer, sizeof(char), 3, stream) > 0 && readCount < 52) {
            strcpy(fields[readCount], buffer);

            readCount++;

        }
        strcpy(Message, "OK");
    }
    {
        if (readCount != 52) {
            strcpy(Message, "Failed");
        }

    }

    fclose(stream);

}
/************************************************< File Count>***********************************************/
int FileCount(char filename[]) {
    FILE *stream;
    int fileCoun = 0;
    char buffer[5];

    stream = fopen(filename, "r");//r
    if (stream != NULL) {

        while (fread(buffer, sizeof(char), 3, stream) > 0) {
            fileCoun++;
        }
    }

    fclose(stream);
    return fileCoun;
}

/************************************************< Load All The Cards With PLAY MODE>***********************************************/
void LoadAllTheCardsWithP(char filename[], struct Game *game, char Message[10]) {
    char ReadFields[53][4];
    readFromFile(filename, "r", ReadFields, Message);
    int fileCount = FileCount(filename);

    if (fileCount != 52) {
        strcpy(Message, "Failed1");
    } else {

        AddCardsToPile(game->Piles, ReadFields, 0, 0, 0, 0);
        AddCardsToPile(game->Piles, ReadFields, 1, 1, 6, 1);
        AddCardsToPile(game->Piles, ReadFields, 2, 7, 13, 2);
        AddCardsToPile(game->Piles, ReadFields, 3, 14, 21, 3);
        AddCardsToPile(game->Piles, ReadFields, 4, 22, 30, 4);
        AddCardsToPile(game->Piles, ReadFields, 5, 31, 40, 5);
        AddCardsToPile(game->Piles, ReadFields, 6, 41, 51, 6);

    }

}
/************************************************< Load All The Cards>***********************************************/
void LoadAllTheCards(char filename[], struct Game *game, char Message[10]) {
    char ReadFields[53][4];
    int cardCount = 0;
    readFromFile(filename, "r", ReadFields, Message);
    int fileCoun = FileCount(filename);


    if (fileCoun != 52) {
        strcpy(Message, "Failed1");
    }
    if (strcmp(Message, "OK") == 0) {
            while (1) {
                for (int j = 0; j < 7; j++) {

                    if (cardCount < 7) {

                        game->Piles[j].cardList = (struct Card *) malloc(sizeof(struct Card));
                        game->Piles[j].cardList->next = NULL;
                        char lo[3];
                        lo[0] = ReadFields[cardCount][0];
                        lo[1] = ReadFields[cardCount][1];
                        lo[2] = '\0';
                        game->Piles[j].cardList->fliped = false;
                        strcpy(game->Piles[j].cardList->value, lo);
                        game->Piles[j].cardList->color = game->Piles[j].cardList->value[1];

                    } else  {
                        if (cardCount > 52 - 1) {
                            return;
                        }

                        struct Card *card = (struct Card *) malloc(sizeof(struct Card));
                        card->next = NULL;

                        char lo[3];
                        lo[0] = ReadFields[cardCount][0];
                        lo[1] = ReadFields[cardCount][1];
                        lo[2] = '\0';

                        strcpy(card->value, lo);
                        card->color = card->value[1];
                        card->fliped = false;
                        AddCardToList(game->Piles[j].cardList, card);

                    }

                    cardCount++;
                }
            }
    }

}

/************************************************< Save Deck Cards>***********************************************/
void SaveDeckCards(struct Game *game, char filename[], char message[], char file[]) {
    if (filename[0] == '\0' || strlen(filename) < 5) {
        strcpy(filename, file);
        FILE *stream;
        stream = fopen(filename, "w");
        fclose(stream);

    }
    for (int i = 0; i < 7; i++) {
        int mIndex = 0;
        int ListCounter = ListCount(game->Piles[i].cardList);
        while (mIndex < ListCounter) {
            struct Card *card = GetCard(game->Piles[i].cardList, mIndex);

            FILE *stream;
            stream = fopen(filename, "a");//a
            char newData[4];
            strcpy(newData, card->value);
            strcat(newData, "\n");
            fwrite(newData, sizeof(char), strlen(newData), stream);
            fclose(stream);
            mIndex++;
        }
    }

    strcpy(message, "OK");
}