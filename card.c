#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "card.h"

// Generate the deck (6 Aces, 6 Kings, 6 Queens, 2 Jokers)
void generate_deck(Deck* deck) {
    int index = 0;

    // 6 Aces, 6 Kings, 6 Queens, 2 Jokers
    for (int i = 0; i < 6; i++) {
        deck->deck[index].value = 1;  // Ace
        index++;
        deck->deck[index].value = 2; // King
        index++;
        deck->deck[index].value = 3; // Queen
        index++;
    }

    // 2 Jokers (can substitute any card)
    deck->deck[index].value = 0;  // Joker
    index++;
    deck->deck[index].value = 0;  // Joker
    index++;

    deck->size = index;
    deck->top = 0;
}

// Shuffle the deck
void shuffle_deck(Deck* deck) {
    srand(time(NULL));  // Random seed
    for (int i = deck->size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Card temp = deck->deck[i];
        deck->deck[i] = deck->deck[j];
        deck->deck[j] = temp;
    }
}

// Deal cards to players
void deal_cards(Deck* deck, Card* hand, int num_cards) {
    for (int i = 0; i < num_cards; i++) {
        if (deck->top < deck->size) {
            hand[i] = deck->deck[deck->top++];
        } else {
            printf("Deck is empty! Cannot deal more cards.\n");
        }
    }
}

// Print the deck (for debugging purposes)
void print_deck(Deck* deck) {
    for (int i = 0; i < deck->size; i++) {
        printf("%d ", deck->deck[i].value);
    }
    printf("\n");
}
