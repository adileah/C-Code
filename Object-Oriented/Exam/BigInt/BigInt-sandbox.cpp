/*    @file sandbox.cpp    
      @author <fill me in>
      @date <fill me in>  

			@description Sandbox for MyComplex
*/

#include <iostream>


#include "BigInt.h"

using namespace std;


int main(int argc, char* argv[]){
  // Use this program to test your MyComplex implementation!
 
  BigInt a(0);
  BigInt b(10);
  BigInt c = a + b;
  cout << "a:" << a << endl;
  cout << "b:" << b << endl;
  cout << "c:" << c << endl;
  
	
	return 0;
}