#ifndef STACK_H
#define STACK_H
/* Name: Garrett Grey, Adileah Smith
   Date: Oct 3, 2018
   Desc: Stack class using linked lists
*/
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cassert>

using namespace std;

struct List_Node_t{
  int data;
  List_Node_t* next;
};

// By subclassing of List, we verify we follow the required List interface.
class Stack{
    private:
    List_Node_t* start;
    unsigned my_size;

    public:
    Stack(){
        start = NULL;
        my_size = 0;
    }
    
    Stack(const Stack &other){ // Copy constructor
        // Pointer to to walk down other
        List_Node_t* cur_other = other.start;
        // Pointer to keep track of the last node, to tack them on.
        List_Node_t* last = NULL;
        start = NULL;
        while(cur_other){
          List_Node_t* temp = new List_Node_t;
          temp->data = cur_other->data;
          temp->next = NULL;
          if(last)last->next = temp;
          if(!start)start = temp;
          last = temp;
          cur_other = cur_other->next;
        }   
        my_size = other.my_size;
      }
      
      ~Stack(){
        clear();
      }
      
      Stack& operator=(const Stack &other){
        // Verify I'm not other
        if(this == &other) return *this;
        // Wipe the current data
        clear();
        // Copy everything from other
        List_Node_t* cur_other = other.start;
        List_Node_t* last = NULL;
        start = NULL;
        while(cur_other){
          List_Node_t* temp = new List_Node_t;
          temp->data = cur_other->data;
          temp->next = NULL;
          if(last)last->next = temp;
          if(!start)start = temp;
          last = temp;
          cur_other = cur_other->next;
        }
        my_size = other.my_size;
        return *this;
      }
      
      void clear(){// Removes all elements from the list.
        // Return all nodes & sets start to NULL
        this->my_size = 0;
        List_Node_t* cur = start;
        start = NULL;
        while(cur){
          List_Node_t* temp = cur;
          cur = cur->next;
          delete temp;
        }
      }
      
      unsigned size() const{ // Returns the length of the list.
        return this->my_size;
      }
      
      void remove(int loc){ // Removes the element at position loc
          // if loc is invalid, throw an error.  Allow negative indexes.
        if(loc >= (int)this->my_size || loc < -(int)this->my_size){
          throw logic_error("Index not valid");
        }
        if(loc < 0){
          loc = my_size + loc;
        }
        assert(loc >= 0);
        if(loc == 0 && this->my_size == 1){
          clear();
          this->my_size--;
          return;
        }
        // Special case where we remove loc=0 as start needs fixing
        if(loc == 0){
          List_Node_t* temp = start;
          start = start->next;
          delete temp;
          this->my_size--;
          return;
        }
        // The trick is we need to stop ONE early to fix the pointers
        // Walk and count
        List_Node_t* cur = start;
        while(cur && loc > 1){ // When cur becomes NULL (0, false) stop counting
          // or we are 1 away
          cur = cur->next;
          loc--;
        }
        assert(cur);
        assert(cur->next);
        // Cur is a node BEFORE the one to remove, save the node to remove
        List_Node_t* temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        this->my_size--;
      }
      
      void push(int value){
        // Create the node
        List_Node_t* temp = new List_Node_t;
        unsigned counter = 0;
        temp->data = value;
        temp->next = NULL;
        // Verify start isn't null
        if(!start){ // Note NULL is 0, which is false!
          start = temp;
          this->my_size++;
          return;
        }
        // Walk to the end
        List_Node_t* cur = start;
        // We need to stop ONE EARLY
        while(counter < this->my_size - 1){
          cur = cur->next;
          counter++;
        }
        // So cur->next should be null, so cur must be the last element
        // Tack on temp onto it!
        cur->next = temp;
        this->my_size++;
      }
      
      void pop(){
        unsigned counter = 0;
        // Verify start isn't null
        if(!start){ // Note NULL is 0, which is false!
          return;
        }
        // Walk to the end
        List_Node_t* cur = start;
        // We need to stop ONE EARLY
        while(counter < this->my_size - 1){
          cur = cur->next;
          counter++;
        }
        // So cur->next should be null, so cur must be the last element
        cur = NULL;
        this->my_size--;
      }
      
      int peek(){
        unsigned counter = 0;
        if(!start){ // Note NULL is 0, which is false!
          throw logic_error("Index not valid");
        }
        // Walk to the end
        List_Node_t* cur = start;
        // We need to stop ONE EARLY
        while(counter < this->my_size - 1){
          cur = cur->next;
          counter++;
        }
        // So cur->next should be null, so cur must be the last element
        return cur->data;
      }
      
};

#endif