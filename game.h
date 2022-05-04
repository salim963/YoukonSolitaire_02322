#include <stdio.h>
#include <stdbool.h>
#include "cards.h"
#include <stdlib.h>
/*_______________________________________________________*/
struct node* CreateDeck(){
    Node* theHead = NodeCreate();
    Card tempCard;
    Node * temp;
    tempCard.visibility = 1; // 1 visibility
    // we need two loop to create a deck for cards
    for(int index=1 ; index<5; index++){
        if(index==1){ tempCard.suit = 'H';}
        if(index==2){ tempCard.suit = 'D';}
        if(index==3){ tempCard.suit = 'C';}
        if(index==4){ tempCard.suit = 'S';}


        for(int i=1; i<=13; i++){
            if (i>0){
                switch(i) {
                    case 1:
                        tempCard.rank ='A';
                        temp = NodeCreate();
                        temp->card = tempCard;
                        insert(theHead,temp);
                        break;
                    case 2:
                        tempCard.rank ='2';
                        temp = NodeCreate();
                        temp->card = tempCard;
                        insert(theHead,temp);
                        break;
                    case 3:
                        tempCard.rank ='3';
                        temp = NodeCreate();
                        temp->card = tempCard;
                        insert(theHead,temp);
                        break;
                    case 4:
                        tempCard.rank ='4';
                        temp = NodeCreate();
                        temp->card = tempCard;
                        insert(theHead,temp);
                        break;
                    case 5:
                        tempCard.rank ='5';
                        temp = NodeCreate();
                        temp->card = tempCard;
                        insert(theHead,temp);
                        break;
                    case 6:
                        tempCard.rank ='6';
                        temp = NodeCreate();
                        temp->card = tempCard;
                        insert(theHead,temp);
                        break;
                    case 7:tempCard.rank ='7';
                        temp = NodeCreate();
                        temp->card = tempCard;
                        insert(theHead,temp);
                        break;
                    case 8:
                        tempCard.rank ='8';
                        temp = NodeCreate();
                        temp->card = tempCard;
                        insert(theHead,temp);
                        break;
                    case 9:
                        tempCard.rank ='9';
                        temp = NodeCreate();
                        temp->card = tempCard;
                        insert(theHead,temp);
                        break;
                    case 10:
                        tempCard.rank ='T';
                        temp = NodeCreate();
                        temp->card = tempCard;
                        insert(theHead,temp);
                        break;
                    case 11:tempCard.rank ='J';
                        temp = NodeCreate();
                        temp->card = tempCard;
                        insert(theHead,temp);
                        break;
                    case 12:
                        tempCard.rank ='Q';
                        temp = NodeCreate();
                        temp->card = tempCard;
                        insert(theHead,temp);
                        break;
                    case 13:
                        tempCard.rank ='K';
                        temp = NodeCreate();
                        temp->card = tempCard;
                        insert(theHead,temp);
                        break;

                    default:
                        printf("error with switch \n ");
                }
            }
        }

    }return theHead;
}

/*_______________________________________________________*/
/*_______________________________________________________*/

Node* MixDeck(Node* theHead){

    int sizeOfDeck = theCountElements(theHead);
    int tempGeneratedNumber = 0;
    int randomNumber[sizeOfDeck];


    for(int j = 0; j<sizeOfDeck;j++){
        randomNumber[j]=-1;
    }

    int tempNr;
    while (tempGeneratedNumber < sizeOfDeck) {
        int random = rand() % sizeOfDeck;
        tempNr=0;
        for (int i=0; i < sizeOfDeck; i++) {
            if (random == randomNumber[i]) {
                tempNr = 1;
                continue;
            }
        }
        if (tempNr == 0) {
            randomNumber[tempGeneratedNumber] = random;
            tempGeneratedNumber++;
            continue;
        }
    }

    Node* theNewDeck = NodeCreate();
    Node* temp;
    for (int i = 0; i < sizeOfDeck; ++i) {
        if(i==0){
            putCard(&theNewDeck->card, fromHead(theHead,randomNumber[i])->card.rank,fromHead(theHead,randomNumber[i])->card.suit,fromHead(theHead,randomNumber[i])->card.visibility);
        }
        if(i>0 && i<=sizeOfDeck){
            temp = NodeCreate();
            putCard(&temp->card, fromHead(theHead,randomNumber[i])->card.rank,fromHead(theHead,randomNumber[i])->card.suit,fromHead(theHead,randomNumber[i])->card.visibility);
            insert(theNewDeck,temp);
        }
    }

    /// to free the lsat unmixed deck
    while(theHead!=NULL){
        temp = theHead;
        theHead = theHead->next;
        deleteNodes(theHead,temp);
    }
    return theNewDeck;
}

