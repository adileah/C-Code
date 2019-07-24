//Adileah Smith and Ezekiel 
//Lab 4

#ifndef AListStatic_H
#define AListStatic_H
#include <string>
#include <iostream> // - Ezekiel

using namespace std;

class AListStatic{
    private: 
      int a[100];
      unsigned asize;
    
    public:
      AListStatic(){
        asize = 0;  
        for(unsigned i = 0; i < 100; i++){
            a[i] = 0;
        }
        //a[100] = {};
      }
      /*AListStatic(const AListStatic& next){
         for(unsigned i = 0; i < asize; i++){
             next.a[i] = a[i];
         }
         next.asize = asize;
      } // Copy constructor
      */
      //virtual ~AListStatic(){};
      
      void clear(){// Removes all elements from the list.
        asize = 0;
      }
      unsigned size() {// Returns the length of the list.
        return asize; //-Ezekiel
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
        return a[loc];  // -Ezekiel
      }          
      void push_back(int value){ // Inserts value on the end of the list
      if(asize == 100){
          throw logic_error("Cannot go above 100 elements");
      }
        asize++;
        a[asize - 1] = value;
      }
      void push_front(int value){ // Inserts value at the beginning of the list
        if(asize == 100){
          throw logic_error("Cannot go above 100 elements");
        }
        asize++;
        for(unsigned i = asize - 1 ; i > 0 ; i--){
            a[i] = a[i-1];
        }
        a[0] = value;
      }
      void remove(int loc){ // Removes the element at position loc
        if (loc <= 0){
            loc = asize - 1 + loc;
        }
        for (unsigned i = loc; i < asize; i++){
            a[i] = a[i+1];
            asize--;
        }
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
};
#endif //- Ezekiel