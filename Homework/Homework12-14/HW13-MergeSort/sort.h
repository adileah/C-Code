#ifndef MYSORT_H
#define MYSORT_H
/* Name: Adilleah Smith
   Date: Nov. 9
   Desc: Implements many sorting functions
*/
#include <iostream>
#include <vector>
#include "MaxHeap.h"
#include "operations.cpp"

using namespace std;

template <class T>
vector<T> bubbleSort(const vector<T> &a){
    vector<T> temp = a;
    temp = bubbleSort3(temp);
    return temp;
}

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
template <class T>
vector<T> n2(const vector<T> &orig){ //insertion algolist.net
    vector<T> temp = orig;
    T tmp;
    for (unsigned i = 1; i < temp.size(); i++) {
        unsigned j = i;
        while (j > 0 && temp[j - 1] > temp[j]) {
            tmp = temp[j];
            temp[j] = temp[j - 1];
            temp[j - 1] = tmp;
            j--;
        }
    }
    return temp;
}
template <class T>
void sort(const vector<T>&left, const vector<T>&right, vector<T> &bars){//stack exchange
    int nL = left.size();
    int nR = right.size();
    int i = 0, j = 0, k = 0;
    while (j < nL && k < nR) 
    {
        if (left[j] < right[k]) {
            bars[i] = left[j];
            j++;
        }
        else {
            bars[i] = right[k];
            k++;
        }
        i++;
    }
    while (j < nL) {
        bars[i] = left[j];
        j++; i++;
    }
    while (k < nR) {
        bars[i] = right[k];
        k++; i++;
    }
}
template <class T>
vector<T> mergeSort(const vector<T> &bar){
    vector<T> temp = bar;
    if (temp.size() <= 1) return bar;
    unsigned mid = temp.size() / 2;
    vector<T> left;
    vector<T> right;

    for (unsigned j = 0; j < mid;j++)
        left.push_back(temp[j]);
    for (unsigned j = 0; j < (temp.size()) - mid; j++)
        right.push_back(temp[mid + j]);

    left = mergeSort(left);
    right = mergeSort(right);
    sort(left, right, temp);
    return temp;
}



#endif