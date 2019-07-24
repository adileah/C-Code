/* Name: Paul Talaga
   Date: 1/30/17
   Desc: Testing file for the Rational class.
*/
#include <iostream>
#include <algorithm>
//#include "LListRE.h"
#include "timer.h"
#include "LListREslow.h"
//#include "LListIT.h"
const unsigned SIZEMAX = 50;
int main(){
  // Example usage of the Rational class
  srand(time(0));
  Timer t;
  LListRE a;
  for(unsigned size = 0; size <= SIZEMAX; size+=5){
      for(unsigned i = 0; i < size; i++){
          a.push_back(i);
      }
    t.setN(size);
    t.tic();
    cout << a.size();
    t.toc();  
    a.clear();
  }
  t.saveResults("LListREslow.csv");
      
  
  return 0;
}