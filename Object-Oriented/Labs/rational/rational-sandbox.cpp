/* Name: Paul Talaga
   Date: 1/30/17
   Desc: Testing file for the Rational class.
*/
#include <iostream>
#include "Rational.h"

int main(){
  // Example usage of the Rational class
  Rational a;
  cout << a.print() << " = 1/1" << endl;
  Rational b(1,2);
  cout << b.print() << " = 1/2" << endl;
  cout << b.getNumerator() << " = 1" << endl;
  cout << b.getDenominator() << " = 2" << endl;
  Rational c;
  c.setNumerator(7);
  c.setDenominator(6);
  cout << c.print() << " = 7/6" << endl;
 
  cout << (a+b).print() << " = 3/2" << endl;
  cout << (a*b).print() << " = 1/2" << endl;
  cout << a.print() << " = 1/1" << endl;
  cout << b.print() << " = 1/2" << endl;
  
  Rational d(5);
  cout << a.isEqualTo(d) << " = 0" << endl;
  Rational e(10,2);
  cout << e.isEqualTo(d) << " = 1" << endl;
  cout << e.isGreaterThan(d) << " = 0" << endl;
  cout << e.isGreaterThanOrEqualTo(d) << " = 1" << endl;
  Rational f(11,2);
  cout << f.isEqualTo(d) << " = 0" << endl;
  cout << f.isGreaterThan(d) << " = 1" << endl;
  cout << f.isGreaterThanOrEqualTo(d) << " = 1" << endl;
  
  
  return 0;
}