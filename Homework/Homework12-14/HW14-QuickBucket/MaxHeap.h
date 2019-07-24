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
        bubbleUp(heap.size());
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
        bubbleDown(heap.size());
    }
    unsigned getLeft(unsigned i){
        return 2*i + 1;
    }
    unsigned getRight(unsigned i){
        return 2*i + 2;
    }
    unsigned getParent(unsigned i){
        return (i-1)/2;
    }
    
    //void?
    void bubbleUp(unsigned curSize){
        //for(unsigned i = curSize-1; i > 0; i--){
        unsigned i = curSize-1;
        if (curSize == 1){
            return;
        }
        while(i > 0){
            if(heap[i]<heap[getParent(i)]){
                T temp = heap[(i-1)/2];
                heap[(i-1)/2] = heap[i];
                heap[i] = temp; 
                i = (i-1)/2;
            }else{
                i = 0;
            }
        }
    }
     void bubbleDown(unsigned curSize){
        if(curSize <= 1)return;
        unsigned cur = 0;
        while(1){
            // See if the right child exists
            if(getLeft(cur) >= curSize){
                return;  // Must be only 1 element!
            }
            if(getRight(cur) >= curSize){  // Nope!
                // Maybe just flip with left
                if(heap[cur] > heap[getLeft(cur)]){
                    T left = heap[getLeft(cur)];
                    heap[getLeft(cur)] = heap[cur];
                    heap[cur] = left;
                    return; // We must be at the bottom level, so are done!
                    //cur = getLeftChild(cur);
                }else{
                    return;
                }
            }else{
                // See if we need to flip
                if(heap[cur] > heap[getLeft(cur)] || heap[cur] > heap[getRight(cur)]){
                    T left = heap[getLeft(cur)];
                    T right = heap[getRight(cur)];
                    if( left < right){
                        heap[getLeft(cur)] = heap[cur];
                        heap[cur] = left;
                        cur = getLeft(cur);
                    }else{
                        heap[getRight(cur)] = heap[cur];
                        heap[cur] = right;
                        cur = getRight(cur);
                    }
                }else{
                    return;
                }
            }
        }
    }
};

#endif

