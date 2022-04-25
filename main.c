#include <stdio.h>


typedef struct {
    char *value;
    char *type;

}card;

int main() {
    printf("Welcome to Yukon Solitaire game\nGroup16 \n\n");


     int i;
     char solitaireSuits[4][1]={'H','D','S','C'};
     char solitaireCards[13][1]={'K','Q','J','T','9','8','7','6','5','4','3','2','A'};

    card c[52];
    for(i=0;i<52; i++){
        c[i].type=solitaireSuits[i % 4 ];
        c[i].type=solitaireCards[i % 13 ];

    }

    for(i=0;i<52; i++){
        printf("%s %s \n",c[i].type,c[i].value);
    }

    return 0;
}
