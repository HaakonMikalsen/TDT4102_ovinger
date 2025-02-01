// Øving 1
// Oversettelse fra Python til C++
#include "std_lib_facilities.h"

int maxOfTwo(int a, int b)   {
    // BEGIN: 2a
    if (a>b){
        cout<< "A is greater than B"<<"\n";
        return a;
    }
    else {
        cout<< "B is greater than a"<<"\n";
        return b;
    }
    // END: 2a
}

int fibonacci(int n) {
    // BEGIN: 2c
    int a = 0;
    int b = 1;
    cout<<"Fibonacci numbers:"<<endl;
    for(int x = 1; x<=n;x++){
        cout << x <<" " << b << endl;
        int temp = b;
        b += a;
        a = temp;
    }
    cout << "----" << endl;
    return b;
    // END: 2c
}

int squareNumberSum(int number) {
    // BEGIN: 2d
    int totalSum = 0;
    for(int i = 1; i<= number+1;i++){
        totalSum += i*i;
        cout << i*i << endl;
    }
    cout << totalSum<< endl;
    return totalSum;
    // END: 2d
}

void triangleNumbersBelow(int number) {
    // BEGIN: 2e
    int acc = 1;
    int num = 2;
    cout << "triangle numbers below "<< number << ":"<< endl;
    while (acc<number)
    {
        cout << acc << endl;
        acc += num;
        num += 1;
    }
    cout << "";
    // END: 2e
}

bool isPrime(int number) {
    // BEGIN: 2f
    for (int j = 2; j < number; j++)
    {
        if (number%j==0){
            return false;
        }
    }
    return true;
    // END: 2f
}

void naivePrimeNumberSearch(int maxNumber) {
    // BEGIN: 2g
    for (int i = 2; i < maxNumber; i++)
    {
        if (isPrime(i)){
            cout << i << " is a prime"<< endl;
        }
    }
    
    // END: 2g 
}

void inputAndPrintNameAndAge() {
    // BEGIN: 2h
    string name = "";
    string age = "";
    
    cout << "Hva heter du? "<< endl;
    cin >> name;
    cout << "Hvor gammel er du? "<< endl;
    cin >> age;

    cout << name << " er " << age << " år gammel." << endl;

    // END: 2h
}

int main() {
    // BEGIN: 2b
    cout << "Oppave a)"<< endl;
    cout << maxOfTwo(5,6) << endl;
    cout <<endl << "Oppave c)"<< endl;
    cout << fibonacci(5) << endl;
    cout <<endl << "Oppave d)"<< endl;
    cout << squareNumberSum(5) << endl;
    cout <<endl << "Oppave e)"<< endl;
    triangleNumbersBelow(10);
    cout <<endl << "Oppave f)"<< endl;
    cout << isPrime(2)<< endl;
    cout << isPrime(31)<< endl;
    cout << isPrime(55)<< endl;
    cout <<endl << "Oppave g)"<< endl;
    naivePrimeNumberSearch(100);
    cout <<endl << "Oppave h)"<< endl;
    inputAndPrintNameAndAge();
    // END: 2b
	return 0;
}
