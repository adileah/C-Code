/*
    @author < Fill Me In >
    @date < Fill Me In >
	Simple non-pointer object demo for Property using .h and .cpp files.
*/

#include <string>
#include <iostream>

#include "Property.h"
#include "Property.cpp"

using namespace std;


int main(){
  Property a;
  cout << "a address: " << a.getAddress();
  cout << " acres: " << a.getAcres();
  cout << " tax: $" << a.getYearTax() << endl;
  
  Property b("123 Here St.");
  cout << "b address: " << b.getAddress();
  cout << " acres: " << b.getAcres();
  cout << " tax: $" << b.getYearTax() << endl;
  
  Property c("894 Nowhere Blvd.", 5);
  c.setAcres(10);
  cout << "c address: " << c.getAddress();
  cout << " acres: " << c.getAcres();
  cout << " tax: $" << c.getYearTax() << endl;
  
  c = b;
  cout << "c address: " << c.getAddress();
  cout << " acres: " << c.getAcres();
  cout << " tax: $" << c.getYearTax() << endl;
}
