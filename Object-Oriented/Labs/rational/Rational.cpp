/* Name: Adileah Smith, James Sprague, Trey Lake
   Date: May 29, 2018
   Desc: Implementation of a Rational number class.
*/
// iostream is not neccassary because cout is not used.
#include <sstream>
#include <string>
#include <stdexcept>

// Be sure to include the .h file!
#include "Rational.h"

using namespace std;

Rational::Rational(){
  numerator = new int;
  *numerator = 1;
  denominator = new int;
  *denominator = 1;
}
  
Rational::Rational(int top){
  numerator = new int;
  *numerator = top;
  denominator = new int;
  *denominator = 1;
}

Rational::Rational(int top, int bottom){
  numerator = new int;
  *numerator = top;
  denominator = new int;
  *denominator = bottom;
}

//destructor, copy, assignment

Rational::~Rational(){
  delete this->numerator;
  this->numerator = NULL;
  delete this->denominator;
  this->denominator = NULL;
}

Rational::Rational(const Rational &other){
  //cout << "copy constructor" << endl;
  this->numerator = new int;
  *(this->numerator) = *(other.numerator);
  this->denominator= new int;
  *(this->denominator) = *(other.denominator);
}
Rational& Rational::operator=(const Rational &other){
  //cout << "weird operator = called!" << endl;
  *(this->numerator) = *(other.numerator);
  *(this->denominator) = *(other.denominator);
  return *this;
} 
  
// Setters
void Rational::setNumerator(const int &n){
  *numerator = n; 
    
  
}
  
void Rational::setDenominator(const int &n){
  *denominator = n;
  
}
  
// Getters
int Rational::getNumerator() const{
    return *numerator;
}
  
int Rational::getDenominator() const{
    return *denominator;
}
  
string Rational::print() const{
  stringstream s;
  s << *numerator << "/" << *denominator;
  return s.str();
}
  
  //operators
  
// Returns a new Rational number, does not change either.
Rational Rational::operator+(const Rational &other) const{
  Rational ret;
  *ret.numerator = *numerator * *other.denominator + *denominator * *other.numerator;
  *ret.denominator = *denominator * *other.denominator;
 
  return ret;
}
  
// Returns a new Rational number, does not change either.
Rational Rational::operator*(const Rational &other) const{
  
  return Rational(*numerator * *other.numerator, *denominator * *other.denominator);
}

// Returns a bool and no need to change this or other
bool Rational::isEqualTo(const Rational &other) const{
  
  int ltop = (*numerator) * (*other.denominator);
  int rtop = *other.numerator * *denominator;
  return ltop == rtop;
}

bool Rational::isGreaterThan(const Rational &other) const{
  int ltop = *numerator * *other.denominator;
  int rtop = *other.numerator * *denominator;
  return ltop > rtop;
}

bool Rational::isGreaterThanOrEqualTo(const Rational &other) const{
  return isEqualTo(other) || isGreaterThan(other);
}

Rational Rational::invert() const{
  /*const int temp = getNumerator();
  setNumerator (getDenominator());
  setDenominator(temp);*/
  return Rational(*denominator, *numerator);
}

Rational Rational::negate() const{
  *numerator = - (*numerator);
  return Rational(*numerator, *denominator);
}

Rational Rational::operator-(const Rational &other) const{
  Rational ret;
  *ret.denominator = *denominator * *other.denominator;
  *ret.numerator = *numerator * *other.denominator - *other.numerator * *denominator;
  return ret;
}

Rational Rational::operator/(const Rational &other) const{
  Rational ret;
  *ret.denominator = *denominator * *other.numerator;
  *ret.numerator = *numerator * *other.denominator;
  return ret;
}

bool Rational::operator<(const Rational &other) const{
  return isLessThan(other);
}

bool Rational::operator>(const Rational &other) const{
  return isGreaterThan(other);
}

bool Rational::operator==(const Rational &other) const{
  return isEqualTo(other);
}

bool Rational::operator>=(const Rational &other) const{
  return isGreaterThanOrEqualTo(other);
}

bool Rational::operator<=(const Rational &other) const{
  return isLessThanOrEqualTo(other);
}

bool Rational::operator!=(const Rational &other) const{
  return isNotEqualTo(other);
}


bool Rational::isNotEqualTo(const Rational &other) const{
  return !isEqualTo(other);
}

bool Rational::isLessThan(const Rational &other) const{
  return !isGreaterThanOrEqualTo(other);
}

bool Rational::isLessThanOrEqualTo(const Rational &other) const{
  return !isGreaterThan(other);
}



