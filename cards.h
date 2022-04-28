
#include<stdio.h>
#include<stdlib.h>
#ifndef YOUKONSOLITAIRE_02322_CARDS_H
#define YOUKONSOLITAIRE_02322_CARDS_H
#endif //YOUKONSOLITAIRE_02322_CARDS_H




///card value
typedef struct card Card;
struct card
{
    char suit;          //C,D,H,S
    char rank;          //A,2,3,4,5,6,7,8,9,T,J,Q,K
    int visibility;     //
};

typedef struct node Node;

 struct node{
    Card card;
    Node* next;
    Node* prev;
    int index;
};



/// give some values tto cards
void putCard(Card* ca, char suit, char rank, int visibility ){
    ca ->suit=suit;
    ca ->rank=rank;
    ca ->visibility=visibility;
}

///crate new node
struct node* NodeCreate(){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->index=0;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

///insert a new node to linklist
void insert(Node* theHead, Node* newElement){
// to find out the tail we need to look at head-> next = NULL which means
// that is the last element in lined list
    while(theHead->next != NULL){
        theHead = theHead->next;
    }
    if(theHead->next == NULL){
        theHead->next = newElement;
        newElement->prev =theHead;
        newElement->next =NULL;
        newElement->index= theHead->index+1;
    }
}

/// we need to implement a method that get the tail
struct node* theTail(Node* theHead){
    Node* tail;
    while (theHead != NULL){
       tail = theHead;
       theHead = theHead->next;
    }return tail;
}

/// get from the tail
struct node * fromTail(Node * theHead, int ft) {
    Node * tmpr = theTail(theHead);
    for (int i = 0; i < ft; ++i) {
        tmpr = tmpr->prev;
    }
    return tmpr;
}


//// we need to implement a method to know the number of element
int theCountElements(Node* theHead){
    int count = 0;
    while(theHead != NULL){
        theHead=theHead->next;
        count++;
    }
    return count;
}

/// get from the head
struct node * fromHead(Node * theHead, int fh) {
    Node * tmp = theHead;
    for (int i = 0; i < fh; ++i) {
        tmp = tmp->next;
    }
    return tmp;
}

/// Method to create a node from card suit and rank
struct node* nodeFromCard(Node* theHead, char suit, char rank){
    while(theHead != NULL) {
        if(theHead->card.suit==suit & theHead->card.rank==rank ){
            return theHead;
        }
        theHead =theHead->next;
    }
    printf("The node not found in the list \n");
    return 0;
}

/// Method to delete a node
struct node* deleteNodes( Node* theHead, Node* deleteNode){
struct node* mainHead = theHead;
    while(theHead != NULL) {
        // if yhe node we want to delete not head or tail
        if(deleteNode->next != NULL & deleteNode->prev != NULL){
         deleteNode->next->prev = deleteNode->prev;
         deleteNode->prev->next = deleteNode->next;
         free(deleteNode);
            return mainHead;
        }
        // if the node equal to head
        if(deleteNode->prev == NULL){
            //make the next node (prev==0)
            deleteNode->next->prev = NULL;
            theHead = deleteNode->next;
            free(deleteNode);
            return mainHead;
        }
        // if the node equal to tail
        if(deleteNode->next == NULL){
            //make the prev node (next==0)
            deleteNode->prev->next = NULL;
            theHead = deleteNode->prev;
            free(deleteNode);
            return mainHead;
        }
        theHead =theHead->next;
    }
}

