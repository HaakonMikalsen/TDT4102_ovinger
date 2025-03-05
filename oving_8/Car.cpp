#include "Car.h"

#include <cassert>

// BEGIN 1b
Car::Car(int initalFreeSeats){
    this->freeSeats = initalFreeSeats;
}
// END 1b

// BEGIN 1c
bool Car::hasFreeSeats() const {
    if (freeSeats != 0) {
        return true;
    }
    return false;
}
void Car::reserveFreeSeat() {
    freeSeats--;
}
// END 1c