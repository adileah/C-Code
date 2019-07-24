/* Name: Paul Talaga
   Date: 1/30/17
   Desc: Testing file
*/
#include <iostream>
#include "Stack.h"
#include "Queue.h"

int main(){
  // Fill me in to experiment
  Queue q;
  Stack s;
  for(int i = 0; i < 5; i++){
      q.enqueue(i);
      s.push(i);
  }
  cout << q.size() << " = " << s.size() << endl;
  q.enqueue(5);
  s.pop();
  Queue otherq;
  Stack others;
  otherq = q;
  others = s;
  cout << q.size() << " = " << otherq.size() << endl;
  cout << s.size() << " = " << others.size() << endl;
  
  return 0;
}