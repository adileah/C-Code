//Adileah Smith and Ezekiel 
//HW 4

#ifndef AListDynamic_H
#define AListDynamic_H
#include <string>
#include <iostream>


using namespace std;

class AListDynamic{
    private: 
      int* a;      // You want a plain pointer
      unsigned asize; // the size of the list
      unsigned capacity; // Needs to keep track of how big it can go before  a resize.
    
    public:
      AListDynamic(){
        asize = 0;  
        capacity = 2;
        a = new int[capacity];  // no need to set elements to 0
      }
      AListDynamic(AListDynamic &other){
        // Do what you do in the default constructor, but duplicate other
        asize = other.asize;  
        capacity = other.capacity;
        a = new int[capacity];
        for(unsigned i = 0; i < asize; i++){
            a[i] = other.a[i];
        }
      } // Copy constructor
      ~AListDynamic(){
        delete[] a;
      };
      
      void clear(){// Removes all elements from the list.
        asize = 0;
      }
      unsigned size() {// Returns the length of the list.
        return asize;
      }
      int& at(int loc){// Returns the element at position loc
                // 0-based, with negatives, -1 is last element
        if (loc < 0){
            loc = asize + loc;
            if (loc < 0){
                throw logic_error("Location not found");
            }
        }
        else if(loc >= asize){
          throw logic_error("Location not found");
        }
        return a[loc];
      }          
      void push_back(int value){ // Inserts value on the end of the list
        if(asize == capacity){
          // Crap!  I need a bigger array!  Do this
          int* new_arr = new int[capacity * 2];
          for(unsigned i = 0; i < asize; i++){
            new_arr[i] = a[i];
          }
          delete[] a;
          a = new_arr;
          capacity = capacity * 2;
        }
        a[asize] = value;
        asize++;
      }
      void push_front(int value){ // Inserts value at the beginning of the list
        // verify it fits, or just do a push_back and let that function deal with it.
        if(asize == capacity){
          // Crap!  I need a bigger array!  Do this
          int* new_arr = new int[capacity * 2];
          for(unsigned i = 0; i < asize; i++){
            new_arr[i] = a[i];
          }
          delete[] a;
          a = new_arr;
          capacity = capacity * 2;
        }
        asize++;
        for(unsigned i = asize - 1 ; i > 0 ; i--){
            a[i] = a[i-1];
        }
        a[0] = value;
      }
      void remove(int loc){ // Removes the element at position loc
        if (loc < 0){
            loc = asize + loc;
        }
        if (loc >= asize){
          throw logic_error("Location not found");
        }
        for (unsigned i = loc; i < asize - 1; i++){
            a[i] = a[i+1];
        }
        asize--;
      }
      unsigned count(int value) const{ // Returns the number of times value
                // is in the list
        unsigned count = 0;
        for(unsigned i = 0; i < asize; i++){
            if (a[i] == value){
                count++;
            }
        }
        return count;
      }
      int location(int value) const{ // Returns the index of the first occurance of value.
                // Throw an exception if value does not exist in the list
        bool didfind = false;
        for(unsigned i = 0; i < asize; i++){
            if (a[i] == value){
                return i;
            }
        }
        if(didfind == false){
            throw logic_error("Value not found");
        }
      }
      
      string getAsString() const{ // Returns a string of the list
      stringstream bunny;
      if(asize == 0){
        return "[]";
      }
      bunny << "[";
        for(unsigned i = 0; i < asize; i++){
            bunny << a[i];
            if (i != asize - 1){
                bunny << ",";
            }
        }
        bunny << "]";
        return bunny.str();
      }
      AListDynamic operator=(const AListDynamic &other){
        /*int* new_arr = new int[other.capacity];
          for(unsigned i = 0; i < other.asize; i++){
            new_arr[i] = a[i];
          }
          delete[] a;
          a = new_arr;
          capacity = other.capacity;
          asize = other.asize;*/
      }
};
#endif