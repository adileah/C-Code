#ifndef RATIONAL_H
#define RATIONAL_H
/* Name: Adileah Smith, James Sprague, Trey Lake
   Date: May 30, 2017
   Desc: Definition of a class
         to store and manipulate rational (fractions, int/int)
         numbers.
*/
#include <string>

using namespace std;

class Rational{
  private:
  int* numerator;
  int* denominator;
  
  public:
  Rational();
  Rational(int top); 
  Rational(int top, int bottom);
  Rational(const Rational &);
  Rational& operator=(const Rational &);
  ~Rational();
  // Setters
  void setNumerator(const int &n);
  void setDenominator(const int &n);
  
  // Getters
  int getNumerator() const;
  int getDenominator() const;
  
  string print() const;
  
  // Comparison functions.
  bool isEqualTo(const Rational &other) const;
  bool isNotEqualTo(const Rational &) const;
  bool isGreaterThan(const Rational &other) const;
  bool isGreaterThanOrEqualTo(const Rational &other) const;
  bool isLessThan(const Rational &) const;
  bool isLessThanOrEqualTo(const Rational &) const;
  
  // These return a new Rational number, does not change either.
  Rational operator+(const Rational &other) const;
  Rational operator*(const Rational &other) const;
  Rational invert() const;
  Rational negate() const;
  Rational operator-(const Rational &) const;
  Rational operator/(const Rational &) const;
  bool operator==(const Rational &) const;
  bool operator<=(const Rational &) const;
  bool operator>=(const Rational &) const;
  bool operator<(const Rational &) const;
  bool operator>(const Rational &) const;
  bool operator!=(const Rational &) const;

};

#endif