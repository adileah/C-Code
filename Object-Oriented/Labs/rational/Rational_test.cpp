/* Name: Adileah Smith, James Sprague, Minhee Kwak
   Date: May 29, 2018
   Desc: Unit tests for the Rational Class
*/
#include "gtest/gtest.h"
#include "Rational.h"

ostream& operator<<(ostream &o, const Rational &r){
  o << r.print();
  return o;
}

TEST(getNumerator, Default){
  Rational a;
  EXPECT_EQ(a.getNumerator(), 1);
}

TEST(getNumerator, Overloaded1){
  Rational a(5,2);
  EXPECT_EQ(a.getNumerator(), 5);
}

TEST(getNumerator, Overloaded2){
  Rational a(-10,2);
  EXPECT_EQ(a.getNumerator(), -10);
}

TEST(getNumerator, Overloaded3){
  Rational a(9);
  EXPECT_EQ(a.getNumerator(), 9);
}


TEST(getDenominator, Default){
  Rational a;
  EXPECT_EQ(a.getDenominator(), 1);
}

TEST(getDenominator, Overloaded1){
  Rational a(5,2);
  EXPECT_EQ(a.getDenominator(), 2);
}

TEST(getDenominator, Overloaded2){
  Rational a(-10,20);
  EXPECT_EQ(a.getDenominator(), 20);
}

// Write more tests here!
TEST(additional, Default){
  Rational a; 
  Rational b;
  Rational c = a + b;
  EXPECT_EQ(c.getNumerator(), 2*c.getDenominator());
}

TEST(additional, two){
  Rational a(2,5); 
  Rational b(3,5);
  Rational c = a + b;
  EXPECT_EQ(c.getNumerator(), 25);
}

TEST(additional, three){
  Rational a(-2,4); 
  Rational b(2,4);
  Rational c = a + b;
  EXPECT_EQ(c.getNumerator(), 0);
}

TEST(mult, Default){
  Rational a;
  Rational b;
  Rational c = a * b;
  EXPECT_EQ(c.getNumerator(), c.getDenominator());
}

TEST(mult, two){
  Rational a(3,5);
  Rational b(2,5);
  Rational c = a * b;
  EXPECT_EQ(c.getNumerator(), 6);
  EXPECT_EQ(c.getDenominator(), 25);
}

TEST(mult, three){
  Rational a(-2,5);
  Rational b(2,5);
  Rational c = a * b;
  EXPECT_EQ(c.getNumerator(), -4);
  EXPECT_EQ(c.getDenominator(), 25);
}

TEST(divide, one){
  Rational a;
  Rational b;
  Rational c = a / b;
  EXPECT_EQ(c.getNumerator(), c.getDenominator() );
}

TEST (divide, two){
  Rational a(1, 2);
  Rational b(3, 2);
  Rational c = a / b;
  EXPECT_EQ(3*c.getNumerator(), c.getDenominator() );
}

TEST (divide, three){
  Rational a(-1, 2);
  Rational b(3, 2);
  Rational c = a / b;
  EXPECT_EQ(-3 * c.getNumerator(), c.getDenominator() );
  
}

TEST(subtract, Default){
  Rational a;
  Rational b;
  Rational c = a - b;
  EXPECT_EQ(c.getNumerator(), 0);
}

TEST(subtract, one){
  Rational a(2,5);
  Rational b(1,5);
  Rational c = a - b;
  EXPECT_EQ(5 * c.getNumerator(), c.getDenominator() );
  //EXPECT_EQ(c.getDenominator(), 25);
}

TEST(copy, one){
  Rational a(2,5);
  Rational b(a);
  EXPECT_EQ(5 * b.getNumerator(), 2 * b.getDenominator() );
}

TEST(assign, one){
  Rational a(2,5);
  Rational b(5,5);
  b = a;
  EXPECT_EQ(5 * b.getNumerator(), 2 * b.getDenominator() );
}

TEST(lessthan, one){
  Rational a(2,5);
  Rational b(5,5);
  EXPECT_EQ(a<b, true);
}

TEST(lessthanorequal, one){
  Rational a(2,5);
  Rational b(5,5);
  EXPECT_EQ(a<=b, true);
}
TEST(lessthanorequal, two){
  Rational a(5,5);
  Rational b(5,5);
  EXPECT_EQ(a<=b, true);
}

TEST(greaterthanorequal, one){
  Rational a(2,5);
  Rational b(5,5);
  EXPECT_EQ(b>=a, true);
}
TEST(greaterthanorequal, two){
  Rational a(2,5);
  Rational b(5,5);
  EXPECT_EQ(a>=b, false);
}
TEST(greaterthan, one){
  Rational a(2,5);
  Rational b(5,5);
  EXPECT_EQ(a>b, false);
}
TEST(equal, one){
  Rational a(5,5);
  Rational b(5,5);
  EXPECT_EQ(a==b, true);
}
TEST(notequal, one){
  Rational a(5,5);
  Rational b(5,5);
  EXPECT_EQ(a!=b, false);
}