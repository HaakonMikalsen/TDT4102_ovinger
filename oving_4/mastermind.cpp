#include "mastermind.h"

#include "utilities.h"

// BEGIN: 4
// Oppgave 4a til 4j løses her forutenom 4e og 4f
void playMastermind() {
    constexpr int size = 4;
    constexpr int letters = 6;
    constexpr int tryes = 10;

    const string code = randomizeString(size, 'A' + letters - 1, 'A');
    string guess = "";

    for (int i = 0; i < tryes; i ++) {
        guess = readInputToString(size, 'A' + letters - 1, 'A');
        int correctPos = checkCharactersAndPosition(code,guess);
        int correctCharacter = checkCharacters(code,guess);
        cout << "You had "<<correctCharacter <<" right charachters"<<endl;
        cout << "You had "<<correctPos <<" right charachters in the right place"<<endl;
        if (correctPos == size){
            cout << "You won"<<endl;
            return;
        }
    }
    cout << "You lost"<<endl;
}
// END: 4

// BEGIN: 4e
int checkCharactersAndPosition(string code, string guess) {
    int s = 0;
    for (int i = 0; i < code.length(); i++) {
        s += code.at(i) == guess.at(i);
    }
    return s;
}
// END: 4e

// BEGIN: 4f
int checkCharacters(string code, string guess) {
    int s = 0;
    for (int i = 0; i < code.length(); i++) {
        s += countChar(code, guess.at(i));
    }
    return s;
}
// END: 4f
