#ifndef MinHEAP_H
#define MinHEAP_H
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
        unsigned sizeHeap;
  
    public:
    
    MinHeap(){
        sizeHeap = 0;
    }
  
    ~MinHeap(){
        
    }
  
    MinHeap(const MinHeap &other){
       heap = other.heap;
    }
    
    MinHeap& operator=(const MinHeap &other){
       heap = other.heap;
       return *this;
    }
  
    // Insert word into the Heap
    void push(const string &word){
        sizeHeap++;
        heap.push_back(word);
        bubbleUp(heap);
    }
  
    // Number of values stored
    unsigned size()const{
        return sizeHeap;
    }
    
    // Returns the Minimum string - Does not change the heap!
    // Throw exception if heap is empty.
    string top()const{
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
        bubbleDown(heap);
    }
    private:
    string getLeft(vector <string> heap, unsigned i){
        return heap[2*i + 1];
    }
    string getRight(vector <string> heap,unsigned i){
        return heap[2*i + 2];
    }
    string getParent(vector <string> heap,unsigned i){
        return heap[(i-1)/2];
    }
    
    //void?
    void bubbleUp(vector <string> &heap){
        //for(unsigned i = heap.size()-1; i > 0; i--){
        unsigned i = heap.size()-1;
        if (heap.size() == 1){
            return;
        }
        while(i > 0){
            if(heap[i]<getParent(heap, i)){
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
        unsigned i = 0;
        if(heap.size() == 1){
            return;
        }
        while(i < heap.size()){
            if(i*2+2 >= heap.size()){
                if(heap[i] > getLeft(heap, i)){
                    string temp = getLeft(heap,i);
                    heap[2*i+1] = heap[i];
                    heap[i] = temp;
                    i = heap.size();
                }
            }
            else if(heap[i] > getLeft(heap, i) || heap[i] > getRight(heap,i)){
                if(getLeft(heap,i) < getRight(heap,i)){
                    string temp = getLeft(heap,i);
                    heap[2*i+1] = heap[i];
                    heap[i] = temp; 
                    i = 2*i + 1;
                }else{
                    string temp = getRight(heap,i);
                    heap[2*i+2] = heap[i];
                    heap[i] = temp;
                    i = 2*i + 2;
                }
            }else{
                i = heap.size();
            }
        }
    }
};

#endif

