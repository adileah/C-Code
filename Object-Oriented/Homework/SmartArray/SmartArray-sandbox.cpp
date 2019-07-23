/* Name: < Fill Me In >
   Date: < Fill Me In >
   Desc: < Fill Me In >
*/
#include <iostream>
#include "SmartArray.h"

int main(){
  // Example usage of the SmartArray class
  SmartArray<int> a;
  a[3] = 5;
  a[10] = 2;
  cout << a << " == [0,0,0,3]" << endl;
  
  SmartArray<string> b;
  b[3] = "no";
  cout << b << endl; 
}