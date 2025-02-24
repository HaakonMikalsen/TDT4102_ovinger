#include <stdlib.h>

#include <iostream>

#include "Dummy.h"
#include "DynamicMemory.h"
#include "Matrix.h"

void Clear() { 
    std::cout << "\x1B[2J\x1B[H"; 
    std::cout << "-------------------"<<std::endl; 
    
    }

int main() {
    // createFibonacci();
    Clear();
    Matrix minMatrise(4, 8);
    minMatrise.set(2, 2, 100);
    // std::cout << minMatrise;
    // Matrix kopiMatrise(minMatrise);
    // minMatrise.~Matrix();
    // std::cout << "----------"<<std::endl;
    // std::cout << minMatrise;
    // Matrix minDiagnoaleMatrise(4);
    // std::cout << minDiagnoaleMatrise<<std::endl;
    // std::cout << "----------"<<std::endl;
    // std::cout << kopiMatrise;

    Matrix matrise2 = minMatrise;
    matrise2.set(1,1,420);
    Matrix matrise3(minMatrise);
    matrise3.set(2,4,700);
    
    // std::cout<<minMatrise;
    // std::cout << "----------"<<std::endl;
    std::cout << "----------"<<std::endl;
    
    std::cout<<matrise2;
    std::cout << "----------"<<std::endl;
    
    std::cout<<matrise3;
    std::cout << "----------"<<std::endl;

    matrise2+=matrise3;
    std::cout<<matrise2;
    std::cout << "----------"<<std::endl;
    
    std::cout<<matrise2+matrise2;
    std::cout << "----------"<<std::endl;
    
    std::cout<<matrise2;
    std::cout << "----------"<<std::endl;
    
    
    dummyTest();
    return 0;
}