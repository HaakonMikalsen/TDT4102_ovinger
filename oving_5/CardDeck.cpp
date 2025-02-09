#include "CardDeck.h"
#include <random>


// BEGIN: 3b
CardDeck::CardDeck(){
    for (int i = 2; i <= 14; i++) {
        for (int j = 1; j <= 4; j++) {
            Card c{static_cast<Suit>(j),static_cast<Rank>(i)};
            cards.push_back(c);
        }
    }
}

// END: 3b

// BEGIN: 3c
void CardDeck::swap(int a,int b){
    Card c1 = cards.at(a);
    Card c2 = cards.at(b);
    cards.at(a) = c2;
    cards.at(b) = c1;
}
// END: 3c

// BEGIN: 3d
void CardDeck::print(){

    for(int i = 0;i<cards.size();i++){
        cout<< cards.at(i).toString()<<endl;
    }
}
// END: 3d

// BEGIN: 3e
void CardDeck::shuffle(){
    const int suffleAmount = 10000;
    random_device rd;
    default_random_engine generator(rd());

    // Define the range for the random number
    uniform_int_distribution<int> distribution(0, 51);
    for( int i = 0; i<suffleAmount;i++){
        swap(distribution(generator),distribution(generator));
    }

}
// END: 3e

// BEGIN: 3f
Card CardDeck::drawCard(){
    Card lastCard = cards.back();
    cards.pop_back();
    return lastCard;
}

// END: 3f
