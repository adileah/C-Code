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

template <class T>
void quickSort2(vector<T> &any, int left, int right) {
      int i = left, j = right;
      T tmp;
      int pivot = any[(left + right) / 2];
      /* partition */
      while (i <= j) {
            while (any[i] < pivot)
                  i++;
            while (any[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = any[i];
                  any[i] = any[j];
                  any[j] = tmp;
                  i++;
                  j--;
            }
      }
      /* recursion */
      if (left < j)
            quickSort2(any, left, j);
      if (i < right)
            quickSort2(any, i, right);
}

template <class T>
vector<T> quickSort(const vector<T> &any){
    if(any.size() <= 1) return any;
    vector<T> temp = any;
    quickSort2(temp, 0, temp.size()-1);
    return temp;
}

vector<unsigned> countingSort(const vector<unsigned> &values){
    if(values.size() <= 1) return values;
    unsigned max = values[0];
    for(unsigned i = 1; i < values.size(); i++){ //this for loop finds max
        if(max < values[i]){
            max = values[i];
        }
    }
    unsigned* counts = new unsigned[max+1]; //makes array of garbage values
    for(unsigned i = 0; i < max+1; i++){ //puts zeros in array
        counts[i] = 0;
    }
    for(unsigned i = 0; i < values.size(); i++){ 
        //looks at value in original vector (values[i]) and finds the index of that value in new array and adds one to it
        counts[values[i]]++;
    }
    vector<unsigned> temp;
    for(unsigned i = 0; i < max+1; i++){ //pushes back the values into a new vector so long as the array value is greater than 0
        while(counts[i]>0){ //counts how many of each index
            temp.push_back(i);
            counts[i]--;
        }
    }
    return temp;
}

#endif