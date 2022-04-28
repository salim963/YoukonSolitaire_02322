#include <stdio.h>
#include <stdbool.h>
#include "cards.h"
#include <stdlib.h>
/*_______________________________________________________*/
struct node* CreateDeck(){
    Node* theHead = NodeCreate();
    Card tempCard;
    Node * temp;
    tempCard.visibility = 1; // 1 means visibility
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
