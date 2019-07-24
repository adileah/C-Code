#ifndef MinHeap_H
#define MinHeap_H
/* Name: Adileah Smith
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

class MinHeap{
    private:
        vector<string> heap;
        unsigned sizeheap;
  
    public:
    
    MinHeap(){
        sizeheap = 0;
    }
  /*
    ~MinHeap(){
        
    }
  
    MinHeap(const MinHeap &other){
       heap = other.heap;
    }
    
    MinHeap& operator=(const MinHeap &other){
       heap = other.heap;
       return *this;
    }
  */
    // Insert word into the heap
    void push(const string &word){
        sizeheap++;
        heap.push_back(word);
        bubbleUp(heap);
    }
  
    // Number of values stored
    unsigned size()const{
        return sizeheap;
    }
    
    // Returns the Minimum string - Does not change the heap!
    // Throw exception if heap is empty.
    string top()const{
        if(sizeheap == 0){
            throw logic_error("Nothing in heap");
        }
        return heap[0];
    }
    
    // Remove the Minimum value from the heap
    void pop(){
        if(sizeheap == 0){
            throw logic_error("Nothing to remove");
        }
        heap[0] = heap[sizeheap-1];
        sizeheap--;
        heap.pop_back();
        bubbleDown(heap);
    }
    private:
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
    void bubbleUp(vector <string> &heap){
        //for(unsigned i = heap.size()-1; i > 0; i--){
        unsigned i = heap.size()-1;
        if (heap.size() == 1){
            return;
        }
        while(i > 0){
            if(heap[i]<heap[getParent(i)]){
                string temp = heap[(i-1)/2];
                heap[(i-1)/2] = heap[i];
                heap[i] = temp; 
                i = (i-1)/2;
            }else{
                i = 0;
            }
        }
    }
     void bubbleDown(vector <string> &heap){
        if(heap.size() <= 1)return;
        unsigned cur = 0;
        while(1){
            // See if the right child exists
            if(getLeft(cur) >= heap.size()){
                return;  // Must be only 1 element!
            }
            if(getRight(cur) >= heap.size()){  // Nope!
                // Maybe just flip with left
                if(heap[cur] > heap[getLeft(cur)]){
                    string left = heap[getLeft(cur)];
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
                    string left = heap[getLeft(cur)];
                    string right = heap[getRight(cur)];
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

