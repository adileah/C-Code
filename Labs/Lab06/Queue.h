#ifndef QUEUE_H
#define QUEUE_H
/* Name: Garrett Grey, Adileah Smith
   Date: Oct 3, 2018
   Desc: Queue class using linked lists
*/
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cassert>              

using namespace std;

// Fill me in
struct List_Node{
    int data;
    List_Node* next;
};

// By subclassing of List, we verify we follow the required List interface.
class Queue{
    private:
      List_Node* start;
      unsigned queue_size;
  
    public:
      Queue(){
          start = NULL;
          queue_size = 0;
      }
      Queue(const Queue &other){
          List_Node* cur_other = other.start;
          List_Node* last = NULL;
          start = NULL;
          while(cur_other){
              List_Node* temp = new List_Node;
              temp->data = cur_other->data;
              temp->next = NULL;
              if(last)last->next = temp;
              if(!start)start = temp;
              last = temp;
              cur_other = cur_other->next;
          }
      }
      ~Queue(){
          clear();
      }
      Queue& operator=(const Queue &other){
          if(this == &other) return *this;
          clear();
          List_Node* cur_other = other.start;
          List_Node* last = NULL;
          start = NULL;
          while(cur_other){
              List_Node* temp = new List_Node;
              temp->data = cur_other->data;
              temp->next = NULL;
              if(last)last->next = temp;
              if(!start)start = temp;
              last = temp;
              cur_other = cur_other->next;
          }
          queue_size = other.queue_size;
          return *this;
      }
      void clear(){
          List_Node* cur = start;
          start = NULL;
          while(cur){
              List_Node* temp = cur;
              cur = cur->next;
              delete temp;
          }
      }
      unsigned size() const{
          return queue_size;
      }
      void enqueue(int value){
        List_Node* temp = new List_Node;
        temp->data = value;
        temp->next = NULL;

        if(!start){ 
          start = temp;
          queue_size++;
          return;
        }
        List_Node* cur = start;
        while(cur->next){
          cur = cur->next;
        }
        cur->next = temp;
        queue_size++;
      }
      void dequeue(){
          if(!start){
              throw logic_error("No elements in list.");
          }
          List_Node* to_die = start;
          start = start-> next;
          delete to_die;
          queue_size--;
      }
      int peek(){
          if(!start){
              throw logic_error("No elements in list.");
          }
          return start->data;
      }
};

#endif