/*_______________________________________________________*/
/*_______________________________________________________*/

void printDeck(Node* head){
    printf("\t");
    while(head!=NULL){
        printf("%c%c\t",head->card.rank,head->card.suit);
        head=head->next;
    }
}

/*_______________________________________________________*/
/*_______________________________________________________*/


 //splitting up the cardDeck to the 7 piles
void splitTheCard( Node ** c1, Node ** c2, Node ** c3 , Node ** c4 , Node ** c5 , Node ** c6 , Node ** c7, Node * sizeOfDeck){

    /************C1***********/
    *c1 = theTail(sizeOfDeck);
    theTail(sizeOfDeck)->prev->next = NULL;
    Node * tmp = *c1;
    tmp->prev = NULL;

    /**********C2*************/
    *c2 = fromTail(sizeOfDeck,6-1);
    fromTail(sizeOfDeck,6-1)->prev->next = NULL;
    tmp = *c2;
    tmp->prev = NULL;

    /**********C3************/
    *c3 = fromTail(sizeOfDeck,7-1);
    fromTail(sizeOfDeck,7-1)->prev->next = NULL;
    tmp = *c3;
    tmp->prev = NULL;
    /***********C4************/
    *c4 = fromTail(sizeOfDeck,8-1);
    fromTail(sizeOfDeck,8-1)->prev->next = NULL;
    tmp = *c4;
    tmp->prev = NULL;

    /***********C5************/
    *c5 = fromTail(sizeOfDeck,9-1);
    fromTail(sizeOfDeck,9-1)->prev->next = NULL;
    tmp = *c5;
    tmp->prev = NULL;

    /***********C6************/
    *c6 = fromTail(sizeOfDeck,10-1);
    fromTail(sizeOfDeck,10-1)->prev->next = NULL;
    tmp = *c6;
    tmp->prev = NULL;

    /***********C7************/
    *c7 = fromTail(sizeOfDeck,11-1);
    tmp = *c7;
    tmp->prev = NULL;

}

/*_______________________________________________________*/
/*_______________________________________________________*/

void setTheGame(Node ** deckHead, Node ** c1,Node ** c2,Node ** c3,Node ** c4,Node ** c5,Node ** c6,Node ** c7,Node ** sC,Node ** sD,Node ** sH,Node ** sS) {
    splitTheCard( deckHead, c1, c2, c3, c4, c5, c6, c7);
    hideAllCards(c2, c3, c4, c5, c6, c7);
}



















