

typedef struct card Card;
struct Pile{ struct Card * cardList;};

struct Game{ struct Pile Piles[7];};

struct Card {
    char rank;
    char suit;
    bool fliped;
    char color;
    char value[3];
    struct Card *next;
} *head = NULL;
