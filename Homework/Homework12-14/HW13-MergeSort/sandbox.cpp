/* Name: Paul Talaga
   Date: XXXXX
   Desc: Testing file
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include "sort.h"
#include "timer.cpp"
//#include "operations.cpp"

using namespace std;


int main(){
  // Fill me in to experiment
    srand((int)(time(0)));
    //Timer t;
    /*for(unsigned length = 1; length <= 1000; length++){
        vector<int> original;
        for(unsigned i = 0; i < length; i++){
            original.push_back(rand()%100);
        }
        t.setN(length);
        t.tic();
        original = mergeSort(original);
        t.toc();
    }
    t.saveResults("mergetimes.csv");*/
    vector<int> orig;
    for(unsigned i = 0; i <= 4; i++){
        orig.push_back(rand()%15);
    }
    orig = mergeSort(orig);
    for(unsigned i = 0; i <= 4; i++){
        cout << orig[i] << " ";
    }
    return 0;
}