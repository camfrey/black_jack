/* 5 points: This file should contain prototypes for all card/deck-related functions (see card.c) as well as the 'card' structure.
 * a 'card' structure has an (int) rank, a (char) suit, and a pointer to card (next in the pile; 0 for end of the list). 
 */


#ifndef CARD_H_
#define CARD_H_

typedef struct Card {
    int rank;
    char suit;
    struct Card *next; /* have to use struct Card because the typedef isnt "ready" yet */
} card;

card *make_deck(void);

void destroy_deck(card *deck);

int count_deck(card *deck); 

card *shuffle(card *deck);

card *deal(card *deck);

int total( card *deck);

void show(card *deck);

void deckStart(card *deck,card *mainDeck);

void giveCard(card *mainDeck,card *playDeck);

#endif
