#ifndef MinHEAP_H
#define MinHEAP_H
/* Name: // Fill me in
   Date: NOV 4, 2018
   Desc: Min heap/priority queue
*/
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cassert>
#include <vector>

using namespace std;

//Left child at 2n+1 Right child at 2n+2
//Parent at (n-1)/2

template <class T>

class MaxHeap{
    private:
        vector<T> heap;
        unsigned sizeHeap;
  
    public:
    
    MaxHeap(){
        sizeHeap = 0;
    }
  
    ~MaxHeap(){
        
    }
  
    MaxHeap(const MaxHeap &other){
       heap = other.heap;
    }
    
    MaxHeap& operator=(const MaxHeap &other){
       heap = other.heap;
       return *this;
    }
  
    // Insert word into the Heap
    void push(const T &type){
        sizeHeap++;
        heap.push_back(type);
        bubbleUp(heap);
    }
  
    // Number of values stored
    unsigned size()const{
        return sizeHeap;
    }
    
    // Returns the Minimum string - Does not change the heap!
    // Throw exception if heap is empty.
    T top()const{
        if(sizeHeap == 0){
            throw logic_error("Nothing in heap");
        }
        return heap[0];
    }
    
    // Remove the Minimum value from the heap
    void pop(){
        if(sizeHeap == 0){
            throw logic_error("Nothing to remove");
        }
        heap[0] = heap[sizeHeap-1];
        sizeHeap--;
        heap.pop_back();
        bubbleDown();
    }
    private:
    string getLeft(vector <T> heap, unsigned i){
        return heap[2*i + 1];
    }
    string getRight(vector <T> heap,unsigned i){
        return heap[2*i + 2];
    }
    string getParent(vector <T> heap,unsigned i){
        return heap[(i+1)/2 - 1];
    }
    
    //void?
    void bubbleUp(vector <T> &heap){
        //for(unsigned i = heap.size()-1; i > 0; i--){
        unsigned i = heap.size()-1;
        if (heap.size() == 1){
            return;
        }
        while(i > 0){
            if(heap[i]>heap[(i+1)/2 -1]){
                T temp = heap[(i-1)/2];
                heap[(i-1)/2] = heap[i];
                heap[i] = temp; 
                i = (i-1)/2;
            }else{
                i = 0;
            }
        }
    }
    void bubbleDown(){
        unsigned i = 0;
        if(heap.size() == 1){
            return;
        }
        while(((i*2)+2) < heap.size()){
            while(heap.at((i * 2) + 1) > heap.at(i) || heap.at((i * 2) + 2) > heap.at(i)){
                if(heap.at((i * 2) + 1) >= heap.at((i * 2) + 2)){
                    T temp = heap.at(i);
                    heap.at(i) = heap.at((i * 2) + 1);
                    heap.at((i * 2) + 1) = temp;
                    i = ((i * 2) + 1);
                }else{
                    T temp = heap.at(i);
                    heap.at(i) = heap.at((i * 2) + 2);
                    heap.at((i * 2) + 2) = temp;
                    i = ((i * 2) + 2);
                }
                if(((i * 2) + 1) < heap.size() - 1 || ((i * 2) + 2) < heap.size() - 1){
                        break;
                }
            }
        }
    }
};

#endif

