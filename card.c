//40 points
/* Define all card/deck related functions as follows:
 * make_deck: generates a new list of 52 unique cards with ranks 1-13 and suits CDHS. Returns a pointer to the head of the list. 
 *            Note: you must use malloc to create all 52 cards.
 * destroy_deck: consumes a pointer to a card. Free memory for all cards in the list.
 * shuffle: consumes a pointer to a card (expected to be the head of a list of cards). Returns a pointer to a card (the possibly new head).
 *          Randomly re-orders the cards in the list. Note; this function has been provided for you.
 * deal: consumes a pointer to a card (expected to be the head of a list of cards). Finds the last card in the list, prints its values, removes it
 *       from the list, and returns it (pointer to card). 
 * total: consumes a pointer to card. Returns the sum of the values in the list headed by the given card (note: 10,11,12, and 13 all value as 10).
 * show: consumes a pointer to card. Prints the rank and suit of all cards in the list (this may be one card) on one line. For example:
 *       11H 9S 3D 1C 1S
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "card.h"



card *make_deck(void){
    char suit[5] = "cdhs";
    card *deck = malloc(sizeof(card));
    card *current = malloc(sizeof(card));
    if( deck == NULL || current == NULL ){
        puts("Another malloc() error");
    }
    current=deck;
    int count = 1;
    for(int i = 1; i <= 13 ; i++){
        for(int x = 0; suit[x]; x++){
            card *new = malloc(sizeof(card));
            current->rank = i;
            current->suit = suit[x];
            if(count < 52){
	    	current->next = new;
            	current = new;
	    	}
	    count++;
        }
    }
    return deck;
}

void destroy_deck(card *deck){
	for(;deck;){
	card *head = deck;
    	deck = deck->next;
	free(head);
    }
}


/* counts the number of cards in the list headed by "deck" */
int count_deck(card *deck) {
    int count=0;
    /* No initialization required. When "deck" is NULL (zero), it's at the end. Otherwise, move to the
    next card and increment the count. No body of the for loop! */
    for(;deck;deck=deck->next,count++);
    return count;
}

/* Emulates a "riffle shuffle" of "deck". */
card *shuffle(card *deck) {
    srand48(time(0));
    int size = count_deck(deck);
    card *cut=deck;
    for(int i=0; i<size/2; i++){
        cut=cut->next;
    }
    /* cut is now the card 1/2 way through the deck */
    card *riffle=cut->next;
    cut->next = 0; /* deck and riffle now head separate lists */
    /* Shuffle the deck by randomly pulling a card from the head of "deck" or "riffle"
       and make it the new head of "retdeck" */
    card *retdeck=0;
    for(;deck || riffle;) { /* just like a while loop */
        card *temp;
        if(deck && (!riffle || drand48()<0.5)) {
            /* next card comes from the top of 'deck' */
            temp=deck;
            deck=deck->next;
        } else if(riffle) {
            /* next card comes from the top of 'riffle' */
            temp=riffle;
            riffle=riffle->next;
        }
        /* put the card at the top of the "retdeck" */
        temp->next=retdeck;
        retdeck=temp;
    }
    return retdeck;
}

int total( card *deck){
	int total = 0;
	card *copy = deck;
	while(copy->next){
		if(deck->rank<10){
			total+=copy->rank ;
			copy=copy->next;
		}
		else{
			total+=10;
			copy=copy->next;
		}
	}
	if(deck->rank<10){
		total+= copy->rank;
	}
	else{total+=10;}
	return total;
}

void show(card *deck){
	card *showDeck;
	showDeck = deck;
	while (showDeck) {
        	printf("%d%c ",showDeck->rank,showDeck->suit);
        	showDeck = showDeck->next;
    	}
	printf("\n");
}

card *deal(card *deck){
	card *head = deck;
	for ( int i = 0; i<count_deck(deck)-2; i++){
		head = head->next;
	}
	card *last = head->next->next;
	card *ret = malloc(sizeof(card));
	ret = head->next;
	head->next = last;
	printf("%d%c ",ret->rank,ret->suit);
	return ret;
}


void deckStart(card *deck,card *mainDeck){
	card *first = (card *)malloc(sizeof(card));
    card *mark = deck;
	first = deal(mainDeck);
	mark->rank = first->rank;
	mark->suit = first->suit;
}	

void giveCard(card *mainDeck,card *playDeck){
	card *last = malloc(sizeof(card));
	last = playDeck;
	while(last->next){
		last=last->next;
	}
	card *new = malloc(sizeof(card));
	new = deal(mainDeck);
	last->next = new;
}


