#include <iostream>
using namespace std;

int maxOfTwo(int a, int b){
    if (a*(a>=b)){
        cout << "A is greater than B\n";
    }
    else{
        cout << "B is greater than A\n";
    }
    return (a*(a>=b))+(b*(b>a));
}

int main(){
    // for (int i = 0; i<20; i++){
    //     cout << maxOfTwo(10,i)<<"\n";
    // }

    cout << "Oppagve 2 a) \n";
    cout << maxOfTwo(5,6)<<"\n";
    
}