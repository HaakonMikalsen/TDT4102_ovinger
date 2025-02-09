#pragma once
#include "Card.h"

// BEGIN: 3a
class CardDeck{
    public:
        vector<Card> cards;
        CardDeck();
        void swap(int a, int b);
        void print();
        void shuffle();
        Card drawCard();
};
// END: 3a
