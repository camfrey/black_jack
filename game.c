/* Contains main() and any desired helper functions to play the game as described in the instructions. Must not _define_ any of the 
 * card-related helper functions but must use thm at least as frequently as indicated below (hit means either player or dealer hit):
 * make_deck:1; shuffle:1; deal: 3+1/hit; append: 1+1/hit; total: 2+1/hit; destroy_deck: 1
 */
 /* 15 points */

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "card.h"


card *deckSetup(void){
	card *deck = make_deck();
	deck = shuffle(deck);
	return deck;
}


int main(void){
	printf("Welcome to blackjack!!\n");
	card *mainDeck = malloc(sizeof(card));
       	mainDeck = deckSetup();	//Initialize and create main deck
	card *playDeck = malloc(sizeof(card));
	card *dealerDeck = malloc(sizeof(card));
	
	printf("----------Player's cards-------------\n");
	deckStart(playDeck,mainDeck);
	giveCard(mainDeck,playDeck);
	printf("Player's total is %d\n",total(playDeck));
	printf("\n");
	
	printf("-----------Dealer's cards-----------\n");
	deckStart(dealerDeck,mainDeck);
	printf("Dealer's total is %d\n",total(dealerDeck));
	printf("\n");
	
	while(1){
		printf("--------------------------------------------\n");
		printf("Type 'h' 'H' or 'hit' for another card\n");
	        printf("Type 's' 'S' or 'stand' to stand\n");	
		char hit[6];
		scanf("%s",*&hit);
		if((strcmp(hit,"hit") == 0) || (strcmp(hit,"h") == 0 ) || (strcmp(hit,"H") == 0)){
			printf("The card dealt is ");
			giveCard(mainDeck,playDeck);
			printf("\nThe player's hand is : ");
			show(playDeck);
			printf("Player's total is %d\n",total(playDeck));
			printf("\n");
			printf("--------------------------------------------\n");
		}
		else if((strcmp(hit,"stand") == 0) || (strcmp(hit,"s") == 0 ) || (strcmp(hit,"S") == 0)){
				break;
				}
		else{printf("Use valid input!\n");}
		if(total(playDeck) > 21){
			printf("You lose!\n");
			destroy_deck(mainDeck);
			destroy_deck(playDeck);
			destroy_deck(dealerDeck);
			return 0;
		}
	}
			
	
	
	while(1){
		if(total(dealerDeck) < 17){
			printf("--------------------------------------------\n");
			printf("The card dealt is ");
			giveCard(mainDeck,dealerDeck);
			printf("\nThe dealer's hand is : ");
			show(dealerDeck);
			printf("Dealer's total is %d\n",total(dealerDeck));
			printf("\n");
			printf("--------------------------------------------\n");
		}
		else{break;}
	}
	if(total(dealerDeck) > 21){
			printf("Player's total is %d\n",total(playDeck));
			printf("Dealer's total is %d\n",total(dealerDeck));
			printf("You win!\n");
			destroy_deck(mainDeck);
			destroy_deck(playDeck);
			destroy_deck(dealerDeck);
			return 0;
		}
	if(total(dealerDeck) >= total(playDeck)){
			printf("Player's total is %d\n",total(playDeck));
			printf("Dealer's total is %d\n",total(dealerDeck));
			printf("You lose!\n");
			destroy_deck(mainDeck);
			destroy_deck(playDeck);
			destroy_deck(dealerDeck);
			return 0;
	}
	else{
			printf("Player's total is %d\n",total(playDeck));
			printf("Dealer's total is %d\n",total(dealerDeck));
			printf("You win!\n");
			destroy_deck(mainDeck);
			destroy_deck(playDeck);
			destroy_deck(dealerDeck);
			return 0;
	}
}
