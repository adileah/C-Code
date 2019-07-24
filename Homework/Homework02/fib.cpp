#include <iostream>
#include "timer2.h"
#include "operations.cpp"

const unsigned LENGTH = 36;
int main(){
    srand(time(0));
    Timer t;
    int a;
    
    // Evaluate different fib lengths
    for(unsigned length = 1; length < LENGTH; length++){
        a = length;
        t.setN(length);
        t.tic();
        fib(a);
        t.toc();
    }
    t.saveResults("fibtimes.csv");
    //O(2^n)
    
    return 0;
}