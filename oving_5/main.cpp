#include "Card.h"
#include "CardDeck.h"
#include "std_lib_facilities.h"

int main() {
    // Rank r = Rank::king;
    // Suit s = Suit::hearts;
    // string rank = rankToString(r);
    // string suit = suitToString(s);
    // cout << "Rank: " << rank << " Suit: " << suit << endl;

    // Card c{Suit::spades, Rank::ace};
    // cout << c.toString() << '\n';
    CardDeck dek{};
    // dek.print();
    // cout << endl;
    // dek.shuffle();
    // dek.print();
    // cout << endl;
    cout << endl << dek.drawCard().toString()<<endl;
    dek.print();
    cout << endl;
    return 0;
}  