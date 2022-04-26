#include <stdio.h>
#include <stdbool.h>
#include "cards.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


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
// if we start a new game than we should create a new deck
        if (newGame == 0) {
            cardsDeckHead ;
        }else{

        }

//
//        if(!strcmp(playCommand,"SW")){
//            printf("Last message: \n",playCommand);
//        }

    }

}

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


    }
}