void theBoard(Node * c1, Node * c2, Node * c3, Node * c4, Node * c5, Node * c6, Node * c7, Node * sC, Node * sD, Node * sH, Node * sS) {

    printf("\tC1\tC2\tC3\tC4\tC5\tC6\tC7\n\n");

    //get needed height for board to be printed
    int boardCount = theCountElements(c1);

    if(theCountElements(c2) > boardCount) {
        boardCount = theCountElements(c2);
    }
    if(theCountElements(c3) > boardCount) {
        boardCount = theCountElements(c3);
    }
    if(theCountElements(c4) > boardCount) {
        boardCount = theCountElements(c4);
    }
    if(theCountElements(c5) > boardCount) {
        boardCount = theCountElements(c5);
    }
    if(theCountElements(c6) > boardCount) {
        boardCount = theCountElements(c6);
    }
    if(theCountElements(c7) > boardCount) {
        boardCount = theCountElements(c7);
    }


    //print for each row
    for (int i = 0; i < boardCount; i++) {
        printf("\t");

        char chString[2];

        //c1
        if (theCountElements(c1) >= i ) {
            if (fromHead(c1,i)->card.visibility == 1) {          //checks if card is visible (1 is visible, 0 is hidden)
                chString[0] = fromHead(c1, i)->card.rank;
                chString[1] = fromHead(c1, i)->card.suit;
            } else {                                                //if card is hidden should show '[]' in TUI
                chString[0] = '[';
                chString[1] = ']';
            }
            printf("%c%c", chString[0],chString[1]);
        } else {
            printf("  ");
        }
        chString[0] = '\0';
        chString[1] = '\0';
        printf("\t");

        //c2
        if (theCountElements(c2) >= i ) {
            if (fromHead(c2,i)->card.visibility == 1) {          //checks if card is visible (1 is visible, 0 is hidden)
                chString[0] = fromHead(c2, i)->card.rank;
                chString[1] = fromHead(c2, i)->card.suit;
            } else {                                                //if card is hidden should show '[]' in TUI
                chString[0] = '[';
                chString[1] = ']';
            }
            printf("%c%c", chString[0],chString[1]);
        } else {
            printf("  ");
        }
        printf("\t");

        //c3
        if (theCountElements(c3) >= i ) {
            if (fromHead(c3,i)->card.visibility == 1) {          //checks if card is visible (1 is visible, 0 is hidden)
                chString[0] = fromHead(c3, i)->card.rank;
                chString[1] = fromHead(c3, i)->card.suit;
            } else {                                                //if card is hidden should show '[]' in TUI
                chString[0] = '[';
                chString[1] = ']';
            }
            printf("%c%c", chString[0],chString[1]);
        } else {
            printf("  ");
        }
        printf("\t");

        //c4
        if (theCountElements(c4) >= i ) {
            if (fromHead(c4,i)->card.visibility == 1) {          //checks if card is visible (1 is visible, 0 is hidden)
                chString[0] = fromHead(c4, i)->card.rank;
                chString[1] = fromHead(c4, i)->card.suit;
            } else {                                                //if card is hidden should show '[]' in TUI
                chString[0] = '[';
                chString[1] = ']';
            }
            printf("%c%c", chString[0],chString[1]);
        } else {
            printf("  ");
        }
        printf("\t");

        //c5
        if (theCountElements(c5) >= i ) {
            if (fromHead(c5,i)->card.visibility == 1) {          //checks if card is visible (1 is visible, 0 is hidden)
                chString[0] = fromHead(c5, i)->card.rank;
                chString[1] = fromHead(c5, i)->card.suit;
            } else {                                                //if card is hidden should show '[]' in TUI
                chString[0] = '[';
                chString[1] = ']';
            }
            printf("%c%c", chString[0],chString[1]);
        } else {
            printf("  ");
        }
        printf("\t");

        //c6
        if (theCountElements(c6) >= i ) {
            if (fromHead(c6,i)->card.visibility == 1) {          //checks if card is visible (1 is visible, 0 is hidden)
                chString[0] = fromHead(c6, i)->card.rank;
                chString[1] = fromHead(c6, i)->card.suit;
            } else {                                                //if card is hidden should show '[]' in TUI
                chString[0] = '[';
                chString[1] = ']';
            }
            printf("%c%c", chString[0],chString[1]);
        } else {
            printf("  ");
        }
        printf("\t");

        //c7
        if (theCountElements(c7) >= i) {
            if (fromHead(c7,i)->card.visibility == 1) {          //checks if card is visible (1 is visible, 0 is hidden)
                chString[0] = fromHead(c7, i)->card.rank;
                chString[1] = fromHead(c7, i)->card.suit;
            } else {                                                //if card is hidden should show '[]' in TUI
                chString[0] = '[';
                chString[1] = ']';
            }
            printf("%c%c", chString[0],chString[1]);
        } else {
            printf("  ");
        }

        //suitStacks
        if (i == 0) {
            if (theCountElements(sC) > 0) {
                chString[0] = theTail(sC)->card.rank;
                chString[1] = theTail(sC)->card.suit;
            } else {                                                //if no cards in suitStack '[]' is shown in TUI
                chString[0] = '[';
                chString[1] = ']';
            }
            printf("\t\t%c%c\tF1", chString[0],chString[1]);
        } else if (i == 2) {
            if (theCountElements(sD) > 0) {
                chString[0] = theTail(sD)->card.rank;
                chString[1] = theTail(sD)->card.suit;
            } else {                                                //if no cards in suitStack '[]' is shown in TUI
                chString[0] = '[';
                chString[1] = ']';
            }
            printf("\t\t%c%c\tF2", chString[0],chString[1]);
        } else if (i == 4) {
            if (theCountElements(sH) > 0) {
                chString[0] = theTail(sH)->card.rank;
                chString[1] = theTail(sH)->card.suit;
            } else {                                                //if no cards in suitStack '[]' is shown in TUI
                chString[0] = '[';
                chString[1] = ']';
            }
            printf("\t\t%c%c\tF3", chString[0],chString[1]);
        } else if (i == 6) {
            if (theCountElements(sS) > 0) {
                chString[0] = theTail(sS)->card.rank;
                chString[1] = theTail(sS)->card.suit;
            } else {                                                //if no cards in suitStack '[]' is shown in TUI
                chString[0] = '[';
                chString[1] = ']';
            }
            printf("\t\t%c%c\tF4", chString[0],chString[1]);
        }
        printf("\n");
    }


    printf("LAST command: \n");
    printf("Message: \n");
    printf("INPUT > \n");

}