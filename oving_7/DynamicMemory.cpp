#include "DynamicMemory.h"

#include <cassert>
#include <iostream>
#include <vector>

// BEGIN: 1a
void fillInFibonacciNumbers(int* result, int length) {
    if (length >= 1) {
        result[0] = 0;
    }
    if (length >= 2) {
        result[1] = 1;
    }
    for (int i = 2; i < length; i++) {
        result[i] = result[i - 1] + result[i - 2];
    }
}
// END: 1a

// BEGIN: 1b
void printArray(int* array, int length){
    for (int i = 0; i < length; i++)
    {
        std::cout << array[i]<<std::endl;
    }
    
}
// END: 1b

// BEGIN: 1c
void createFibonacci(){
    int lenght  = 0;
    std::cout << "Hov many nymbers want?"<<std::endl;
    std::cin >> lenght;
    int* numbers = new int {};
    fillInFibonacciNumbers(numbers,lenght);
    printArray(numbers,lenght);
    delete numbers;
    numbers = nullptr;
}
// END: 1c