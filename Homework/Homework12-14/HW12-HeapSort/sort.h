#ifndef MYSORT_H
#define MYSORT_H
/* Name: Adilleah Smith
   Date: Nov. 9
   Desc: Implements many sorting functions
*/
#include <iostream>
#include <vector>
#include "MaxHeap.h"

using namespace std;

template <class T>
vector<T> heapSort(const vector<T> &orig){
    MaxHeap<T> cur;
    vector<T> temp = orig;
    for(unsigned i = 0; i<temp.size(); i++){
        cur.push(temp[i]);
    }
    for(unsigned i = 0; i < temp.size(); i++){
        temp[i] = cur.top();
        cur.pop();
    }
    return temp;
}

#endif